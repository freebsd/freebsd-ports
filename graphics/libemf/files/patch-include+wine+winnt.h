--- include/wine/winnt.h.orig	Tue Jan 29 13:31:53 2002
+++ include/wine/winnt.h	Wed Mar 17 20:00:59 2004
@@ -45,6 +45,18 @@
 # undef WORDS_BIGENDIAN
 # undef BITFIELDS_BIGENDIAN
 # undef ALLOW_UNALIGNED_ACCESS
+#elif defined(__amd64__)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# define ALLOW_UNALIGNED_ACCESS
+#elif defined(__ia64__)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# define ALLOW_UNALIGNED_ACCESS
+#elif defined(__sparc64__)
+# undef  WORDS_BIGENDIAN
+# undef  BITFIELDS_BIGENDIAN
+# define ALLOW_UNALIGNED_ACCESS
 #elif !defined(RC_INVOKED)
 # error Unknown CPU architecture!
 #endif
@@ -211,7 +223,7 @@
 typedef unsigned short  WORD,       *PWORD,    *LPWORD;
 typedef int             INT,        *PINT,     *LPINT;
 typedef unsigned int    UINT,       *PUINT,    *LPUINT;
-#if !defined(__alpha__)
+#if !defined(__alpha__) && !defined(__amd64__) && !defined(__ia64__) && !defined(__sparc64__)
 typedef unsigned long   DWORD,      *PDWORD,   *LPDWORD;
 typedef unsigned long   ULONG,      *PULONG,   *LPULONG;
 #else /* defined( __alpha__ ) */
@@ -257,7 +269,7 @@
 typedef BYTE            BOOLEAN,    *PBOOLEAN;
 typedef char            CHAR,       *PCHAR;
 typedef short           SHORT,      *PSHORT;
-#if !defined(__alpha__)
+#if !defined(__alpha__) && !defined(__amd64__) && !defined(__ia64__) && !defined(__sparc64__)
 typedef long            LONG,       *PLONG,    *LPLONG;
 #else /* defined( __alpha__ ) */
 typedef int             LONG,       *PLONG,    *LPLONG;
@@ -1044,6 +1056,11 @@
 } CONTEXT;
 
 #endif  /* __sparc__ */
+
+#if defined(__amd64__) || defined(__ia64__) || defined(__sparc64__)
+#define CONTEXT_FULL 1
+typedef struct _CONTEXT CONTEXT;
+#endif
 
 #if !defined(CONTEXT_FULL) && !defined(RC_INVOKED)
 #error You need to define a CONTEXT for your CPU
