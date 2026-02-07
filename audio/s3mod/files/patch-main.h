--- main.h.orig	1995-10-21 06:56:32 UTC
+++ main.h
@@ -43,7 +43,7 @@ extern uint32 mixspeed;
 
 void help(void);
 void get_audio_device(void);
-void main(int argc, char **argv);
+int main(int argc, char **argv);
 
 
 #endif /* _MAIN_H */
