https://github.com/boostorg/coroutine/pull/45

--- boost/coroutine/asymmetric_coroutine.hpp.orig	2019-12-10 00:18:47 UTC
+++ boost/coroutine/asymmetric_coroutine.hpp
@@ -2361,32 +2361,32 @@ struct coroutine
 template< typename R >
 typename pull_coroutine< R >::iterator
 begin( pull_coroutine< R > & c)
-{ return boost::begin( c); }
+{ return coroutines::range_begin( c); }
 
 template< typename R >
 typename pull_coroutine< R >::const_iterator
 begin( pull_coroutine< R > const& c)
-{ return boost::begin( c); }
+{ return coroutines::range_begin( c); }
 
 template< typename R >
 typename pull_coroutine< R >::iterator
 end( pull_coroutine< R > & c)
-{ return boost::end( c); }
+{ return coroutines::range_end( c); }
 
 template< typename R >
 typename pull_coroutine< R >::const_iterator
 end( pull_coroutine< R > const& c)
-{ return boost::end( c); }
+{ return coroutines::range_end( c); }
 
 template< typename R >
 typename push_coroutine< R >::iterator
 begin( push_coroutine< R > & c)
-{ return boost::begin( c); }
+{ return coroutines::range_begin( c); }
 
 template< typename R >
 typename push_coroutine< R >::iterator
 end( push_coroutine< R > & c)
-{ return boost::end( c); }
+{ return coroutines::range_end( c); }
 
 }
 
