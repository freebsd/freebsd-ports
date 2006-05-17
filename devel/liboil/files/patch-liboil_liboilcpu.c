--- liboil/liboilcpu.c.orig	Mon Mar 20 22:14:01 2006
+++ liboil/liboilcpu.c	Wed May 17 17:47:44 2006
@@ -71,7 +71,11 @@
   cpuinfo = malloc(4096);
   if (cpuinfo == NULL) return NULL;
 
-  fd = open("/proc/cpuinfo", O_RDONLY);
+ #if defined(__FreeBSD__)
+   fd = open("/var/run/dmesg.boot", O_RDONLY);
+ #else
+   fd = open("/proc/cpuinfo", O_RDONLY);
+ #endif
   if (fd < 0) {
     free (cpuinfo);
     return NULL;
@@ -104,6 +108,37 @@
   }
 
   flags = strsplit(cpuinfo_flags);
+#if defined(__FreeBSD__)
+  for (f = flags; *f; f++) {
+    if (strcmp (*f, "CMOV") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_CMOV;
+    }
+    if (strcmp (*f, "MMX") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_MMX;
+    }
+    if (strcmp (*f, "SSE") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_SSE;
+    }
+    if (strcmp (*f, "AMIE") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_MMXEXT;
+    }
+    if (strcmp (*f, "SSE2") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_SSE2;
+    }
+    if (strcmp (*f, "3DNow!") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_3DNOW;
+    }
+    if (strcmp (*f, "DSP") == 0) {
+      OIL_DEBUG ("cpu flag %s", *f);
+      oil_cpu_flags |= OIL_IMPL_FLAG_3DNOWEXT;
+    }
+#else
   for (f = flags; *f; f++) {
     if (strcmp (*f, "cmov") == 0) {
       OIL_DEBUG ("cpu flag %s", *f);
@@ -134,6 +169,7 @@
       OIL_DEBUG ("cpu flag %s", *f);
       oil_cpu_flags |= OIL_IMPL_FLAG_3DNOWEXT;
     }
+#endif
 
     free (*f);
   }
@@ -381,12 +417,22 @@
   char *end;
   char *colon;
 
+#if defined(__FreeBSD__)
+  flags = strstr(cpuinfo,"Features");
+#else
   flags = strstr(cpuinfo,"flags");
+#endif
   if (flags == NULL) return NULL;
 
+#if defined(__FreeBSD__)
+  end = strchr(flags, '>');
+  if (end == NULL) return NULL;
+  colon = strchr (flags, '<');
+#else
   end = strchr(flags, '\n');
   if (end == NULL) return NULL;
   colon = strchr (flags, ':');
+#endif
   if (colon == NULL) return NULL;
   colon++;
   if(colon >= end) return NULL;
@@ -402,15 +448,22 @@
   char *tok;
   int n = 0;
 
+#if !defined(__FreeBSD__)
   while (*s == ' ') s++;
+#endif
 
   list = malloc (1 * sizeof(char *));
   while (*s) {
     tok = s;
+#if defined(__FreeBSD__)
+    while (*s && *s != ',') s++;
+    list[n] = _strndup (tok, s - tok);
+    s++;
+#else
     while (*s && *s != ' ') s++;
-
     list[n] = _strndup (tok, s - tok);
     while (*s && *s == ' ') s++;
+#endif
     list = realloc (list, (n + 2) * sizeof(char *));
     n++;
   }
