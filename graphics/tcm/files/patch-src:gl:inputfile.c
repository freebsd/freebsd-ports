--- src/gl/inputfile.c.orig	Sat Oct 19 21:37:26 2002
+++ src/gl/inputfile.c	Sat Oct 19 21:37:53 2002
@@ -51,7 +51,7 @@
 }
 
 void InputFile::SkipLine() {
-	unsigned char c;
+	char c;
 	while (!ifile->eof()) {
 		ifile->get(c);
 		if (c == '\n') {
@@ -62,7 +62,7 @@
 }
 
 int InputFile::ReadChar() {
-	unsigned char c;
+	char c;
 	while (!ifile->eof()) {
 		ifile->get(c);
 		if (c == '\n')
@@ -78,7 +78,7 @@
 }
 
 bool InputFile::LookupChar(const char c) {
-	unsigned char c2;
+	char c2;
 	while (!ifile->eof()) {
 		ifile->get(c2);
 		if (c2 == '\n')
@@ -100,7 +100,7 @@
 
 bool InputFile::LookupWord(const string *word) {
 	string word2;
-	unsigned char c;
+	char c;
 	// skip white space and comment.
 	do {
 		if (ifile->eof())
@@ -138,7 +138,7 @@
 
 bool InputFile::LookupString(const string *s) {
 	string string2;
-	unsigned char c;
+	char c;
 	bool escaped = False;
 	if (!LookupChar('"'))
 		return False;
@@ -179,7 +179,7 @@
 }
 
 bool InputFile::ReadWord(string *word) {
-	unsigned char c;
+	char c;
 	*word = "";
 	// skip white space and comment.
 	do {
@@ -211,7 +211,7 @@
 }
 
 bool InputFile::ReadString(string *s) {
-	unsigned char c;
+	char c;
 	*s = "";
 	bool escaped = False;
 	if (!LookupChar('"'))
