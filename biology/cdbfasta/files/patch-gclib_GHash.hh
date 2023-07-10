--- gclib/GHash.hh.orig	2023-07-10 09:56:48 UTC
+++ gclib/GHash.hh
@@ -544,7 +544,7 @@ template <class OBJ> char* GHash<OBJ>::NextKey() {
 }
 
 template <class OBJ> char* GHash<OBJ>::NextKey() {
- register int pos=fCurrentEntry;
+ int pos=fCurrentEntry;
  while (pos<fCapacity && hash[pos].hash<0) pos++;
  if (pos==fCapacity) {
                  fCurrentEntry=fCapacity;
@@ -557,7 +557,7 @@ template <class OBJ> OBJ* GHash<OBJ>::NextData() {
 }
 
 template <class OBJ> OBJ* GHash<OBJ>::NextData() {
- register int pos=fCurrentEntry;
+ int pos=fCurrentEntry;
  while (pos<fCapacity && hash[pos].hash<0) pos++;
  if (pos==fCapacity) {
                  fCurrentEntry=fCapacity;
@@ -571,7 +571,7 @@ template <class OBJ> OBJ* GHash<OBJ>::NextData(char* &
 }
 
 template <class OBJ> OBJ* GHash<OBJ>::NextData(char* &nextkey) {
- register int pos=fCurrentEntry;
+ int pos=fCurrentEntry;
  while (pos<fCapacity && hash[pos].hash<0) pos++;
  if (pos==fCapacity) {
                  fCurrentEntry=fCapacity;
@@ -589,7 +589,7 @@ template <class OBJ> int GHash<OBJ>::First() const {
 
 // Get first non-empty entry
 template <class OBJ> int GHash<OBJ>::First() const {
-  register int pos=0;
+  int pos=0;
   while(pos<fCapacity){ if(0<=hash[pos].hash) break; pos++; }
   GASSERT(fCapacity<=pos || 0<=hash[pos].hash);
   return pos;
@@ -597,7 +597,7 @@ template <class OBJ> int GHash<OBJ>::Last() const {
 
 // Get last non-empty entry
 template <class OBJ> int GHash<OBJ>::Last() const {
-  register int pos=fCapacity-1;
+  int pos=fCapacity-1;
   while(0<=pos){ if(0<=hash[pos].hash) break; pos--; }
   GASSERT(pos<0 || 0<=hash[pos].hash);
   return pos;
@@ -624,7 +624,7 @@ template <class OBJ> void GHash<OBJ>::Clear(){
 
 // Remove all
 template <class OBJ> void GHash<OBJ>::Clear(){
-  register int i;
+  int i;
   for(i=0; i<fCapacity; i++){
     if(hash[i].hash>=0){
       if (hash[i].keyalloc) GFREE((hash[i].key));
@@ -681,7 +681,7 @@ template <class OBJ> GHash<OBJ>::~GHash(){
 
 // Destroy table
 template <class OBJ> GHash<OBJ>::~GHash(){
-  register int i;
+  int i;
   for(i=0; i<fCapacity; i++){
     if(hash[i].hash>=0){
       if (hash[i].keyalloc) GFREE((hash[i].key));
