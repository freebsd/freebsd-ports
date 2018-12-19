--- test/test-main.c.orig	2018-03-08 05:27:35 UTC
+++ test/test-main.c
@@ -43,6 +43,7 @@ extern Suite *uinput_suite(void);
 static int
 is_debugger_attached(void)
 {
+#if defined (linux)
 	int status;
 	int rc;
 	int pid = fork();
@@ -66,6 +67,15 @@ is_debugger_attached(void)
 	}
 
 	return rc;
+#else
+	/*
+	 * Skip useless gdb test as setting CK_FORK environment variable in
+	 * absence of attached debugger gives no harm to user.
+	 * Moreover this test is broken on most nonlinux systems, look at
+	 * discussion here: http://stackoverflow.com/questions/3596781/
+	 */
+	return 1;
+#endif
 }
 
 int main(void)
