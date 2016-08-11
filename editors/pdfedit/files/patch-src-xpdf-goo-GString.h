--- src/xpdf/goo/GString.h.orig	2009-09-11 12:02:56 UTC
+++ src/xpdf/goo/GString.h
@@ -67,8 +67,8 @@ public:
   //     t -- GString *
   //     w -- blank space; arg determines width
   // To get literal curly braces, use {{ or }}.
-  static GString *format(char *fmt, ...);
-  static GString *formatv(char *fmt, va_list argList);
+  static GString *format(const char *fmt, ...);
+  static GString *formatv(const char *fmt, va_list argList);
 
   // Destructor.
   ~GString();
@@ -95,8 +95,8 @@ public:
   GString *append(const char *str, int lengthA);
 
   // Append a formatted string.
-  GString *appendf(char *fmt, ...);
-  GString *appendfv(char *fmt, va_list argList);
+  GString *appendf(const char *fmt, ...);
+  GString *appendfv(const char *fmt, va_list argList);
 
   // Insert a character or string.
   GString *insert(int i, char c);
@@ -125,12 +125,12 @@ private:
   void resize(int length1);
   static void formatInt(long x, char *buf, int bufSize,
 			GBool zeroFill, int width, int base,
-			char **p, int *len);
+			const char **p, int *len);
   static void formatUInt(Gulong x, char *buf, int bufSize,
 			 GBool zeroFill, int width, int base,
-			 char **p, int *len);
+			 const char **p, int *len);
   static void formatDouble(double x, char *buf, int bufSize, int prec,
-			   GBool trim, char **p, int *len);
+			   GBool trim, const char **p, int *len);
 };
 
 #if defined(WIN32) || defined(UNDER_CE)
