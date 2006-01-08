--- ark/filelistview.cpp.orig	Mon Dec 19 15:40:44 2005
+++ ark/filelistview.cpp	Mon Dec 19 15:41:20 2005
@@ -260,7 +260,7 @@
 				 * the next item is the next sibling of its parent, and so on.
 				 */
 				FileLVI *nitem = static_cast<FileLVI*>( item->nextSibling() );
-				while ( !nitem and item->parent() )
+				while ( !nitem && item->parent() )
 				{
 					item = static_cast<FileLVI*>( item->parent() );
 					nitem = static_cast<FileLVI*>( item->parent()->nextSibling() );
