--- ./scanner.h.orig	Thu Aug 26 23:46:32 1999
+++ ./scanner.h	Sat Oct  5 13:27:00 2002
@@ -6,10 +6,10 @@
 class Scanner {
   private:
     int			in;
-    uchar		*bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
+    char		*bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
     uint		tchar, tline, cline;
   private:
-    uchar *fill(uchar*);
+    char *fill(char*);
   public:
     Scanner(int);
     int echo(ostream&);
