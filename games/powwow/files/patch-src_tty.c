--- src/tty.c.orig	2019-11-06 05:25:17 UTC
+++ src/tty.c
@@ -9,7 +9,12 @@
  *  (at your option) any later version.
  *
  */
-#include <alloca.h>
+
+#ifdef BSD_LIKE
+#define COMPAT_43TTY 1
+#define __BSD_VISIBLE 1
+#endif
+
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -847,31 +852,25 @@ again:
 
 int tty_printf(const char *format, ...)
 {
-    char buf[1024], *bufp = buf;
+    char *bufp;
+    char *old_locale;
     va_list va;
     int res;
 
-    char *old_locale = strdup(setlocale(LC_ALL, NULL));
+    if ((old_locale = strdup(setlocale(LC_ALL, NULL))) == NULL)
+	    return -1;
 
     setlocale(LC_ALL, "C");
-
     va_start(va, format);
-    res = vsnprintf(buf, sizeof buf, format, va);
+    res = vasprintf(&bufp, format, va);
     va_end(va);
-
-    if (res >= sizeof buf) {
-	bufp = alloca(res + 1);
-	va_start(va, format);
-	vsprintf(bufp, format, va);
-        assert(strlen(bufp) == res);
-	va_end(va);
-    }
-
+    if (res < 0)
+	    goto out;
     setlocale(LC_ALL, old_locale);
-    free(old_locale);
-
     tty_puts(bufp);
-
+    free(bufp);
+out:
+    free(old_locale);
     return res;
 }
 
@@ -968,16 +967,23 @@ int tty_read(char *buf, size_t count)
 
 void tty_gets(char *s, int size)
 {
-    wchar_t *ws = alloca(size * sizeof *ws);
+    wchar_t *ws = NULL;
 
+    if ((ws = malloc(size * sizeof *ws)) == NULL)
+	    goto out;;
+
     if (!fgetws(ws, size, stdin))
-	return;
+	goto out;
 
     while (*ws) {
 	if (!(*ws & ~0xff))
 	    *s++ = (unsigned char)*ws;
 	++ws;
     }
+out:
+    if (ws != NULL)
+	    free(ws);
+    return;
 }
 
 void tty_flush(void)
