--- character.h.orig	Sun Nov 16 17:40:28 2003
+++ character.h	Sun Nov 16 17:40:44 2003
@@ -64,6 +64,7 @@
   void swap_guesses( int i, int j ) throw();
   const Guess & guess( int i ) const throw();
   int guesses() const throw() { return _guess.size(); }
+#undef isalnum
   bool isalnum() const throw();
 
   void join( Character & c ) throw();
