--- build/src/libkawari/wordcollection.h.orig	Fri Jan 31 03:31:14 2003
+++ build/src/libkawari/wordcollection.h	Wed Jun  1 00:39:13 2005
@@ -95,14 +95,14 @@
 	// Delete NULL
 	virtual bool Delete(unsigned int id){
 		if(TWordCollection<T*,Compare>::Delete(id)){
-			WordList[id-1]=NULL;
+			TWordCollection<T*,Compare>::WordList[id-1]=NULL;
 			return true;
 		}else{
 			return false;
 		}
 	}
 	virtual ~TWordPointerCollection (){
-		for (typename std::vector<T*>::iterator it=WordList.begin(); it < WordList.end(); it++){
+		for (typename std::vector<T*>::iterator it=TWordCollection<T*,Compare>::WordList.begin(); it < TWordCollection<T*,Compare>::WordList.end(); it++){
 			if((*it))
 				delete (*it);
 		}
