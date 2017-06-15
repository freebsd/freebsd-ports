--- src/PoolFile/TPoolFile.cpp.orig	2013-02-10 06:35:02 UTC
+++ src/PoolFile/TPoolFile.cpp
@@ -20,11 +20,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
  */
 
-/* this would be needed if I were utilizing gcc's implicit instantiation for TPoolFile
 #ifndef __TPoolFile_H__CPP
 #error this file must be included through TPoolFile.h NOT compiled on its own
 #endif
-*/
 
 /* ???
  * There are places that I have to do: container.erase(container.begin+index);  
@@ -575,7 +573,7 @@ template<class l_addr_t,class p_addr_t>
 	invalidateAllCachedBlocks(false,poolId);
 
 	// remove poolName with poolId of the parameter
-	for(map<string,poolId_t>::const_iterator t=poolNames.begin();t!=poolNames.end();t++)
+	for(map<const string,poolId_t>::const_iterator t=poolNames.begin();t!=poolNames.end();t++)
 	{
 		if(t->second==poolId)
 		{
