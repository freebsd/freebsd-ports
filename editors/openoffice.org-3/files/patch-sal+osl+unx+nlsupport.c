--- ../sal/osl/unx/nlsupport.c	Wed Feb 27 00:54:01 2002
+++ ../sal/osl/unx/nlsupport.c	Wed Feb 27 15:00:58 2002
@@ -63,7 +63,7 @@
 #include <osl/diagnose.h>
 #include <osl/process.h>
 
-#if defined(LINUX) || defined(SOLARIS)
+#if defined(LINUX) || defined(SOLARIS) || defined(FREEBSD)
 #include <pthread.h>
 #include <locale.h>
 #include <langinfo.h>
@@ -841,7 +841,7 @@
             snprintf(env_buf, sizeof(env_buf), "LC_CTYPE=%s", locale_buf);
             env_buf[sizeof(env_buf)] = '\0';
             putenv(env_buf);
-#elif defined( FREEBAD ) || defined( NETBSD )
+#elif defined( FREEBSD ) || defined( NETBSD )
             setenv("LC_CTYPE", locale_buf, 1 );
 #else
             setenv( "LC_CTYPE", locale_buf );
@@ -853,7 +853,7 @@
             snprintf(env_buf, sizeof(env_buf), "LANG=%s", locale_buf);
             env_buf[sizeof(env_buf)] = '\0';
             putenv(env_buf);
-#elif defined( FREEBAD ) || defined( NETBSD )
+#elif defined( FREEBSD ) || defined( NETBSD )
             setenv("LC_CTYPE", locale_buf, 1 );
 #else
             setenv( "LANG", locale_buf );
