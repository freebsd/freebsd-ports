--- src/plt/acf/ccnf.cpp.orig	Tue Feb  8 21:37:05 2005
+++ src/plt/acf/ccnf.cpp	Tue Feb  8 21:38:33 2005
@@ -41,6 +41,7 @@
 #define ALEPH_PROCTYPE_PA64      9
 #define ALEPH_PROCTYPE_IA64     10
 #define ALEPH_PROCTYPE_S390     11
+#define ALEPH_PROCTYPE_AMD64    12
 
 // recognized processor name
 #define ALEPH_PROCNAME_IA        "ia"
@@ -54,6 +55,7 @@
 #define ALEPH_PROCNAME_PA64      "pa64"
 #define ALEPH_PROCNAME_IA64      "ia64"
 #define ALEPH_PROCNAME_S390      "s390"
+#define ALEPH_PROCNAME_AMD64     "amd64"
 
 // force size type with S390
 #if defined(__s390__)
@@ -114,6 +116,9 @@
   // s390
   if (strcmp (proc, ALEPH_PROCNAME_S390) == 0)
     return ALEPH_PROCTYPE_S390;
+  // amd64
+  if (strcmp (proc, ALEPH_PROCNAME_AMD64) == 0)
+    return ALEPH_PROCTYPE_AMD64;
   // unknown
   return ALEPH_PROCTYPE_UNKNOWN;
 }
@@ -228,6 +233,8 @@
 	   ALEPH_PROCTYPE_IA64);
   fprintf (stdout, "#define  ALEPH_PROCTYPE_S390      %d\n",
 	   ALEPH_PROCTYPE_S390);
+  fprintf (stdout, "#define  ALEPH_PROCTYPE_AMD64     %d\n",
+	   ALEPH_PROCTYPE_AMD64);
   fprintf (stdout, "\n");
 
   // install the config names
