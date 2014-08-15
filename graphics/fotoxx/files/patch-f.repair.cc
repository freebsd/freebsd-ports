--- f.repair.cc.orig	2014-08-15 14:19:11.000000000 -0400
+++ f.repair.cc	2014-08-15 14:20:01.000000000 -0400
@@ -1571,7 +1571,7 @@
 int smart_erase_dialog_event(zdialog *zd, const char *event)               //  overhauled
 {
    void smart_erase_func(int mode);
-   void smart_erase_blur(float radius);
+   int smart_erase_blur(float radius);
    
    float       radius;
    int         cc;
