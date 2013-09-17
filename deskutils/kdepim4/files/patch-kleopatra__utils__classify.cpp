--- kleopatra/utils/classify.cpp
+++ kleopatra/utils/classify.cpp
@@ -43,7 +43,7 @@
 
 #include <boost/range.hpp>
 
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
 # include <ext/algorithm>
 #endif
 
@@ -150,7 +150,7 @@ unsigned int Kleo::classify( const QStringList & fileNames ) {
 }
 
 unsigned int Kleo::classify( const QString & filename ) {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
     assert( __gnu_cxx::is_sorted( begin( classifications ), end( classifications ), ByExtension<std::less>() ) );
 #endif
 
@@ -179,7 +179,7 @@ unsigned int Kleo::classify( const QString & filename ) {
 }
 
 unsigned int Kleo::classifyContent( const QByteArray & data ) {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
     assert( __gnu_cxx::is_sorted( begin( content_classifications ), end( content_classifications ), ByContent<std::less>(100) ) );
 #endif
 
