--- cdplayer.cc.orig	1999-02-02 23:28:24 UTC
+++ cdplayer.cc
@@ -29,7 +29,7 @@ private:
 public:
     button (char *s) {state=0; strcpy (name, s);}
     ~button () {}
-    set (int i) {
+    void set (int i) {
 	if (state != i) {
 	    state = i;
 	    if (state == 0)
@@ -90,7 +90,7 @@ button play_button ("play"),  pause_butt
 #define S(t) toc_buffer[t].addr.msf.second
 #define F(t) toc_buffer[t].addr.msf.frame
 
-main (int argc, char **argv)
+int main (int argc, char **argv)
 {
     char dev[20], line[50];
     int i;
