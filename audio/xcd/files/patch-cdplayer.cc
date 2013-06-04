--- cdplayer.cc.orig	Sat Nov 27 16:20:49 1999
+++ cdplayer.cc	Sat Nov 27 16:24:02 1999
@@ -29,7 +29,7 @@
 public:
     button (char *s) {state=0; strcpy (name, s);}
     ~button () {}
-    set (int i) {
+    void set (int i) {
 	if (state != i) {
 	    state = i;
 	    if (state == 0)
@@ -90,7 +90,7 @@
 #define S(t) toc_buffer[t].addr.msf.second
 #define F(t) toc_buffer[t].addr.msf.frame
 
-main (int argc, char **argv)
+int main (int argc, char **argv)
 {
     char dev[20], line[50];
     int i;
