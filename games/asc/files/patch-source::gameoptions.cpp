
$FreeBSD$

--- source/gameoptions.cpp.orig	Tue Oct  1 15:26:40 2002
+++ source/gameoptions.cpp	Tue Oct  1 15:29:07 2002
@@ -112,7 +112,7 @@
    defaultSuperVisorPassword.setName ( "" );
 
 
-#if USE_HOME_DIRECTORY == 0
+#if _UNIX_ == 0
    searchPath[0].setName ( ".\\" );
    for ( int i = 1; i < getSearchPathNum(); i++ )
       searchPath[i].setName ( NULL );
@@ -120,7 +120,7 @@
 for ( int i = 0; i < getSearchPathNum(); i++ )
    searchPath[i].setName ( NULL );
    searchPath[0].setName ( "~/.asc/" );
-   searchPath[1].setName ( "/var/local/games/asc/" );
+   searchPath[1].setName ( PREFIX "/share/asc/" );
    searchPath[2].setName ( "/var/games/asc/" );
    searchPath[3].setName ( "/usr/local/share/games/asc/" );
    searchPath[4].setName ( "/usr/share/games/asc/" );
