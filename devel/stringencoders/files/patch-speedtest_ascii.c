--- test/speedtest_ascii.c.orig	Wed Jun  6 13:24:30 2007
+++ test/speedtest_ascii.c	Thu Jun 14 05:39:13 2007
@@ -244,7 +244,7 @@
     }
     t1 = clock();
     last = t1 -t0;
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     /**
@@ -255,7 +255,7 @@
         toupper_copy2(obuf, buf, sizeof(buf));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     /**
@@ -266,7 +266,7 @@
         toupper_copy3(obuf, buf, sizeof(buf));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     /**
@@ -277,7 +277,7 @@
         toupper_copy4(obuf, buf, sizeof(buf));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
 
@@ -289,7 +289,7 @@
         toupper_copy5(obuf, buf, sizeof(buf));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     /**
@@ -300,7 +300,7 @@
         toupper_copy6(obuf, buf, sizeof(buf));
     }
     t1 = clock();
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     /**
@@ -312,7 +312,7 @@
     }
     t1 = clock();
 
-    printf("%lu\t", (t1-t0));
+    printf("%lu\t", (unsigned long)(t1-t0));
     fflush(stdout);
 
     printf("%.1fx\n", last/(t1-t0));
