Use the type basic_pstreambuf::fd_type is a typedef of.

./libs/pstreams/pstream.h:1742:28: error: return type of out-of-line definition of 'redi::basic_pstreambuf::wpipe' differs from that in the declaration
    basic_pstreambuf<C,T>::wpipe()
                           ^
./libs/pstreams/pstream.h:221:7: note: previous declaration is here
      wpipe();
      ^
./libs/pstreams/pstream.h:1750:28: error: return type of out-of-line definition of 'redi::basic_pstreambuf::rpipe' differs from that in the declaration
    basic_pstreambuf<C,T>::rpipe()
                           ^
./libs/pstreams/pstream.h:225:7: note: previous declaration is here
      rpipe();
      ^
./libs/pstreams/pstream.h:1758:28: error: return type of out-of-line definition of 'redi::basic_pstreambuf::rpipe' differs from that in the declaration
    basic_pstreambuf<C,T>::rpipe(buf_read_src which)
                           ^
./libs/pstreams/pstream.h:229:7: note: previous declaration is here
      rpipe(buf_read_src which);
      ^
--- libs/pstreams/pstream.h.orig	2017-07-26 12:51:55 UTC
+++ libs/pstreams/pstream.h
@@ -1738,7 +1738,7 @@ namespace redi
 
   /** @return a reference to the output file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstreams::fd_type&
     basic_pstreambuf<C,T>::wpipe()
     {
       return wpipe_;
@@ -1746,7 +1746,7 @@ namespace redi
 
   /** @return a reference to the active input file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstreams::fd_type&
     basic_pstreambuf<C,T>::rpipe()
     {
       return rpipe_[rsrc_];
@@ -1754,7 +1754,7 @@ namespace redi
 
   /** @return a reference to the specified input file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstreams::fd_type&
     basic_pstreambuf<C,T>::rpipe(buf_read_src which)
     {
       return rpipe_[which];
