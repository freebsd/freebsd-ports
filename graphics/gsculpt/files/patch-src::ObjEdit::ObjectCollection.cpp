--- ./src/ObjEdit/ObjectCollection.cpp.orig	Mon Jul 21 18:47:55 2003
+++ ./src/ObjEdit/ObjectCollection.cpp	Mon Jul 21 19:44:26 2003
@@ -326,11 +326,14 @@
 UniqueId ObjectCollection::getUniqueId(const string& name) const
 {
 	IdTable::const_iterator iter = nameToId.find(name);
-	if ( iter != objects.end() )
+
+	//if (iter != objects.end() )
+	// Is this correct? 21.7.03, barner@in.tum.de
+	if (iter != nameToId.end())
 	{
 		return (*iter).second;
 	}
-	else
+	else 
 	{
 		return -1;
 	}
