--- Zend/zend_alloc.c.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_alloc.c
@@ -57,6 +57,7 @@
 #include "zend_operators.h"
 #include "zend_multiply.h"
 #include "zend_bitset.h"
+#include "zend_execute.h"
 #include <signal.h>
 
 #ifdef HAVE_UNISTD_H
@@ -363,9 +364,44 @@ static ZEND_COLD ZEND_NORETURN void zend_mm_panic(cons
 #if ZEND_DEBUG && defined(HAVE_KILL) && defined(HAVE_GETPID)
 	kill(getpid(), SIGSEGV);
 #endif
-	exit(1);
+	_exit(1);
 }
 
+ZEND_API ZEND_COLD ZEND_NORETURN void zend_mm_safe_error_ex(const char *format, ...)
+{
+	zend_string *script_filename = NULL;
+	uint32_t script_lineno = 0;
+
+	if (zend_is_executing()) {
+		script_filename = zend_get_executed_filename_ex();
+		script_lineno = zend_get_executed_lineno();
+	} else if (zend_is_compiling()) {
+		script_filename = zend_get_compiled_filename();
+		script_lineno = zend_get_compiled_lineno();
+	}
+
+	va_list args;
+	va_start(args, format);
+
+	char buf[1024];
+	vsnprintf(buf, sizeof(buf), format, args);
+
+	va_end(args);
+
+	fprintf(stderr,
+			"\nFatal error: %s in %s on line %d\n",
+			buf,
+			script_filename ? ZSTR_VAL(script_filename) : "Unknown",
+			script_lineno);
+
+	/* See http://support.microsoft.com/kb/190351 */
+# ifdef ZEND_WIN32
+	fflush(stderr);
+# endif
+
+	_exit(1);
+}
+
 static ZEND_COLD ZEND_NORETURN void zend_mm_safe_error(zend_mm_heap *heap,
 	const char *format,
 	size_t limit,
@@ -375,22 +411,14 @@ static ZEND_COLD ZEND_NORETURN void zend_mm_safe_error
 #endif
 	size_t size)
 {
+	(void) heap;
 
-	heap->overflow = 1;
-	zend_try {
-		zend_error_noreturn(E_ERROR,
-			format,
-			limit,
+	zend_mm_safe_error_ex(format, limit,
 #if ZEND_DEBUG
-			filename,
-			lineno,
+		filename,
+		lineno,
 #endif
-			size);
-	} zend_catch {
-	}  zend_end_try();
-	heap->overflow = 0;
-	zend_bailout();
-	exit(1);
+		size);
 }
 
 #ifdef _WIN32
@@ -1318,7 +1346,7 @@ static zend_always_inline void *zend_mm_alloc_heap(zen
 	size = MAX(size, 1);
 	size = ZEND_MM_ALIGNED_SIZE(size) + ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info));
 	if (UNEXPECTED(size < real_size)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu + %zu)", ZEND_MM_ALIGNED_SIZE(real_size), ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info)));
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%zu + %zu)", ZEND_MM_ALIGNED_SIZE(real_size), ZEND_MM_ALIGNED_SIZE(sizeof(zend_mm_debug_info)));
 		return NULL;
 	}
 #endif
@@ -1762,7 +1790,7 @@ static void *zend_mm_alloc_huge(zend_mm_heap *heap, si
 	void *ptr;
 
 	if (UNEXPECTED(new_size < size)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%zu + %zu)", size, alignment);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%zu + %zu)", size, alignment);
 	}
 
 #if ZEND_MM_LIMIT
@@ -2618,7 +2646,7 @@ ZEND_API char* ZEND_FASTCALL _estrdup(const char *s ZE
 
 	length = strlen(s);
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) _emalloc(length + 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 	memcpy(p, s, length+1);
@@ -2630,7 +2658,7 @@ ZEND_API char* ZEND_FASTCALL _estrndup(const char *s, 
 	char *p;
 
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) _emalloc(length + 1 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 	memcpy(p, s, length);
@@ -2644,7 +2672,7 @@ ZEND_API char* ZEND_FASTCALL zend_strndup(const char *
 	char *p;
 
 	if (UNEXPECTED(length + 1 == 0)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (1 * %zu + 1)", length);
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (1 * %zu + 1)", length);
 	}
 	p = (char *) malloc(length + 1);
 	if (UNEXPECTED(p == NULL)) {
@@ -3048,7 +3076,7 @@ static ZEND_COLD ZEND_NORETURN void zend_out_of_memory
 static ZEND_COLD ZEND_NORETURN void zend_out_of_memory(void)
 {
 	fprintf(stderr, "Out of memory\n");
-	exit(1);
+	_exit(1);
 }
 
 ZEND_API void * __zend_malloc(size_t len)
