--- main.c.orig	2017-03-30 13:30:41 UTC
+++ main.c
@@ -1264,8 +1264,10 @@ int main(int argc, char * argv [])
       }
     }
     
+    AVRMEM * m;
+    m = avr_locate_mem(p, "fuse");
     /* Now check what fuses are against what they should be */
-    if (safemodeafter_fuse != safemode_fuse) {
+    if (compare_memory_masked(m, safemodeafter_fuse, safemode_fuse)) {
       fuses_updated = 1;
       avrdude_message(MSG_INFO, "%s: safemode: fuse changed! Was %x, and is now %x\n",
               progname, safemode_fuse, safemodeafter_fuse);
@@ -1293,7 +1295,8 @@ int main(int argc, char * argv [])
     }
 
     /* Now check what fuses are against what they should be */
-    if (safemodeafter_lfuse != safemode_lfuse) {
+    m = avr_locate_mem(p, "lfuse");
+    if (compare_memory_masked(m, safemodeafter_lfuse, safemode_lfuse)) {
       fuses_updated = 1;
       avrdude_message(MSG_INFO, "%s: safemode: lfuse changed! Was %x, and is now %x\n",
               progname, safemode_lfuse, safemodeafter_lfuse);
@@ -1321,7 +1324,8 @@ int main(int argc, char * argv [])
     }
 
     /* Now check what fuses are against what they should be */
-    if (safemodeafter_hfuse != safemode_hfuse) {
+    m = avr_locate_mem(p, "hfuse");
+    if (compare_memory_masked(m, safemodeafter_hfuse, safemode_hfuse)) {
       fuses_updated = 1;
       avrdude_message(MSG_INFO, "%s: safemode: hfuse changed! Was %x, and is now %x\n",
               progname, safemode_hfuse, safemodeafter_hfuse);
@@ -1346,7 +1350,8 @@ int main(int argc, char * argv [])
     }
 
     /* Now check what fuses are against what they should be */
-    if (safemodeafter_efuse != safemode_efuse) {
+    m = avr_locate_mem(p, "efuse");
+    if (compare_memory_masked(m, safemodeafter_efuse, safemode_efuse)) {
       fuses_updated = 1;
       avrdude_message(MSG_INFO, "%s: safemode: efuse changed! Was %x, and is now %x\n",
               progname, safemode_efuse, safemodeafter_efuse);
