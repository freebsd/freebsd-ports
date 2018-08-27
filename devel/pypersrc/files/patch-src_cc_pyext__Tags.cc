--- src/cc/pyext_Tags.cc.orig	2018-08-27 20:08:28 UTC
+++ src/cc/pyext_Tags.cc
@@ -122,8 +122,8 @@ static Tags sTags;
 	else																		\
 	{																			\
 		++NUM_VAR;																\
-		MAP_STR_NUM.insert( make_pair<string,Tags::TagInt>(str, NUM_VAR) );		\
-		MAP_NUM_STR.insert( make_pair<Tags::TagInt,string>(NUM_VAR, str) );		\
+		MAP_STR_NUM.insert( make_pair(str, NUM_VAR) );		\
+		MAP_NUM_STR.insert( make_pair(NUM_VAR, str) );		\
 		return NUM_VAR;															\
 	}																			\
 }
@@ -248,7 +248,7 @@ Tags::Insert( const char* pTagName, const char* pTagTy
     string tagName(pTagName);
 //	TagVal val( string(pTagName), typeNum, fileNum, tagLine );  // g++ 2.9 won't compile this
 	TagVal val( tagName, typeNum, fileNum, tagLine );           // value holds tag name's original case
-	mTagMap.insert( make_pair<string,TagVal>(key, val) );
+	mTagMap.insert( make_pair(key, val) );
 	return true;
 }
 
