--- test/test_foreign_exceptions.cc.orig	2016-05-29 13:30:15 UTC
+++ test/test_foreign_exceptions.cc
@@ -0,0 +1,125 @@
+#include <cstdio>
+#include <cstdlib>
+#include "unwind.h"
+
+#define EXCEPTION_CLASS(a,b,c,d,e,f,g,h) \
+	((static_cast<uint64_t>(a) << 56) +\
+	 (static_cast<uint64_t>(b) << 48) +\
+	 (static_cast<uint64_t>(c) << 40) +\
+	 (static_cast<uint64_t>(d) << 32) +\
+	 (static_cast<uint64_t>(e) << 24) +\
+	 (static_cast<uint64_t>(f) << 16) +\
+	 (static_cast<uint64_t>(g) << 8) +\
+	 (static_cast<uint64_t>(h)))
+
+// using ld --wrap=_Unwind_RaiseException hook feature
+extern "C" _Unwind_Reason_Code __real__Unwind_RaiseException (_Unwind_Exception *e);
+extern "C" _Unwind_Reason_Code __wrap__Unwind_RaiseException (_Unwind_Exception *e);
+
+extern "C" _Unwind_Reason_Code __wrap__Unwind_RaiseException (_Unwind_Exception *e)
+{
+	// clobber exception class forcing libcxx own exceptions to be treated
+	// as foreign exception within libcxx itself
+	e->exception_class = EXCEPTION_CLASS('F','O','R','E','I','G','N','\0');
+	__real__Unwind_RaiseException(e);
+}
+
+_Unwind_Exception global_e;
+
+enum test_status {
+	PENDING, PASSED, FAILED
+};
+
+const char test_status_str[][8] = {
+	"PENDING", "PASSED", "FAILED"
+};
+
+test_status test1_status = PENDING;
+test_status test2_status = PENDING;
+test_status test3_status = PENDING;
+
+void test2_exception_cleanup(_Unwind_Reason_Code code, _Unwind_Exception *e)
+{
+	fputs("(2) exception_cleanup called\n", stderr);
+	if (e != &global_e) {
+		fprintf(stderr, "(2) ERROR: unexpected ptr: expecting %p, got %p\n", &global_e, e);
+		test2_status = FAILED;
+	}
+	if (test2_status == PENDING)
+		test2_status = PASSED;
+}
+
+struct test3_exception
+{
+	static int counter;
+	~test3_exception()
+	{
+		counter++;
+		fputs("(3) exception dtor\n", stderr);
+	}
+};
+int test3_exception::counter = 0;
+
+int main()
+{
+	///////////////////////////////////////////////////////////////
+	fputs("(1) foreign exception, exception_cleanup=nullptr\n", stderr);
+	try
+	{
+		global_e.exception_class = 0;
+		global_e.exception_cleanup = 0;
+		__real__Unwind_RaiseException(&global_e);
+	}
+	catch (...)
+	{
+	}
+	test1_status = PASSED;
+	fputs("(1) PASS\n", stderr);
+
+	///////////////////////////////////////////////////////////////
+	fputs("(2) foreign exception, exception_cleanup present\n", stderr);
+	try
+	{
+		global_e.exception_class = 0;
+		global_e.exception_cleanup = test2_exception_cleanup;
+		__real__Unwind_RaiseException(&global_e);
+	}
+	catch (...)
+	{
+	}
+	fprintf(stderr, "(2) %s\n", test_status_str[test2_status]);
+
+	///////////////////////////////////////////////////////////////
+	fputs("(3) C++ exception in foreign environment\n", stderr);
+	int counter_expected;
+	try
+	{
+		// throw was rigged such that the runtime treats C++ exceptions
+		// as foreign ones
+		throw test3_exception();
+	}
+	catch (test3_exception&)
+	{
+		fputs("(3) ERROR: wrong catch\n", stderr);
+		test3_status = FAILED;
+	}
+	catch (...)
+	{
+		fputs("(3) catch(...)\n", stderr);
+		counter_expected = test3_exception::counter + 1;
+		// one more dtor immediately after we leave catch
+	}
+	if (test3_status == PENDING && test3_exception::counter != counter_expected) {
+		fputs("(3) ERROR: exception dtor didn't run\n", stderr);
+		test3_status = FAILED;
+	}
+	if (test3_status == PENDING)
+		test3_status = PASSED;
+	fprintf(stderr, "(3) %s\n", test_status_str[test3_status]);
+
+	///////////////////////////////////////////////////////////////
+	if (test1_status == PASSED && test2_status == PASSED && test3_status == PASSED)
+		return EXIT_SUCCESS;
+	else
+		return EXIT_FAILURE;
+}
