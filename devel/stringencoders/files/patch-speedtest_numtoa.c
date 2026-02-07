--- test/speedtest_numtoa.c.orig	Wed Jun  6 13:24:30 2007
+++ test/speedtest_numtoa.c	Thu Jun 14 05:38:14 2007
@@ -26,7 +26,7 @@
         sprintf(buf, "%hhu", ju8);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -36,7 +36,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -45,7 +45,7 @@
         modp_uitoa10(ju8, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -56,7 +56,7 @@
         sprintf(buf, "%hu", ju16);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -66,7 +66,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -75,7 +75,7 @@
         modp_uitoa10(ju16, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -86,7 +86,7 @@
         sprintf(buf, "%u", i);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -95,7 +95,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -103,7 +103,7 @@
         modp_uitoa10(i, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -114,7 +114,7 @@
         sprintf(buf, "%hhd", ju8);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -124,7 +124,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -133,7 +133,7 @@
         modp_itoa10(j8, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -144,7 +144,7 @@
         sprintf(buf, "%hd", j16);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -154,7 +154,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -163,7 +163,7 @@
         modp_itoa10(j16, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -175,7 +175,7 @@
         sprintf(buf, "%d", i);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -184,7 +184,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -192,7 +192,7 @@
         modp_itoa10(i, buf);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
@@ -203,7 +203,7 @@
         sprintf(buf, "%e", (double)(i));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -213,7 +213,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -223,7 +223,7 @@
     }
     t1 = clock();
     last = (t1-t0);
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     t0 = clock();
@@ -232,7 +232,7 @@
         modp_dtoa(d, buf, 6);
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     printf("%.1fx\n", last/(t1-t0));
     fflush(stdout);
 
