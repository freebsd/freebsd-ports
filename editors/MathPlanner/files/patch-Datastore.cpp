--- src/Datastore.cpp.orig	2007-08-02 14:12:54.000000000 +0200
+++ src/Datastore.cpp	2007-08-02 14:13:28.000000000 +0200
@@ -447,7 +447,7 @@
 
 bool DataStorage::AddPointer(char *name,void *data)
 {
-	return(AddEntry(name,1,4,(int)data));
+	return(AddEntry(name,1,4,(intptr_t)data));
 }
 
 
