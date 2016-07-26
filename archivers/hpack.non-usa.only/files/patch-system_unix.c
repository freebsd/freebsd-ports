--- system/unix.c.orig	1993-08-27 17:20:56 UTC
+++ system/unix.c
@@ -123,7 +123,7 @@ static int randomBufferPos = 0;
 
 #if defined( BSD386 ) || defined( CONVEX ) || defined( HPUX ) || \
 	defined( IRIX ) || defined( LINUX ) || defined( POSIX ) || \
-	defined( SVR4 ) || defined( UTS4 )
+	defined( SVR4 ) || defined( UTS4 ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 
 #include <termios.h>
 
@@ -144,7 +144,7 @@ int hgetch( void )
 		tcgetattr( ttyFD, &ttyInfo );
 #if defined( BSD386 ) || defined( CONVEX ) || defined( HPUX ) || \
 	defined( IRIX ) || defined( LINUX ) || defined( POSIX ) || \
-	defined( UTS4 )
+	defined( UTS4 ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 		ttyInfo.c_lflag &= ~ECHO;
 		ttyInfo.c_lflag &= ~ICANON;
 #else
@@ -183,7 +183,7 @@ int hgetch( void )
 		tcgetattr( ttyFD, &ttyInfo );
 #if defined( BSD386 ) || defined( CONVEX ) || defined( HPUX ) || \
 	defined( IRIX ) || defined( LINUX ) || defined( POSIX ) || \
-	defined( UTS4 )
+	defined( UTS4 ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 		ttyInfo.c_lflag |= ECHO;
 		ttyInfo.c_lflag |= ICANON;
 #else
@@ -728,7 +728,7 @@ int getCountry( void )
 	defined( HPUX ) || defined( IRIX ) || defined( LINUX ) || \
 	defined( NEXT ) || defined( OSF1 ) || defined( SUNOS ) || \
 	defined( SVR4 ) || defined( ULTRIX ) || defined( ULTRIX_OLD ) || \
-	defined( UTS4 )
+	defined( UTS4 ) || defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
 
 int htruncate( const FD theFD )
 	{
