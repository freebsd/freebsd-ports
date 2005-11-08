--- src/bibtexstring.cpp.orig	Tue Nov  8 13:07:00 2005
+++ src/bibtexstring.cpp	Tue Nov  8 13:07:40 2005
@@ -112,6 +112,7 @@
             else result.append( "\"" );
 
             result.append( " }" );
+            return result;
         }
         break;
     case BibTeXFile::formatXML:
