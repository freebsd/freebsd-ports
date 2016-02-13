--- src/filter/pfstag.cpp.orig	2005-06-15 13:36:54 UTC
+++ src/filter/pfstag.cpp
@@ -58,7 +58,7 @@ struct TagOperation
   string channel;
 };
 
-typedef list<TagOperation> ListOfTags;
+typedef std::list<TagOperation> ListOfTags;
 
 TagOperation parseTagOperation( const char *tag, bool remove )
 {
@@ -133,9 +133,9 @@ void setTagsOnFrames( int argc, char* ar
     for( it = setTags.begin(); it != setTags.end(); it++ ) {
       TagOperation &tagop = *it;
       if( tagop.remove )       
-        cerr << PROG_NAME ": remove tag '" << tagop.name << "'\n";
+        std::cerr << PROG_NAME ": remove tag '" << tagop.name << "'\n";
       else
-        cerr << PROG_NAME ": set tag '" << tagop.name << "' to '" << tagop.value << "'\n";
+        std::cerr << PROG_NAME ": set tag '" << tagop.name << "' to '" << tagop.value << "'\n";
     }
     
   }
