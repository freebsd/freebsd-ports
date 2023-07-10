--- gclib/GStr.cpp.orig	2023-07-10 09:57:46 UTC
+++ gclib/GStr.cpp
@@ -424,8 +424,8 @@ GStr& GStr::trim(char c) {
   }
 
 GStr& GStr::trim(char c) {
- register int istart;
- register int iend;
+ int istart;
+ int iend;
  for (istart=0; istart<length() && my_data->chars[istart]==c;istart++) ;
  if (istart==length()) {
        make_unique(); //edit operation ahead
@@ -444,8 +444,8 @@ GStr& GStr::trim(const char* c) {
  }
 
 GStr& GStr::trim(const char* c) {
- register int istart;
- register int iend;
+ int istart;
+ int iend;
  for (istart=0; istart<length() && strchr(c, my_data->chars[istart])!=NULL ;istart++) ;
  if (istart==length()) {
         prep_data(0); //string was entirely trimmed
@@ -464,8 +464,8 @@ GStr& GStr::trimR(char c) {
 
 GStr& GStr::trimR(char c) {
  //only trim the right end
- //register int istart;
- register int iend;
+ //int istart;
+ int iend;
  for (iend=length()-1; iend>=0 && my_data->chars[iend]==c;iend--) ;
  if (iend==-1) {
        make_unique();
@@ -488,7 +488,7 @@ GStr& GStr::trimR(const char* c) {
  }
 
 GStr& GStr::trimR(const char* c) {
- register int iend;
+ int iend;
  for (iend=length()-1; iend>=0 && strchr(c,my_data->chars[iend])!=NULL;iend--) ;
  if (iend==-1) {
        make_unique();
@@ -511,7 +511,7 @@ GStr& GStr::chomp(const char* cstr) {
 
 
 GStr& GStr::chomp(const char* cstr) {
- register int iend;
+ int iend;
  if (cstr==NULL || *cstr==0) return *this;
  //check if this ends with cstr
  int cend=strlen(cstr)-1;
@@ -537,7 +537,7 @@ GStr& GStr::trimL(char c) {
  }
 
 GStr& GStr::trimL(char c) {
- register int istart;
+ int istart;
  for (istart=0; istart<length() && my_data->chars[istart]==c;istart++) ;
  if (istart==length()) {
        prep_data(0); //string was entirely trimmed
@@ -554,7 +554,7 @@ GStr& GStr::trimL(const char* c) {
  }
 
 GStr& GStr::trimL(const char* c) {
- register int istart;
+ int istart;
  for (istart=0; istart<length() && strchr(c,my_data->chars[istart])!=NULL;istart++) ;
  if (istart==length()) {
        prep_data(0); //string was entirely trimmed
@@ -700,7 +700,7 @@ bool GStr::is_space() const {
     if (my_data == &null_data)
         return false;
 
-    for (register const char *p = my_data->chars; *p; p++)
+    for (const char *p = my_data->chars; *p; p++)
         if (!isspace(*p))
             return false;
 
@@ -1083,7 +1083,7 @@ GStr& GStr::upper() {
 
 GStr& GStr::upper() {
   make_unique(); //edit operation ahead
-  for (register char *p = chrs(); *p; p++)
+  for (char *p = chrs(); *p; p++)
             *p = (char) toupper(*p);
 
     return *this;
@@ -1094,7 +1094,7 @@ GStr& GStr::lower() {
 GStr& GStr::lower() {
     make_unique();
 
-    for (register char *p = chrs(); *p; p++)
+    for (char *p = chrs(); *p; p++)
           *p = (char) tolower(*p);
 
     return *this;
