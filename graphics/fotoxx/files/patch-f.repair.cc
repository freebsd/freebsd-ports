--- f.repair.cc.orig	2015-05-01 09:40:38 UTC
+++ f.repair.cc
@@ -2055,7 +2055,7 @@ void m_smart_erase(GtkWidget *, const ch
 int smart_erase_dialog_event(zdialog *zd, const char *event)               //  overhauled
 {
    void smart_erase_func(int mode);
-   void smart_erase_blur(float radius);
+   int smart_erase_blur(float radius);
 
    float       radius;
    int         cc;
