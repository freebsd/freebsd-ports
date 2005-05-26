--- liboil/liboilcpu.c.orig	Sat May 21 14:12:56 2005
+++ liboil/liboilcpu.c	Sat May 21 14:34:37 2005
@@ -59,7 +59,11 @@
   cpuinfo = malloc(4096);
   if (cpuinfo == NULL) return NULL;
 
+#if defined(__FreeBSD__)
+  fd = open("/var/run/dmesg.boot", O_RDONLY);
+#else
   fd = open("/proc/cpuinfo", O_RDONLY);
+#endif
   if (fd < 0) return NULL;
 
   n = read(fd, cpuinfo, 4095);
@@ -84,6 +88,37 @@
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
@@ -113,6 +148,7 @@
       OIL_DEBUG ("cpu flag %s", *f);
       oil_cpu_flags |= OIL_IMPL_FLAG_3DNOWEXT;
     }
+#endif
 
     free (*f);
   }
@@ -282,12 +318,22 @@
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
@@ -303,15 +349,22 @@
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
