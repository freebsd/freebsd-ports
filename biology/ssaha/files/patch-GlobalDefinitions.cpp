--- ./Global/GlobalDefinitions.cpp.orig	2004-03-01 13:51:28.000000000 -0300
+++ ./Global/GlobalDefinitions.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -119,7 +119,7 @@
 MakeIntoWord::MakeIntoWord( int bitsPerSymbol, const char* tt ):
 bitsPerSymbol_( bitsPerSymbol ), tt_( tt ) 
 {
-  for ( unsigned int i(0) ; i < (1<<bitsPerSymbol_) ; ++i )
+  for ( unsigned int i(0) ; i < ( unsigned int )(1<<bitsPerSymbol_) ; ++i )
   {
     map_.insert( make_pair( (static_cast<char>(tolower(tt[i]))),i ) );
     map_.insert( make_pair( (static_cast<char>(toupper(tt[i]))),i ) );
