
$FreeBSD$

--- source/gameoptions.cpp.orig	Sat Feb 17 20:16:39 2001
+++ source/gameoptions.cpp	Sat Feb 17 20:18:31 2001
@@ -96,13 +96,13 @@
 
    defaultSuperVisorPassword.setName ( "" );
 
-  #if USE_HOME_DIRECTORY == 0
+  #ifndef _UNIX_
    searchPath[0].setName ( ".\\" );
    for ( int i = 1; i < getSearchPathNum(); i++ )
       searchPath[i].setName ( NULL );
   #else
    searchPath[0].setName ( "~/.asc/" );
-   searchPath[1].setName ( "/var/local/games/asc/" );
+   searchPath[1].setName ( PREFIX "/share/asc/" );
    searchPath[2].setName ( "/var/games/asc/" );
    searchPath[3].setName ( "/usr/local/share/games/asc/" );
    searchPath[4].setName ( "/usr/share/games/asc/" );
