--- src/xpdf/goo/GString.cc.orig	2009-09-11 12:02:56 UTC
+++ src/xpdf/goo/GString.cc
@@ -60,7 +60,7 @@ enum GStringFormatType {
   fmtSpace
 };
 
-static char *formatStrings[] = {
+static const char *formatStrings[] = {
   "d", "x", "o", "b", "ud", "ux", "uo", "ub",
   "ld", "lx", "lo", "lb", "uld", "ulx", "ulo", "ulb",
   "f", "g",
@@ -144,14 +144,14 @@ GString::GString(const GString *str1, co
 
 GString *GString::fromInt(int x) {
   char buf[24]; // enough space for 64-bit ints plus a little extra
-  char *p;
+  const char *p;
   int len;
 
   formatInt(x, buf, sizeof(buf), gFalse, 0, 10, &p, &len);
   return new GString(p, len);
 }
 
-GString *GString::format(char *fmt, ...) {
+GString *GString::format(const char *fmt, ...) {
   va_list argList;
   GString *s;
 
@@ -162,7 +162,7 @@ GString *GString::format(char *fmt, ...)
   return s;
 }
 
-GString *GString::formatv(char *fmt, va_list argList) {
+GString *GString::formatv(const char *fmt, va_list argList) {
   GString *s;
 
   s = new GString();
@@ -213,7 +213,7 @@ GString *GString::append(const char *str
   return this;
 }
 
-GString *GString::appendf(char *fmt, ...) {
+GString *GString::appendf(const char *fmt, ...) {
   va_list argList;
 
   va_start(argList, fmt);
@@ -222,7 +222,7 @@ GString *GString::appendf(char *fmt, ...
   return this;
 }
 
-GString *GString::appendfv(char *fmt, va_list argList) {
+GString *GString::appendfv(const char *fmt, va_list argList) {
   GStringFormatArg *args;
   int argsLen, argsSize;
   GStringFormatArg arg;
@@ -231,7 +231,7 @@ GString *GString::appendfv(char *fmt, va
   GStringFormatType ft;
   char buf[65];
   int len, i;
-  char *p0, *p1, *str;
+  const char *p0, *p1, *str;
 
   argsLen = 0;
   argsSize = 8;
@@ -465,7 +465,7 @@ GString *GString::appendfv(char *fmt, va
 
 void GString::formatInt(long x, char *buf, int bufSize,
 			GBool zeroFill, int width, int base,
-			char **p, int *len) {
+			const char **p, int *len) {
   static char vals[17] = "0123456789abcdef";
   GBool neg;
   int start, i, j;
@@ -497,7 +497,7 @@ void GString::formatInt(long x, char *bu
 
 void GString::formatUInt(Gulong x, char *buf, int bufSize,
 			 GBool zeroFill, int width, int base,
-			 char **p, int *len) {
+			 const char **p, int *len) {
   static char vals[17] = "0123456789abcdef";
   int i, j;
 
@@ -520,7 +520,7 @@ void GString::formatUInt(Gulong x, char 
 }
 
 void GString::formatDouble(double x, char *buf, int bufSize, int prec,
-			   GBool trim, char **p, int *len) {
+			   GBool trim, const char **p, int *len) {
   GBool neg, started;
   double x2;
   int d, i, j;
