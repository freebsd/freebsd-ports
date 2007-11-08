--- include/tv/inputln.h.orig	2007-11-05 15:06:18.000000000 +0600
+++ include/tv/inputln.h	2007-11-05 15:06:41.000000000 +0600
@@ -196,7 +196,7 @@
      { return name; }
 
 protected:
- TInputLine::TInputLine(StreamableInit) :
+ TInputLine(StreamableInit) :
    TInputLineBaseT<char,TDrawBuffer>(streamableInit) {}
 
 public:
