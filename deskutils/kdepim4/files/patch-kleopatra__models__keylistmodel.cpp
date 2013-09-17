--- kleopatra/models/keylistmodel.cpp
+++ kleopatra/models/keylistmodel.cpp
@@ -73,7 +73,7 @@
 #include <iterator>
 #include <cassert>
 
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
 #include <ext/algorithm> // for is_sorted
 #endif
 
@@ -460,7 +460,7 @@ QModelIndex FlatKeyListModel::doMapFromKey( const Key & key, int col ) const {
 }
 
 QList<QModelIndex> FlatKeyListModel::doAddKeys( const std::vector<Key> & keys ) {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
     assert( __gnu_cxx::is_sorted( keys.begin(), keys.end(), _detail::ByFingerprint<std::less>() ) );
 #endif
     if ( keys.empty() )
@@ -717,7 +717,7 @@ static std::vector<Key> topological_sort( const std::vector<Key> & keys ) {
 }
 
 QList<QModelIndex> HierarchicalKeyListModel::doAddKeys( const std::vector<Key> & keys ) {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
     assert( __gnu_cxx::is_sorted( keys.begin(), keys.end(), _detail::ByFingerprint<std::less>() ) );
 #endif
     if ( keys.empty() )
