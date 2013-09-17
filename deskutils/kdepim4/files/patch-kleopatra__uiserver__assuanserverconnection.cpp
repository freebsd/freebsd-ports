--- kleopatra/uiserver/assuanserverconnection.cpp
+++ kleopatra/uiserver/assuanserverconnection.cpp
@@ -96,7 +96,7 @@
 
 #include <errno.h>
 
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
 # include <ext/algorithm> // for is_sorted
 #endif
 
@@ -827,7 +827,7 @@ AssuanServerConnection::Private::Private( assuan_fd_t fd_, const std::vector< sh
       sessionId( 0 ),
       factories( factories_ )
 {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
     assert( __gnu_cxx::is_sorted( factories_.begin(), factories_.end(), _detail::ByName<std::less>() ) );
 #endif
 
