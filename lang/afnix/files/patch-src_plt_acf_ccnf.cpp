--- src/plt/acf/ccnf.cpp.orig	Wed Jan 12 06:05:00 2005
+++ src/plt/acf/ccnf.cpp	Wed Feb 16 19:18:04 2005
@@ -42,6 +42,7 @@
 #define AFNIX_PROCTYPE_IA64     10
 #define AFNIX_PROCTYPE_S390     11
 #define AFNIX_PROCTYPE_X64      12
+#define AFNIX_PROCTYPE_AMD64    12
 
 // recognized processor name
 #define AFNIX_PROCNAME_UNKNOWN   "unknown"
@@ -57,6 +58,7 @@
 #define AFNIX_PROCNAME_IA64      "ia64"
 #define AFNIX_PROCNAME_S390      "s390"
 #define AFNIX_PROCNAME_X64       "x64"
+#define AFNIX_PROCNAME_AMD64     "amd64"
 
 // force size type with S390
 #if defined(__s390__)
@@ -117,6 +119,9 @@
   // s390
   if (strcmp (proc, AFNIX_PROCNAME_S390) == 0)
     return AFNIX_PROCTYPE_S390;
+  // amd64
+  if (strcmp (proc, AFNIX_PROCNAME_AMD64) == 0)
+    return AFNIX_PROCTYPE_AMD64;
   // x86-64
   if (strcmp (proc, AFNIX_PROCNAME_X64) == 0) {
     switch (sizeof(void*)) {
@@ -260,6 +265,8 @@
 	   AFNIX_PROCTYPE_IA64);
   fprintf (stdout, "#define  AFNIX_PROCTYPE_S390      %d\n",
 	   AFNIX_PROCTYPE_S390);
+  fprintf (stdout, "#define  AFNIX_PROCTYPE_AMD64     %d\n",
+	   AFNIX_PROCTYPE_AMD64);
   fprintf (stdout, "#define  AFNIX_PROCTYPE_X64       %d\n",
 	   AFNIX_PROCTYPE_X64);
   fprintf (stdout, "\n");
