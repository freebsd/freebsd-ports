--- ../mingpp.h	Thu Mar  7 18:28:27 2002
+++ ../mingpp.h	Thu Mar  7 18:28:41 2002
@@ -627,7 +627,7 @@
   void setColor(unsigned char r, unsigned char g, unsigned char b, int a=0xff)
     { SWFText_setColor(this->text, r, g, b, a); }
 
-  void addString(const char *string, float *advance=NULL)
+  void addString(const char *string, int *advance=NULL)
     { SWFText_addString(this->text, string, advance); }
 
   void setSpacing(float spacing)
