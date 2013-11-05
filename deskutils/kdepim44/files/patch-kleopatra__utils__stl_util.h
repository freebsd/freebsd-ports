commit 47323edeea633998fff40e5ce1e04e9138e8062f
Author: Andreas Holzammer <andreas.holzammer@kdab.com>
Date:   Fri Feb 25 16:59:19 2011 +0100

    dont confuse copy_if and none_of for kdetools and boost

--- kleopatra/utils/stl_util.h
+++ kleopatra/utils/stl_util.h
@@ -347,7 +347,7 @@ namespace kdtools {
     template <typename O, typename I, typename P>
     O copy_if( const I & i, P p ) {
         O o;
-        copy_if( boost::begin( i ), boost::end( i ), std::back_inserter( o ), p );
+        kdtools::copy_if( boost::begin( i ), boost::end( i ), std::back_inserter( o ), p );
         return o;
     }
 
@@ -390,7 +390,7 @@ namespace kdtools {
 
     template <typename C, typename P>
     bool none_of( const C & c, P p ) {
-        return none_of( boost::begin( c ), boost::end( c ), p );
+        return kdtools::none_of( boost::begin( c ), boost::end( c ), p );
     }
 
     template <typename C, typename B>
