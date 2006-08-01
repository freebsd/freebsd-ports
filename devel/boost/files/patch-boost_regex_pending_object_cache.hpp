--- boost/regex/pending/object_cache.hpp.orig	Mon Jun 20 13:48:37 2005
+++ boost/regex/pending/object_cache.hpp	Tue Aug  1 20:58:55 2006
@@ -35,16 +35,16 @@
 class object_cache
 {
 public:
-   typedef std::pair< ::boost::shared_ptr<Object>, Key const*> value_type;
+   typedef std::pair< ::boost::shared_ptr<Object const>, Key const*> value_type;
    typedef std::list<value_type> list_type;
    typedef typename list_type::iterator list_iterator;
    typedef std::map<Key, list_iterator> map_type;
    typedef typename map_type::iterator map_iterator;
    typedef typename list_type::size_type size_type;
-   static boost::shared_ptr<Object> get(const Key& k, size_type max_cache_size);
+   static boost::shared_ptr<Object const> get(const Key& k, size_type max_cache_size);
 
 private:
-   static boost::shared_ptr<Object> do_get(const Key& k, size_type max_cache_size);
+   static boost::shared_ptr<Object const> do_get(const Key& k, size_type max_cache_size);
 
    struct data
    {
@@ -58,7 +58,7 @@
 };
 
 template <class Key, class Object>
-boost::shared_ptr<Object> object_cache<Key, Object>::get(const Key& k, size_type max_cache_size)
+boost::shared_ptr<Object const> object_cache<Key, Object>::get(const Key& k, size_type max_cache_size)
 {
 #ifdef BOOST_HAS_THREADS
    static boost::static_mutex mut = BOOST_STATIC_MUTEX_INIT;
@@ -80,7 +80,7 @@
 }
 
 template <class Key, class Object>
-boost::shared_ptr<Object> object_cache<Key, Object>::do_get(const Key& k, size_type max_cache_size)
+boost::shared_ptr<Object const> object_cache<Key, Object>::do_get(const Key& k, size_type max_cache_size)
 {
    typedef typename object_cache<Key, Object>::data object_data;
    typedef typename list_type::size_type list_size_type;
@@ -115,7 +115,7 @@
    // if we get here then the item is not in the cache,
    // so create it:
    //
-   boost::shared_ptr<Object> result(new Object(k));
+   boost::shared_ptr<Object const> result(new Object(k));
    //
    // Add it to the list, and index it:
    //
