--- textline.cc.orig	Sun Nov 16 17:39:59 2003
+++ textline.cc	Sun Nov 16 17:44:01 2003
@@ -33,7 +33,7 @@
   for( ; end < characters(); ++end )
     {
     Character & c = character( end );
-    if( c.guesses() && std::isspace( c.guess(0).ch ) ) break;
+    if( c.guesses() && isspace( c.guess(0).ch ) ) break;
     }
   return end;
   }
@@ -264,11 +264,11 @@
     if( c1.guesses() == 1 )
       {
       unsigned char ch = c1.guess( 0 ).ch;
-      if( std::isspace( ch ) ) { begin = i + 1 ; continue; }
+      if( isspace( ch ) ) { begin = i + 1 ; continue; }
       if( ch != 'c' && ch != 'o' && ch != 's' && ch != 'u' && ch != 'v' &&
           ch != 'w' && ch != 'x' && ch != 'z' ) continue;
       if( 4 * c1.height() > 5 * mean_height() )
-        { c1.only_guess( std::toupper( ch ), 0 ); continue; }
+        { c1.only_guess( toupper( ch ), 0 ); continue; }
       if( 5 * c1.height() < 4 * mean_height() ) continue;
       for( int j = begin; j < characters(); ++j ) if( j != i )
         {
@@ -276,12 +276,12 @@
         if( c2.guesses() >= 1 )
           {
           unsigned char ch2 = c2.guess( 0 ).ch;
-          if( std::isspace( ch2 ) ) break;
-          if( ( std::isalpha( ch2 ) && 4 * c1.height() > 5 * c2.height() ) ||
-              ( ( std::isupper( ch2 ) || ch2 == 'l' ) && ch2 != 'B' &&
+          if( isspace( ch2 ) ) break;
+          if( ( isalpha( ch2 ) && 4 * c1.height() > 5 * c2.height() ) ||
+              ( ( isupper( ch2 ) || ch2 == 'l' ) && ch2 != 'B' &&
                 ( c1.height() >= c2.height() ||
                   Ocrad::similar( c1.height(), c2.height(), 10 ) ) ) )
-            { c1.insert_guess( 0, std::toupper( ch ), 1 ); break; }
+            { c1.insert_guess( 0, toupper( ch ), 1 ); break; }
           }
         }
       }
@@ -310,7 +310,7 @@
     if( c1.guesses() >= 1 )
       {
       unsigned char ch = c1.guess( 0 ).ch;
-      if( std::isspace( ch ) ) { begin = i + 1 ; continue; }
+      if( isspace( ch ) ) { begin = i + 1 ; continue; }
       if( ch <= 127 || c1.block_vector().size() < 2 ) continue;
       int chb = ISO_8859_1::base_letter( ch );
       if( chb != 'o' && chb != 'u' ) continue;
@@ -323,11 +323,11 @@
           unsigned char ch2 = c2.guess( 0 ).ch;
           int ch2b = ISO_8859_1::base_letter( ch2 );
           if( !ch2b && ch2 > 127 ) continue;
-          if( std::isspace( ch2 ) ) break;
-          if( ( std::isalpha( ch2 ) && 4 * b1.height() > 5 * c2.height() ) ||
-              ( std::isupper( ch2 ) && Ocrad::similar( b1.height(), c2.height(), 10 ) ) ||
-              ( std::isalpha( ch2b ) && 4 * c1.height() > 5 * c2.height() ) ||
-              ( std::isupper( ch2b ) && Ocrad::similar( c1.height(), c2.height(), 10 ) ) )
+          if( isspace( ch2 ) ) break;
+          if( ( isalpha( ch2 ) && 4 * b1.height() > 5 * c2.height() ) ||
+              ( isupper( ch2 ) && Ocrad::similar( b1.height(), c2.height(), 10 ) ) ||
+              ( isalpha( ch2b ) && 4 * c1.height() > 5 * c2.height() ) ||
+              ( isupper( ch2b ) && Ocrad::similar( c1.height(), c2.height(), 10 ) ) )
             { c1.insert_guess( 0, ISO_8859_1::toupper( ch ), 1 ); break; }
           }
         }
@@ -341,7 +341,7 @@
     if( c1.guesses() >= 1 )
       {
       unsigned char ch = c1.guess( 0 ).ch;
-      if( std::isspace( ch ) ) { begin = i + 1 ; continue; }
+      if( isspace( ch ) ) { begin = i + 1 ; continue; }
       if( ch != 'o' && ch != 'O' && ch != 'l' ) continue;
       for( int j = begin; j < characters(); ++j ) if( j != i )
         {
@@ -349,8 +349,8 @@
         if( c2.guesses() >= 1 )
           {
           unsigned char ch2 = c2.guess( 0 ).ch;
-          if( std::isspace( ch2 ) ) break;
-          if( std::isdigit( ch2 ) )
+          if( isspace( ch2 ) ) break;
+          if( isdigit( ch2 ) )
             {
             if( Ocrad::similar( c1.height(), c2.height(), 10 ) )
               c1.insert_guess( 0, (ch == 'l') ? '1' : '0', c1.guess(0).value + 1 );
@@ -372,7 +372,7 @@
       Character & c2 = character( i );
       if( !c2.guesses() ) continue;
       unsigned char ch = c2.guess( 0 ).ch;
-      if( !std::isalnum( ch ) && ch != '.' && ch != '|' ) continue;
+      if( !isalnum( ch ) && ch != '.' && ch != '|' ) continue;
       switch( ch )
         {
         case 'g': case 'j': case 'p': case 'q': case 'y':
@@ -426,14 +426,14 @@
       if( i < characters() - 1 && character( i + 1 ).guesses() )
         rch = character( i + 1 ).guess( 0 ).ch;
       if( ISO_8859_1::isupper( rch ) &&
-          ( !lch || ISO_8859_1::isupper( lch ) || std::isspace( lch ) ) )
+          ( !lch || ISO_8859_1::isupper( lch ) || isspace( lch ) ) )
         { c.insert_guess( 0, 'I', 1 ); continue; }
       if( ch == 'l' ) continue;
       if( ISO_8859_1::isalpha( lch ) || ISO_8859_1::isalpha( rch ) )
         { c.insert_guess( 0, 'l', 1 ); continue; }
-      if( rch == '|' && ( !lch || std::isspace( lch ) ) &&
+      if( rch == '|' && ( !lch || isspace( lch ) ) &&
           i < characters() - 2 && character( i + 2 ).guesses() &&
-          std::isalpha( character( i + 2 ).guess( 0 ).ch ) )
+          isalpha( character( i + 2 ).guess( 0 ).ch ) )
         { c.insert_guess( 0, 'l', 1 ); continue; }
       }
     }
@@ -475,7 +475,7 @@
     if( c.guesses() )
       {
       unsigned char ch = c.guess( 0 ).ch;
-      if( std::isspace( ch ) ) { begin = i + 1 ; continue; }
+      if( isspace( ch ) ) { begin = i + 1 ; continue; }
       if( i == begin && ch == 'a' && c.guesses() == 2 &&
           c.guess( 1 ).ch == 'Q' && 4 * c.height() > 5 * mean_height() )
         c.swap_guesses( 0, 1 );
@@ -501,7 +501,7 @@
     if( c1.guesses() )
       {
       unsigned char ch = c1.guess(0).ch;
-      if( std::isspace( ch ) ) { begin = i + 1 ; continue; }
+      if( isspace( ch ) ) { begin = i + 1 ; continue; }
       if( c1.guesses() != 2 || ch != 'B' || c1.guess(1).ch != 'a' ) continue;
       if( 4 * c1.height() > 5 * mean_height() ) continue;
       for( int j = begin; j < characters(); ++j ) if( j != i )
@@ -510,9 +510,9 @@
         if( c2.guesses() >= 1 )
           {
           unsigned char ch2 = c2.guess(0).ch;
-          if( std::isspace( ch2 ) ) break;
-          if( ( std::isalpha( ch2 ) && 5 * c1.height() < 4 * c2.height() ) ||
-              ( std::islower( ch2 ) &&
+          if( isspace( ch2 ) ) break;
+          if( ( isalpha( ch2 ) && 5 * c1.height() < 4 * c2.height() ) ||
+              ( islower( ch2 ) &&
                 ( c1.height() <= c2.height() ||
                   Ocrad::similar( c1.height(), c2.height(), 10 ) ) ) )
             { c1.swap_guesses( 0, 1 ); break; }
