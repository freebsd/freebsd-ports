
$FreeBSD$

--- source/gameoptions.cpp.orig	Tue May 22 22:28:53 2001
+++ source/gameoptions.cpp	Tue May 22 22:30:29 2001
@@ -103,7 +103,7 @@
    defaultSuperVisorPassword.setName ( "" );
 
 
-  #if USE_HOME_DIRECTORY == 0
+  #if _UNIX_ == 0
    searchPath[0].setName ( ".\\" );
    for ( int i = 1; i < getSearchPathNum(); i++ )
       searchPath[i].setName ( NULL );
@@ -111,7 +111,7 @@
    for ( int i = 0; i < getSearchPathNum(); i++ )
       searchPath[i].setName ( NULL );
    searchPath[0].setName ( "~/.asc/" );
-   searchPath[1].setName ( "/var/local/games/asc/" );
+   searchPath[1].setName ( PREFIX "/share/asc/" );
    searchPath[2].setName ( "/var/games/asc/" );
    searchPath[3].setName ( "/usr/local/share/games/asc/" );
    searchPath[4].setName ( "/usr/share/games/asc/" );
