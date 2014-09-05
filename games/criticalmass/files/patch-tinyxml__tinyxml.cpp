--- tinyxml/tinyxml.cpp.orig
+++ tinyxml/tinyxml.cpp
@@ -22,6 +22,9 @@
 */
 
 #include "tinyxml.h"
+#include <cstdlib>
+#include <cstring>
+#include <climits>
 
 
 TiXmlNode::TiXmlNode( NodeType _type )
@@ -377,7 +380,7 @@
 {
 	const std::string* s = Attribute( name );
 	if ( s )
-		*i = atoi( s->c_str() );
+		*i = ( int )strtol( s->c_str(), ( char ** )NULL, 10 );
 	else
 		*i = 0;
 	return s;
