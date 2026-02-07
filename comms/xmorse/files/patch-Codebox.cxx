Codebox.cxx:122:16: error: non-constant-expression cannot be narrowed from type 'int' to 'char' in initializer list [-Wc++11-narrowing]
  char s[] = { c, '\0' };               //   A 1-char string version of c.
               ^

--- Codebox.cxx.orig	2018-07-29 11:57:10 UTC
+++ Codebox.cxx
@@ -119,7 +119,7 @@ int Codebox::handle(int event) {	// Called by FLTK whe
  *  moved to the end of the line, and the character is inserted there.
  */
 void Codebox::append(int c) {		// Append character to displayed line
-  char s[] = { c, '\0' };		//   A 1-char string version of c.
+  char s[] = { static_cast<char>(c), '\0' };		//   A 1-char string version of c.
   if (size() >= maximum_size())		//   If no room for character,
      cut(0,1);				//     discard one off left side
   position(maximum_size());		//   Return to right end of buffer
