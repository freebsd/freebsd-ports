Subversion 1.9 and more recent versions have removed some interfaces, which
the Subversion developers consider to serve only svn-internal purposes, from
the header files installed by the package.

The following patch (orignally from pkgsrc) provides an own sort mechanism
to replace the no longer available svn_sort__hash functionality.

--- svn/svn.cpp.orig	2015-09-20 17:51:35.000000000 +0000
+++ svn/svn.cpp
@@ -54,6 +54,8 @@
 #include "svn.h"
 #include <apr_portable.h>
 
+#include <algorithm>
+
 using namespace KIO;
 
 typedef struct
@@ -107,11 +109,6 @@ static svn_error_t *write_to_string(void
 	return SVN_NO_ERROR;
 }
 
-static int
-compare_items_as_paths (const svn_sort__item_t*a, const svn_sort__item_t*b) {
-  return svn_path_compare_paths ((const char *)a->key, (const char *)b->key);
-}
-
 kio_svnProtocol::kio_svnProtocol(const QByteArray &pool_socket, const QByteArray &app_socket)
 	: SlaveBase("kio_svn", pool_socket, app_socket) {
 		kDebug(7128) << "kio_svnProtocol::kio_svnProtocol()";
@@ -515,6 +512,11 @@ void kio_svnProtocol::stat(const KUrl & 
 	svn_pool_destroy( subpool );
 }
 
+static bool
+sort_by_path(const std::pair<const char *, svn_dirent_t *> &a, const std::pair<const char *, svn_dirent_t *> &b) {
+	return svn_path_compare_paths(a.first, b.first) < 0;
+}
+
 void kio_svnProtocol::listDir(const KUrl& url) {
 	kDebug(7128) << "kio_svn::listDir(const KUrl& url) : " << url.url();
 
@@ -547,23 +549,23 @@ void kio_svnProtocol::listDir(const KUrl
 		return;
 	}
 
-  apr_array_header_t *array;
-  int i;
-
-  array = svn_sort__hash (dirents, compare_items_as_paths, subpool);
+	std::vector<std::pair<const char *, svn_dirent_t *> > array;
+	for (apr_hash_index_t *hi = apr_hash_first(subpool, dirents); hi; hi = apr_hash_next(hi)) {
+		const void *key;
+		void *data;
+		apr_hash_this(hi, &key, NULL, &data);
+		array.push_back(std::make_pair(reinterpret_cast<const char *>(key), reinterpret_cast<svn_dirent_t *>(data)));
+	}
+	std::sort(array.begin(), array.end(), sort_by_path);
 
-  UDSEntry entry;
-  for (i = 0; i < array->nelts; ++i) {
+	UDSEntry entry;
+	for (size_t i = 0; i < array.size(); ++i) {
 	  entry.clear();
 	  const char *utf8_entryname, *native_entryname;
 	  svn_dirent_t *dirent;
-	  svn_sort__item_t *item;
 
-	  item = &APR_ARRAY_IDX (array, i, svn_sort__item_t);
-
-	  utf8_entryname = (const char*)item->key;
-
-	  dirent = (svn_dirent_t*)apr_hash_get (dirents, utf8_entryname, item->klen);
+	  utf8_entryname = array[i].first;
+	  dirent = array[i].second;
 
 	  svn_utf_cstring_from_utf8 (&native_entryname, utf8_entryname, subpool);
 	  const char *native_author = NULL;
@@ -577,7 +579,7 @@ void kio_svnProtocol::listDir(const KUrl
 	  if ( createUDSEntry(QString( native_entryname ), QString( native_author ), dirent->size,
 				  dirent->kind==svn_node_dir ? true : false, mtime, entry) )
 		  listEntry( entry, false );
-  }
+	}
 	listEntry( entry, true );
 
 	finished();
