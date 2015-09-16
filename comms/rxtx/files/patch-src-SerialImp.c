--- src/SerialImp.c.orig	2009-02-04 22:06:16.000000000 +0000
+++ src/SerialImp.c	2015-05-11 16:52:36.000000000 +0100
@@ -1,60 +1,79 @@
 /*-------------------------------------------------------------------------
-|   RXTX License v 2.1 - LGPL v 2.1 + Linking Over Controlled Interface.
-|   RXTX is a native interface to serial ports in java.
-|   Copyright 1997-2009 by Trent Jarvi tjarvi@qbang.org and others who
-|   actually wrote it.  See individual source files for more information.
+|	RXTX License v 2.1 - LGPL v 2.1 + Linking Over Controlled Interface.
+|	RXTX is a native interface to serial ports in java.
+|	Copyright 1997-2009 by Trent Jarvi tjarvi@qbang.org and others who
+|	actually wrote it.  See individual source files for more information.
 |
-|   A copy of the LGPL v 2.1 may be found at
-|   http://www.gnu.org/licenses/lgpl.txt on March 4th 2007.  A copy is
-|   here for your convenience.
+|	A copy of the LGPL v 2.1 may be found at
+|	http://www.gnu.org/licenses/lgpl.txt on March 4th 2007.  A copy is
+|	here for your convenience.
 |
-|   This library is free software; you can redistribute it and/or
-|   modify it under the terms of the GNU Lesser General Public
-|   License as published by the Free Software Foundation; either
-|   version 2.1 of the License, or (at your option) any later version.
+|	This library is free software; you can redistribute it and/or
+|	modify it under the terms of the GNU Lesser General Public
+|	License as published by the Free Software Foundation; either
+|	version 2.1 of the License, or (at your option) any later version.
 |
-|   This library is distributed in the hope that it will be useful,
-|   but WITHOUT ANY WARRANTY; without even the implied warranty of
-|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-|   Lesser General Public License for more details.
+|	This library is distributed in the hope that it will be useful,
+|	but WITHOUT ANY WARRANTY; without even the implied warranty of
+|	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+|	Lesser General Public License for more details.
 |
-|   An executable that contains no derivative of any portion of RXTX, but
-|   is designed to work with RXTX by being dynamically linked with it,
-|   is considered a "work that uses the Library" subject to the terms and
-|   conditions of the GNU Lesser General Public License.
+|	An executable that contains no derivative of any portion of RXTX, but
+|	is designed to work with RXTX by being dynamically linked with it,
+|	is considered a "work that uses the Library" subject to the terms and
+|	conditions of the GNU Lesser General Public License.
 |
-|   The following has been added to the RXTX License to remove
-|   any confusion about linking to RXTX.   We want to allow in part what
-|   section 5, paragraph 2 of the LGPL does not permit in the special
-|   case of linking over a controlled interface.  The intent is to add a
-|   Java Specification Request or standards body defined interface in the
-|   future as another exception but one is not currently available.
+|	The following has been added to the RXTX License to remove
+|	any confusion about linking to RXTX.	We want to allow in part what
+|	section 5, paragraph 2 of the LGPL does not permit in the special
+|	case of linking over a controlled interface.  The intent is to add a
+|	Java Specification Request or standards body defined interface in the
+|	future as another exception but one is not currently available.
 |
-|   http://www.fsf.org/licenses/gpl-faq.html#LinkingOverControlledInterface
+|	http://www.fsf.org/licenses/gpl-faq.html#LinkingOverControlledInterface
 |
-|   As a special exception, the copyright holders of RXTX give you
-|   permission to link RXTX with independent modules that communicate with
-|   RXTX solely through the Sun Microsytems CommAPI interface version 2,
-|   regardless of the license terms of these independent modules, and to copy
-|   and distribute the resulting combined work under terms of your choice,
-|   provided that every copy of the combined work is accompanied by a complete
-|   copy of the source code of RXTX (the version of RXTX used to produce the
-|   combined work), being distributed under the terms of the GNU Lesser General
-|   Public License plus this exception.  An independent module is a
-|   module which is not derived from or based on RXTX.
+|	As a special exception, the copyright holders of RXTX give you
+|	permission to link RXTX with independent modules that communicate with
+|	RXTX solely through the Sun Microsytems CommAPI interface version 2,
+|	regardless of the license terms of these independent modules, and to copy
+|	and distribute the resulting combined work under terms of your choice,
+|	provided that every copy of the combined work is accompanied by a complete
+|	copy of the source code of RXTX (the version of RXTX used to produce the
+|	combined work), being distributed under the terms of the GNU Lesser General
+|	Public License plus this exception.  An independent module is a
+|	module which is not derived from or based on RXTX.
 |
-|   Note that people who make modified versions of RXTX are not obligated
-|   to grant this special exception for their modified versions; it is
-|   their choice whether to do so.  The GNU Lesser General Public License
-|   gives permission to release a modified version without this exception; this
-|   exception also makes it possible to release a modified version which
-|   carries forward this exception.
+|	Note that people who make modified versions of RXTX are not obligated
+|	to grant this special exception for their modified versions; it is
+|	their choice whether to do so.  The GNU Lesser General Public License
+|	gives permission to release a modified version without this exception; this
+|	exception also makes it possible to release a modified version which
+|	carries forward this exception.
 |
-|   You should have received a copy of the GNU Lesser General Public
-|   License along with this library; if not, write to the Free
-|   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-|   All trademarks belong to their respective owners.
+|	You should have received a copy of the GNU Lesser General Public
+|	License along with this library; if not, write to the Free
+|	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+|	All trademarks belong to their respective owners.
 --------------------------------------------------------------------------*/
+/**
+ *	9th May 2015 - james.c.elstone (at) ntlworld.com:
+ *		
+ *		Added STDOUT debug stream, so can see when used with OpenJDK in
+ *		console terminal.  Useful for seeing events interleaved, with OS
+ *		activity.  Just put '#define DEBUG_STDOUT' just below...
+ *		
+ *		Altered behaviour of SIGABRT in RXTXPort(interruptEventLoop)
+ *		to prevent Core Dump from being performed on POSIX compliant OS.
+ * 
+ * 		Sorted out null termination on all debug strings!
+ * 		
+ *		Clearing of char array for sprintfs, driver enumerated multilpe
+ *		times, leaving the content behind in places.
+ *		
+ **/
+
+//#define DEBUG_STDOUT
+
 #if defined(__MWERKS__) /* dima */
 #include "RXTXPort.h" /* dima */
 #else  /* dima */
@@ -64,7 +83,7 @@
 #include "gnu_io_RXTXPort.h"
 #endif /* dima */
 #ifdef __LCC__ /* windows lcc compiler for fd_set. probably wrong */
-#   include<winsock.h>
+#	include<winsock.h>
 #endif /* __LCC__ */
 #include <time.h>
 #include <stdio.h>
@@ -91,23 +110,23 @@
 #ifdef HAVE_TERMIOS_H
 #	include <termios.h>
 #endif /* HAVE_TERMIOS_H */
-#   include <signal.h>
+#	include <signal.h>
 #ifdef HAVE_SIGNAL_H
-#   include <signal.h>
+#	include <signal.h>
 #endif /* HAVE_SIGNAL_H */
 #ifdef HAVE_SYS_SIGNAL_H
-#   include <sys/signal.h>
+#	include <sys/signal.h>
 #endif /* HAVE_SYS_SIGNAL_H */
 #include <sys/types.h>
 #ifdef HAVE_SYS_TIME_H
-#   include <sys/time.h>
+#	include <sys/time.h>
 #endif /* HAVE_SYS_TIME_H */
-#   include <fcntl.h>
+#	include <fcntl.h>
 #ifdef HAVE_SYS_FCNTL_H
-#   include <sys/fcntl.h>
+#	include <sys/fcntl.h>
 #endif /* HAVE_SYS_FCNTL_H */
 #ifdef HAVE_SYS_FILE_H
-#   include <sys/file.h>
+#	include <sys/file.h>
 #endif /* HAVE_SYS_FILE_H */
 #ifdef LFS  /* File Lock Server */
 #	include <sys/socket.h>
@@ -167,59 +186,59 @@
 /*----------------------------------------------------------
 cfmakeraw
 
-   accept:      termios to be set to raw
-   perform:     initializes the termios structure.
-   return:      int 0 on success
-   exceptions:  none
-   comments:    this is how linux cfmakeraw works.
-		termios(3) manpage
+	accept:		termios to be set to raw
+	perform:	initializes the termios structure.
+	return:		int 0 on success
+	exceptions: none
+	comments:	this is how linux cfmakeraw works.
+				termios(3) manpage
 ----------------------------------------------------------*/
 
 int cfmakeraw ( struct termios *term )
 {
-	ENTER( "cfmakeraw" );
+	report( "Entering - cfmakeraw\n" );
 	term->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
 	term->c_oflag &= ~OPOST;
 	term->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
 	term->c_cflag &= ~(CSIZE|PARENB);
 	term->c_cflag |= CS8;
-	LEAVE( "cfmakeraw" );
+	report( "Leaving - cfmakeraw\n" );
 	return( 0 );
 }
 #endif /* __sun__  || __hpux__ */
 
 #ifdef DEBUG_TIMING
-struct timeval snow, enow, seloop, eeloop;
-#define report_time_eventLoop( ) { \
-	if ( seloop.tv_sec == eeloop.tv_sec && seloop.tv_usec == eeloop.tv_usec ) \
+	struct timeval snow, enow, seloop, eeloop;
+	#define report_time_eventLoop( ) { \
+		if ( seloop.tv_sec == eeloop.tv_sec && seloop.tv_usec == eeloop.tv_usec ) \
+		{ \
+			gettimeofday(&eeloop, NULL); \
+			seloop.tv_sec = eeloop.tv_sec; \
+			seloop.tv_usec = eeloop.tv_usec; \
+			printf("%8i sec : %8i usec\n", eeloop.tv_sec - seloop.tv_sec, eeloop.tv_usec - seloop.tv_usec); \
+		} \
+	}
+	#define report_time( ) \
 	{ \
-		gettimeofday(&eeloop, NULL); \
-		seloop.tv_sec = eeloop.tv_sec; \
-		seloop.tv_usec = eeloop.tv_usec; \
-		printf("%8i sec : %8i usec\n", eeloop.tv_sec - seloop.tv_sec, eeloop.tv_usec - seloop.tv_usec); \
-	} \
-}
-#define report_time( ) \
-{ \
-	struct timeval now; \
-	gettimeofday(&now, NULL); \
-	mexPrintf("%8s : %5i : %8i sec : %8i usec\n", __TIME__, __LINE__, now.tv_sec, now.tv_usec); \
-}
-#define report_time_start( ) \
-{ \
-	gettimeofday(&snow, NULL); \
-	mexPrintf("%8s : %5i : %8i sec : %8i usec", __TIME__, __LINE__, snow.tv_sec, snow.tv_usec); \
-}
-#define report_time_end( ) \
-{ \
-	gettimeofday(&enow, NULL); \
-	mexPrintf("%8i sec : %8i usec\n", enow.tv_sec - snow.tv_sec, enow.tv_sec - snow.tv_sec?snow.tv_usec-enow.tv_usec:enow.tv_usec - snow.tv_usec); \
-}
+		struct timeval now; \
+		gettimeofday(&now, NULL); \
+		mexPrintf("%8s : %5i : %8i sec : %8i usec\n", __TIME__, __LINE__, now.tv_sec, now.tv_usec); \
+	}
+	#define report_time_start( ) \
+	{ \
+		gettimeofday(&snow, NULL); \
+		mexPrintf("%8s : %5i : %8i sec : %8i usec", __TIME__, __LINE__, snow.tv_sec, snow.tv_usec); \
+	}
+	#define report_time_end( ) \
+	{ \
+		gettimeofday(&enow, NULL); \
+		mexPrintf("%8i sec : %8i usec\n", enow.tv_sec - snow.tv_sec, enow.tv_sec - snow.tv_sec?snow.tv_usec-enow.tv_usec:enow.tv_usec - snow.tv_usec); \
+	}
 #else
-#define report_time_eventLoop( ){};
-#define report_time( ) {}
-#define report_time_start( ) {}
-#define report_time_end( ) {}
+	#define report_time_eventLoop( ){};
+	#define report_time( ) {}
+	#define report_time_start( ) {}
+	#define report_time_end( ) {}
 #endif /* DEBUG_TIMING */
 
 
@@ -229,16 +248,16 @@
 /*----------------------------------------------------------
 RXTXPort.Initialize
 
-   accept:      The JNIEnv and jobj of the thread, the original eis.
-   perform:     fill in the needed variables with this threads values
-   return:      none
-   exceptions:  none
-   comments:    java variables (especially JNIEnv) should not be shared
-		between threads.  Right now we build a local struct with
-		the thread's info before using the variabls.  This is
-		especially true for send_event.
-
-		See also JNI_OnLoad() if the thread does not have the values
+	accept:		The JNIEnv and jobj of the thread, the original eis.
+	perform:	fill in the needed variables with this threads values
+	return:		none
+	exceptions: none
+	comments:	java variables (especially JNIEnv) should not be shared
+				between threads.  Right now we build a local struct with
+				the thread's info before using the variabls.  This is
+				especially true for send_event.
+				
+	See also JNI_OnLoad() if the thread does not have the values
 ----------------------------------------------------------*/
 struct event_info_struct build_threadsafe_eis(
 	JNIEnv *env,
@@ -264,13 +283,13 @@
 /*----------------------------------------------------------
 RXTXPort.Initialize
 
-   accept:      none
-   perform:     Initialize the native library
-   return:      none
-   exceptions:  none
-   comments:    Basically this just causes rxtx to ignore signals.  signal
-		handlers where tried but the VM (circa 1.1) did not like it.
-
+	accept:		none
+	perform:	Initialize the native library
+	return:		none
+	exceptions:	none
+	comments:	Basically this just causes rxtx to ignore signals.  signal
+				handlers where tried but the VM (circa 1.1) did not like it.
+				
 		It also allows for some sanity checks on linux boxes if DEBUG
 		is enabled.
 ----------------------------------------------------------*/
@@ -284,9 +303,9 @@
 	char message[80];
 #endif /* DEBUG && __linux__ */
 	/* This bit of code checks to see if there is a signal handler installed
-	   for SIGIO, and installs SIG_IGN if there is not.  This is necessary
-	   for the native threads jdk, but we don't want to do it with green
-	   threads, because it slows things down.  Go figure. */
+		for SIGIO, and installs SIG_IGN if there is not.  This is necessary
+		for the native threads jdk, but we don't want to do it with green
+		threads, because it slows things down.  Go figure. */
 
 	/* POSIX signal handling functions */
 #if !defined(WIN32)
@@ -306,7 +325,7 @@
 		sigaction(SIGIO, &new_action, NULL);
 	}
 #endif /* !WIN32 */
-	ENTER( "RXTXPort:Initialize" );
+	report( "Entering - RXTXPort:Initialize\n" );
 #ifdef PRERELEASE
 	/*  this is just for avoiding confusion while testing new libraries */
 #ifdef DEBUG_MW
@@ -322,32 +341,33 @@
 	/* Lets let people who upgraded kernels know they may have problems */
 	if (uname (&name) == -1)
 	{
-		report( "RXTX WARNING:  cannot get system name\n" );
-		LEAVE( "RXTXPort:Initialize" );
+		report( "RXTX WARNING:	cannot get system name\n" );
+		report( "Leaving - RXTXPort:Initialize\n" );
 		return;
 	}
 	if(strcmp(name.release,UTS_RELEASE)!=0)
 	{
-		sprintf( message, LINUX_KERNEL_VERSION_ERROR, UTS_RELEASE,
+		memset(&message[0], 0, sizeof(message));
+		sprintf( message, "%s%s%s\n", LINUX_KERNEL_VERSION_ERROR, UTS_RELEASE,
 			name.release );
 		report( message );
 		getchar();
 	}
-	LEAVE( "RXTXPort:Initialize" );
+	report( "Leaving - RXTXPort:Initialize\n" );
 #endif /* DEBUG && __linux__ */
 }
 
 /*----------------------------------------------------------
 RXTXPort.find_preopened_ports
-   accept:      The device to find if preopened.  ie "/dev/ttyS0"
-   perform:     find the filedescriptor if preopened
-   return:      fd
-   exceptions:  none
-   comments:    see
-			RXTXPort.nativeStaticSetDSR
-			RXTXPort.nativeStaticSetDTR
-			RXTXPort.nativeStaticSetRTS
-			RXTXPort.nativeStaticSetSerialPortParams
+	accept:		The device to find if preopened.  ie "/dev/ttyS0"
+	perform:	find the filedescriptor if preopened
+	return:		fd
+	exceptions:	none
+	comments:	see
+				RXTXPort.nativeStaticSetDSR
+				RXTXPort.nativeStaticSetDTR
+				RXTXPort.nativeStaticSetRTS
+				RXTXPort.nativeStaticSetSerialPortParams
 		This is used so people can setDTR low before calling the
 		Java open().
 ----------------------------------------------------------*/
@@ -401,13 +421,13 @@
 /*----------------------------------------------------------
 configure_port
 
-   accept:      env, file descriptor
-   perform:     set the termios struct to sane settings and
-   return:      0 on success
-   exceptions:  IOExcepiton
-   comments:    Very often people complain about not being able to get past
-                this function and it turns out to be permissions on the
-                device file or bios has the device disabled.
+	accept:		Env, file descriptor
+	perform:	set the termios struct to sane settings and
+	return:		0 on success
+	exceptions:	IOExcepiton
+	comments:	Very often people complain about not being able to get past
+				this function and it turns out to be permissions on the
+				device file or bios has the device disabled.
 ----------------------------------------------------------*/
 int configure_port( int fd )
 {
@@ -446,31 +466,31 @@
 /*----------------------------------------------------------
 get_java_baudrate
 
-   accept:      the native speed setting
-   perform:     translate the native speed to a Java speed
-   return:      the Java speed
-   exceptions:  none
-   comments:    This is used by open() (indirectly) and
-		nativeStaticGetBaudRate()
+	accept:		the native speed setting
+	perform:	translate the native speed to a Java speed
+	return:		the Java speed
+	exceptions:	none
+	comments:	This is used by open() (indirectly) and
+				nativeStaticGetBaudRate()
 ----------------------------------------------------------*/
 int get_java_baudrate( int native_speed )
 {
 	switch( native_speed )
 	{
-		case B0:     return 0;
-		case B50:    return 50;
-		case B75:    return 75;
-		case B110:   return 110;
-		case B134:   return 134;
-		case B150:   return 150;
-		case B200:   return 200;
-		case B300:   return 300;
-		case B600:   return 600;
-		case B1200:  return 1200;
-		case B1800:  return 1800;
-		case B2400:  return 2400;
-		case B4800:  return 4800;
-		case B9600:  return 9600;
+		case B0:	return 0;
+		case B50:	return 50;
+		case B75:	return 75;
+		case B110:	return 110;
+		case B134:	return 134;
+		case B150:	return 150;
+		case B200:	return 200;
+		case B300:	return 300;
+		case B600:	return 600;
+		case B1200:	return 1200;
+		case B1800:	return 1800;
+		case B2400:	return 2400;
+		case B4800:	return 4800;
+		case B9600:	return 9600;
 #ifdef B14400
 		case B14400: return 14400;
 #endif /* B14400 */
@@ -536,13 +556,13 @@
 /*----------------------------------------------------------
 set_java_vars
 
-   accept:      fd of the preopened device
-   perform:     Now that the object is instatiated, set the Java variables
-		to the preopened states.
-   return:      none
-   exceptions:  none
-   comments:    preopened refers to the fact that the serial port has
-		been configured before the Java open() has been called.
+	accept:		fd of the preopened device
+	perform:	Now that the object is instatiated, set the Java variables
+				to the preopened states.
+	return:		none
+	exceptions:	none
+	comments:	preopened refers to the fact that the serial port has
+				been configured before the Java open() has been called.
 ----------------------------------------------------------*/
 
 void set_java_vars( JNIEnv *env, jobject jobj, int fd )
@@ -570,10 +590,10 @@
 
 
 	switch( ttyset.c_cflag&CSIZE ) {
-		case CS5:  databits = JDATABITS_5; break;
-		case CS6:  databits = JDATABITS_6; break;
-		case CS7:  databits = JDATABITS_7; break;
-		case CS8:  databits = JDATABITS_8; break;
+		case CS5:	databits = JDATABITS_5; break;
+		case CS6:	databits = JDATABITS_6; break;
+		case CS7:	databits = JDATABITS_7; break;
+		case CS8:	databits = JDATABITS_8; break;
 	}
 #ifdef CMSPAR
 	switch( ttyset.c_cflag&(PARENB|PARODD|CMSPAR ) ) {
@@ -588,9 +608,9 @@
 		case PARENB | CMSPAR: jparity = JPARITY_SPACE; break;
 #endif /* CMSPAR */
 	}
-        switch( ttyset.c_cflag&(CSTOPB) ) {
-                case 0: stop_bits = STOPBITS_1; break;
-                case CSTOPB:
+	 switch( ttyset.c_cflag&(CSTOPB) ) {
+			case 0: stop_bits = STOPBITS_1; break;
+			case CSTOPB:
 			if ( (ttyset.c_cflag & CSIZE) ==  CS5 ) {
 				stop_bits = STOPBITS_1_5;
 			}
@@ -598,7 +618,7 @@
 				stop_bits = STOPBITS_2;
 			}
 			break;
-        }
+	 }
 /*
 dima writes:
 
@@ -616,9 +636,9 @@
 
 */
 #if defined(CBAUD)/* dima */
-    	baudrate = ttyset.c_cflag&CBAUD;
+		baudrate = ttyset.c_cflag&CBAUD;
 #else
-    	baudrate = cfgetispeed(&ttyset);
+		baudrate = cfgetispeed(&ttyset);
 #endif
 	(*env)->SetIntField(env, jobj, jfspeed,
 		( jint ) get_java_baudrate(baudrate) );
@@ -629,14 +649,14 @@
 /*----------------------------------------------------------
 RXTXPort.open
 
-   accept:      The device to open.  ie "/dev/ttyS0"
-   perform:     open the device, set the termios struct to sane settings and
-                return the filedescriptor
-   return:      fd
-   exceptions:  IOExcepiton
-   comments:    Very often people complain about not being able to get past
-                this function and it turns out to be permissions on the
-                device file or bios has the device disabled.
+	accept:		The device to open.  ie "/dev/ttyS0"
+	perform:	open the device, set the termios struct to sane settings and
+				return the filedescriptor
+	return:		fd
+	exceptions:	IOExcepiton
+	comments:	Very often people complain about not being able to get past
+				this function and it turns out to be permissions on the
+				device file or bios has the device disabled.
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(open)(
 	JNIEnv *env,
@@ -676,9 +696,10 @@
 			system_does_not_lock	Win32
 	*/
 
-	ENTER( "RXTXPort:open" );
+	report( "Entering - RXTXPort:open\n" );
 	if ( LOCK( filename, pid ) )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message, "open: locking has failed for %s\n",
 			filename );
 		report( message );
@@ -686,6 +707,7 @@
 	}
 	else
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message, "open: locking worked for %s\n", filename );
 		report( message );
 	}
@@ -703,36 +725,36 @@
 	}  while (fd < 0 && errno==EINTR);
 
 #ifdef OPEN_EXCL
-       /*
-       Note that open() follows POSIX semantics: multiple open() calls to
-       the same file will succeed unless the TIOCEXCL ioctl is issued.
-       This will prevent additional opens except by root-owned processes.
-       See tty(4) ("man 4 tty") and ioctl(2) ("man 2 ioctl") for details.
-       */
-
-       if (fd >= 0 && (ioctl(fd, TIOCEXCL) == -1))
-       {
-               sprintf( message, "open: exclusive access denied for %s\n",
-                       filename );
-               report( message );
-               report_error( message );
-
-               close(fd);
-               goto fail;
-       }
+	/*
+	Note that open() follows POSIX semantics: multiple open() calls to
+	the same file will succeed unless the TIOCEXCL ioctl is issued.
+	This will prevent additional opens except by root-owned processes.
+	See tty(4) ("man 4 tty") and ioctl(2) ("man 2 ioctl") for details.
+	*/
+
+	if (fd >= 0 && (ioctl(fd, TIOCEXCL) == -1))
+	{
+			memset(&message[0], 0, sizeof(message));
+			sprintf( message, "open: exclusive access denied for %s\n", filename );
+			report( message );
+			report_error( message );
+			close(fd);
+			goto fail;
+	}
 #endif /* OPEN_EXCL */
 
 	if( configure_port( fd ) ) goto fail;
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "open: fd returned is %i\n", fd );
 	report( message );
-	LEAVE( "RXTXPort:open" );
+	report( "Leaving - RXTXPort:open\n" );
 	report_time_end( );
 	return (jint)fd;
 
 fail:
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:open" );
+	report( "Leaving - RXTXPort:open\n" );
 	throw_java_exception( env, PORT_IN_USE_EXCEPTION, "open",
 		strerror( errno ) );
 	return -1;
@@ -741,10 +763,10 @@
 /*----------------------------------------------------------
 RXTXPort.nativeClose
 
-   accept:      none
-   perform:     get the fd from the java end and close it
-   return:      none
-   exceptions:  none
+	accept:		none
+	perform:	get the fd from the java end and close it
+	return:		none
+	exceptions:	none
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(nativeClose)( JNIEnv *env,
 	jobject jobj,jstring jstr )
@@ -764,7 +786,7 @@
 		(*env)->ExceptionDescribe( env );
 		(*env)->ExceptionClear( env );
 		(*env)->DeleteLocalRef( env, jclazz );
-		report("nativeClose: Close not detecting thread pid");
+		report("nativeClose: Close not detecting thread pid\n");
 		return;
 	}
 	report("<nativeClose: pid\n");
@@ -777,14 +799,14 @@
 			system_does_not_unlock	Win32
 	*/
 
-	ENTER( "RXTXPort:nativeClose" );
+	report( "Entering - RXTXPort:nativeClose\n" );
 	if (fd > 0)
 	{
 		report("nativeClose: discarding remaining data (tcflush)\n");
 		/* discard any incoming+outgoing data not yet read/sent */
 		tcflush(fd, TCIOFLUSH);
  		do {
-			report("nativeClose:  calling close\n");
+			report("nativeClose:	calling close\n");
 			result=CLOSE (fd);
 		}  while ( result < 0 && errno == EINTR );
 		UNLOCK( filename, pid );
@@ -793,7 +815,7 @@
 	(*env)->DeleteLocalRef( env, jclazz );
 	report("nativeClose: release filename\n");
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeClose" );
+	report( "Leaving - RXTXPort:nativeClose\n" );
 	report_time_end( );
 	return;
 }
@@ -801,15 +823,15 @@
 /*----------------------------------------------------------
  RXTXPort.set_port_params
 
-   accept:     env, fd, speed, data bits, stop bits, parity
-   perform:    set the serial port parameters
-   return:     1 on error
-   exceptions: UnsupportedCommOperationException
-   comments:   There is a static method and an instance method that use this
-		function.  The static method gets a fd first.  The instance
-		method can get the fd from the object.
+	accept:		env, fd, speed, data bits, stop bits, parity
+	perform:	set the serial port parameters
+	return:		1 on error
+	exceptions: UnsupportedCommOperationException
+	comments:	There is a static method and an instance method that use this
+				function.  The static method gets a fd first.  The instance
+				method can get the fd from the object.
 
-		see:  nativeSetSerialPortParams & nativeStaticSerialPortParams
+	see:		nativeSetSerialPortParams & nativeStaticSerialPortParams
 ----------------------------------------------------------*/
 int set_port_params( JNIEnv *env, int fd, int cspeed, int dataBits,
 			int stopBits, int parity )
@@ -864,36 +886,36 @@
 		ioctl( fd, TIOCMSET, &result );
 	}
 	/*
-	   B38400 is a special case in Linux for custom baud rates.
+		B38400 is a special case in Linux for custom baud rates.
 
-	   We just treat this as a custom speed for now.  If you take this ifdef
-	   out and select baud rates 38400 then 28800 then 38400, you will get
-	   a final baud rate of 28800 because you did not update the divisor.
+		We just treat this as a custom speed for now.  If you take this ifdef
+		out and select baud rates 38400 then 28800 then 38400, you will get
+		a final baud rate of 28800 because you did not update the divisor.
 
-	   See the next ifdef below for the divisor.
+		See the next ifdef below for the divisor.
 	*/
 #if defined(TIOCGSERIAL)
 	if ( cspeed == B38400 )
 		cspeed = 38400;
 #endif /* TIOCGSERIAL */
-	if(     cfsetispeed( &ttyset, cspeed ) < 0 ||
+	if(	cfsetispeed( &ttyset, cspeed ) < 0 ||
 		cfsetospeed( &ttyset, cspeed ) < 0 )
 	{
 		/*
-		    Some people need to set the baud rate to ones not defined
-		    in termios.h
+			Some people need to set the baud rate to ones not defined
+			in termios.h
 
-		    This includes some baud rates which are supported by CommAPI
-		    in Unix ( 14400, 28800, 128000, 256000 )
+			This includes some baud rates which are supported by CommAPI
+			in Unix ( 14400, 28800, 128000, 256000 )
 
-		    If the above fails, we assume this is not a defined
-		    baud rate on Unix.  With Win32, It is assumed the kernel
-		    will do this for us.
+			If the above fails, we assume this is not a defined
+			baud rate on Unix.  With Win32, It is assumed the kernel
+			will do this for us.
 
-		    The baud_base and desired speed are used to
-		    calculate a custom divisor.
+			The baud_base and desired speed are used to
+			calculate a custom divisor.
 
-		    On linux the setserial man page covers this.
+			On linux the setserial man page covers this.
 		*/
 
 #if defined(TIOCGSERIAL)
@@ -905,7 +927,7 @@
 		sstruct.custom_divisor = ( sstruct.baud_base/cspeed );
 		cspeed = B38400;
 #endif /* TIOCGSERIAL */
-		if(     cfsetispeed( &ttyset, cspeed ) < 0 ||
+		if(	cfsetispeed( &ttyset, cspeed ) < 0 ||
 			cfsetospeed( &ttyset, cspeed ) < 0 )
 		{
 			/* OK, we tried everything */
@@ -933,10 +955,10 @@
 /*----------------------------------------------------------
  RXTXPort.nativeSetSerialPortParams
 
-   accept:     speed, data bits, stop bits, parity
-   perform:    set the serial port parameters
-   return:     jboolean 1 on error
-   exceptions: UnsupportedCommOperationException
+	accept:		speed, data bits, stop bits, parity
+	perform:	set the serial port parameters
+	return:		jboolean 1 on error
+	exceptions: UnsupportedCommOperationException
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeSetSerialPortParams)(
 	JNIEnv *env, jobject jobj, jint speed, jint dataBits, jint stopBits,
@@ -945,15 +967,15 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	int cspeed = translate_speed( env, speed );
 
-	ENTER( "RXTXPort:nativeSetSerialPortParams" );
+	report( "Entering - RXTXPort:nativeSetSerialPortParams\n" );
 	report_time_start( );
 
 	if (cspeed < 0 )
 	{
 		report(" invalid cspeed\n");
 /*
-    For some reason the native exceptions are not being caught.  Moving this
-    to the Java side fixed the issue.  taj.
+	For some reason the native exceptions are not being caught.  Moving this
+	to the Java side fixed the issue.  taj.
 		throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 			"", "BaudRate could not be set to the specified value" );
 */
@@ -964,17 +986,17 @@
 	if( set_port_params( env, fd, cspeed, dataBits, stopBits, parity ) )
 	{
 		report("set_port_params failed\n");
-		LEAVE( "RXTXPort:nativeSetSerialPortParams" );
+		report( "Leaving - RXTXPort:nativeSetSerialPortParams\n" );
 /*
-    For some reason the native exceptions are not being caught.  Moving this
-    to the Java side fixed the issue.  taj.
+	For some reason the native exceptions are not being caught.  Moving this
+	to the Java side fixed the issue.  taj.
 		throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 			"nativeSetSerialPortParams", strerror( errno ) );
 */
 		return(1);
 	}
 
-	LEAVE( "RXTXPort:nativeSetSerialPortParams" );
+	report( "Leaving - RXTXPort:nativeSetSerialPortParams\n" );
 	report_time_end( );
 	return(0);
 }
@@ -982,17 +1004,17 @@
 /*----------------------------------------------------------
  translate_speed
 
-   accept:     speed in bits-per-second
-   perform:    convert bits-per-second to a speed_t constant
-   return:     speed_t constant
-   exceptions: returns -1 and the calling method throws the exception so
-	       it may be caught in java.
-   comments:   Only the lowest level code should know about
-               the magic constants.
+	accept:		speed in bits-per-second
+	perform:	convert bits-per-second to a speed_t constant
+	return:		speed_t constant
+	exceptions: returns -1 and the calling method throws the exception so
+				it may be caught in java.
+	comments:	Only the lowest level code should know about
+				the magic constants.
 ----------------------------------------------------------*/
 int translate_speed( JNIEnv *env, jint speed )
 {
-	LEAVE( "RXTXPort:translate_speed" );
+	report( "Leaving - RXTXPort:translate_speed\n" );
 	switch( speed ) {
 		case 0:		return B0;
 		case 50:	return B50;
@@ -1072,7 +1094,7 @@
 	if( speed >= 0 ) return speed;
 	else
 	{
-		LEAVE( "RXTXPort:translate_speed: Error condition" );
+		report( "Leaving - RXTXPort:translate_speed: Error condition\n" );
 		return -1;
 	}
 }
@@ -1080,16 +1102,16 @@
 /*----------------------------------------------------------
  translate_data_bits
 
-   accept:     gnu.io.SerialPort.DATABITS_* constant
-   perform:    set proper termios c_cflag bits
-   return:     1 on error
-   exceptions: UnsupportedCommOperationException
+	accept:		gnu.io.SerialPort.DATABITS_* constant
+	perform:	set proper termios c_cflag bits
+	return:		1 on error
+	exceptions: UnsupportedCommOperationException
 ----------------------------------------------------------*/
 int translate_data_bits( JNIEnv *env, tcflag_t *cflag, jint dataBits )
 {
 	int temp = (*cflag) & ~CSIZE;
 
-	ENTER( "translate_date_bits" );
+	report( "Entering - translate_date_bits\n" );
 	switch( dataBits ) {
 		case JDATABITS_5:
 			(*cflag) = temp | CS5;
@@ -1105,10 +1127,10 @@
 			return 0;
 	}
 
-	LEAVE( "RXTXPort:translate_date_bits" );
+	report( "Leaving - RXTXPort:translate_date_bits\n" );
 /*
-    For some reason the native exceptions are not being caught.  Moving this
-    to the Java side fixed the issue.  taj.
+	For some reason the native exceptions are not being caught.  Moving this
+	to the Java side fixed the issue.  taj.
 	throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 		"", "databit value not supported" );
 */
@@ -1118,20 +1140,20 @@
 /*----------------------------------------------------------
  translate_stop_bits
 
-   accept:     gnu.io.SerialPort.STOPBITS_* constant
-   perform:    set proper termios c_cflag bits
-   return:     1 on error
-   exceptions: UnsupportedCommOperationException
-   comments:   If you specify 5 data bits and 2 stop bits, the port will
-               allegedly use 1.5 stop bits.  Does anyone care?
+	accept:		gnu.io.SerialPort.STOPBITS_* constant
+	perform:	set proper termios c_cflag bits
+	return:		1 on error
+	exceptions: UnsupportedCommOperationException
+	comments:	If you specify 5 data bits and 2 stop bits, the port will
+				allegedly use 1.5 stop bits.  Does anyone care?
 ----------------------------------------------------------*/
 int translate_stop_bits( JNIEnv *env, tcflag_t *cflag, jint stopBits )
 {
-	ENTER( "translate_stop_bits" );
+	report( "Entering - translate_stop_bits\n" );
 	switch( stopBits ) {
 		case STOPBITS_1:
 			(*cflag) &= ~CSTOPB;
-			LEAVE( "RXTXPort:translate_stop_bits" );
+			report( "Leaving - RXTXPort:translate_stop_bits\n" );
 			return 0;
 		/*  ok.. lets try putting it in and see if anyone notices */
 		case STOPBITS_1_5:
@@ -1141,14 +1163,14 @@
 			return 0;
 		case STOPBITS_2:
 			(*cflag) |= CSTOPB;
-			LEAVE( "RXTXPort:translate_stop_bits" );
+			report( "Leaving - RXTXPort:translate_stop_bits\n" );
 			return 0;
 	}
 
-	LEAVE( "RXTXPort:translate_stop_bits" );
+	report( "Leaving - RXTXPort:translate_stop_bits\n" );
 /*
-    For some reason the native exceptions are not being caught.  Moving this
-    to the Java side fixed the issue.  taj.
+	For some reason the native exceptions are not being caught.  Moving this
+	to the Java side fixed the issue.  taj.
 	throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 		"", "stopbit value not supported" );
 */
@@ -1181,7 +1203,7 @@
 
 	if( tcgetattr( fd, &ttyset ) < 0 )
 	{
-		report("nativeGetParity:  tcgetattr failed\n");
+		report("nativeGetParity:	tcgetattr failed\n");
 		return( -1 );
 	}
 #ifdef  CMSPAR
@@ -1215,49 +1237,49 @@
 /*----------------------------------------------------------
  translate_parity
 
-   accept:     javax.comm.SerialPort.PARITY_* constant
-   perform:    set proper termios c_cflag bits
-   return:     1 on error
-   exceptions: UnsupportedCommOperationException
-   comments:   The CMSPAR bit should be used for 'mark' and 'space' parity,
-               but it's not in glibc's includes.  Oh well, rarely used anyway.
+	accept:		javax.comm.SerialPort.PARITY_* constant
+	perform:	set proper termios c_cflag bits
+	return:		1 on error
+	exceptions:	UnsupportedCommOperationException
+	comments:	The CMSPAR bit should be used for 'mark' and 'space' parity,
+				but it's not in glibc's includes.  Oh well, rarely used anyway.
 ----------------------------------------------------------*/
 int translate_parity( JNIEnv *env, tcflag_t *cflag, jint parity )
 {
-	ENTER( "translate_parity" );
+	report( "Entering - translate_parity\n" );
 #ifdef CMSPAR
 	(*cflag) &= ~(PARENB | PARODD | CMSPAR );
 #endif /* CMSPAR */
 	switch( parity ) {
 		case JPARITY_NONE:
-			LEAVE( "translate_parity" );
+			report( "Leaving - translate_parity\n" );
 			return 0;
 		case JPARITY_EVEN:
 			(*cflag) |= PARENB;
-			LEAVE( "translate_parity" );
+			report( "Leaving - translate_parity\n" );
 			return 0;
 		case JPARITY_ODD:
 			(*cflag) |= PARENB | PARODD;
-			LEAVE( "translate_parity" );
+			report( "Leaving - translate_parity\n" );
 			return 0;
 #ifdef CMSPAR
 		case JPARITY_MARK:
 			(*cflag) |= PARENB | PARODD | CMSPAR;
-			LEAVE( "translate_parity" );
+			report( "Leaving - translate_parity\n" );
 			return 0;
 		case JPARITY_SPACE:
 			(*cflag) |= PARENB | CMSPAR;
-			LEAVE( "translate_parity" );
+			report( "Leaving - translate_parity\n" );
 			return 0;
 #endif /* CMSPAR */
 		default:
 			printf("Parity missed %i\n", (int) parity );
 	}
 
-	LEAVE( "translate_parity" );
+	report( "Leaving - translate_parity\n" );
 /*
-    For some reason the native exceptions are not being caught.  Moving this
-    to the Java side fixed the issue.  taj.
+	For some reason the native exceptions are not being caught.  Moving this
+	to the Java side fixed the issue.  taj.
 	throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 		"", "parity value not supported" );
 */
@@ -1267,48 +1289,63 @@
 /*----------------------------------------------------------
 drain_loop()
 
-   accept:
-   perform:	call tcdrain() and report an event when it succeds
-   return:      none
-   exceptions:
-   comments:
+	accept:
+	perform:	call tcdrain() and report an event when it succeds
+	return:		none
+	exceptions:
+	comments:
 ----------------------------------------------------------*/
 void *drain_loop( void *arg )
 {
+	report("Entering - drain_loop\n");	
 	struct event_info_struct *eis = ( struct event_info_struct * ) arg;
 	/* char msg[80]; */
 	int i;
+	
+	report_verbose("drain_loop: pthread detaching\n");
 	pthread_detach( pthread_self() );
-
+	
+	report_verbose("drain_loop: begining for loop\n");
 	for(i=0;;i++)
 	{
-		report_verbose("drain_loop:  looping\n");
+		report_verbose("drain_loop: looping\n");
 		if( eis->eventloop_interrupted )
 		{
+			report_verbose("drain_loop: EventLoop Interrupted\n");
 			goto end;
 		}
-#if defined(__sun__)
-	/* FIXME: No time to test on all OS's for production */
-		if (usleep(5000)) {
-			report("drain_loop:  received EINTR");
-		}
-#else
-		if (usleep(1000000)) {
-			report("drain_loop:  received EINTR");
-		}
-#endif /* __sun__ */
+		
+		#if defined(__sun__)
+			/* FIXME: No time to test on all OS's for production */
+			report_verbose("drain_loop: SUN: Sleeping now\n");
+			if (usleep(5000)) {
+				report("***drain_loop: received EINTR\n");
+			}
+		#else
+			report_verbose("drain_loop: Sleeping now\n");
+			if (usleep(1000000)) {
+				report("***drain_loop: received EINTR\n");
+			}
+		#endif /* __sun__ */
+		
+		report_verbose("***drain_loop: Out of sleep loop\n");
 		/*
 		system_wait();
 		*/
+		
 		if( eis->eventloop_interrupted )
 		{
+			report_verbose("*** drain_loop: Interupted\n");
+			eis->closing = 1;
 			goto end;
 		}
+		
 		if( tcdrain( eis->fd ) == 0 )
 		{
 			if( eis && eis->writing )
 			{
 				/*
+				memset(&msg[0], 0, sizeof(msg));
 				sprintf(msg, "drain_loop: setting OUTPUT_BUFFER_EMPTY\n" );
 				report( msg );
 				*/
@@ -1321,17 +1358,17 @@
 				{
 					goto end;
 				}
-				report_verbose("drain_loop:  writing not set\n");
+				report_verbose("drain_loop: writing not set\n");
 			}
 		}
 		else if (errno != EINTR)
 		{
-			report("drain_loop:  tcdrain bad fd\n");
+			report("drain_loop:	tcdrain bad fd\n");
 			goto end;
 		}
 		else
 		{
-			report("drain_loop:  received EINTR in tcdrain\n");
+			report("drain_loop:	received EINTR in tcdrain\n");
 		}
 	}
 end:
@@ -1344,12 +1381,12 @@
 /*----------------------------------------------------------
 finalize_threads( )
 
-   accept:      event_info_struct used to access java and communicate with
-	        eventLoop().
-   perform:     see comments
-   return:      none
-   exceptions:  none
-   comments:
+	accept:		event_info_struct used to access java and communicate with
+				eventLoop().
+	perform:	see comments
+	return:		none
+	exceptions:	none
+	comments:
 	The is the pthread spawned on systems that can't access the
 	LSR (Line Status Register).  Without access to the LSR rxtx
 	cannot detect when the output buffer is empty in the Monitor
@@ -1361,14 +1398,14 @@
 ----------------------------------------------------------*/
 void finalize_threads( struct event_info_struct *eis )
 {
-#if     !defined(TIOCSERGETLSR) && !defined( WIN32 )
+#if	!defined(TIOCSERGETLSR) && !defined( WIN32 )
 	/* used to shut down any remaining write threads */
 
 	eis->output_buffer_empty_flag = 0;
-	ENTER("finalize_threads\n");
+	report("Entering - finalize_threads\n");
 
 	/* need to clean up again after working events */
-	LEAVE("---------------- finalize_threads ---------------");
+	report("Leaving - ---------------- finalize_threads ---------------\n");
 #endif /* TIOCSERGETLSR & !WIN32 */
 }
 
@@ -1377,6 +1414,8 @@
 {
 	/*
 	char msg[80];
+	
+	memset(&msg[0], 0, sizeof(msg));
 	sprintf( msg, "RXTX Recieved Signal %i\n", signo );
 	report_error( msg );
 	*/
@@ -1386,17 +1425,19 @@
 /*----------------------------------------------------------
 init_threads( )
 
-   accept:      none
-   perform:
-   return:      none
-   exceptions:  none
-   comments:
-   this function is called from the event_loop or in other words
-   from the monitor thread. On systems !WIN32 and without TIOCSERGETLSR
-   it will create a new thread looping a call to tcdrain.
+	accept:		none
+	perform:
+	return:		none
+	exceptions:	none
+	comments:
+				this function is called from the event_loop or in other
+				words from the monitor thread. On systems !WIN32 and 
+				without TIOCSERGETLSR it will create a new thread
+				looping a call to tcdrain.
 ----------------------------------------------------------*/
 int init_threads( struct event_info_struct *eis )
 {
+	report("Entering - init_threads\n");
 	jfieldID jeis;
 #if !defined(TIOCSERGETLSR) & !defined(WIN32)
 	sigset_t newmask, oldmask;
@@ -1404,7 +1445,7 @@
 	pthread_t tid;
 
 	report_time_start( );
-	report("init_threads:  start\n");
+	report("init_threads:	start\n");
 	/* ignore child thread status changes */
 	sigemptyset(&newmask);
 	sigaddset(&newmask, SIGCHLD);
@@ -1412,14 +1453,17 @@
 	/* install our own signal hander */
 	newaction.sa_handler = warn_sig_abort;
 	sigemptyset( &newaction.sa_mask );
-#ifdef SA_INTERRUPT
-	newaction.sa_flags = SA_INTERRUPT;
-#endif /* SA_INTERRUPT */
-#ifdef SA_RESTART
-	/* JOE: do not demand restart! we are handling EINTR */
-/*	newaction.sa_flags = SA_RESTART;*/
-#endif /* SA_RESTART */
-
+	#ifdef SA_INTERRUPT
+		newaction.sa_flags = SA_INTERRUPT;
+	#endif /* SA_INTERRUPT */
+	#ifdef SA_RESTART
+		/* JOE: do not demand restart! we are handling EINTR */
+		/*	newaction.sa_flags = SA_RESTART;*/
+	#endif /* SA_RESTART */
+
+	/**
+	*	POSIX SIGABRT behaviour not changed in original code!!
+	**/
 	sigaction(SIGABRT, &newaction, &oldaction);
 	sigaction(SIGCHLD, &newaction, &oldaction);
 	sigaction(SIGALRM, &newaction, &oldaction);
@@ -1443,23 +1487,25 @@
 	pthread_detach( tid );
 	eis->drain_tid = tid;
 #endif /* TIOCSERGETLSR */
+
 	report("init_threads: get eis\n");
 	jeis  = (*eis->env)->GetFieldID( eis->env, eis->jclazz, "eis", "J" );
 	report("init_threads: set eis\n");
 	(*eis->env)->SetLongField(eis->env, *eis->jobj, jeis, ( size_t ) eis );
-	report("init_threads:  stop\n");
+	report("init_threads:	stop\n");
 	report_time_end( );
+	report("Leaving - init_threads\n");
 	return( 1 );
 }
 
 /*----------------------------------------------------------
 RXTXPort.writeByte
 
-   accept:      byte to write (passed as int)
-                jboolean interrupted (no events if true)
-   perform:     write a single byte to the port
-   return:      none
-   exceptions:  IOException
+	accept:		byte to write (passed as int)
+				jboolean interrupted (no events if true)
+	perform:	write a single byte to the port
+	return:		none
+	exceptions:	IOException
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(writeByte)( JNIEnv *env,
 	jobject jobj, jint ji, jboolean interrupted )
@@ -1476,8 +1522,9 @@
 #endif /* __sun__ */
 
 	report_time_start();
-	ENTER( "RXTXPort:writeByte" );
+	report( "Entering - RXTXPort:writeByte\n" );
 	do {
+		memset(&msg[0], 0, sizeof(msg));
 		sprintf( msg, "writeByte %c>>\n", byte );
 		report( msg );
 		result=WRITE (fd, (void * ) &byte, sizeof(unsigned char));
@@ -1506,12 +1553,14 @@
 				index->next ) index = index->next;
 		}
 		index->writing = 1;
-		report( "writeByte:  index->writing = 1" );
+		report( "writeByte:	index->writing = 1\n" );
 	}
 #endif
+	
+	memset(&msg[0], 0, sizeof(msg));
 	sprintf( msg, "RXTXPort:writeByte %i\n", result );
 	report( msg );
-	LEAVE( "RXTXPort:writeByte" );
+	report( "Leaving - RXTXPort:writeByte\n" );
 	if(result >= 0)
 	{
 		report_time_end();
@@ -1525,13 +1574,13 @@
 /*----------------------------------------------------------
 RXTXPort.writeArray
 
-   accept:      jbarray: bytes used for writing
-                offset: offset in array to start writing
-                count: Number of bytes to write
-                jboolean interrupted (no events if true)
-   perform:     write length bytes of jbarray
-   return:      none
-   exceptions:  IOException
+	accept:		jbarray: bytes used for writing
+	offset:		offset in array to start writing
+	count:		Number of bytes to write
+				jboolean interrupted (no events if true)
+	perform:	write length bytes of jbarray
+	return:		none
+	exceptions:	IOException
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(writeArray)( JNIEnv *env,
 	jobject jobj, jbyteArray jbarray, jint offset, jint count,
@@ -1562,9 +1611,10 @@
 /* return; OH CRAP */
 
 	report_time_start();
-	ENTER( "writeArray" );
+	report( "Entering - writeArray\n" );
 	/* warning Roy Rogers */
 	/*
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "::::RXTXPort:writeArray(%s);\n", (char *) body );
 	report_verbose( message );
 	*/
@@ -1600,7 +1650,7 @@
 				index->next ) index = index->next;
 		}
 		index->writing = 1;
-		report( "writeArray:  index->writing = 1" );
+		report( "writeArray:	index->writing = 1\n" );
 	}
 #endif /* TIOCSERGETLSR */
 	/*
@@ -1615,7 +1665,7 @@
 
 		Things just start spinning out of control after that.
 	*/
-	LEAVE( "RXTXPort:writeArray" );
+	report( "Leaving - RXTXPort:writeArray\n" );
 	report_time_end();
 fail:
 	if( result < 0 ) throw_java_exception( env, IO_EXCEPTION,
@@ -1625,15 +1675,14 @@
 /*----------------------------------------------------------
 RXTXPort.nativeDrain
 
-   accept:      jboolean interrupted (no events if true)
-   perform:     wait until all data is transmitted
-   return:      none
-   exceptions:  IOException
-   comments:    java.io.OutputStream.flush() is equivalent to tcdrain,
-                not tcflush, which throws away unsent bytes
-
-                count logic added to avoid infinite loops when EINTR is
-                true...  Thread.yeild() was suggested.
+	accept:		jboolean interrupted (no events if true)
+	perform:	wait until all data is transmitted
+	return:		none
+	exceptions:	IOException
+	comments:	java.io.OutputStream.flush() is equivalent to tcdrain,
+				not tcflush, which throws away unsent bytes
+				count logic added to avoid infinite loops when EINTR is
+				true...  Thread.yeild() was suggested.
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeDrain)( JNIEnv *env,
 	jobject jobj, jboolean interrupted )
@@ -1644,7 +1693,7 @@
 
 	char message[80];
 
-	ENTER( "SerialImp.c:drain()" );
+	report( "Entering - SerialImp.c:drain()\n" );
 	report_time_start( );
 	do {
 		report_verbose( "nativeDrain: trying tcdrain\n" );
@@ -1652,13 +1701,15 @@
 		count++;
 	}  while (result && errno==EINTR && count <3);
 
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:drain() returns: %i\n", result );
 	report_verbose( message );
+	
 #if defined(__sun__)
 	/* FIXME: No time to test on all OS's for production */
 	return( JNI_TRUE );
 #endif /* __sun__ */
-	LEAVE( "RXTXPort:drain()" );
+	report( "Leaving - RXTXPort:drain()\n" );
 	if( result ) throw_java_exception( env, IO_EXCEPTION, "nativeDrain",
 		strerror( errno ) );
 	if( interrupted ) return( JNI_FALSE );
@@ -1669,10 +1720,12 @@
 		eis->output_buffer_empty_flag = 0;
 	}
 #endif /* !TIOCSERGETLSR !WIN32 */
+
 	if( eis && eis->eventflags[SPE_OUTPUT_BUFFER_EMPTY] )
 	{
-                struct event_info_struct myeis =
+		struct event_info_struct myeis =
 			build_threadsafe_eis( env, &jobj, eis );
+			
 		send_event( &myeis, SPE_OUTPUT_BUFFER_EMPTY, 1 );
 	}
 	report_time_end( );
@@ -1682,29 +1735,29 @@
 /*----------------------------------------------------------
 RXTXPort.sendBreak
 
-   accept:     duration in milliseconds.
-   perform:    send break for actual time.  not less than 0.25 seconds.
-   exceptions: none
-   comments:   not very precise
+	accept:		duration in milliseconds.
+	perform:	send break for actual time.  not less than 0.25 seconds.
+	exceptions: none
+	comments:	not very precise
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(sendBreak)( JNIEnv *env,
 	jobject jobj, jint duration )
 {
 	int fd = get_java_var( env, jobj,"fd","I" );
 	report_time_start( );
-	ENTER( "RXTXPort:sendBreak()" );
+	report( "Entering - RXTXPort:sendBreak()\n" );
 	tcsendbreak( fd, (int)( duration / 250 ) );
 	report_time_end( );
-	LEAVE( "RXTXPort:sendBreak()" );
+	report( "Leaving - RXTXPort:sendBreak()\n" );
 }
 
 /*----------------------------------------------------------
 RXTXPort.NativegetReceiveTimeout
 
-   accept:     none
-   perform:    get termios.c_cc[VTIME]
-   return:     VTIME
-   comments:   see  NativeEnableReceiveTimeoutThreshold
+	accept:		none
+	perform:	get termios.c_cc[VTIME]
+	return:	VTIME
+	comments:	see  NativeEnableReceiveTimeoutThreshold
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(NativegetReceiveTimeout)(
 	JNIEnv *env,
@@ -1714,12 +1767,12 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	struct termios ttyset;
 
-	ENTER( "RXTXPort:nativegetRecieveTimeout()" );
+	report( "Entering - RXTXPort:nativegetRecieveTimeout()\n" );
 	if( tcgetattr( fd, &ttyset ) < 0 ) goto fail;
-	LEAVE( "RXTXPort:nativegetRecieveTimeout()" );
+	report( "Leaving - RXTXPort:nativegetRecieveTimeout()\n" );
 	return(ttyset.c_cc[ VTIME ] * 100);
 fail:
-	LEAVE( "RXTXPort:nativegetRecieveTimeout()" );
+	report( "Leaving - RXTXPort:nativegetRecieveTimeout()\n" );
 	throw_java_exception( env, IO_EXCEPTION, "getReceiveTimeout",
 		strerror( errno ) );
 	return -1;
@@ -1728,10 +1781,10 @@
 /*----------------------------------------------------------
 RXTXPort.NativeisReceiveTimeoutEnabled
 
-   accept:     none
-   perform:    determine if VTIME is none 0
-   return:     JNI_TRUE if VTIME > 0 else JNI_FALSE
-   comments:   see  NativeEnableReceiveTimeoutThreshold
+	accept:		none
+	perform:	determine if VTIME is none 0
+	return:		JNI_TRUE if VTIME > 0 else JNI_FALSE
+	comments:	see  NativeEnableReceiveTimeoutThreshold
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(NativeisReceiveTimeoutEnabled)(
 	JNIEnv *env,
@@ -1740,12 +1793,12 @@
 {
 	int fd = get_java_var( env, jobj,"fd","I" );
 	struct termios ttyset;
-	ENTER( "RXTXPort:NativeisRecieveTimeoutEnabled()" );
+	report( "Entering - RXTXPort:NativeisRecieveTimeoutEnabled()\n" );
 	if( tcgetattr( fd, &ttyset ) < 0 ) goto fail;
-	LEAVE( "RXTXPort:NativeisRecieveTimeoutEnabled()" );
+	report( "Leaving - RXTXPort:NativeisRecieveTimeoutEnabled()\n" );
 	return(ttyset.c_cc[ VTIME ] > 0 ? JNI_TRUE:JNI_FALSE);
 fail:
-	LEAVE( "RXTXPort:NativeisRecieveTimeoutEnabled()" );
+	report( "Leaving - RXTXPort:NativeisRecieveTimeoutEnabled()\n" );
 	throw_java_exception( env, IO_EXCEPTION, "isReceiveTimeoutEnabled",
 		strerror( errno ) );
 	return JNI_FALSE;
@@ -1754,12 +1807,12 @@
 /*----------------------------------------------------------
 RXTXPort.isDSR
 
-   accept:      none
-   perform:     check status of DSR
-   return:      true if TIOCM_DSR is set
-                false if TIOCM_DSR is not set
-   exceptions:  none
-   comments:    DSR stands for Data Set Ready
+	accept:		none
+	perform:	check status of DSR
+	return:		true if TIOCM_DSR is set
+				false if TIOCM_DSR is not set
+	exceptions:	none
+	comments:	DSR stands for Data Set Ready
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isDSR)( JNIEnv *env,
 	jobject jobj )
@@ -1768,11 +1821,13 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isDSR" );
+	report( "Entering - RXTXPort:isDSR\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:isDSR returns %i\n", result & TIOCM_DSR );
 	report( message );
-	LEAVE( "RXTXPort:isDSR" );
+	report( "Leaving - RXTXPort:isDSR\n" );
 	if( result & TIOCM_DSR ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1780,15 +1835,15 @@
 /*----------------------------------------------------------
 RXTXPort.isCD
 
-   accept:      none
-   perform:     check status of CD
-   return:      true if TIOCM_CD is set
-                false if TIOCM_CD is not set
-   exceptions:  none
-   comments:    CD stands for Carrier Detect
-                The following comment has been made...
-                "well, it works, there might ofcourse be a bug, but making DCD
-                permanently on fixed it for me so I don't care"
+	accept:		none
+	perform:	check status of CD
+	return:		true if TIOCM_CD is set
+				false if TIOCM_CD is not set
+	exceptions:	none
+	comments:	CD stands for Carrier Detect
+				The following comment has been made...
+				"well, it works, there might ofcourse be a bug, but making DCD
+				permanently on fixed it for me so I don't care"
 
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isCD)( JNIEnv *env,
@@ -1798,10 +1853,12 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isCD" );
+	report( "Entering - RXTXPort:isCD\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:isCD returns %i\n", result & TIOCM_CD );
-	LEAVE( "RXTXPort:isCD" );
+	report( "Leaving - RXTXPort:isCD\n" );
 	if( result & TIOCM_CD ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1809,12 +1866,12 @@
 /*----------------------------------------------------------
 RXTXPort.isCTS
 
-   accept:      none
-   perform:     check status of CTS
-   return:      true if TIOCM_CTS is set
-                false if TIOCM_CTS is not set
-   exceptions:  none
-   comments:    CTS stands for Clear To Send.
+	accept:		none
+	perform:	check status of CTS
+	return:		true if TIOCM_CTS is set
+				false if TIOCM_CTS is not set
+	exceptions:	none
+	comments:	CTS stands for Clear To Send.
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isCTS)( JNIEnv *env,
 	jobject jobj )
@@ -1823,11 +1880,13 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isCTS" );
+	report( "Entering - RXTXPort:isCTS\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:isCTS returns %i\n", result & TIOCM_CTS );
 	report( message );
-	LEAVE( "RXTXPort:isCTS" );
+	report( "Leaving - RXTXPort:isCTS\n" );
 	if( result & TIOCM_CTS ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1835,12 +1894,12 @@
 /*----------------------------------------------------------
 RXTXPort.isRI
 
-   accept:      none
-   perform:     check status of RI
-   return:      true if TIOCM_RI is set
-                false if TIOCM_RI is not set
-   exceptions:  none
-   comments:    RI stands for Ring Indicator
+	accept:		none
+	perform:	check status of RI
+	return:		true if TIOCM_RI is set
+				false if TIOCM_RI is not set
+	exceptions:	none
+	comments:	RI stands for Ring Indicator
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isRI)( JNIEnv *env,
 	jobject jobj )
@@ -1849,11 +1908,13 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isRI" );
+	report( "Entering - RXTXPort:isRI\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:isRI returns %i\n", result & TIOCM_RI );
 	report( message );
-	LEAVE( "RXTXPort:isRI" );
+	report( "Leaving - RXTXPort:isRI\n" );
 	if( result & TIOCM_RI ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1861,12 +1922,12 @@
 /*----------------------------------------------------------
 RXTXPort.isRTS
 
-   accept:      none
-   perform:     check status of RTS
-   return:      true if TIOCM_RTS is set
-                false if TIOCM_RTS is not set
-   exceptions:  none
-   comments:    tcgetattr with c_cflag CRTS_IFLOW
+	accept:		none
+	perform:	check status of RTS
+	return:		true if TIOCM_RTS is set
+				false if TIOCM_RTS is not set
+	exceptions:	none
+	comments:	tcgetattr with c_cflag CRTS_IFLOW
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isRTS)( JNIEnv *env,
 	jobject jobj )
@@ -1875,11 +1936,13 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isRTS" );
+	report( "Entering - RXTXPort:isRTS\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "RXTXPort:isRTS returns %i\n", result & TIOCM_RTS );
 	report( message );
-	LEAVE( "RXTXPort:isRTS" );
+	report( "Leaving - RXTXPort:isRTS\n" );
 	if( result & TIOCM_RTS ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1887,13 +1950,13 @@
 /*----------------------------------------------------------
 RXTXPort.setRTS
 
-   accept:      state  flag to set/unset.
-   perform:     depends on the state flag
-                if true TIOCM_RTS is set
-                if false TIOCM_RTS is unset
-   return:      none
-   exceptions:  none
-   comments:    tcsetattr with c_cflag CRTS_IFLOW
+	accept:		state  flag to set/unset.
+	perform:	depends on the state flag
+				if true TIOCM_RTS is set
+				if false TIOCM_RTS is unset
+	return:		none
+	exceptions:	none
+	comments:	tcsetattr with c_cflag CRTS_IFLOW
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setRTS)( JNIEnv *env,
 	jobject jobj, jboolean state )
@@ -1902,27 +1965,29 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:setRTS" );
+	report( "Entering - RXTXPort:setRTS\n" );
 	ioctl( fd, TIOCMGET, &result );
 	if( state == JNI_TRUE ) result |= TIOCM_RTS;
 	else result &= ~TIOCM_RTS;
 	ioctl( fd, TIOCMSET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "setRTS( %i )\n", state );
 	report( message );
-	LEAVE( "RXTXPort:setRTS" );
+	report( "Leaving - RXTXPort:setRTS\n" );
 	return;
 }
 
 /*----------------------------------------------------------
 RXTXPort.setDSR
 
-   accept:      state  flag to set/unset.
-   perform:     depends on the state flag
-                if true TIOCM_DSR is set
-                if false TIOCM_DSR is unset
-   return:      none
-   exceptions:  none
-   comments:    tcsetattr with c_cflag CRTS_IFLOW
+	accept:		state  flag to set/unset.
+	perform:	depends on the state flag
+				if true TIOCM_DSR is set
+				if false TIOCM_DSR is unset
+	return:		none
+	exceptions:	none
+	comments:	tcsetattr with c_cflag CRTS_IFLOW
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setDSR)( JNIEnv *env,
 	jobject jobj, jboolean state )
@@ -1931,28 +1996,31 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:setDSR()" );
+	report( "Entering - RXTXPort:setDSR()\n" );
 	ioctl( fd, TIOCMGET, &result );
 
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "setDSR( %i )\n", state );
 	if( state == JNI_TRUE ) result |= TIOCM_DSR;
 	else result &= ~TIOCM_DSR;
 	ioctl( fd, TIOCMSET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "setDSR( %i )\n", state );
 	report( message );
-	LEAVE( "RXTXPort:setDSR()" );
+	report( "Leaving - RXTXPort:setDSR()\n" );
 	return;
 }
 
 /*----------------------------------------------------------
 RXTXPort.isDTR
 
-   accept:      none
-   perform:     check status of DTR
-   return:      true if TIOCM_DTR is set
-                false if TIOCM_DTR is not set
-   exceptions:  none
-   comments:    DTR stands for Data Terminal Ready
+	accept:		none
+	perform:	check status of DTR
+	return:		true if TIOCM_DTR is set
+				false if TIOCM_DTR is not set
+	exceptions:	none
+	comments:	DTR stands for Data Terminal Ready
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(isDTR)( JNIEnv *env,
 	jobject jobj )
@@ -1961,11 +2029,13 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:isDTR" );
+	report( "Entering - RXTXPort:isDTR\n" );
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "isDTR( ) returns %i\n", result& TIOCM_DTR );
 	report( message );
-	LEAVE( "RXTXPort:isDTR" );
+	report( "Leaving - RXTXPort:isDTR\n" );
 	if( result & TIOCM_DTR ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -1973,12 +2043,12 @@
 /*----------------------------------------------------------
 RXTXPort.setDTR
 
-   accept:      new DTR state
-   perform:     if state is true, TIOCM_DTR is set
-                if state is false, TIOCM_DTR is unset
-   return:      none
-   exceptions:  none
-   comments:    DTR stands for Data Terminal Ready
+	accept:		new DTR state
+	perform:	if state is true, TIOCM_DTR is set
+				if state is false, TIOCM_DTR is unset
+	return:		none
+	exceptions:	none
+	comments:	DTR stands for Data Terminal Ready
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setDTR)( JNIEnv *env,
 	jobject jobj, jboolean state )
@@ -1987,32 +2057,35 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	char message[80];
 
-	ENTER( "RXTXPort:setDTR" );
+	report( "Entering - RXTXPort:setDTR\n" );
 	ioctl( fd, TIOCMGET, &result );
 	if( state == JNI_TRUE ) result |= TIOCM_DTR;
 	else result &= ~TIOCM_DTR;
 	ioctl( fd, TIOCMSET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "setDTR( %i )\n", state );
 	report( message );
-	LEAVE( "RXTXPort:setDTR" );
+	report( "Leaving - RXTXPort:setDTR\n" );
 	return;
 }
 /*----------------------------------------------------------
 RXTXPort.static_add_filename
 
-   accept:      filename and fd to save
-   perform:     add a struct holding the info to a linked list
-   return:      none
-   exceptions:  none
-   comments:    the info is checked on open() if its in the list no
-		changes are performed on the file on open()
-
-   comments:    see
-			RXTXPort.nativeStaticSetDSR
-			RXTXPort.nativeStaticSetDTR
-			RXTXPort.nativeStaticSetRTS
-			RXTXPort.nativeStaticSetSerialPortParams
-		This is used so people can setDTR low before calling the
+	accept:		filename and fd to save
+	perform:	add a struct holding the info to a linked list
+	return:		none
+	exceptions:	none
+	comments:	the info is checked on open() if its in the list no
+				changes are performed on the file on open()
+
+	comments:	see
+				RXTXPort.nativeStaticSetDSR
+				RXTXPort.nativeStaticSetDTR
+				RXTXPort.nativeStaticSetRTS
+				RXTXPort.nativeStaticSetSerialPortParams
+				
+	This is used so people can setDTR low before calling the
 -----------------------------------------------------------*/
 
 void static_add_filename( const char *filename, int fd)
@@ -2055,14 +2128,14 @@
 /*----------------------------------------------------------
 RXTXPort.nativeSetBaudBase
 
-   accept:      The Baud Base for custom speeds
-   perform:     set the Baud Base
-   return:      0 on success
-   exceptions:  Unsupported Comm Operation on systems not supporting
-                TIOCGSERIAL
-   comments:
-		Set baud rate to 38400 before using this
-		First introduced in rxtx-2.1-3
+	accept:		The Baud Base for custom speeds
+	perform:	set the Baud Base
+	return:		0 on success
+	exceptions:	Unsupported Comm Operation on systems not supporting
+				TIOCGSERIAL
+	comments:
+				Set baud rate to 38400 before using this
+				First introduced in rxtx-2.1-3
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeSetBaudBase)(
 	JNIEnv *env,
@@ -2103,13 +2176,13 @@
 /*----------------------------------------------------------
 RXTXPort.nativeGetBaudBase
 
-   accept:      the Baud Base used for custom speeds
-   perform:
-   return:      Baud Base
-   exceptions:  Unsupported Comm Operation on systems not supporting
-                TIOCGSERIAL
-   comments:
-		First introduced in rxtx-2.1-3
+	accept:		the Baud Base used for custom speeds
+	perform:
+	return:		Baud Base
+	exceptions:	Unsupported Comm Operation on systems not supporting
+				TIOCGSERIAL
+	comments:
+				First introduced in rxtx-2.1-3
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeGetBaudBase)(
 	JNIEnv *env,
@@ -2141,14 +2214,14 @@
 /*----------------------------------------------------------
 RXTXPort.nativeSetDivisor
 
-   accept:      Divisor for custom speeds
-   perform:     set the Divisor for custom speeds
-   return:      0 on success
-   exceptions:  Unsupported Comm Operation on systems not supporting
-                TIOCGSERIAL
-   comments:
-		Set baud rate to 38400 before using this
-		First introduced in rxtx-2.1-3
+	accept:		Divisor for custom speeds
+	perform:	set the Divisor for custom speeds
+	return:		0 on success
+	exceptions:	Unsupported Comm Operation on systems not supporting
+				TIOCGSERIAL
+	comments:
+				Set baud rate to 38400 before using this
+				First introduced in rxtx-2.1-3
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeSetDivisor)(
 	JNIEnv *env,
@@ -2187,13 +2260,13 @@
 /*----------------------------------------------------------
 RXTXPort.nativeGetDivisor
 
-   accept:      none
-   perform:     Find the Divisor used for custom speeds
-   return:      Divisor negative value on error.
-   exceptions:  Unsupported Comm Operation on systems not supporting
-	        TIOCGSERIAL
-   comments:
-		First introduced in rxtx-2.1-3
+	accept:		none
+	perform:	Find the Divisor used for custom speeds
+	return:		Divisor negative value on error.
+	exceptions:	Unsupported Comm Operation on systems not supporting
+				TIOCGSERIAL
+	comments:
+				First introduced in rxtx-2.1-3
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeGetDivisor)(
 	JNIEnv *env,
@@ -2226,18 +2299,18 @@
 /*----------------------------------------------------------
 RXTXPort.nativeStaticSetDSR
 
-   accept:      new RTS state
-   perform:     if flag is true, TIOCM_DSR is set
-                if flag is false, TIOCM_DSR is unset
-   return:      none
-   exceptions:  none
-   comments:    Set the DSR so it does not raise on the next open
-		needed for some funky test boards?
+	accept:		new RTS state
+	perform:	if flag is true, TIOCM_DSR is set
+				if flag is false, TIOCM_DSR is unset
+	return:		none
+	exceptions:	none
+	comments:	Set the DSR so it does not raise on the next open
+				needed for some funky test boards?
 
-		This is static so we can not call the open() setDSR()
-		we dont have the jobject.
+			This is static so we can not call the open() setDSR()
+			we dont have the jobject.
 
-		First introduced in rxtx-1.5-9
+			First introduced in rxtx-1.5-9
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticSetDSR) (JNIEnv *env,
 	jclass jclazz, jstring jstr, jboolean flag)
@@ -2247,7 +2320,7 @@
 	int result;
 	const char *filename = (*env)->GetStringUTFChars( env, jstr, 0 );
 
-	ENTER( "RXTXPort:nativeStaticSetDSR" );
+	report( "Entering - RXTXPort:nativeStaticSetDSR\n" );
 #ifndef WIN32
 	pid = getpid();
 #endif /* WIN32 */
@@ -2281,29 +2354,29 @@
 
 	/* dont close the port.  Its not clear if the DSR would remain high */
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetDSR" );
+	report( "Leaving - RXTXPort:nativeStaticSetDSR\n" );
 	return( JNI_TRUE );
 fail:
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetDSR" );
+	report( "Leaving - RXTXPort:nativeStaticSetDSR\n" );
 	return( JNI_FALSE );
 }
 
 /*----------------------------------------------------------
 RXTXPort.nativeStaticSetRTS
 
-   accept:      new RTS state
-   perform:     if flag is true, TIOCM_RTS is set
-                if flag is false, TIOCM_RTS is unset
-   return:      none
-   exceptions:  none
-   comments:    Set the RTS so it does not raise on the next open
-		needed for some funky test boards?
-
-		This is static so we can not call the open() setDTR()
-		we dont have the jobject.
-
-		First introduced in rxtx-1.5-9
+	accept:		new RTS state
+	perform:	if flag is true, TIOCM_RTS is set
+				if flag is false, TIOCM_RTS is unset
+	return:		none
+	exceptions:	none
+	comments:	Set the RTS so it does not raise on the next open
+				needed for some funky test boards?
+
+				This is static so we can not call the open() setDTR()
+				we dont have the jobject.
+				
+				First introduced in rxtx-1.5-9
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticSetRTS) (JNIEnv *env,
 	jclass jclazz, jstring jstr, jboolean flag)
@@ -2313,7 +2386,7 @@
 	int result;
 	const char *filename = (*env)->GetStringUTFChars( env, jstr, 0 );
 
-	ENTER( "RXTXPort:nativeStaticSetRTS" );
+	report( "Entering - RXTXPort:nativeStaticSetRTS\n" );
 #ifndef WIN32
 	pid = getpid();
 #endif /* WIN32 */
@@ -2347,29 +2420,29 @@
 
 	/* dont close the port.  Its not clear if the RTS would remain high */
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetRTS" );
+	report( "Leaving - RXTXPort:nativeStaticSetRTS\n" );
 	return( JNI_TRUE );
 fail:
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetRTS" );
+	report( "Leaving - RXTXPort:nativeStaticSetRTS\n" );
 	return( JNI_FALSE );
 }
 
 /*----------------------------------------------------------
 RXTXPort.nativeStaticSetSerialPortParams
 
-   accept:      string for the filename, int baudrate, int databits,
-		int stopbits, int parity
-   perform:     set the serial port, set the params, save the fd in a linked
+	accept:		string for the filename, int baudrate, int databits,
+				int stopbits, int parity
+	perform:	set the serial port, set the params, save the fd in a linked
 		list.
-   return:      none
-   exceptions:  none
-   comments:    Not set the speed on the next 'open'
+	return:		none
+	exceptions:	none
+	comments:	Not set the speed on the next 'open'
 
-		This is static so we can not call the open() setDTR()
-		we dont have the jobject.
+				This is static so we can not call the open() setDTR()
+				we dont have the jobject.
 
-		First introduced in rxtx-1.5-9
+				First introduced in rxtx-1.5-9
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(nativeStaticSetSerialPortParams) (JNIEnv *env,
 	jclass jclazz, jstring jstr, jint baudrate, jint dataBits, jint stopBits, jint parity )
@@ -2380,7 +2453,7 @@
 	int cspeed = translate_speed( env, baudrate );
 
 
-	ENTER( "RXTXPort:nativeStaticSetSerialPortParams" );
+	report( "Entering - RXTXPort:nativeStaticSetSerialPortParams\n" );
 #ifndef WIN32
 	pid = getpid();
 #endif /* WIN32 */
@@ -2400,7 +2473,7 @@
 	if ( fd < 0 )
 	{
 		(*env)->ReleaseStringUTFChars( env, jstr, filename );
-		LEAVE( "RXTXPort:nativeStaticSetSerialPortParams" );
+		report( "Leaving - RXTXPort:nativeStaticSetSerialPortParams\n" );
 		throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 			"nativeStaticSetSerialPortParams", strerror( errno ) );
 		return;
@@ -2410,14 +2483,14 @@
 	{
 		(*env)->ReleaseStringUTFChars( env, jstr, filename );
 		throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
-			"", "BaudRate could not be set to the specified value" );
+			"", "BaudRate could not be set to the specified value\n" );
 		return;
 	}
 
 	if( set_port_params( env, fd, cspeed, dataBits, stopBits, parity ) )
 	{
 		(*env)->ReleaseStringUTFChars( env, jstr, filename );
-		LEAVE( "RXTXPort:nativeStatic SetSerialPortParams" );
+		report( "Leaving - RXTXPort:nativeStatic SetSerialPortParams\n" );
 		throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 			"nativeStaticSetSerialPortParams", strerror( errno ) );
 		return;
@@ -2431,29 +2504,29 @@
 	/* dont close the port. */
 
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetSerialPortParams" );
+	report( "Leaving - RXTXPort:nativeStaticSetSerialPortParams\n" );
 	return;
 fail:
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetSerialPortParams" );
+	report( "Leaving - RXTXPort:nativeStaticSetSerialPortParams\n" );
 	return;
 }
 
 /*----------------------------------------------------------
 RXTXPort.nativeStaticSetDTR
 
-   accept:      new DTR state
-   perform:     if flag is true, TIOCM_DTR is set
-                if flag is false, TIOCM_DTR is unset
-   return:      none
-   exceptions:  none
-   comments:    Set the DTR so it does not raise on the next open
-		needed for some funky test boards?
-
-		This is static so we can not call the open() setDTR()
-		we dont have the jobject.
-
-		First introduced in rxtx-1.5-9
+	accept:		new DTR state
+	perform:	if flag is true, TIOCM_DTR is set
+				if flag is false, TIOCM_DTR is unset
+	return:		none
+	exceptions:	none
+	comments:	Set the DTR so it does not raise on the next open
+				needed for some funky test boards?
+				
+				This is static so we can not call the open() setDTR()
+				we dont have the jobject.
+				
+				First introduced in rxtx-1.5-9
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticSetDTR) (JNIEnv *env,
 	jclass jclazz, jstring jstr, jboolean flag)
@@ -2463,7 +2536,7 @@
 	const char *filename = (*env)->GetStringUTFChars( env, jstr, 0 );
 	int result;
 
-	ENTER( "RXTXPort:nativeStaticSetDTR" );
+	report( "Entering - RXTXPort:nativeStaticSetDTR\n" );
 #ifndef WIN32
 	pid = getpid();
 #endif /* WIN32 */
@@ -2497,24 +2570,24 @@
 	/* dont close the port.  Its not clear if the DTR would remain high */
 
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetDTR" );
+	report( "Leaving - RXTXPort:nativeStaticSetDTR\n" );
 	return( JNI_TRUE );
 fail:
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
-	LEAVE( "RXTXPort:nativeStaticSetDTR" );
+	report( "Leaving - RXTXPort:nativeStaticSetDTR\n" );
 	return( JNI_FALSE );
 }
 
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsRTS
 
-   accept:      filename
-   perform:     check status of RTS of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_RTS is set
-                false if TIOCM_RTS is not set
-   exceptions:  none
-   comments:    RTS stands for Request to Send
+	accept:		filename
+	perform:	check status of RTS of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_RTS is set
+				false if TIOCM_RTS is not set
+	exceptions:	none
+	comments:	RTS stands for Request to Send
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsRTS)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2524,29 +2597,31 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsRTS" );
+	report( "Entering - RXTXPort:nativeStaticIsRTS\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticIsRTS( ) returns %i\n", result& TIOCM_RTS );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsRTS" );
+	report( "Leaving - RXTXPort:nativeStaticIsRTS\n" );
 	if( result & TIOCM_RTS ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsDSR
 
-   accept:      filename
-   perform:     check status of DSR of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_DSR is set
-                false if TIOCM_DSR is not set
-   exceptions:  none
-   comments:
+	accept:		filename
+	perform:	check status of DSR of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_DSR is set
+				false if TIOCM_DSR is not set
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsDSR)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2556,29 +2631,31 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsDSR" );
+	report( "Entering - RXTXPort:nativeStaticIsDSR\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticIsDSR( ) returns %i\n", result& TIOCM_DSR );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsDSR" );
+	report( "Leaving - RXTXPort:nativeStaticIsDSR\n" );
 	if( result & TIOCM_DSR ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsDTR
 
-   accept:      filename
-   perform:     check status of DTR of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_DTR is set
-                false if TIOCM_DTR is not set
-   exceptions:  none
-   comments:    DTR stands for Data Terminal Ready
+	accept:		filename
+	perform:	check status of DTR of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_DTR is set
+				false if TIOCM_DTR is not set
+	exceptions:	none
+	comments:	DTR stands for Data Terminal Ready
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsDTR)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2588,29 +2665,31 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsDTR" );
+	report( "Entering - RXTXPort:nativeStaticIsDTR\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticIsDTR( ) returns %i\n", result& TIOCM_DTR );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsDTR" );
+	report( "Leaving - RXTXPort:nativeStaticIsDTR\n" );
 	if( result & TIOCM_DTR ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsCD
 
-   accept:      filename
-   perform:     check status of CD of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_CD is set
-                false if TIOCM_CD is not set
-   exceptions:  none
-   comments:    CD stands for carrier detect
+	accept:		filename
+	perform:	check status of CD of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_CD is set
+				false if TIOCM_CD is not set
+	exceptions:	none
+	comments:	CD stands for carrier detect
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsCD)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2620,29 +2699,31 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsCD" );
+	report( "Entering - RXTXPort:nativeStaticIsCD\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticIsCD( ) returns %i\n", result& TIOCM_CD );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsCD" );
+	report( "Leaving - RXTXPort:nativeStaticIsCD\n" );
 	if( result & TIOCM_CD ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsCTS
 
-   accept:      filename
-   perform:     check status of CTS of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_CTS is set
-                false if TIOCM_CTS is not set
-   exceptions:  none
-   comments:    CTS stands for Clear To Send
+	accept:		filename
+	perform:	check status of CTS of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_CTS is set
+				false if TIOCM_CTS is not set
+	exceptions:	none
+	comments:	CTS stands for Clear To Send
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsCTS)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2652,29 +2733,31 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsCTS" );
+	report( "Entering - RXTXPort:nativeStaticIsCTS\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticIsCTS( ) returns %i\n", result& TIOCM_CTS );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsCTS" );
+	report( "Leaving - RXTXPort:nativeStaticIsCTS\n" );
 	if( result & TIOCM_CTS ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticIsRI
 
-   accept:      filename
-   perform:     check status of RI of preopened ports (setting lines/params
-		before calling the Java open()
-   return:      true if TIOCM_RI is set
-                false if TIOCM_RI is not set
-   exceptions:  none
-   comments:    RI stands for carrier detect
+	accept:		filename
+	perform:	check status of RI of preopened ports (setting lines/params
+				before calling the Java open()
+	return:		true if TIOCM_RI is set
+				false if TIOCM_RI is not set
+	exceptions:	none
+	comments:	RI stands for carrier detect
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeStaticIsRI)( JNIEnv *env,
 	jobject jobj, jstring jstr )
@@ -2684,16 +2767,18 @@
 	int fd = find_preopened_ports( filename );
 	char message[80];
 
-	ENTER( "RXTXPort:nativeStaticIsRI" );
+	report( "Entering - RXTXPort:nativeStaticIsRI\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
 		return JNI_FALSE;
 	}
 	ioctl( fd, TIOCMGET, &result );
+	
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "nativeStaticRI( ) returns %i\n", result& TIOCM_RI );
 	report( message );
-	LEAVE( "RXTXPort:nativeStaticIsRI" );
+	report( "Leaving - RXTXPort:nativeStaticIsRI\n" );
 	if( result & TIOCM_RI ) return JNI_TRUE;
 	else return JNI_FALSE;
 }
@@ -2701,11 +2786,11 @@
 /*----------------------------------------------------------
 RXTXPort.nativeStaticGetBaudRate
 
-   accept:      filename
-   perform:     find the baud rate (not all buads are handled yet)
-   return:      return the baud rate or -1 if not supported yet.
-   exceptions:
-   comments:    simple test for preopened ports
+	accept:		filename
+	perform:	find the baud rate (not all buads are handled yet)
+	return:		return the baud rate or -1 if not supported yet.
+	exceptions:
+	comments:	simple test for preopened ports
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeStaticGetBaudRate)( JNIEnv *env, jobject jobj, jstring jstr )
 {
@@ -2715,7 +2800,7 @@
 	int baudrate;
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
 
-	ENTER( "RXTXPort:nativeStaticGetBaudRate" );
+	report( "Entering - RXTXPort:nativeStaticGetBaudRate\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
@@ -2743,21 +2828,21 @@
 
 */
 #if defined(CBAUD)/* dima */
-    	baudrate = ttyset.c_cflag&CBAUD;
+		baudrate = ttyset.c_cflag&CBAUD;
 #else
-    	if(cfgetispeed(&ttyset) != cfgetospeed(&ttyset)) return -1;
-    	baudrate = cfgetispeed(&ttyset);
+		if(cfgetispeed(&ttyset) != cfgetospeed(&ttyset)) return -1;
+		baudrate = cfgetispeed(&ttyset);
 #endif
 	return( get_java_baudrate(baudrate) );
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticGetDataBits
 
-   accept:      filename
-   perform:     find the data bits (not all buads are handled yet)
-   return:      return the data bits
-   exceptions:
-   comments:    simple test for preopened ports
+	accept:		filename
+	perform:	find the data bits (not all buads are handled yet)
+	return:		return the data bits
+	exceptions:
+	comments:	simple test for preopened ports
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeStaticGetDataBits)( JNIEnv *env, jobject jobj, jstring jstr )
 {
@@ -2766,7 +2851,7 @@
 	struct termios ttyset;
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
 
-	ENTER( "RXTXPort:nativeStaticGetDataBits" );
+	report( "Entering - RXTXPort:nativeStaticGetDataBits\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
@@ -2778,21 +2863,21 @@
 		return(-1);
 	}
 	switch( ttyset.c_cflag&CSIZE ) {
-		case CS5:  return JDATABITS_5;
-		case CS6:  return JDATABITS_6;
-		case CS7:  return JDATABITS_7;
-		case CS8:  return JDATABITS_8;
-		default:  return(-1);
+		case CS5:	return JDATABITS_5;
+		case CS6:	return JDATABITS_6;
+		case CS7:	return JDATABITS_7;
+		case CS8:	return JDATABITS_8;
+		default:	return(-1);
 	}
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticGetParity
 
-   accept:      filename
-   perform:     find the parity
-   return:      return the parity
-   exceptions:
-   comments:    simple test for preopened ports
+	accept:		filename
+	perform:	find the parity
+	return:		return the parity
+	exceptions:
+	comments:	simple test for preopened ports
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeStaticGetParity)( JNIEnv *env, jobject jobj, jstring jstr )
 {
@@ -2801,7 +2886,7 @@
 	struct termios ttyset;
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
 
-	ENTER( "RXTXPort:nativeStaticGetParity" );
+	report( "Entering - RXTXPort:nativeStaticGetParity\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
@@ -2824,17 +2909,17 @@
 		case PARENB | PARODD | CMSPAR: return JPARITY_MARK;
 		case PARENB | CMSPAR: return JPARITY_SPACE;
 #endif /* CMSPAR */
-		default:  return(-1);
+		default:	return(-1);
 	}
 }
 /*----------------------------------------------------------
 RXTXPort.nativeStaticGetStopBits
 
-   accept:      filename
-   perform:     find the stop bits
-   return:      return the stop bits
-   exceptions:
-   comments:    simple test for preopened ports
+	accept:		filename
+	perform:	find the stop bits
+	return:		return the stop bits
+	exceptions:
+	comments:	simple test for preopened ports
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeStaticGetStopBits)( JNIEnv *env, jobject jobj, jstring jstr )
 {
@@ -2843,7 +2928,7 @@
 	struct termios ttyset;
 	(*env)->ReleaseStringUTFChars( env, jstr, filename );
 
-	ENTER( "RXTXPort:nativeStaticGetStopBits" );
+	report( "Entering - RXTXPort:nativeStaticGetStopBits\n" );
 	if( !fd )
 	{
 		/* Exception? FIXME */
@@ -2872,46 +2957,46 @@
 /*----------------------------------------------------------
 RXTXPort.nativeGetParityErrorChar
 
-   accept:      -
-   perform:     check the ParityErrorChar
-   return:      The ParityErrorChar as an jbyte.
-   exceptions:  UnsupportedCommOperationException if not implemented
-   comments:    It appears the Parity char is usually \0.  The windows
-		API allows for this to be changed.  I cant find may
-		examples of this being done.  Maybe for a reason.
-
-		Use a direct call to the termios file until we find a
-		solution.
+	accept:	-
+	perform:	check the ParityErrorChar
+	return:		The ParityErrorChar as an jbyte.
+	exceptions:	UnsupportedCommOperationException if not implemented
+	comments:	It appears the Parity char is usually \0.  The windows
+				API allows for this to be changed.  I cant find may
+				examples of this being done.  Maybe for a reason.
+				
+				Use a direct call to the termios file until we find a
+				solution.
 ----------------------------------------------------------*/
 JNIEXPORT jbyte JNICALL RXTXPort(nativeGetParityErrorChar)( JNIEnv *env,
 	jobject jobj )
 {
 	unsigned int result = 0;
 
-	ENTER( "nativeGetParityErrorChar" );
+	report( "Entering - nativeGetParityErrorChar\n" );
 #ifdef WIN32
 	result = ( jbyte ) termiosGetParityErrorChar(
 			get_java_var(env, jobj, "fd", "I" ) );
 #else
 	/*
-	   arg!  I cant find a way to change it from \0 in Linux.  I think
-		   the frame and parity error characters are hardcoded.
+		arg!  I cant find a way to change it from \0 in Linux.  I think
+			the frame and parity error characters are hardcoded.
 	*/
 		result = ( jint ) '\0';
 
 #endif /* WIN32 */
-	LEAVE( "nativeGetParityErrorChar" );
+	report( "Leaving - nativeGetParityErrorChar\n" );
 	return( ( jbyte ) result );
 }
 
 /*----------------------------------------------------------
 RXTXPort.nativeGetEndOfInputChar
 
-   accept:      -
-   perform:     check the EndOf InputChar
-   return:      the EndOfInputChar as an jbyte.  -1 on error
-   exceptions:  UnsupportedCommOperationException if not implemented
-   comments:
+	accept:		-
+	perform:	check the EndOf InputChar
+	return:		the EndOfInputChar as an jbyte.  -1 on error
+	exceptions:	UnsupportedCommOperationException if not implemented
+	comments:
 ----------------------------------------------------------*/
 JNIEXPORT jbyte JNICALL RXTXPort(nativeGetEndOfInputChar)( JNIEnv *env,
 	jobject jobj )
@@ -2919,12 +3004,12 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	struct termios ttyset;
 
-	ENTER( "nativeGetEndOfInputChar" );
+	report( "Entering - nativeGetEndOfInputChar\n" );
 	if( tcgetattr( fd, &ttyset ) < 0 ) goto fail;
-	LEAVE( "nativeGetEndOfInputChar" );
+	report( "Leaving - nativeGetEndOfInputChar" );
 	return( (jbyte) ttyset.c_cc[VEOF] );
 fail:
-	LEAVE( "nativeGetEndOfInputChar" );
+	report( "Leaving - nativeGetEndOfInputChar\n" );
 	report( "nativeGetEndOfInputChar failed\n" );
 	return( ( jbyte ) -1 );
 }
@@ -2932,16 +3017,16 @@
 /*----------------------------------------------------------
 RXTXPort.nativeSetParityErrorChar
 
-   accept:      the ParityArrorCharacter as an int.
-   perform:     Set the ParityErrorChar
-   return:      JNI_TRUE on success
-   exceptions:  UnsupportedCommOperationException if not implemented
-   comments:    It appears the Parity char is usually \0.  The windows
-		API allows for this to be changed.  I cant find may
-		examples of this being done.  Maybe for a reason.
+	accept:		the ParityArrorCharacter as an int.
+	perform:	Set the ParityErrorChar
+	return:		JNI_TRUE on success
+	exceptions:	UnsupportedCommOperationException if not implemented
+	comments:	It appears the Parity char is usually \0.  The windows
+				API allows for this to be changed.  I cant find may
+				examples of this being done.  Maybe for a reason.
 
-		Use a direct call to the termios file until we find a
-		solution.
+				Use a direct call to the termios file until we find a
+				solution.
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeSetParityErrorChar)( JNIEnv *env,
 	jobject jobj, jbyte value )
@@ -2949,21 +3034,21 @@
 
 #ifdef WIN32
 		int fd = get_java_var( env, jobj,"fd","I" );
-		ENTER( "nativeSetParityErrorChar" );
+		report( "Entering - nativeSetParityErrorChar\n" );
 		termiosSetParityError( fd, ( char ) value );
-		LEAVE( "nativeSetParityErrorChar" );
+		report( "Leaving - nativeSetParityErrorChar\n" );
 		return( JNI_TRUE );
 #else
-		ENTER( "nativeSetParityErrorChar" );
+		report( "Entering - nativeSetParityErrorChar\n" );
 	/*
-	   arg!  I cant find a way to change it from \0 in Linux.  I think
-	   the frame and parity error characters are hardcoded.
+		arg!  I cant find a way to change it from \0 in Linux.  I think
+		the frame and parity error characters are hardcoded.
 	*/
 
 	throw_java_exception( env, UNSUPPORTED_COMM_OPERATION,
 		"Not implemented... yet",
 		strerror( errno ) );
-	LEAVE( "nativeSetParityErrorChar" );
+	report( "Leaving - nativeSetParityErrorChar\n" );
 	return( JNI_FALSE );
 #endif /* WIN32 */
 }
@@ -2971,17 +3056,17 @@
 /*----------------------------------------------------------
 RXTXPort.nativeSetEndOfInputChar
 
-   accept:      The EndOfInputChar as an int
-   perform:     set the EndOfInputChar
-   return:      JNI_TRUE on success
-   exceptions:  UnsupportedCommOperationException if not implemented
-   comments:    This may cause troubles on Windows.
-		Lets give it a shot and see what happens.
+	accept:		The EndOfInputChar as an int
+	perform:	set the EndOfInputChar
+	return:		JNI_TRUE on success
+	exceptions:	UnsupportedCommOperationException if not implemented
+	comments:	This may cause troubles on Windows.
+				Lets give it a shot and see what happens.
 
-		See termios.c for the windows bits.
+				See termios.c for the windows bits.
 
-		EofChar = val;
-		fBinary = false;  winapi docs say always use true. ?
+				EofChar = val;
+				fBinary = false;  winapi docs say always use true. ?
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeSetEndOfInputChar)( JNIEnv *env,
 	jobject jobj, jbyte value )
@@ -2989,17 +3074,17 @@
 	int fd = get_java_var( env, jobj,"fd","I" );
 	struct termios ttyset;
 
-	ENTER( "nativeSetEndOfInputChar" );
+	report( "Entering - nativeSetEndOfInputChar\n" );
 	if( tcgetattr( fd, &ttyset ) < 0 ) goto fail;
 	ttyset.c_cc[VEOF] = ( char ) value;
 	if( tcsetattr( fd, TCSANOW, &ttyset ) < 0 ) goto fail;
-	LEAVE( "nativeSetEndOfInputChar" );
+	report( "Leaving - nativeSetEndOfInputChar\n" );
 	return( JNI_TRUE );
 fail:
 	throw_java_exception( env, IO_EXCEPTION, "nativeSetEndOfInputChar",
 		strerror( errno ) );
 	report( "nativeSetEndOfInputChar failed\n" );
-	LEAVE( "nativeSetEndOfInputChar" );
+	report( "Leaving - nativeSetEndOfInputChar\n" );
 	return( JNI_FALSE );
 }
 
@@ -3025,28 +3110,31 @@
 /*----------------------------------------------------------
 read_byte_array
 
-   accept:      int                fd   file descriptor to read from
-                unsigned char *buffer   buffer to read data into
-                int            length   number of bytes to read
-		int           timeout   milliseconds to wait before returning
-   perform:     read bytes from the port into a buffer
-   return:      status of read
-                -1 fail (IOException)
-                 0 timeout
-                >0 number of bytes read
-   comments:    According to the Communications API spec, a receive threshold
-                of 1 is the same as having the threshold disabled.
-
-		The nuts and bolts are documented in
-		NativeEnableReceiveTimeoutThreshold()
-----------------------------------------------------------*/
-
-int read_byte_array( JNIEnv *env,
-                     jobject *jobj,
-                     int fd,
-                     unsigned char *buffer,
-                     int length,
-                     int timeout )
+	accept:		int 			fd		file descriptor to read from
+				unsigned char 	*buffer	buffer to read data into
+				int				length	number of bytes to read
+				int				timeout	milliseconds to wait
+	perform:	read bytes from the port into a buffer
+	return:		status of read
+				-1 fail (IOException)
+				0 timeout
+				>0 number of bytes read
+	comments:	According to the Communications API spec, a receive
+				threshold of 1 is the same as having the threshold
+				disabled.
+
+				The nuts and bolts are documented in
+				NativeEnableReceiveTimeoutThreshold()
+----------------------------------------------------------*/
+
+int read_byte_array( 
+	JNIEnv *env,
+	jobject *jobj,
+	int fd,
+	unsigned char *buffer,
+	int length,
+	int timeout
+)
 {
 	int ret, left, bytes = 0;
 	long timeLeft, now = 0, start = 0;
@@ -3062,7 +3150,8 @@
 	flag = eis->eventflags[SPE_DATA_AVAILABLE];
 	eis->eventflags[SPE_DATA_AVAILABLE] = 0;
 /*
-	ENTER( "read_byte_array" );
+	report( "Entering - read_byte_array\n" );
+	memset(&message[0], 0, sizeof(message));
 	sprintf(msg, "read_byte_array requests %i\n", length);
 	report( msg );
 */
@@ -3102,7 +3191,7 @@
 #endif /* WIN32 */
 		if (ret == -1){
 			report( "read_byte_array: select returned -1\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			eis->eventflags[SPE_DATA_AVAILABLE] = flag;
 			return -1;
 		}
@@ -3111,7 +3200,7 @@
 			if ((ret = READ( fd, buffer + bytes, left )) < 0 ){
 				if (errno != EINTR && errno != EAGAIN){
 					report( "read_byte_array: read returned -1\n" );
-					LEAVE( "read_byte_array" );
+					report( "Leaving - read_byte_array\n" );
 					eis->eventflags[SPE_DATA_AVAILABLE] = flag;
 					return -1;
 				}
@@ -3146,9 +3235,10 @@
 			"No data available" );
 	}
 
+	memset(&message[0], 0, sizeof(message));
 	sprintf(msg, "read_byte_array returns %i\n", bytes);
 	report( msg );
-	LEAVE( "read_byte_array" );
+	report( "Leaving - read_byte_array\n" );
 	report_time_end();
 */
 	eis->eventflags[SPE_DATA_AVAILABLE] = flag;
@@ -3168,7 +3258,8 @@
 	char msg[80];
 
 	report_time_start();
-	ENTER( "read_byte_array" );
+	report( "Entering - read_byte_array\n" );
+	memset(&message[0], 0, sizeof(message));
 	sprintf(msg, "read_byte_array requests %i\n", length);
 	report( msg );
 	left = length;
@@ -3186,15 +3277,16 @@
 			if (errno == EINTR)
 				goto RETRY;
 			report( "read_byte_array: read returned -1\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			return -1;
 		}
 		bytes += ret;
 		left -= ret;
 	}
+	memset(&message[0], 0, sizeof(message));
 	sprintf(msg, "read_byte_array returns %i\n", bytes);
 	report( msg );
-	LEAVE( "read_byte_array" );
+	report( "Leaving - read_byte_array\n" );
 	report_time_end();
 	return bytes;
 }
@@ -3217,7 +3309,7 @@
 	struct timeval *psleep=&sleep;
 #endif /* WIN32 */
 
-	ENTER( "read_byte_array" );
+	report( "Entering - read_byte_array\n" );
 	left = length;
 	FD_ZERO( &rfds );
 	FD_SET( fd, &rfds );
@@ -3228,10 +3320,10 @@
 	}
 	while( bytes < length )
 	{
-         /* FIXME: In Linux, select updates the timeout automatically, so
-            other OSes will need to update it manually if they want to have
-            the same behavior.  For those OSes, timeouts will occur after no
-            data AT ALL is received for the timeout duration.  No big deal. */
+		/* FIXME: In Linux, select updates the timeout automatically, so
+		other OSes will need to update it manually if they want to have
+		the same behavior.  For those OSes, timeouts will occur after no
+		data AT ALL is received for the timeout duration.  No big deal. */
 #ifndef WIN32
 		do {
 			if( timeout == 0 ) psleep = NULL;
@@ -3239,9 +3331,9 @@
 		}  while (ret < 0 && errno==EINTR);
 #else
 		/*
-		    the select() needs some work before the above will
-		    work on win32.  The select code cannot be accessed
-		    from both the Monitor Thread and the Reading Thread.
+			the select() needs some work before the above will
+			work on win32.  The select code cannot be accessed
+			from both the Monitor Thread and the Reading Thread.
 
 		*/
 		ret = RXTXPort(nativeavailable)( env, *jobj );
@@ -3249,44 +3341,44 @@
 		if( ret == 0 )
 		{
 			report( "read_byte_array: select returned 0\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			break;
 		}
 		if( ret < 0 )
 		{
 			report( "read_byte_array: select returned -1\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			return -1;
 		}
 		ret = READ( fd, buffer + bytes, left );
 		if( ret == 0 )
 		{
 			report( "read_byte_array: read returned 0 bytes\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			break;
 		}
 		else if( ret < 0 )
 		{
 			report( "read_byte_array: read returned -1\n" );
-			LEAVE( "read_byte_array" );
+			report( "Leaving - read_byte_array\n" );
 			return -1;
 		}
 		bytes += ret;
 		left -= ret;
 	}
-	LEAVE( "read_byte_array" );
+	report( "Leaving - read_byte_array\n" );
 	return bytes;
 }
 #endif /* asdf */
 
 /*----------------------------------------------------------
 NativeEnableReceiveTimeoutThreshold
-   accept:      int  threshold, int vtime,int buffer
-   perform:     Set c_cc->VMIN to threshold and c_cc=>VTIME to vtime
-   return:      void
-   exceptions:  IOException
-   comments:    This is actually all handled in read with select in
-                canonical input mode.
+	accept:		int  threshold, int vtime,int buffer
+	perform:	Set c_cc->VMIN to threshold and c_cc=>VTIME to vtime
+	return:		void
+	exceptions:	IOException
+	comments:	This is actually all handled in read with select in
+				canonical input mode.
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(NativeEnableReceiveTimeoutThreshold)(
 	JNIEnv *env, jobject jobj, jint vtime, jint threshold, jint buffer)
@@ -3305,16 +3397,16 @@
 		timeout = vtime;
 	}
 
-	ENTER( "RXTXPort:NativeEnableRecieveTimeoutThreshold" );
+	report( "Entering - RXTXPort:NativeEnableRecieveTimeoutThreshold\n" );
 	if( tcgetattr( fd, &ttyset ) < 0 ) goto fail;
 	ttyset.c_cc[ VMIN ] = threshold;
 	ttyset.c_cc[ VTIME ] = timeout/100;
 	if( tcsetattr( fd, TCSANOW, &ttyset ) < 0 ) goto fail;
 
-	LEAVE( "RXTXPort:NativeEnableRecieveTimeoutThreshold" );
+	report( "Leaving - RXTXPort:NativeEnableRecieveTimeoutThreshold\n" );
 	return;
 fail:
-	LEAVE( "RXTXPort:NativeEnableRecieveTimeoutThreshold" );
+	report( "Leaving - RXTXPort:NativeEnableRecieveTimeoutThreshold\n" );
 	throw_java_exception( env, IO_EXCEPTION, "TimeoutThreshold",
 		strerror( errno ) );
 	return;
@@ -3323,16 +3415,16 @@
 /*----------------------------------------------------------
 RXTXPort.readByte
 
-   accept:      none
-   perform:     Read a single byte from the port.  Block unless an exeption
-	        is thrown, or end of stream.
-   return:      The byte read
-   exceptions:  IOException
-   comments:
+	accept:		none
+	perform:	Read a single byte from the port.  Block unless an exeption
+				is thrown, or end of stream.
+	return:		The byte read
+	exceptions:	IOException
+	comments:
 
-On Fri, 30 Aug 2002, Bill Smith wrote:
+	On Fri, 30 Aug 2002, Bill Smith wrote:
 
-I agree, the documentation isn't the best. No surprises there.
+	I agree, the documentation isn't the best. No surprises there.
 
 I did do a test using the sun/win32 comm driver with read() and retrieve
 timeout enabled. It blocked until the timeout expired, then returned a -1.
@@ -3350,32 +3442,32 @@
 > I have a couple of questions/comments.
 >
 > 1) I noticed in the thread last night and in the code changes this morning that you
->    now have readByte() (which is called from the input stream read(), to block
->    forever. I pulled the following info from the javax.comm doc for the CommPort class in
->    getInputStream().
+>	now have readByte() (which is called from the input stream read(), to block
+>	forever. I pulled the following info from the javax.comm doc for the CommPort class in
+>	getInputStream().
 >
->    The way I interpret that is that read() just like read(byte[]), and read(byte[], int, int),
->    show only block indefinitely if timeout is disabled. The sun implementation for win32 (as
->    well as the one we have for vxworks) returns a -1 when it times out.
+>	The way I interpret that is that read() just like read(byte[]), and read(byte[], int, int),
+>	show only block indefinitely if timeout is disabled. The sun implementation for win32 (as
+>	well as the one we have for vxworks) returns a -1 when it times out.
 >
 
 Doing what Sun does is going to the least hassle.  The documentation was a
 little unclear to me.  I assume this is the CommPort.getInputStream
 comment that you mention
 
-        The read behaviour of the input stream returned by getInputStream
-        depends on combination of the threshold and timeout values. The
-        possible behaviours are described in the table below: ...
+	 The read behaviour of the input stream returned by getInputStream
+	 depends on combination of the threshold and timeout values. The
+	 possible behaviours are described in the table below: ...
 
 But InputStream is where read(byte) is documented
 http://java.sun.com/j2se/1.3/docs/api/java/io/InputStream.html#read()
 
-        Reads the next byte of data from the input stream. The value byte
-        is returned as an int in the range 0 to 255. If no byte is
-        available because the end of the stream has been reached, the value
-        -1 is returned. This method blocks until input data is
-        available, the end of the stream is detected, or an exception is
-        thrown
+	 Reads the next byte of data from the input stream. The value byte
+	 is returned as an int in the range 0 to 255. If no byte is
+	 available because the end of the stream has been reached, the value
+	 -1 is returned. This method blocks until input data is
+	 available, the end of the stream is detected, or an exception is
+	 thrown
 
 If you are sure commapi is doing a timeout and returning -1, I can change
 it back and document the issue.
@@ -3383,20 +3475,20 @@
 Because I often grep my own mailbox for details, I'm going to add
 these two comments also:
 
-        public int read(byte[] b)
+	 public int read(byte[] b)
 )
 http://java.sun.com/j2se/1.3/docs/api/java/io/InputStream.html#read(byte[])
 
-        Reads some number of bytes from the input stream and stores them
-        into the buffer array b. The number of bytes actually read is
-        returned as an integer. This method blocks until input data is
-        available, end of file is detected, or an exception is thrown.
-
-        If b is null, a NullPointerException is thrown. If the length of b
-        is zero, then no bytes are read and 0 is returned; otherwise,
-        there is an attempt to read at least one byte. If no byte is
-        available because the stream is at end of file, the value -1 is
-        returned; otherwise, at least one byte is read and stored into b.
+	 Reads some number of bytes from the input stream and stores them
+	 into the buffer array b. The number of bytes actually read is
+	 returned as an integer. This method blocks until input data is
+	 available, end of file is detected, or an exception is thrown.
+
+	 If b is null, a NullPointerException is thrown. If the length of b
+	 is zero, then no bytes are read and 0 is returned; otherwise,
+	 there is an attempt to read at least one byte. If no byte is
+	 available because the stream is at end of file, the value -1 is
+	 returned; otherwise, at least one byte is read and stored into b.
 
 So read(byte[] b) is documented as blocking for the first byte.
 
@@ -3404,10 +3496,10 @@
 http://java.sun.com/j2se/1.3/docs/api/java/io/InputStream.html#read(byte[],
 int, int)
 
-        Reads up to len bytes of data from the input stream into an array of
-        bytes. An attempt is made to read as many as len bytes, but a
-        smaller number may be read, possibly zero. The number of bytes
-        actually read is returned as an integer.
+	 Reads up to len bytes of data from the input stream into an array of
+	 bytes. An attempt is made to read as many as len bytes, but a
+	 smaller number may be read, possibly zero. The number of bytes
+	 actually read is returned as an integer.
 
 Which makes sense with the timeout documentation.
 
@@ -3434,18 +3526,18 @@
 > described in the table below:
 >
 >
->    Threshold             Timeout        Read Buffer    Read Behaviour
-> State     Value       State     Value       Size
+>	Threshold		Timeout	 Read Buffer	Read Behaviour
+> State	Value	State	Value	Size
 >
 -----------------------------------------------------------------------------------
-> disabled    -         disabled    -       n bytes      block until any data is available
+> disabled	-		disabled	-	n bytes	block until any data is available
 >
-> enabled   m bytes     disabled    -       n bytes      block until min(m,n) bytes are available
+> enabled	m bytes	disabled	-	n bytes	block until min(m,n) bytes are available
 >
-> disabled    -         enabled   x ms      n bytes      block for x ms or
+> disabled	-		enabled	x ms	n bytes	block for x ms or
 until any data is available
 >
-> enabled   m bytes     enabled   x ms      n bytes      block for x ms or
+> enabled	m bytes	enabled	x ms	n bytes	block for x ms or
 until min(m,n) bytes are available
 >
 > Returns: InputStream object that can be used to read from the port
@@ -3464,18 +3556,19 @@
 	/* char msg[80]; */
 
 /*
-	ENTER( "RXTXPort:readByte" );
+	report( "Entering - RXTXPort:readByte" );
 	report_time_start( );
 */
 	bytes = read_byte_array( env, &jobj, fd, buffer, 1, timeout );
 	if( bytes < 0 ) {
-		LEAVE( "RXTXPort:readByte" );
+		report( "Leaving - RXTXPort:readByte\n" );
 		throw_java_exception( env, IO_EXCEPTION, "readByte",
 			strerror( errno ) );
 		return -1;
 	}
 /*
-	LEAVE( "RXTXPort:readByte" );
+	report( "Leaving - RXTXPort:readByte\n" );
+	memset(&message[0], 0, sizeof(message));
 	sprintf( msg, "readByte return(%i)\n", bytes ? buffer[ 0 ] : -1 );
 	report( msg );
 	report_time_end( );
@@ -3486,14 +3579,14 @@
 /*----------------------------------------------------------
 RXTXPort.readArray
 
-   accept:       offset (offset to start storing data in the jbarray) and
-                 Length (bytes to read)
-   perform:      read bytes from the port into a byte array
-   return:       bytes read on success
-                 0 on read timeout
-   exceptions:   IOException
-   comments:     throws ArrayIndexOutOfBoundsException if asked to
-                 read more than SSIZE_MAX bytes
+	accept:		offset (offset to start storing data in the jbarray) and
+		*		Length (bytes to read)
+	perform:	read bytes from the port into a byte array
+	return:		bytes read on success
+		*		0 on read timeout
+	exceptions:	IOException
+	comments:	throws ArrayIndexOutOfBoundsException if asked to
+		*		read more than SSIZE_MAX bytes
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(readArray)( JNIEnv *env,
 	jobject jobj, jbyteArray jbarray, jint offset, jint length )
@@ -3505,12 +3598,12 @@
 	int timeout = get_java_var( env, jobj, "timeout", "I" );
 
 /*
-	ENTER( "readArray" );
+	report( "Entering - readArray\n" );
 	report_time_start( );
 */
 	if( (size_t) length > SSIZE_MAX || (size_t) length < 0 ) {
-		report( "RXTXPort:readArray length > SSIZE_MAX" );
-		LEAVE( "RXTXPort:readArray" );
+		report( "RXTXPort:readArray length > SSIZE_MAX\n" );
+		report( "Leaving - RXTXPort:readArray\n" );
 		throw_java_exception( env, ARRAY_INDEX_OUT_OF_BOUNDS,
 			"readArray", "Invalid length" );
 		return -1;
@@ -3519,17 +3612,18 @@
 	bytes = read_byte_array( env, &jobj, fd, (unsigned char *)(body+offset), length, timeout );/* dima */
 	(*env)->ReleaseByteArrayElements( env, jbarray, body, 0 );
 	if( bytes < 0 ) {
-		report( "RXTXPort:readArray bytes < 0" );
-		LEAVE( "RXTXPort:readArray" );
+		report( "RXTXPort:readArray bytes < 0\n" );
+		report( "Leaving - RXTXPort:readArray\n" );
 		throw_java_exception( env, IO_EXCEPTION, "readArray",
 			strerror( errno ) );
 		return -1;
 	}
 /*
+	memset(&message[0], 0, sizeof(message));
 	sprintf( msg, "RXTXPort:readArray: %i %i\n", (int) length, bytes);
 	report( msg );
 	report_time_end( );
-	LEAVE( "RXTXPort:readArray" );
+	report( "Leaving - RXTXPort:readArray\n" );
 */
 	return (bytes);
 }
@@ -3537,11 +3631,11 @@
 /*----------------------------------------------------------
 RXTXPort.nativeClearCommInput
 
-   accept:       none
-   perform:      try to clear the input.
-   return:       true on success, false on error
-   exceptions:   none
-   comments:     This is an extension to commapi.
+	accept:		none
+	perform:	try to clear the input.
+	return:		true on success, false on error
+	exceptions:	none
+	comments:	This is an extension to commapi.
 ----------------------------------------------------------*/
 JNIEXPORT jboolean JNICALL RXTXPort(nativeClearCommInput)( JNIEnv *env,
 	jobject jobj )
@@ -3554,18 +3648,18 @@
 /*----------------------------------------------------------
 RXTXPort.readTerminatedArray
 
-   accept:       offset (offset to start storing data in the jbarray) and
-                 Length (bytes to read).  Terminator - 2 bytes that we
-		 dont read past
-   perform:      read bytes from the port into a byte array
-   return:       bytes read on success
-                 0 on read timeout
-   exceptions:   IOException
-   comments:     throws ArrayIndexOutOfBoundsException if asked to
-                 read more than SSIZE_MAX bytes
-		 timeout is not properly handled
+	accept:		offset (offset to start storing data in the jbarray) and
+				Length (bytes to read).  Terminator - 2 bytes that we
+				dont read past
+	perform:	read bytes from the port into a byte array
+	return:		bytes read on success
+				0 on read timeout
+	exceptions:	IOException
+	comments:	throws ArrayIndexOutOfBoundsException if asked to
+				read more than SSIZE_MAX bytes
+				timeout is not properly handled
 
-		 This is an extension to commapi.
+				This is an extension to commapi.
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(readTerminatedArray)( JNIEnv *env,
 	jobject jobj, jbyteArray jbarray, jint offset, jint length,
@@ -3578,12 +3672,12 @@
 	int timeout = get_java_var( env, jobj, "timeout", "I" );
 
 /*
-	ENTER( "readArray" );
+	report( "Entering - readArray\n" );
 	report_time_start( );
 */
 	if( (size_t) length > SSIZE_MAX || (size_t) length < 0 ) {
-		report( "RXTXPort:readArray length > SSIZE_MAX" );
-		LEAVE( "RXTXPort:readArray" );
+		report( "RXTXPort:readArray length > SSIZE_MAX\n" );
+		report( "Leaving - RXTXPort:readArray\n" );
 		throw_java_exception( env, ARRAY_INDEX_OUT_OF_BOUNDS,
 			"readArray", "Invalid length" );
 		return -1;
@@ -3595,8 +3689,8 @@
 		bytes = read_byte_array( env, &jobj, fd, (unsigned char *)(body+offset + total ), 1 , timeout );/* dima */
 		total += bytes;
 		if( bytes < 0 ) {
-			report( "RXTXPort:readArray bytes < 0" );
-			LEAVE( "RXTXPort:readArray" );
+			report( "RXTXPort:readArray bytes < 0\n" );
+			report( "Leaving - RXTXPort:readArray\n" );
 			throw_java_exception( env, IO_EXCEPTION, "readArray",
 				strerror( errno ) );
 			return -1;
@@ -3612,10 +3706,11 @@
 	} while ( bytes > 0 && total < length );
 	(*env)->ReleaseByteArrayElements( env, jbarray, body, 0 );
 /*
+	memset(&message[0], 0, sizeof(message));
 	sprintf( msg, "RXTXPort:readArray: %i %i\n", (int) length, bytes);
 	report( msg );
 	report_time_end( );
-	LEAVE( "RXTXPort:readArray" );
+	report( "Leaving - RXTXPort:readArray\n" );
 */
 	return (bytes);
 }
@@ -3623,11 +3718,11 @@
 /*----------------------------------------------------------
 RXTXPort.nativeavailable
 
-   accept:      none
-   perform:     find out the number of bytes available for reading
-   return:      available bytes
-                -1 on error
-   exceptions:  none
+	accept:		none
+	perform:	find out the number of bytes available for reading
+	return:		available bytes
+				-1 on error
+	exceptions:	none
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(nativeavailable)( JNIEnv *env,
 	jobject jobj )
@@ -3638,13 +3733,13 @@
 	char message[80];
 
 
-	ENTER( "RXTXPort:nativeavailable" );
+	report( "Entering - RXTXPort:nativeavailable\n" );
 
-    On SCO OpenServer FIONREAD always fails for serial devices,
-    so try ioctl FIORDCHK instead; will only tell us whether
-    bytes are available, not how many, but better than nothing.
+	On SCO OpenServer FIONREAD always fails for serial devices,
+	so try ioctl FIORDCHK instead; will only tell us whether
+	bytes are available, not how many, but better than nothing.
 
-    This turns out to be true on Solaris also.  taj.
+	This turns out to be true on Solaris also.  taj.
 */
 #ifdef FIORDCHK  /* __unixware__ __sun__ probably others */
 	result = ioctl(fd, FIORDCHK, 0);
@@ -3658,22 +3753,24 @@
 		goto fail;
 	}
 /*
-	sprintf(message, "    nativeavailable: FIORDCHK result %d, \
+	memset(&message[0], 0, sizeof(message));
+	sprintf(message, "	nativeavailable: FIORDCHK result %d, \
 		errno %d\n", result , result == -1 ? errno : 0);
 	report_verbose( message );
 	if( result )
 	{
-		sprintf(message, "    nativeavailable: FIORDCHK result %d, \
+		memset(&message[0], 0, sizeof(message));
+		sprintf(message, "	nativeavailable: FIORDCHK result %d, \
 				errno %d\n", result , result == -1 ? errno : 0);
 		report( message );
 	}
-	LEAVE( "RXTXPort:nativeavailable" );
+	report( "Leaving - RXTXPort:nativeavailable\n" );
 */
 	return (jint)result;
 fail:
-	report("RXTXPort:nativeavailable:  ioctl() failed\n");
+	report("RXTXPort:nativeavailable:	ioctl() failed\n");
 /*
-	LEAVE( "RXTXPort:nativeavailable" );
+	report( "Leaving - RXTXPort:nativeavailable\n" );
 */
 	throw_java_exception( env, IO_EXCEPTION, "nativeavailable",
 		strerror( errno ) );
@@ -3683,17 +3780,17 @@
 /*----------------------------------------------------------
 RXTXPort.setflowcontrol
 
-   accept:      flowmode
-	FLOWCONTROL_NONE        none
-	FLOWCONTROL_RTSCTS_IN   hardware flow control
-	FLOWCONTROL_RTSCTS_OUT         ""
-	FLOWCONTROL_XONXOFF_IN  input software flow control
-	FLOWCONTROL_XONXOFF_OUT output software flow control
-   perform:     set flow control to flowmode
-   return:      none
-   exceptions:  UnsupportedCommOperationException
-   comments:  there is no differentiation between input and output hardware
-              flow control
+	accept:		flowmode
+				FLOWCONTROL_NONE	 none
+				FLOWCONTROL_RTSCTS_IN	hardware flow control
+				FLOWCONTROL_RTSCTS_OUT		""
+				FLOWCONTROL_XONXOFF_IN  input software flow control
+				FLOWCONTROL_XONXOFF_OUT output software flow control
+	perform:	set flow control to flowmode
+	return:		none
+	exceptions:	UnsupportedCommOperationException
+	comments:	there is no differentiation between input and output hardware
+				flow control
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setflowcontrol)( JNIEnv *env,
 	jobject jobj, jint flowmode )
@@ -3701,7 +3798,7 @@
 	struct termios ttyset;
 	int fd = get_java_var( env, jobj,"fd","I" );
 
-	ENTER( "RXTXPort:setflowcontrol" );
+	report( "Entering - RXTXPort:setflowcontrol\n" );
 	if( tcgetattr( fd, &ttyset ) ) goto fail;
 
 	if ( flowmode & ( FLOWCONTROL_RTSCTS_IN | FLOWCONTROL_RTSCTS_OUT ) )
@@ -3726,10 +3823,10 @@
 	else ttyset.c_iflag &= ~IXON;
 /* TRENT */
 	if( tcsetattr( fd, TCSANOW, &ttyset ) ) goto fail;
-	LEAVE( "RXTXPort:setflowcontrol" );
+	report( "Leaving - RXTXPort:setflowcontrol\n" );
 	return;
 fail:
-	LEAVE( "RXTXPort:setflowcontrol" );
+	report( "Leaving - RXTXPort:setflowcontrol\n" );
 	throw_java_exception( env, UNSUPPORTED_COMM_OPERATION, "",
 		"flow control type not supported" );
 	return;
@@ -3738,30 +3835,32 @@
 /*----------------------------------------------------------
 unlock_monitor_thread
 
-   accept:      event_info_struct
-   perform:     unlock the monitor thread so event notification can start.
-   return:      none
-   exceptions:  none
-   comments:    Events can be missed otherwise.
+	accept:		event_info_struct
+	perform:	unlock the monitor thread so event notification can start.
+	return:		none
+	exceptions:	none
+	comments:	Events can be missed otherwise.
 ----------------------------------------------------------*/
 
 void unlock_monitor_thread( struct event_info_struct *eis )
 {
+	report("Entering - unlock_monitor_thread\n");
 	JNIEnv *env = eis->env;
 	jobject jobj = *(eis->jobj);
 
 	jfieldID jfid = (*env)->GetFieldID( env, (*env)->GetObjectClass( env, jobj ), "MonitorThreadLock", "Z" );
 	(*env)->SetBooleanField( env, jobj, jfid, (jboolean) 0 );
+	report("Leaving - unlock_monitor_thread\n");
 }
 
 /*----------------------------------------------------------
 check_line_status_register
 
-   accept:      event_info_struct
-   perform:     check for changes on the LSR
-   return:      0 on success
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
+	accept:		event_info_struct
+	perform:	check for changes on the LSR
+	return:		0 on success
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
 ----------------------------------------------------------*/
 int check_line_status_register( struct event_info_struct *eis )
 {
@@ -3771,8 +3870,8 @@
 	if( ! eis->eventflags[SPE_OUTPUT_BUFFER_EMPTY] )
 	{
 		/* This occurs constantly so remove for now
-		 * report( "check_line_status_registe OUPUT_BUFFER_EMPTY not set\n" );
-		 */
+		* report( "check_line_status_registe OUPUT_BUFFER_EMPTY not set\n" );
+		*/
 		return 0;
 	}
 	if ( fstat( eis->fd, &fstatbuf ) )
@@ -3811,16 +3910,17 @@
 /*----------------------------------------------------------
 has_line_status_register_access
 
-   accept:      fd of interest
-   perform:     check for access to the LSR
-   return:      0 if not available
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
-		JK00: work around for multiport cards without TIOCSERGETLSR
-		Cyclades is one of those :-(
+	accept:		fd of interest
+	perform:	check for access to the LSR
+	return:		0 if not available
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
+	JK00: 		work around for multiport cards without TIOCSERGETLSR
+				Cyclades is one of those :-(
 ----------------------------------------------------------*/
 int has_line_status_register_access( int fd )
 {
+	report("Entering - has_line_status_register_access\n");
 #if defined(TIOCSERGETLSR)
 	int change;
 
@@ -3835,17 +3935,17 @@
 /*----------------------------------------------------------
 check_cgi_count
 
-   accept:      fd of interest
-   perform:     check for access to TIOCGICOUNT
-   return:      0 if not available
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
-	 *	wait for RNG, DSR, CD or CTS  but not DataAvailable
-	 *      The drawback here is it never times out so if someone
-	 *      reads there will be no chance to try again.
-	 *      This may make sense if the program does not want to
-	 *      be notified of data available or errors.
-	 *	ret=ioctl(fd,TIOCMIWAIT);
+	accept:		fd of interest
+	perform:	check for access to TIOCGICOUNT
+	return:		0 if not available
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
+				wait for RNG, DSR, CD or CTS  but not DataAvailable
+				The drawback here is it never times out so if someone
+				reads there will be no chance to try again.
+				This may make sense if the program does not want to
+				be notified of data available or errors.
+				ret=ioctl(fd,TIOCMIWAIT);
 ----------------------------------------------------------*/
 void check_cgi_count( struct event_info_struct *eis )
 {
@@ -3885,11 +3985,11 @@
 /*----------------------------------------------------------
 port_has_changed_fionread
 
-   accept:      fd of interest
-   perform:     check if FIONREAD has changed
-   return:      0 if no data available
-   exceptions:  none
-   comments:
+	accept:		fd of interest
+	perform:	check if FIONREAD has changed
+	return:		0 if no data available
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 int port_has_changed_fionread( struct event_info_struct *eis )
 {
@@ -3897,17 +3997,19 @@
 	char message[80];
 
 	rc = ioctl( eis->fd, FIONREAD, &change );
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "port_has_changed_fionread: change is %i ret is %i\n", change, eis->ret );
 #if defined(__unixware__) || defined(__sun__)
 	/*
-	   On SCO OpenServer FIONREAD always fails for serial devices,
-	   so rely upon select() result to know whether data available.
+		On SCO OpenServer FIONREAD always fails for serial devices,
+		so rely upon select() result to know whether data available.
 
-	   This is true for Solaris, also.  taj.
+		This is true for Solaris, also.  taj.
 	*/
 	if( (rc != -1 && change) || (rc == -1 && eis->ret > 0) )
 		return( 1 );
 #else
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "port_has_changed_fionread: change is %i\n", change );
 	report_verbose( message );
 	if( change )
@@ -3919,11 +4021,11 @@
 /*----------------------------------------------------------
 check_tiocmget_changes
 
-   accept:      event_info_struct
-   perform:     use TIOCMGET to report events
-   return:      none
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
+	accept:		event_info_struct
+	perform:	use TIOCMGET to report events
+	return:		none
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
 ----------------------------------------------------------*/
 void check_tiocmget_changes( struct event_info_struct * eis )
 {
@@ -3966,11 +4068,11 @@
 /*----------------------------------------------------------
 system_wait
 
-   accept:
-   perform:
-   return:
-   exceptions:  none
-   comments:
+	accept:
+	perform:
+	return:
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void system_wait()
 {
@@ -3987,9 +4089,9 @@
 #else
 #ifdef TRENT_IS_HERE_DEBUGGING_THREADS
 	/* On NT4 The following was observed in a intense test:
-		50000   95%   179 sec
-		200000  95%   193 sec
-		1000000 95%   203 sec	some callback failures sometimes.
+		50000	95%	179 sec
+		200000  95%	193 sec
+		1000000 95%	203 sec	some callback failures sometimes.
 		2000000 0-95% 		callback failures.
 	*/
 #endif /* TRENT_IS_HERE_DEBUGGING_THREADS */
@@ -3999,28 +4101,32 @@
 /*----------------------------------------------------------
 driver_has_tiocgicount
 
-   accept:      fd of interest
-   perform:     check for access to TIOCGICOUNT
-   return:      0 if not available
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
-		Some multiport serial cards do not implement TIOCGICOUNT ...
-		So use the 'dumb' mode to enable using them after all! JK00
+	accept:		fd of interest
+	perform:	check for access to TIOCGICOUNT
+	return:		0 if not available
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
+				Some multiport serial cards do not implement TIOCGICOUNT
+				So use the 'dumb' mode to enable using them after all!
+				JK00
 ----------------------------------------------------------*/
 int driver_has_tiocgicount( struct event_info_struct * eis )
 {
+	report("Entering - driver_has_tiocgicount\n");
 #if defined(TIOCGICOUNT)
-
+	report("TIOCGICOUNT is defined\n");
 	/* Some multiport serial cards do not implement TIOCGICOUNT ... */
 	/* So use the 'dumb' mode to enable using them after all! JK00 */
 
 	if( ioctl( eis->fd, TIOCGICOUNT, &eis->osis ) < 0 ) {
-		report_verbose( " driver_has_tiocgicount:  Port does not support TIOCGICOUNT events\n" );
+		report_verbose( " driver_has_tiocgicount:	Port does not support TIOCGICOUNT events\n" );
 		return(0);
 	}
 	else
+		report("driver_has_tiocgicount: TIOCGICOUNT is implemented\n");
 		return(1);
 #endif /*  TIOCGICOUNT */
+	report("Leaving - driver_has_tiocgicount\n");
 	return(0);
 
 }
@@ -4028,11 +4134,11 @@
 /*----------------------------------------------------------
 report_serial_events
 
-   accept:      event_info_struct
-   perform:     send events if they occured
-   return:      0 if not available
-   exceptions:  none
-   comments:    not supported on all devices/drivers.
+	accept:		event_info_struct
+	perform:	send events if they occured
+	return:		0 if not available
+	exceptions:	none
+	comments:	not supported on all devices/drivers.
 ----------------------------------------------------------*/
 void report_serial_events( struct event_info_struct *eis )
 {
@@ -4053,7 +4159,7 @@
 		{
 			report_verbose("report_serial_events: ignoring DATA_AVAILABLE\n");
 /*
-			report(".");
+			report(".\n");
 */
 			usleep(20000);
 #if !defined(__sun__)
@@ -4078,14 +4184,15 @@
 /*----------------------------------------------------------
 initialise_event_info_struct
 
-   accept:      event_info_struct for this thread.
-   perform:     initialise or reset the event_info_struct
-   return:      1 on success
-   exceptions:  none
-   comments:
+	accept:		event_info_struct for this thread.
+	perform:	initialise or reset the event_info_struct
+	return:		1 on success
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 int initialise_event_info_struct( struct event_info_struct *eis )
 {
+	report("Entering - initialise_event_info_struct\n");
 	int i;
 	jobject jobj = *eis->jobj;
 	JNIEnv *env = eis->env;
@@ -4141,21 +4248,23 @@
 	eis->tv_sleep.tv_sec = 0;
 	eis->tv_sleep.tv_usec = 1000;
 	eis->initialised = 1;
+	report("Leaving - initialise_event_info_struct\n");
 	return( 1 );
 fail:
 	report_error("initialise_event_info_struct: initialise failed!\n");
 	finalize_event_info_struct( eis );
+	report("Leaving - initialise_event_info_struct\n");
 	return( 0 );
 }
 
 /*----------------------------------------------------------
 finalize_event_info_struct
 
-   accept:      event_info_struct for this thread.
-   perform:     free resources
-   return:      none
-   exceptions:  none
-   comments:
+	accept:		event_info_struct for this thread.
+	perform:	free resources
+	return:		none
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void finalize_event_info_struct( struct event_info_struct *eis )
 {
@@ -4181,14 +4290,15 @@
 /*----------------------------------------------------------
 RXTXPort.eventLoop
 
-   accept:      none
-   perform:     periodically check for SerialPortEvents
-   return:      none
-   exceptions:  none
-   comments:	please keep this function clean.
+	accept:		none
+	perform:	periodically check for SerialPortEvents
+	return:		none
+	exceptions:	none
+	comments:	please keep this function clean.
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(eventLoop)( JNIEnv *env, jobject jobj )
 {
+	report( "Entering - RXTXPort_eventLoop\n" );
 #ifdef WIN32
 	int i = 0;
 #endif /* WIN32 */
@@ -4198,74 +4308,92 @@
 	eis.jobj = &jobj;
 	eis.initialised = 0;
 
-	ENTER( "eventLoop\n" );
+	
 	if ( !initialise_event_info_struct( &eis ) ) goto end;
 	if ( !init_threads( &eis ) ) goto end;
+	
+	report( "RXTXPort_eventLoop - Unlocking Monitor Thread\n" );
 	unlock_monitor_thread( &eis );
+	
 	do{
 		report_time_eventLoop( );
 		do {
 			/* nothing goes between this call and select */
 			if( eis.closing )
 			{
-				report("eventLoop: got interrupt\n");
+				report( "RXTXPort_eventLoop - Got Interupted\n" );
 				finalize_threads( &eis );
 				finalize_event_info_struct( &eis );
-				LEAVE("eventLoop");
+				report("Leaving - RXTXPort_eventLoop\n");
 				return;
 			}
-#ifndef WIN32
-			/* report( "." ); */
-			do {
-				eis.ret = SELECT( eis.fd + 1, &eis.rfds, NULL, NULL,
-					&eis.tv_sleep );
-			} while (eis.ret < 0 && errno==EINTR);
-#else
-			/*
-			    termios.c:serial_select is instable for some
-			    reason
-
-			    polling is not blowing up.
-			*/
-/*
-			usleep(5000);
-*/
-			eis.ret=1;
-			while( i++ < 5 )
-			{
-				if(eis.eventflags[SPE_DATA_AVAILABLE] )
+			
+			#ifndef WIN32
+				
+				/**
+				*	report( "." );
+				**/
+				
+				do {
+					eis.ret = SELECT( eis.fd + 1, &eis.rfds, NULL, NULL,
+						&eis.tv_sleep );
+				} while (eis.ret < 0 && errno==EINTR);
+				
+			#else
+				
+				/**
+				*	termios.c:serial_select is instable for some
+				*	reason
+				*
+				*	polling is not blowing up.
+				**/
+				
+				/**
+				*	usleep(5000);
+				**/
+				
+				eis.ret=1;
+				while( i++ < 5 )
 				{
-					if( port_has_changed_fionread( &eis ) )
+					if(eis.eventflags[SPE_DATA_AVAILABLE] )
 					{
-						send_event( &eis, SPE_DATA_AVAILABLE, 1 );
+						if( port_has_changed_fionread( &eis ) )
+						{
+							send_event( &eis, SPE_DATA_AVAILABLE, 1 );
+						}
 					}
+					usleep(1000);
 				}
-				usleep(1000);
-			}
-			i = 0;
-#endif /* WIN32 */
+				i = 0;
+				
+			#endif /* WIN32 */
 		}  while ( eis.ret < 0 && errno == EINTR );
+		
+		
+		
 		if( eis.ret >= 0 )
 		{
 			report_serial_events( &eis );
 		}
+		
 		initialise_event_info_struct( &eis );
+		
 	} while( 1 );
 end:
-	LEAVE( "eventLoop:  Bailing!\n" );
+	report( "Leaving - eventLoop:	Bailing!\n" );
 }
 
 /*----------------------------------------------------------
 RXTXVersion.nativeGetVersion
 
-   accept:      none
-   perform:     return the current version
-   return:      version
-   exceptions:  none
-   comments:    This is used to avoid mixing versions of the .jar and
-		native library.
-		First introduced in rxtx-1.5-9
-                Moved from RXTXCommDriver to RXTXVersion in rxtx-2.1-7
+	accept:		none
+	perform:	return the current version
+	return:		version
+	exceptions:	none
+	comments:	This is used to avoid mixing versions of the .jar and
+				native library.
+				First introduced in rxtx-1.5-9
+				Moved from RXTXCommDriver to RXTXVersion in rxtx-2.1-7
 
 ----------------------------------------------------------*/
 JNIEXPORT jstring JNICALL RXTXVersion(nativeGetVersion) (JNIEnv *env,
@@ -4277,13 +4405,13 @@
 /*----------------------------------------------------------
 RXTXCommDriver.testRead
 
-   accept:      tty_name The device to be tested
-   perform:     test if the device can be read from
-   return:      JNI_TRUE if the device can be read from
-   exceptions:  none
-   comments:    From Wayne Roberts wroberts1@home.com
-   		check tcget/setattr returns.
-		support for non serial ports Trent
+	accept:		tty_name The device to be tested
+	perform:	test if the device can be read from
+	return:		JNI_TRUE if the device can be read from
+	exceptions:	none
+	comments:	From Wayne Roberts wroberts1@home.com
+				check tcget/setattr returns.
+				support for non serial ports Trent
 ----------------------------------------------------------*/
 
 JNIEXPORT jboolean  JNICALL RXTXCommDriver(testRead)(
@@ -4293,68 +4421,117 @@
 	jint port_type
 )
 {
+	
+	const char *name = (*env)->GetStringUTFChars(env, tty_name, 0);
+	
+	char sm[256];
+	memset(&sm[0], 0, sizeof(sm));
+	sprintf( sm, "Entering - RXTXPort:testRead(%s, %i)\n", name, port_type );
+	report( sm );
+
 	struct termios ttyset;
 	char c;
-#ifdef TRENT_IS_HERE_DEBUGGING_ENUMERATION
-	char message[80];
-#endif /* TRENT_IS_HERE_DEBUGGING_ENUMERATION */
+	char message[256];
 	int fd;
-	const char *name = (*env)->GetStringUTFChars(env, tty_name, 0);
+	
 	int ret = JNI_TRUE;
 	int pid = -1;
-	/* We opened the file in this thread, use this pid to unlock */
-#ifndef WIN32
-	pid = getpid();
-#else
-	char full_windows_name[80];
-#endif /* WIN32 */
-
-	ENTER( "RXTXPort:testRead" );
-#ifdef TRENT_IS_HERE_DEBUGGING_ENUMERATION
-	/* vmware lies about which ports are there causing irq conflicts */
-	/* this is for testing only */
-	if( !strcmp( name, "COM1" ) || !strcmp( name, "COM2") )
-	{
-		printf("%s is good\n",name);
-		sprintf( message, "testRead: %s is good!\n", name );
-		report( message );
+	
+	/* We open the file in this thread, use this pid to unlock */
+	#ifndef WIN32
+		pid = getpid();
+	#else
+		char full_windows_name[80];
+	#endif /* WIN32 */
+		
+	#ifdef TRENT_IS_HERE_DEBUGGING_ENUMERATION
+		char message[80];
+		/* vmware lies about which ports are there causing irq conflicts */
+		/* this is for testing only */
+		if( !strcmp( name, "COM1" ) || !strcmp( name, "COM2") )
+		{
+			printf("%s is good\n",name);
+			memset(&message[0], 0, sizeof(message));
+			sprintf( message, "testRead: %s is good!\n", name );
+			report( message );
+			(*env)->ReleaseStringUTFChars( env, tty_name, name );
+			return( JNI_TRUE );
+		}
 		(*env)->ReleaseStringUTFChars( env, tty_name, name );
-		return( JNI_TRUE );
-	}
-	(*env)->ReleaseStringUTFChars( env, tty_name, name );
-	return( JNI_FALSE );
-#endif /* TRENT_IS_HERE_DEBUGGING_ENUMERATION */
-#ifdef WIN32
-	strcpy( full_windows_name, DEVICEDIR );
-	strcat( full_windows_name, name );
-	ret = serial_test((char *) full_windows_name );
-	(*env)->ReleaseStringUTFChars( env, tty_name, name );
-	return(ret);
-#endif /* WIN32 */
+		return( JNI_FALSE );
+	#endif /* TRENT_IS_HERE_DEBUGGING_ENUMERATION */
+	
+	#ifdef WIN32
+		strcpy( full_windows_name, DEVICEDIR );
+		strcat( full_windows_name, name );
+		ret = serial_test((char *) full_windows_name );
+		(*env)->ReleaseStringUTFChars( env, tty_name, name );
+		return(ret);
+	#endif /* WIN32 */
 
-	/*
-		LOCK is one of three functions defined in SerialImp.h
+	/**
+	*	LOCK is one of three functions defined in SerialImp.h
+	*		uucp_lock		Solaris
+	*		fhs_lock		Linux
+	*		system_does_not_lock	Win32
+	**/
 
-			uucp_lock		Solaris
-			fhs_lock		Linux
-			system_does_not_lock	Win32
-	*/
-
-	if ( LOCK( name, pid ) )
+	
+	if ( port_type == PORT_SERIAL )
 	{
-		(*env)->ReleaseStringUTFChars(env, tty_name, name);
-		LEAVE( "RXTXPort:testRead no lock" );
-		return JNI_FALSE;
-	}
+		int lockstate;
+		report( "testRead() checking for lock\n" );
+		lockstate = LOCK(name, pid);
+		report( "testRead() - lock check complete\n" );
+		
 
-	/*
-           CLOCAL eliminates open blocking on modem status lines
-           -- changed to O_NONBLOCK
-	*/
-	do {
+		if ( lockstate == 1 )
+		{
+			(*env)->ReleaseStringUTFChars(env, tty_name, name);
+			report( "Leaving - RXTXPort:testRead no lock\n" );
+			return JNI_FALSE;
+		}
+		else
+		{	
+			memset(&message[0], 0, sizeof(message));
+			sprintf( message, "testRead() - going to open the file (%i)\n", (int) O_RDWR);
+			report( message );
+		}
+	}
+	/**
+	*	CLOCAL eliminates open blocking on modem status lines
+	*	-- changed to O_NONBLOCK
+	**/
+
+	/**
+	*	FIXME - On FreeBSD the open command on /dev/lpt0 hangs for
+	*	about 5 - 30 seconds in FreeBSD v10.1-p9 on i386.
+	* 	No idea how to resolve yet.  Returns errno == EBUSY.
+	**/	
+	
+	do 
+	{
 		fd=OPEN ( name, O_RDWR | O_NOCTTY | O_NONBLOCK );
 	}  while ( fd < 0 && errno==EINTR );
 
+	/**
+	*	Just because a port is busy, doesn't mean that we can't use it,
+	*	but shows it is available for future use...
+	*	Note: This skips all the permission tests, as it is in use.
+	*	
+	* 	FIXME: Get perms on FreeBSD from STAT command returned results.
+	* 	
+	*	so:
+	**/
+	if ( errno == EBUSY )
+	{
+		goto END;
+	}
+	
+	memset(&message[0], 0, sizeof(message));
+	sprintf( message, "testRead() - open returned(errno = %i, fd = %i)\n", (int) errno, (int) fd);
+	report( message );
+	
 	if( fd < 0 )
 	{
 		report_verbose( "testRead() open failed\n" );
@@ -4366,12 +4543,14 @@
 	{
 		int saved_flags;
 		struct termios saved_termios;
-
+		
+		report_verbose( "testRead() - tcgetattr\n" );
+		
 		if (tcgetattr(fd, &ttyset) < 0) {
 			ret = JNI_FALSE;
 			goto END;
 		}
-
+		
 		/* save, restore later */
 		if ( ( saved_flags = fcntl(fd, F_GETFL ) ) < 0 )
 		{
@@ -4379,7 +4558,7 @@
 			ret = JNI_FALSE;
 			goto END;
 		}
-
+		
 		memcpy( &saved_termios, &ttyset, sizeof( struct termios ) );
 
 		if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
@@ -4400,97 +4579,97 @@
 			goto END;
 		}
 
-/*
-
-              The following may mess up if both EAGAIN and EWOULDBLOCK
-              are defined but only EWOULDBLOCK is used
-
-              Linux:
-
-              man 2 open
-              O_NONBLOCK or O_NDELAY
-              When  possible,  the file is opened in non-blocking
-              mode. Neither the open nor  any  subsequent  opera�
-              tions on the file descriptor which is returned will
-              cause the calling process to wait.   For  the  han�
-              dling  of  FIFOs  (named  pipes), see also fifo(4).
-              This mode need not have any effect on  files  other
-              than FIFOs.
-
-	      man 2 read
-              EAGAIN
-              Non-blocking I/O has been selected using O_NONBLOCK
-              and no data was immediately available for  reading.
-
-
-              /usr/include/asm/error.h:
-              #define EAGAIN          11      / Try again /
-              #define EWOULDBLOCK     EAGAIN  / Operation would block /
-
-              looks like the kernel is using EAGAIN
-
-              -- should be OK
-
-              Solaris:
-
-              man 2 open
-              EAGAIN    The path  argument  names  the  slave  side  of  a
-              pseudo-terminal device that is locked.
-
-              man 2 read
-              If O_NONBLOCK is set, read() returns -1 and sets errno
-              to EAGAIN.
-
-              -- should be OK.
-
-              HP-UX
-
-              both are defined but EAGAIN is used.
-
-              -- should be OK.
-
-              Win32
-
-              neither errno is currently set.  Comment added to termios.c
-              serial_open().
-
-              -- should be OK
-
-Steven's book.  Advanced programming in the Unix Environment pg 364
-
-"A common use for nonblocking I/O is for dealing with a terminal device
-for a network connection and these devices are normally used by one process
-at a time.  This means that the change in the BSD semantics normally does 't
-effect us.  The different error return, EWOULDBLOCK, instead of POSIX.1
-EAGAIN, continues to be a portability difference that we must deal with."
-
-*/
-
+		/**
+		*	The following may mess up if both EAGAIN and EWOULDBLOCK
+		*	are defined but only EWOULDBLOCK is used
+		*	
+		*	Linux:
+		*	
+		*	man 2 open
+		*	O_NONBLOCK or O_NDELAY
+		*	When  possible,  the file is opened in non-blocking
+		*	mode. Neither the open nor  any  subsequent  opera�
+		*	tions on the file descriptor which is returned will
+		*	cause the calling process to wait.	For  the  han�
+		*	dling  of  FIFOs  (named  pipes), see also fifo(4).
+		*	This mode need not have any effect on  files  other
+		*	than FIFOs.
+
+		*	man 2 read
+		*	EAGAIN
+		*	Non-blocking I/O has been selected using O_NONBLOCK
+		*	and no data was immediately available for  reading.
+		*	/usr/include/asm/error.h:
+		*	#define EAGAIN		11	/ Try again /
+		*	#define EWOULDBLOCK	EAGAIN  / Operation would block /
+		*	looks like the kernel is using EAGAIN
+		*	-- should be OK
+
+		*	Solaris:
+		*	man 2 open
+		*	EAGAIN	The path  argument  names  the  slave  side  of  a
+		*	pseudo-terminal device that is locked.
+		*	man 2 read
+		*	If O_NONBLOCK is set, read() returns -1 and sets errno
+		*	to EAGAIN.
+		*	-- should be OK.
+
+		*	HP-UX
+		*	both are defined but EAGAIN is used.
+		*	-- should be OK.
+
+		*	Win32
+		*	neither errno is currently set.  Comment added to termios.c
+		*	serial_open().
+		*	-- should be OK
+
+		*	Steven's book.  Advanced programming in the Unix Environment pg 364
+
+		*	"A common use for nonblocking I/O is for dealing with a terminal device
+		*	for a network connection and these devices are normally used by one process
+		*	at a time.  This means that the change in the BSD semantics normally does 't
+		*	effect us.  The different error return, EWOULDBLOCK, instead of POSIX.1
+		*	EAGAIN, continues to be a portability difference that we must deal with."
+		**/
+		report_verbose( "testRead() - Reading...\n" );
+		
 		if ( READ( fd, &c, 1 ) < 0 )
 		{
-#ifdef EAGAIN
-			if ( errno != EAGAIN ) {
-				report( "testRead() read failed\n" );
-				ret = JNI_FALSE;
-			}
-#else
-#ifdef EWOULDBLOCK
-			if ( errno != EWOULDBLOCK )
-			{
-				report( "testRead() read failed\n" );
-				ret = JNI_FALSE;
-			}
-#else
-			ret = JNI_FALSE;
-#endif /* EWOULDBLOCK */
-#endif /* EAGAIN */
+			#ifdef EAGAIN
+				if ( errno != EAGAIN ) {
+					report( "testRead() read failed\n" );
+					ret = JNI_FALSE;
+				}
+			#else
+				#ifdef EWOULDBLOCK
+					if ( errno != EWOULDBLOCK )
+					{
+						report( "testRead() read failed\n" );
+						ret = JNI_FALSE;
+					}
+				#else
+					ret = JNI_FALSE;
+				#endif /* EWOULDBLOCK */
+			#endif /* EAGAIN */
 		}
-
+		report_verbose( "testRead() - Read Complete\n" );
+		
 		/* dont walk over unlocked open devices */
 		tcsetattr( fd, TCSANOW, &saved_termios );
 		fcntl( fd, F_SETFL, saved_flags );
 	}
-
+	else if ( port_type == PORT_PARALLEL )
+	{
+		/**
+		*	Parrellel ports are also sent here for testing.
+		*	We should be doing some sort of check...
+		*	FIXME - To implement.
+		**/
+		report( "testRead() This is a parrelle port, skipping\n" );
+	}
+	
+	
+	
 	/*
 		UNLOCK is one of three functions defined in SerialImp.h
 
@@ -4500,185 +4679,249 @@
 	*/
 
 END:
-	UNLOCK(name, pid );
-	(*env)->ReleaseStringUTFChars( env, tty_name, name );
-	CLOSE( fd );
-	LEAVE( "RXTXPort:testRead" );
+	report_verbose( "testRead() - at end\n" );
+	if ( port_type == PORT_SERIAL )
+	{
+		report_verbose( "testRead() - unlocking\n" );
+		UNLOCK(name, pid );
+		report_verbose( "testRead()  - Releasing String Chars\n" );
+		(*env)->ReleaseStringUTFChars( env, tty_name, name );
+		report_verbose( "testRead() - Closing...\n" );
+		CLOSE( fd );
+	}
+	else
+	{
+		report_verbose( "testRead()  - Releasing String Chars\n" );
+		(*env)->ReleaseStringUTFChars( env, tty_name, name );
+	}
+	report( "Leaving - RXTXPort:testRead\n" );
 	return ret;
 }
 
 #if defined(__APPLE__)
-/*----------------------------------------------------------
- createSerialIterator()
-   accept:
-   perform:
-   return:
-   exceptions:
-   comments:
+	
+	/*----------------------------------------------------------
+	createSerialIterator()
+	accept:
+	perform:
+	return:
+	exceptions:
+	comments:
 		Code courtesy of Eric Welch at Keyspan, except for the bugs
 		which are courtesy of Joseph Goldstone (joseph@lp.com)
-----------------------------------------------------------*/
-
-kern_return_t
-createSerialIterator(io_iterator_t *serialIterator)
-{
-    kern_return_t    kernResult;
-    mach_port_t        masterPort;
-    CFMutableDictionaryRef    classesToMatch;
-    if ((kernResult=IOMasterPort( (int) NULL, &masterPort ) ) != KERN_SUCCESS)
-    {
-	printf( "IOMasterPort returned %d\n", kernResult);
-	return kernResult;
-    }
-    if ((classesToMatch = IOServiceMatching(kIOSerialBSDServiceValue)) == NULL)
-    {
-	printf( "IOServiceMatching returned NULL\n" );
-	return kernResult;
-    }
-    CFDictionarySetValue(classesToMatch, CFSTR(kIOSerialBSDTypeKey), CFSTR(kIOSerialBSDAllTypes));
-    kernResult = IOServiceGetMatchingServices(masterPort, classesToMatch, serialIterator);
-    if (kernResult != KERN_SUCCESS)
-    {
-	printf( "IOServiceGetMatchingServices returned %d\n", kernResult);
-    }
-    return kernResult;
-}
+	----------------------------------------------------------*/
+	
+	kern_return_t
+	createSerialIterator(io_iterator_t *serialIterator)
+	{
+		kern_return_t			kernResult;
+		mach_port_t				masterPort;
+		CFMutableDictionaryRef	classesToMatch;
+		
+		if ((kernResult=IOMasterPort( (int) NULL, &masterPort ) ) != KERN_SUCCESS)
+		{
+			printf( "IOMasterPort returned %d\n", kernResult);
+			return kernResult;
+		}
+		if ((classesToMatch = IOServiceMatching(kIOSerialBSDServiceValue)) == NULL)
+		{
+			printf( "IOServiceMatching returned NULL\n" );
+			return kernResult;
+		}
+		
+		CFDictionarySetValue(classesToMatch, CFSTR(kIOSerialBSDTypeKey), CFSTR(kIOSerialBSDAllTypes));
+		
+		kernResult = IOServiceGetMatchingServices(masterPort, classesToMatch, serialIterator);
+		
+		if (kernResult != KERN_SUCCESS)
+		{
+			printf( "IOServiceGetMatchingServices returned %d\n", kernResult);
+		}
+		
+		return kernResult;
+	}
 
-/*----------------------------------------------------------
- getRegistryString()
-
-   accept:
-   perform:
-   return:
-   exceptions:
-   comments:
+	/*----------------------------------------------------------
+	getRegistryString()
+	
+	accept:
+	perform:
+	return:
+	exceptions:
+	comments:
 		Code courtesy of Eric Welch at Keyspan, except for the bugs
 		which are courtesy of Joseph Goldstone (joseph@lp.com)
-----------------------------------------------------------*/
-char *
-getRegistryString(io_object_t sObj, char *propName)
-{
-    static char resultStr[256];
-    CFTypeRef   nameCFstring;
-    resultStr[0] = 0;
-    nameCFstring = IORegistryEntryCreateCFProperty(sObj,
-            CFStringCreateWithCString(kCFAllocatorDefault, propName, kCFStringEncodingASCII),
-                                                   kCFAllocatorDefault, 0);
-    if (nameCFstring)
-    {
-        CFStringGetCString(nameCFstring, resultStr, sizeof(resultStr), kCFStringEncodingASCII);
-        CFRelease(nameCFstring);
-    }
-    return resultStr;
-}
+	----------------------------------------------------------*/
+	char *
+	getRegistryString(io_object_t sObj, char *propName)
+	{
+		static char resultStr[256];
+		CFTypeRef	nameCFstring;
+		resultStr[0] = 0;
+		nameCFstring = IORegistryEntryCreateCFProperty(
+			sObj,
+		CFStringCreateWithCString
+				(
+					kCFAllocatorDefault,
+					propName,
+					kCFStringEncodingASCII
+				),
+		kCFAllocatorDefault, 
+		0
+		);
+		if (nameCFstring)
+		{
+			CFStringGetCString(nameCFstring, resultStr, sizeof(resultStr), kCFStringEncodingASCII);
+			CFRelease(nameCFstring);
+		}
+		return resultStr;
+	}
+	
+	/*----------------------------------------------------------
+	registerKnownSerialPorts()
+	accept:
+	perform:
+	return:
+	exceptions:
+	comments:
+	----------------------------------------------------------*/
+	int
+	registerKnownSerialPorts(JNIEnv *env, jobject jobj, jint portType) /* dima */
+	{
+		io_iterator_t	theSerialIterator;
+		io_object_t	theObject;
+		int		*	numPorts = 0;/* dima it should initiated */
+	
+		if 	(
+				( createSerialIterator( &theSerialIterator ) != KERN_SUCCESS) ||
+				( ! IOIteratorIsValid( theSerialIterator))
+			)
+		{
+			/*  This also happens when no drivers are installed */
+			report( "createSerialIterator failed\n" );
+			return(0);
+		} 
+		else
+		{
+			jclass cls;
+			jmethodID mid;
+			cls = (*env)->FindClass(env,"gnu/io/CommPortIdentifier" );
+			if (cls == 0)
+			{ 
+				report( "can't find class of gnu/io/CommPortIdentifier\n" );
+				return numPorts;
+			}
+			mid = (*env)->GetStaticMethodID(
+				env, 
+				cls, 
+				"addPortName",
+				"(Ljava/lang/String;ILgnu/io/CommDriver;)V"
+			);
 
-/*----------------------------------------------------------
- registerKnownSerialPorts()
-   accept:
-   perform:
-   return:
-   exceptions:
-   comments:
-----------------------------------------------------------*/
-int
-registerKnownSerialPorts(JNIEnv *env, jobject jobj, jint portType) /* dima */
-{
-    io_iterator_t    theSerialIterator;
-    io_object_t      theObject;
-    int              numPorts = 0;/* dima it should initiated */
-
-    if (( createSerialIterator( &theSerialIterator ) != KERN_SUCCESS) ||
-        ( ! IOIteratorIsValid( theSerialIterator)))
-    {
-	/*  This also happens when no drivers are installed */
-        report( "createSerialIterator failed\n" );
-	return(0);
-    } else {
-	jclass cls; /* dima */
-	jmethodID mid; /* dima */
-        cls = (*env)->FindClass(env,"gnu/io/CommPortIdentifier" ); /* dima */
-        if (cls == 0) { /* dima */
-            report( "can't find class of gnu/io/CommPortIdentifier\n" ); /* dima */
-            return numPorts; /* dima */
-        } /* dima */
-        mid = (*env)->GetStaticMethodID(env, cls, "addPortName", "(Ljava/lang/String;ILgnu/io/CommDriver;)V" ); /* dima */
-
-        if (mid == 0) {
-            printf( "getMethodID of CommDriver.addPortName failed\n" );
-        } else {
-            while (theObject = IOIteratorNext(theSerialIterator))
-            {
- /* begin dima */
-            	jstring	tempJstring;
-				tempJstring = (*env)->NewStringUTF(env,getRegistryString(theObject, kIODialinDeviceKey));
-                (*env)->CallStaticVoidMethod(env, cls, mid,tempJstring,portType,jobj);/* dima */
- 				(*env)->DeleteLocalRef(env,tempJstring);
-                numPorts++;
-
- 				tempJstring = (*env)->NewStringUTF(env,getRegistryString(theObject, kIOCalloutDeviceKey));
-               (*env)->CallStaticVoidMethod(env, cls, mid,tempJstring,portType,jobj);/* dima */
- 				(*env)->DeleteLocalRef(env,tempJstring);
-                numPorts++;
-/* end dima */
-            }
-        }
-    }
-    return numPorts;
-}
+			if (mid == 0) 
+			{
+				printf( "getMethodID of CommDriver.addPortName failed\n" );
+			} 
+			else 
+			{
+				while (theObject = IOIteratorNext(theSerialIterator))
+				{
+					/* begin dima */
+					jstring	tempJstring;
+					tempJstring = (*env)->NewStringUTF(env,getRegistryString(theObject, kIODialinDeviceKey));
+					(*env)->CallStaticVoidMethod(env, cls, mid,tempJstring,portType,jobj);/* dima */
+					(*env)->DeleteLocalRef(env,tempJstring);
+					numPorts++;
+					
+					tempJstring = (*env)->NewStringUTF(env,getRegistryString(theObject, kIOCalloutDeviceKey));
+					(*env)->CallStaticVoidMethod(env, cls, mid,tempJstring,portType,jobj);/* dima */
+					(*env)->DeleteLocalRef(env,tempJstring);
+					numPorts++;
+					/* end dima */
+				}
+			}
+		}
+		return numPorts;
+	}
 #endif /* __APPLE__ */
 
 /*----------------------------------------------------------
  registerKnownPorts
 
-   accept:      the type of port
-   perform:     register any ports of the desired type a priori known to this OS
-   return:      JNI_TRUE if any such ports were registered otherwise JNI_FALSE
-   exceptions:  none
-   comments:
+	accept:		the type of port
+	perform:	register any ports of the desired type a priori known
+	 			to this OS
+	return:		JNI_TRUE if any such ports were registered otherwise
+				JNI_FALSE
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
-JNIEXPORT jboolean JNICALL RXTXCommDriver(registerKnownPorts)(JNIEnv *env,
-    jobject jobj, jint portType)
+JNIEXPORT jboolean JNICALL RXTXCommDriver(registerKnownPorts)(
+	JNIEnv *env,
+	jobject jobj, 
+	jint portType
+)
 {
-	enum {PORT_TYPE_SERIAL = 1,
+	report("Entering - RXTXCommDriver_registerKnownPorts\n");
+	
+	char strbuf[256];
+	
+	enum 
+	{
+		PORT_TYPE_SERIAL = 1,
 		PORT_TYPE_PARALLEL,
 		PORT_TYPE_I2C,
 		PORT_TYPE_RS485,
-		PORT_TYPE_RAW};
+		PORT_TYPE_RAW
+	};
+		
 	jboolean result = JNI_FALSE;
 	char message[80];
 
-	switch(portType) {
+	switch(portType)
+	{
 		case PORT_TYPE_SERIAL:
-#if defined(__APPLE__)
-			if (registerKnownSerialPorts(env, jobj,
-				PORT_TYPE_SERIAL) > 0) {/* dima */
-				result = JNI_TRUE;
-			}
-#endif
-           		 break;
-		case PORT_TYPE_PARALLEL: break;
-		case PORT_TYPE_I2C:      break;
-		case PORT_TYPE_RS485:    break;
-		case PORT_TYPE_RAW:      break;
+			#if defined(__APPLE__)
+				if (registerKnownSerialPorts(env, jobj, PORT_TYPE_SERIAL) > 0)
+				{
+					/* dima */
+					result = JNI_TRUE;
+				}
+			#endif
+			break;
+			
+		case PORT_TYPE_PARALLEL: 
+			break;
+			
+		case PORT_TYPE_I2C:	
+			break;
+			
+		case PORT_TYPE_RS485:	
+			break;
+			
+		case PORT_TYPE_RAW:	
+			break;
+			
 		default:
-			sprintf( message, "unknown portType %d handed to \
-				native RXTXCommDriver.registerKnownPorts() \
-				 method.\n",
-				(int) portType
-			);
+			memset(&message[0], 0, sizeof(message));
+			sprintf( message, "RXTXCommDriver_registerKnownPorts Unknown portType %d handed to native RXTXCommDriver.registerKnownPorts() method.\n", (int) portType);
 			report( message );
 	}
+	memset(&strbuf[0], 0, sizeof(strbuf));
+	sprintf(strbuf, "Leaving - RXTXCommDriver_registerKnownPorts(%i)\n", result);
+	report(strbuf);
+	
 	return result;
 }
 
 /*----------------------------------------------------------
  isPortPrefixValid
 
-   accept:      a port prefix
-   perform:     see if the port prefix matches a port that is valid on this OS.
-   return:      JNI_TRUE if it exists otherwise JNI_FALSE
-   exceptions:  none
-   comments:
+	accept:		a port prefix
+	perform:	see if the port prefix matches a port that is valid on this OS.
+	return:		JNI_TRUE if it exists otherwise JNI_FALSE
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 JNIEXPORT jboolean  JNICALL RXTXCommDriver(isPortPrefixValid)(JNIEnv *env,
 	jobject jobj, jstring tty_name)
@@ -4686,87 +4929,106 @@
 	jboolean result;
 	static struct stat mystat;
 	char teststring[256];
+	char strbuf[256];
 	int fd,i;
 	const char *name = (*env)->GetStringUTFChars(env, tty_name, 0);
 
-	ENTER( "RXTXCommDriver:isPortPrefixValid" );
-	for(i=0;i<64;i++){
-#if defined(__sun__)
-		/* Solaris uses /dev/cua/a instead of /dev/cua0 */
-		if( i > 25 ) break;
-		sprintf(teststring,"%s%s%c",DEVICEDIR, name, i + 97 );
-		fprintf(stderr, "testing: %s\n", teststring);
-#else
-#if defined(_GNU_SOURCE)
-		snprintf(teststring, 256, "%s%s%i",DEVICEDIR,name, i);
-#else
-		sprintf(teststring,"%s%s%i",DEVICEDIR,name, i);
-#endif /* _GNU_SOURCE */
-		stat(teststring,&mystat);
-#endif /* __sun__ */
-/* XXX the following hoses freebsd when it tries to open the port later on */
-#ifndef __FreeBSD__
-		if(S_ISCHR(mystat.st_mode)){
-			fd=OPEN(teststring,O_RDONLY|O_NONBLOCK);
-			if (fd>0){
-				CLOSE(fd);
-				result=JNI_TRUE;
-				break;
+	report( "Entering - RXTXCommDriver:isPortPrefixValid\n" );
+	for(i=0;i<64;i++)
+	{
+		#if defined(__sun__)
+			/* Solaris uses /dev/cua/a instead of /dev/cua0 */
+			if( i > 25 ) break;
+			sprintf(teststring,"%s%s%c\n",DEVICEDIR, name, i + 97 );
+			fprintf(stderr, "testing: %s\n", teststring);
+		#else
+			#if defined(_GNU_SOURCE)
+				snprintf(teststring, 256, "%s%s%i\n",DEVICEDIR,name, i);
+			#else
+				sprintf(teststring,"%s%s%i\n",DEVICEDIR,name, i);
+			#endif /* _GNU_SOURCE */
+			stat(teststring,&mystat);
+		#endif /* __sun__ */
+
+		/* XXX the following hoses freebsd when it tries to open the port later on */
+		#ifndef __FreeBSD__
+			if(S_ISCHR(mystat.st_mode))
+			{
+				fd=OPEN(teststring,O_RDONLY|O_NONBLOCK);
+				if (fd>0)
+				{
+					CLOSE(fd);
+					result=JNI_TRUE;
+					break;
+				}
+				else
+				{
+					result=JNI_FALSE;
+				}
 			}
 			else
+			{
 				result=JNI_FALSE;
-		}
-		else
-			result=JNI_FALSE;
-#else
-		result=JNI_TRUE;
-#endif  /* __FreeBSD __ */
+			}
+		#else
+			result=JNI_TRUE;
+		#endif  /* __FreeBSD __ */
 	}
-#if defined(_GNU_SOURCE)
-	snprintf(teststring, 256, "%s%s",DEVICEDIR,name);
-#else
-	sprintf(teststring,"%s%s",DEVICEDIR,name);
-#endif /* _GNU_SOURCE */
+	
+	#if defined(_GNU_SOURCE)
+		snprintf(teststring, 256, "%s%s",DEVICEDIR,name);
+	#else
+		sprintf(teststring,"%s%s",DEVICEDIR,name);
+	#endif /* _GNU_SOURCE */
+	
 	stat(teststring,&mystat);
-	if(S_ISCHR(mystat.st_mode)){
+	
+	if(S_ISCHR(mystat.st_mode))
+	{
 		fd=OPEN(teststring,O_RDONLY|O_NONBLOCK);
-		if (fd>0){
+		if (fd>0)
+		{
 			CLOSE(fd);
 			result=JNI_TRUE;
 		}
 	}
+	
 	(*env)->ReleaseStringUTFChars(env, tty_name, name);
-	LEAVE( "RXTXCommDriver:isPortPrefixValid" );
+	
+	memset(&strbuf[0], 0, sizeof(strbuf));
+	sprintf(strbuf, "Leaving - RXTXCommDriver:isPortPrefixValid(%i)\n", result);
+	report(strbuf);
+	
 	return(result);
 }
 
 /*----------------------------------------------------------
  getDeviceDirectory
 
-   accept:
-   perform:
-   return:      the directory containing the device files
-   exceptions:
-   comments:    use this to avoid hard coded "/dev/"
-   		values are in SerialImp.h
+	accept:
+	perform:
+	return:		the directory containing the device files
+	exceptions:
+	comments:	use this to avoid hard coded "/dev/"
+				values are in SerialImp.h
 ----------------------------------------------------------*/
 
 JNIEXPORT jstring  JNICALL RXTXCommDriver(getDeviceDirectory)(JNIEnv *env,
 	jobject jobj)
 {
-	ENTER( "RXTXCommDriver:getDeviceDirectory" );
+	report( "Entering - RXTXCommDriver:getDeviceDirectory\n" );
 	return (*env)->NewStringUTF(env, DEVICEDIR);
-	LEAVE( "RXTXCommDriver:getDeviceDirectory" );
+	report( "Leaving - RXTXCommDriver:getDeviceDirectory\n" );
 }
 
 /*----------------------------------------------------------
  setInputBufferSize
 
-   accept:
-   perform:
-   return:      none
-   exceptions:  none
-   comments:    see fopen/fclose/fwrite/fread man pages.
+	accept:
+	perform:
+	return:		none
+	exceptions:	none
+	comments:	see fopen/fclose/fwrite/fread man pages.
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setInputBufferSize)(JNIEnv *env,
 	jobject jobj,  jint size )
@@ -4777,11 +5039,11 @@
 /*----------------------------------------------------------
  getIputBufferSize
 
-   accept:
-   perform:
-   return:      none
-   exceptions:  none
-   comments:    see fopen/fclose/fwrite/fread man pages.
+	accept:
+	perform:
+	return:		none
+	exceptions:	none
+	comments:	see fopen/fclose/fwrite/fread man pages.
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(getInputBufferSize)(JNIEnv *env,
 	jobject jobj)
@@ -4793,11 +5055,11 @@
 /*----------------------------------------------------------
  setOutputBufferSize
 
-   accept:
-   perform:
-   return:      none
-   exceptions:  none
-   comments:    see fopen/fclose/fwrite/fread man pages.
+	accept:
+	perform:
+	return:		none
+	exceptions:	none
+	comments:	see fopen/fclose/fwrite/fread man pages.
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(setOutputBufferSize)(JNIEnv *env,
 	jobject jobj, jint size )
@@ -4808,11 +5070,11 @@
 /*----------------------------------------------------------
  getOutputBufferSize
 
-   accept:
-   perform:
-   return:      none
-   exceptions:  none
-   comments:    see fopen/fclose/fwrite/fread man pages.
+	accept:
+	perform:
+	return:		none
+	exceptions:	none
+	comments:	see fopen/fclose/fwrite/fread man pages.
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL RXTXPort(getOutputBufferSize)(JNIEnv *env,
 	jobject jobj)
@@ -4824,23 +5086,33 @@
 /*----------------------------------------------------------
  interruptEventLoop
 
-   accept:      nothing
-   perform:     increment eventloop_interrupted
-   return:      nothing
-   exceptions:  none
-   comments:    all eventloops in this PID will check if their thread
-		is interrupted.  When all the interrupted threads exit
-		they will decrement the var leaving it 0.
-		the remaining threads will continue.
+	accept:		nothing
+	perform:	increment eventloop_interrupted
+	return:		nothing
+	exceptions:	none
+	comments:	all eventloops in this PID will check if their thread
+				is interrupted.  When all the interrupted threads exit
+				they will decrement the var leaving it 0.
+				the remaining threads will continue.
 ----------------------------------------------------------*/
-JNIEXPORT void JNICALL RXTXPort(interruptEventLoop)(JNIEnv *env,
-	jobject jobj)
+JNIEXPORT void JNICALL RXTXPort(interruptEventLoop)(
+	JNIEnv *env,
+	jobject jobj
+)
 {
+	report("Entering - RXTXPort_interruptEventLoop\n");
+	
 	struct event_info_struct *index = master_index;
+	
 	int fd = get_java_var( env, jobj, "fd", "I" );
+	
 	int searching = 1;
-
-
+	int waiting = 1;
+	int loop_count = 0;
+	char buff[ 60 ] = "";
+	
+	report("RXTXPort_interruptEventLoop - Searching...\n");
+	
 	while( searching )
 	{
 		index = master_index;
@@ -4852,63 +5124,161 @@
 		}
 		else
 			report("x");
+			
 		if( searching )
 		{
 			report("@");
 			usleep(1000);
 		}
 	}
+	report("RXTXPort_interruptEventLoop - Searched\n");
+	
+	/**
+	* We now set a flag for the drain_loop thread to jump to it's end.
+	**/
+	
 	index->eventloop_interrupted = 1;
-	/*
-	Many OS's need a thread running to determine if output buffer is
-	empty.  For Linux and Win32 it is not needed.  So closing is used to
-	shut down the thread in the write order on OS's that don't have
-	kernel support for output buffer empty.
-
-	In rxtx TIOCSERGETLSR is defined for win32 and Linux
-	*/
-#ifdef TIOCSERGETLSR
-	index->closing=1;
-#endif /* TIOCSERGETLSR */
-#ifdef WIN32
-	termios_interrupt_event_loop( index->fd, 1 );
-#endif /* WIN32 */
-#if !defined(TIOCSERGETLSR) && !defined(WIN32)
-	/* make sure that the drainloop unblocks from tcdrain */
-	pthread_kill(index->drain_tid, SIGABRT);
-	/* TODO use wait/join/SIGCHLD/?? instead of sleep? */
-	usleep(50 * 1000);
-	/*
-	Under normal conditions, SIGABRT will unblock tcdrain. However
-	a non-responding USB device combined with an unclean driver
-	may still block. This is very ugly because it may block the call
-	to close indefinetly.
-	*/
-	if (index->closing != 1) {
-		/* good bye tcdrain, and thanks for all the fish */
-		report("interruptEventLoop: canceling blocked drain thread\n");
-		pthread_cancel(index->drain_tid);
-		index->closing = 1;
-	}
-#endif
-	report("interruptEventLoop: interrupted\n");
+	
+	report("RXTXPort_interruptEventLoop - Interrupted\n");
+	
+	/**
+	*	Many OS's need a thread running to determine if output buffer is
+	*	empty.  For Linux and Win32 it is not needed.  So closing is
+	*	used to shut down the thread in the write order on OS's that
+	*	don't have kernel support for output buffer empty.
+	*	
+	*	In rxtx TIOCSERGETLSR:
+	*		is defined for win32 and Linux
+	* 		is not defined for FreeBSD 10.1-p9 i386
+	*		Other OSs not tested; not available...
+	*	
+	*	(
+	*		From looking at the RXTX source code tarball, TIOCSERGETLSR
+	*		is only manually defined if on WinCE, unless set / supported
+	*		by OS dependant c precompiler...
+	*	)
+	**/
+	
+	#ifdef TIOCSERGETLSR
+		report("RXTXPort_interruptEventLoop - TIOCSERGETLSR defined\n");
+		index->closing=1;
+	#endif /* TIOCSERGETLSR */
+	
+	#ifdef WIN32
+		report("RXTXPort_interruptEventLoop - WIN32 defined\n");
+		termios_interrupt_event_loop( index->fd, 1 );
+	#endif /* WIN32 */
+	
+	#if !defined(TIOCSERGETLSR) && !defined(WIN32)
+	
+		report("RXTXPort_interruptEventLoop - TIOCSERGETLSR and WIN32 not defined\n");
+		/* make sure that the drainloop unblocks from tcdrain */
+	
+		/**
+		*	JCE: This was supposed to kill off drain_loop...
+		* 	CORE DUMP seen with original code on i386 FreeBSD v10.1-p9.
+		*	
+		* 	As eventloop_interrupted is set to 1 above, the attempted
+		*	forced closure of the thread is now not needed: the thread
+		*	kills its self off politely when it sees the flag.
+		*	
+		*	Going to wait 1/20th + 1 of the maximum sleep time
+		*	(SUN = 5000, ANOs=1000000) and see if it has cancelled.
+		* 	After 20 iterations we have waited for the entire sleep,
+		*	at which point we just get on with it and will be caught by
+		*	the good bye tcdrain code block at the end of this function.
+		**/
+		
+		memset(&buff[0], 0, sizeof(buff));
+		sprintf( buff, "RXTXPort_interruptEventLoop - Closing State is %i\n", index->closing );
+		report (buff);
+		
+		report("RXTXPort_interruptEventLoop - Going to wait for thread to say it is closing\n");
+		
+		loop_count = 0;		
+		while( waiting )
+		{
+			report("RXTXPort_interruptEventLoop - Waiting\n");
+			usleep(5001);
+			loop_count = loop_count + 1;
+			if ((index->closing) == 1) waiting = 0;
+			if (loop_count > 20) waiting = 0;
+		}
+		
+		memset(&buff[0], 0, sizeof(buff));
+		sprintf( buff, "RXTXPort_interruptEventLoop - Closing State is now %i\n", index->closing );
+		report (buff);
+		
+		/**
+		*	The command below was being sent to the relevant thread,
+		*	however under POSIX spec this abort signal applies to the
+		* 	whole process, NOT the thread.
+		*	
+		*	However, if RXTX is being call by something else in Java,
+		*	this causes the parent enumaertor and the entire JRE to
+		*	SIGABRT, resulting in a Java Core Dump (as requested)!
+		*	
+		*	Not sure what this call was supposed to achive; Have
+		*	included new wait loop above to ensure that we wait for the
+		*	thread to pick up that we have asked for it to exit:
+		* 
+		*		index->eventloop_interrupted = 1;
+		*	
+		*	No way for checking if an OS is POSIX compliant with
+		*	pthread_kill, when TIOCSERGETLSR is not defined?
+		**/ 	
+		
+		/**	
+		*	pthread_kill(index->drain_tid, SIGABRT);	
+		**/
+		
+		report("***RXTXPort_interruptEventLoop - Thread Killed\n");
+		
+		/* TODO use wait/join/SIGCHLD/?? instead of sleep? */
+	
+		report("RXTXPort_interruptEventLoop - Sleeping now...\n");
+		usleep(50 * 1000);
+		
+		report("RXTXPort_interruptEventLoop - Waking up...\n");
+		
+		/**
+		*	Under normal conditions, SIGABRT will unblock tcdrain. However
+		*	a non-responding USB device combined with an unclean driver
+		*	may still block. This is very ugly because it may block the call
+		*	to close indefinetly.
+		* 
+		*	UPDATE to above statement:
+		*		SIGABRT does not have the expected results in a
+		*		POSIX environment.
+		**/
+	
+		if (index->closing != 1) {
+			/* good bye tcdrain, and thanks for all the fish */
+			report("interruptEventLoop: canceling blocked drain thread\n");
+			pthread_cancel(index->drain_tid);
+			index->closing = 1;
+		}
+		
+	#endif
+	
+	report("Leaving - interruptEventLoop\n");
 }
 
 /*----------------------------------------------------------
  is_interrupted
 
-   accept:      event_info_struct
-   perform:     see if the port is being closed.
-   return:      a positive value if the port is being closed.
-   exceptions:  none
-   comments:
+	accept:		event_info_struct
+	perform:	see if the port is being closed.
+	return:		a positive value if the port is being closed.
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 jboolean is_interrupted( struct event_info_struct *eis )
 {
 	int result;
 	JNIEnv *env = eis->env;
 
-	ENTER( "is_interrupted" );
+	report( "Entering - is_interrupted\n" );
 	(*env)->ExceptionClear(env);
 	result = (*env)->CallBooleanMethod( env, *eis->jobj,
 			eis->checkMonitorThread );
@@ -4919,18 +5289,18 @@
 		(*env)->ExceptionClear(env);
 	}
 #endif /* DEBUG */
-	LEAVE( "RXTXCommDriver:is_interrupted" );
+	report( "Leaving - RXTXCommDriver:is_interrupted\n" );
 	return(result);
 }
 
 /*----------------------------------------------------------
  nativeSetEventFlag
 
-   accept:      fd for finding the struct, event to flag, flag.
-   perform:     toggle the flag
-   return:      none
-   exceptions:  none
-   comments:	all the logic used to be done in Java but its too noisy
+	accept:	fd for finding the struct, event to flag, flag.
+	perform:	toggle the flag
+	return:		none
+	exceptions:	none
+	comments:	all the logic used to be done in Java but its too noisy
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL RXTXPort(nativeSetEventFlag)( JNIEnv *env,
 							jobject jobj,
@@ -4964,11 +5334,11 @@
 /*----------------------------------------------------------
  send_event
 
-   accept:      event_info_structure, event type and true/false
-   perform:     if state is > 0 send a JNI_TRUE event otherwise send JNI_FALSE
-   return:      a positive value if the port is being closed.
-   exceptions:  none
-   comments:
+	accept:		event_info_structure, event type and true/false
+	perform:	if state is > 0 send a JNI_TRUE event otherwise send JNI_FALSE
+	return:		a positive value if the port is being closed.
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 int send_event( struct event_info_struct *eis, jint type, int flag )
 {
@@ -4977,7 +5347,7 @@
 	if( eis ) env = eis->env;
 	else return(-1);
 
-	ENTER( "send_event" );
+	report( "Entering - send_event\n" );
 	if( !eis || eis->eventloop_interrupted > 1 )
 	{
 		report("event loop interrupted\n");
@@ -5002,18 +5372,18 @@
 	}
 #endif /* asdf */
 	/* report("e"); */
-	LEAVE( "send_event" );
+	report( "Leaving - send_event\n" );
 	return(result);
 }
 
 /*----------------------------------------------------------
 get_java_var
 
-   accept:      env (keyhole to java)
-                jobj (java RXTXPort object)
-   return:      the fd field from the java object
-   exceptions:  none
-   comments:
+	accept:		env (keyhole to java)
+			 	jobj (java RXTXPort object)
+	return:		the fd field from the java object
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 size_t get_java_var( JNIEnv *env, jobject jobj, char *id, char *type ) {
   return (size_t) get_java_var_long( env, jobj, id, type );
@@ -5026,26 +5396,26 @@
 	jfieldID jfd = (*env)->GetFieldID( env, jclazz, id, type );
 
 /*
-	ENTER( "get_java_var" );
+	report( "Entering - get_java_var\n" );
 */
 	if( !jfd ) {
 		(*env)->ExceptionDescribe( env );
 		(*env)->ExceptionClear( env );
 		(*env)->DeleteLocalRef( env, jclazz );
-		LEAVE( "get_java_var" );
+		report( "Leaving - get_java_var\n" );
 		return result;
 	}
 	if ( !strcmp( type, "J" ) ) {
-	  result = (long)( (*env)->GetLongField( env, jobj, jfd ) );
+	 result = (long)( (*env)->GetLongField( env, jobj, jfd ) );
 	} else {
-	  result = (size_t) ( (*env)->GetIntField( env, jobj, jfd ) );
+	 result = (size_t) ( (*env)->GetIntField( env, jobj, jfd ) );
 	}
 /* ct7 & gel * Added DeleteLocalRef */
 	(*env)->DeleteLocalRef( env, jclazz );
 	if(!strncmp( "fd",id,2) && result == 0)
 		report_error( "get_java_var: invalid file descriptor\n" );
 /*
-	LEAVE( "get_java_var" );
+	report( "Leaving - get_java_var\n" );
 */
 	return result;
 }
@@ -5053,110 +5423,132 @@
 /*----------------------------------------------------------
 throw_java_exception
 
-   accept:      env (keyhole to java)
-                *exc (exception class name)
-                *foo (function name)
-                *msg (error message)
-   perform:     Throw a new java exception
-   return:      none
-   exceptions:  haha!
-   comments:
+	accept:		env (keyhole to java)
+				*exc (exception class name)
+				*foo (function name)
+				*msg (error message)
+	perform:	Throw a new java exception
+	return:		none
+	exceptions:	haha!
+	comments:
 ----------------------------------------------------------*/
 void throw_java_exception( JNIEnv *env, char *exc, char *foo, char *msg )
 {
 	char buf[ 60 ];
 	jclass clazz = (*env)->FindClass( env, exc );
-	ENTER( "throw_java_exception" );
+	report( "Entering - throw_java_exception\n" );
 	if( !clazz ) {
 		(*env)->ExceptionDescribe( env );
 		(*env)->ExceptionClear( env );
-		LEAVE( "throw_java_exception" );
+		report( "Leaving - throw_java_exception\n" );
 		return;
 	}
+	memset(&buf[0], 0, sizeof(buf));
 #if defined(_GNU_SOURCE)
-	snprintf( buf, 60, "%s in %s", msg, foo );
+	snprintf( buf, 60, "%s in %s\n", msg, foo );
 #else
-	sprintf( buf,"%s in %s", msg, foo );
+	sprintf( buf,"%s in %s\n", msg, foo );
 #endif /* _GNU_SOURCE */
 	(*env)->ThrowNew( env, clazz, buf );
 /* ct7 * Added DeleteLocalRef */
 	(*env)->DeleteLocalRef( env, clazz );
-	LEAVE( "throw_java_exception" );
+	report( "Leaving - throw_java_exception\n" );
 }
 
 /*----------------------------------------------------------
  report_warning
 
-   accept:      string to send to report as an message
-   perform:     send the string to stderr or however it needs to be reported.
-   return:      none
-   exceptions:  none
-   comments:
+	accept:		string to send to report as an message
+	perform:	send the string to stderr or however it needs to be reported.
+	return:		none
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void report_warning(char *msg)
 {
-#ifndef DEBUG_MW
-	fprintf(stderr, msg);
-#else
-	mexWarnMsgTxt( (const char *) msg );
-#endif /* DEBUG_MW */
+	
+	#if defined(DEBUG_STDOUT)
+		report(msg);
+	#endif
+	
+	#ifdef DEBUG
+		fprintf(stderr, "%s", msg);
+	#endif
+	
 }
 
 /*----------------------------------------------------------
  report_verbose
 
-   accept:      string to send to report as an verbose message
-   perform:     send the string to stderr or however it needs to be reported.
-   return:      none
-   exceptions:  none
-   comments:
+	accept:		string to send to report as an verbose message
+	perform:	send the string to stderr or however it needs to be reported.
+	return:		none
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void report_verbose(char *msg)
 {
-#ifdef DEBUG_VERBOSE
-#ifdef DEBUG_MW
-	mexErrMsgTxt( msg );
-#else
-	fprintf(stderr, msg);
-#endif /* DEBUG_MW */
-#endif /* DEBUG_VERBOSE */
+	
+	#if defined(DEBUG_STDOUT)
+		report(msg);
+	#endif
+	
+	#ifdef DEBUG
+		fprintf(stderr, "%s", msg);
+	#endif
+	
 }
 /*----------------------------------------------------------
  report_error
 
-   accept:      string to send to report as an error
-   perform:     send the string to stderr or however it needs to be reported.
-   return:      none
-   exceptions:  none
-   comments:
+	accept:	string to send to report as an error
+	perform:	send the string to stderr or however it needs to be reported.
+	return:		none
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void report_error(char *msg)
 {
-#ifndef DEBUG_MW
-	fprintf(stderr, msg);
-#else
-	mexWarnMsgTxt( msg );
-#endif /* DEBUG_MW */
+	
+	#if defined(DEBUG_STDOUT)
+		report(msg);
+	#endif
+	
+	#ifdef DEBUG
+		fprintf(stderr, "%s", msg);
+	#endif
+	
 }
 
 /*----------------------------------------------------------
  report
 
-   accept:      string to send to stderr
-   perform:     if DEBUG is defined send the string to stderr.
-   return:      none
-   exceptions:  none
-   comments:
+	accept:	string to send to stderr
+	perform:	if DEBUG is defined send the string to stderr.
+	return:		none
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 void report(char *msg)
 {
-#ifdef DEBUG
-#	ifndef DEBUG_MW
-		fprintf(stderr, msg);
-#	else
-		mexPrintf( msg );
-#	endif /* DEBUG_MW */
-#endif /* DEBUG */
+	#if defined(DEBUG_STDOUT)
+		
+		char message[1024] = "";
+		char fmsg[1024] = "";
+		
+		memset(&fmsg[0], 0, sizeof(fmsg));
+		strcat ( fmsg, "SerialImp.c: " );
+		strcat ( fmsg, msg );
+		
+		memset(&message[0], 0, sizeof(message));
+		sprintf( message, "%s", fmsg);
+		fprintf(stdout, "%s", message);
+		
+	#endif
+	
+	#ifdef DEBUG
+		fprintf(stderr, "%s", msg);
+	#endif /* DEBUG */
 }
 
 #ifndef WIN32
@@ -5164,12 +5556,12 @@
 /*----------------------------------------------------------
  lfs_lock
 
-   accept:      The name of the device to try to lock
-   perform:     Create a lock file if there is not one already using a
-                lock file server.
-   return:      1 on failure 0 on success
-   exceptions:  none
-   comments:
+	accept:		The name of the device to try to lock
+	perform:	Create a lock file if there is not one already using a
+				lock file server.
+	return:		1 on failure 0 on success
+	exceptions:	none
+	comments:
 
 ----------------------------------------------------------*/
 int lfs_lock( const char *filename, int pid )
@@ -5189,7 +5581,7 @@
 	if ( !connect( s, ( struct sockaddr * ) &addr, sizeof( addr ) ) == 0 )
 		return 1;
 	ret=recv( s, buffer, size, 0 );
-	sprintf( buffer, "lock %s %i\n", filename, pid );
+	sprintf( buffer, "lock %s %i", filename, pid );
 	/* printf( "%s", buffer ); */
 	send( s, buffer, strlen(buffer), 0 );
 	ret=recv( s, buffer, size, 0 );
@@ -5208,12 +5600,12 @@
 /*----------------------------------------------------------
  lfs_unlock
 
-   accept:      The name of the device to try to unlock
-   perform:     Remove a lock file if there is one using a
-                lock file server.
-   return:      1 on failure 0 on success
-   exceptions:  none
-   comments:
+	accept:		The name of the device to try to unlock
+	perform:	Remove a lock file if there is one using a
+				lock file server.
+	return:		1 on failure 0 on success
+	exceptions:	none
+	comments:
 
 ----------------------------------------------------------*/
 int lfs_unlock( const char *filename, int pid )
@@ -5232,7 +5624,7 @@
 
 	if ( !connect( s, ( struct sockaddr * ) &addr, sizeof( addr ) ) == 0 )
 		return 1;
-	sprintf( buffer, "unlock %s %i\n", filename, pid );
+	sprintf( buffer, "unlock %s %i", filename, pid );
 	/* printf( "%s", buffer ); */
 	send( s, buffer, strlen(buffer), 0 );
 	ret = recv( s, buffer, size, 0 );
@@ -5251,14 +5643,14 @@
 /*----------------------------------------------------------
  lib_lock_dev_unlock
 
-   accept:      The name of the device to try to unlock
-   perform:     Remove a lock file if there is one using a
-                lock file server.
-   return:      1 on failure 0 on success
-   exceptions:  none
-   comments:    This is for use with liblockdev which comes with Linux
-		distros.  I suspect it will be problematic with embeded
-		Linux.   taj
+	accept:		The name of the device to try to unlock
+	perform:	Remove a lock file if there is one using a
+				lock file server.
+	return:		1 on failure 0 on success
+	exceptions:	none
+	comments:	This is for use with liblockdev which comes with Linux
+				distros. I suspect it will be problematic with embeded
+				Linux.	taj
 
 ----------------------------------------------------------*/
 #ifdef LIBLOCKDEV
@@ -5276,17 +5668,17 @@
 /*----------------------------------------------------------
  lib_lock_dev_lock
 
-   accept:      The name of the device to try to lock
-                termios struct
-   perform:     Create a lock file if there is not one already.
-   return:      1 on failure 0 on success
-   exceptions:  none
-   comments:    This is for use with liblockdev which comes with Linux
-		distros.  I suspect it will be problematic with embeded
-		Linux.   taj
+	accept:		The name of the device to try to lock
+				termios struct
+	perform:	Create a lock file if there is not one already.
+	return:		1 on failure 0 on success
+	exceptions:	none
+	comments:	This is for use with liblockdev which comes with Linux
+				distros.  I suspect it will be problematic with embeded
+				Linux.	taj
 
-		One could load the library here rather than link it and
-		always try to use this.
+				One could load the library here rather than link it and
+				always try to use this.
 
 ----------------------------------------------------------*/
 #ifdef LIBLOCKDEV
@@ -5301,6 +5693,7 @@
 	}
 	if ( dev_lock( filename ) )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message,
 			"RXTX fhs_lock() Error: creating lock file for: %s: %s\n",
 			filename, strerror(errno) );
@@ -5314,27 +5707,24 @@
 /*----------------------------------------------------------
  fhs_lock
 
-   accept:      The name of the device to try to lock
-                termios struct
-   perform:     Create a lock file if there is not one already.
-   return:      1 on failure 0 on success
-   exceptions:  none
-   comments:    This is for linux and freebsd only currently.  I see SVR4 does
-                this differently and there are other proposed changes to the
-		Filesystem Hierachy Standard
-
-		more reading:
-
+	accept:		The name of the device to try to lock
+				termios struct
+	perform:	Create a lock file if there is not one already.
+	return:		1 on failure 0 on success
+	exceptions:	none
+	comments:	This is for linux and freebsd only currently.  I see SVR4 does
+				this differently and there are other proposed changes to the
+				Filesystem Hierachy Standard
 ----------------------------------------------------------*/
 int fhs_lock( const char *filename, int pid )
 {
 	/*
-	 * There is a zoo of lockdir possibilities
-	 * Its possible to check for stale processes with most of them.
-	 * for now we will just check for the lockfile on most
-	 * Problem lockfiles will be dealt with.  Some may not even be in use.
-	 *
-	 */
+	* There is a zoo of lockdir possibilities
+	* Its possible to check for stale processes with most of them.
+	* for now we will just check for the lockfile on most
+	* Problem lockfiles will be dealt with.  Some may not even be in use.
+	*
+	*/
 	int fd,j;
 	char lockinfo[12], message[80];
 	char file[80], *p;
@@ -5342,7 +5732,7 @@
 	j = strlen( filename );
 	p = ( char * ) filename + j;
 	/*  FIXME  need to handle subdirectories /dev/cua/...
-	    SCO Unix use lowercase all the time
+		SCO Unix use lowercase all the time
 			taj
 	*/
 	while( *( p - 1 ) != '/' && j-- != 1 )
@@ -5361,13 +5751,15 @@
 	fd = open( file, O_CREAT | O_WRONLY | O_EXCL, 0444 );
 	if( fd < 0 )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message,
 			"RXTX fhs_lock() Error: creating lock file: %s: %s\n",
 			file, strerror(errno) );
 		report_error( message );
 		return 1;
 	}
-	sprintf( lockinfo, "%10d\n",(int) getpid() );
+	sprintf( lockinfo, "%10d",(int) getpid() );
+	memset(&message[0], 0, sizeof(message));
 	sprintf( message, "fhs_lock: creating lockfile: %s\n", lockinfo );
 	report( message );
 	write( fd, lockinfo, 11 );
@@ -5378,11 +5770,12 @@
 /*----------------------------------------------------------
  uucp_lock
 
-   accept:     char * filename.  Device to be locked
-   perform:    Try to get a uucp_lock
-   return:     int 0 on success
-   exceptions: none
-   comments:
+	accept:		char * filename.  Device to be locked
+	perform:	Try to get a uucp_lock
+	return:		int 0 on success
+	exceptions: none
+	comments:
+	
 		The File System Hierarchy Standard
 		http://www.pathname.com/fhs/
 
@@ -5408,9 +5801,9 @@
 			/var/lock
 		4) handle stale locks  (done except kermit locks)
 		5) handle minicom lockfile contents (FSSTND?)
-			"     16929 minicom root\n"  (done)
+			"	16929 minicom root\n"  (done)
 		6) there are other Lock conventions that use Major and Minor
-		   numbers...
+			numbers...
 		7) Stevens recommends LCK..<pid>
 
 		most are caught above.  If they turn out to be problematic
@@ -5424,7 +5817,8 @@
 	int fd;
 	struct stat buf;
 
-	sprintf( message, "uucp_lock( %s );\n", filename );
+	memset(&message[0], 0, sizeof(message));
+	sprintf( message, "uucp_lock(%s)\n", filename );
 	report( message );
 
 	if ( check_lock_status( filename ) )
@@ -5432,55 +5826,75 @@
 		report( "RXTX uucp check_lock_status true\n" );
 		return 1;
 	}
+	report("uucp_lock - getting STAT on lock dir\n");
 	if ( stat( LOCKDIR, &buf ) != 0 )
 	{
 		report( "RXTX uucp_lock() could not find lock directory.\n" );
 		return 1;
 	}
+	
+	report("uucp_lock - getting STAT on filename\n");
 	if ( stat( filename, &buf ) != 0 )
 	{
+		memset(&message[0], 0, sizeof(message));
 		report( "RXTX uucp_lock() could not find device.\n" );
 		sprintf( message, "uucp_lock: device was %s\n", name );
 		report( message );
 		return 1;
 	}
+	report("uucp_lock - generating lock filename\n");
 	sprintf( lockfilename, "%s/LK.%03d.%03d.%03d",
 		LOCKDIR,
 		(int) major( buf.st_dev ),
-	 	(int) major( buf.st_rdev ),
+		(int) major( buf.st_rdev ),
 		(int) minor( buf.st_rdev )
 	);
-	sprintf( lockinfo, "%10d\n", (int) getpid() );
+	report("uucp_lock - generating lock info\n");
+	sprintf( lockinfo, "%10d", (int) getpid() );
+	
+	report("uucp_lock - getting STAT on lock filename\n");
 	if ( stat( lockfilename, &buf ) == 0 )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message, "RXTX uucp_lock() %s is there\n",
 			lockfilename );
 		report( message );
 		report_error( message );
 		return 1;
 	}
+	
+	report("uucp_lock - Opening lock file\n");
 	fd = open( lockfilename, O_CREAT | O_WRONLY | O_EXCL, 0444 );
+	
+	
 	if( fd < 0 )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message,
 			"RXTX uucp_lock() Error: creating lock file: %s\n",
 			lockfilename );
 		report_error( message );
 		return 1;
 	}
+	else
+	{
+		report("uucp_lock - lock file created\n");
+	}
 	write( fd, lockinfo,11 );
+	report("uucp_lock - Writen lockinfo, closing on lock filen\n");
 	close( fd );
+	report("uucp_lock - returning (0)\n");
 	return 0;
 }
 
 /*----------------------------------------------------------
  check_lock_status
 
-   accept:      the lock name in question
-   perform:     Make sure everything is sane
-   return:      0 on success
-   exceptions:  none
-   comments:
+	accept:	the lock name in question
+	perform:	Make sure everything is sane
+	return:	0 on success
+	exceptions:	none
+	comments:
 ----------------------------------------------------------*/
 int check_lock_status( const char *filename )
 {
@@ -5515,13 +5929,13 @@
 /*----------------------------------------------------------
  fhs_unlock
 
-   accept:      The name of the device to unlock
-   perform:     delete the lock file
-   return:      none
-   exceptions:  none
-   comments:    This is for linux only currently.  I see SVR4 does this
-                differently and there are other proposed changes to the
-		Filesystem Hierachy Standard
+	accept:		The name of the device to unlock
+	perform:	delete the lock file
+	return:		none
+	exceptions:	none
+	comments:	This is for linux only currently.  I see SVR4 does this
+				differently and there are other proposed changes to the
+				Filesystem Hierachy Standard
 ----------------------------------------------------------*/
 void fhs_unlock( const char *filename, int openpid )
 {
@@ -5548,11 +5962,11 @@
 /*----------------------------------------------------------
  uucp_unlock
 
-   accept:     char *filename the device that is locked
-   perform:    remove the uucp lockfile if it exists
-   return:     none
-   exceptions: none
-   comments:   http://docs.freebsd.org/info/uucp/uucp.info.UUCP_Lock_Files.html
+	accept:		char *filename the device that is locked
+	perform:	remove the uucp lockfile if it exists
+	return:		none
+	exceptions: none
+	comments:	http://docs.freebsd.org/info/uucp/uucp.info.UUCP_Lock_Files.html
 ----------------------------------------------------------*/
 void uucp_unlock( const char *filename, int openpid )
 {
@@ -5560,34 +5974,46 @@
 	char file[80], message[80];
 	/* FIXME */
 
-	sprintf( message, "uucp_unlock( %s );\n", filename );
+	memset(&message[0], 0, sizeof(message));
+	sprintf( message, "uucp_unlock(%s);\n", filename );
 	report( message );
 
 	if ( stat( filename, &buf ) != 0 )
 	{
 		/* hmm the file is not there? */
-		report( "uucp_unlock() no such device\n" );
+		report( "uucp_unlock() - no such device\n" );
 		return;
 	}
+	else
+	{	
+		report( "uucp_unlock() - device exists\n" );
+	}
+	
 	sprintf( file, LOCKDIR"/LK.%03d.%03d.%03d",
 		(int) major( buf.st_dev ),
-	 	(int) major( buf.st_rdev ),
+		(int) major( buf.st_rdev ),
 		(int) minor( buf.st_rdev )
 	);
+	
+	report( "uucp_unlock() - going to stat\n" );
 	if ( stat( file, &buf ) != 0 )
 	{
 		/* hmm the file is not there? */
 		report( "uucp_unlock no such lockfile\n" );
 		return;
 	}
+	report( "uucp_unlock() - going to check lock pid\n" );
 	if( !check_lock_pid( file, openpid ) )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message, "uucp_unlock: unlinking %s\n", file );
 		report( message );
 		unlink(file);
+		report( "uucp_unlock() - Unlink completed\n" );
 	}
 	else
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf( message, "uucp_unlock: unlinking failed %s\n", file );
 		report( message );
 	}
@@ -5596,11 +6022,11 @@
 /*----------------------------------------------------------
  check_lock_pid
 
-   accept:     the name of the lockfile
-   perform:    make sure the lock file is ours.
-   return:     0 on success
-   exceptions: none
-   comments:
+	accept:		the name of the lockfile
+	perform:	make sure the lock file is ours.
+	return:		0 on success
+	exceptions: none
+	comments:
 ----------------------------------------------------------*/
 int check_lock_pid( const char *file, int openpid )
 {
@@ -5624,6 +6050,7 @@
 	/* Native threads JVM's have multiple pids */
 	if ( lockpid != getpid() && lockpid != getppid() && lockpid != openpid )
 	{
+		memset(&message[0], 0, sizeof(message));
 		sprintf(message, "check_lock_pid: lock = %s pid = %i gpid=%i openpid=%i\n",
 			pid_buffer, (int) getpid(), (int) getppid(), openpid );
 		report( message );
@@ -5635,16 +6062,17 @@
 /*----------------------------------------------------------
  check_group_uucp
 
-   accept:     none
-   perform:    check if the user is root or in group uucp
-   return:     0 on success
-   exceptions: none
-   comments:
+	accept:		none
+	perform:	check if the user is root or in group uucp
+	return:		0 on success
+	exceptions: none
+	comments:
 		This checks if the effective user is in group uucp so we can
 		create lock files.  If not we give them a warning and bail.
 		If its root we just skip the test.
 
-		if someone really wants to override this they can use the			USER_LOCK_DIRECTORY --not recommended.
+		if someone really wants to override this they can use the
+		USER_LOCK_DIRECTORY --not recommended.
 
 		In a recent change RedHat 7.2 decided to use group lock.
 		In order to get around this we just check the group id
@@ -5674,7 +6102,7 @@
 			+ strlen(testLockFileName) + 2, sizeof(char));
 	if ( NULL == testLockAbsFileName )
 	{
-		report_error("check_group_uucp(): Insufficient memory");
+		report_error("check_group_uucp(): Insufficient memory\n");
 		return 1;
 	}
 	strcat(testLockAbsFileName, testLockFileDirName);
@@ -5683,16 +6111,14 @@
 	if ( NULL == mktemp(testLockAbsFileName) )
 	{
 		free(testLockAbsFileName);
-		report_error("check_group_uucp(): mktemp malformed string - \
-			should not happen");
+		report_error("check_group_uucp(): mktemp malformed string - should not happen\n");
 
 		return 1;
 	}
 	testLockFile = fopen (testLockAbsFileName, "w+");
 	if (NULL == testLockFile)
 	{
-		report_error("check_group_uucp(): error testing lock file "
-			"creation Error details:");
+		report_error("check_group_uucp(): error testing lock file creation Error details:\n");
 		report_error(strerror(errno));
 		free(testLockAbsFileName);
 		return 1;
@@ -5717,7 +6143,8 @@
 
 	if( stat( LOCKDIR, &buf) )
 	{
-		sprintf( msg, "check_group_uucp:  Can not find Lock Directory: %s\n", LOCKDIR );
+		memset(&msg[0], 0, sizeof(msg));
+		sprintf( msg, "check_group_uucp:	Can not find Lock Directory: %s\n", LOCKDIR );
 		report_error( msg );
 		return( 1 );
 	}
@@ -5741,6 +6168,7 @@
 		}
 		if( buf.st_gid == list[ group_count ] )
 			return 0;
+		memset(&msg[0], 0, sizeof(msg));
 		sprintf( msg, "%i %i\n", buf.st_gid, list[ group_count ] );
 		report_error( msg );
 		report_error( UUCP_ERROR );
@@ -5776,7 +6204,7 @@
  for information.
 
  * realpath() doesn't exist on all of the systems my code has to run
-   on (HP-UX 9.x, specifically)
+	on (HP-UX 9.x, specifically)
 ----------------------------------------------------------
 int different_from_LOCKDIR(const char* ld)
 {
@@ -5798,13 +6226,13 @@
 /*----------------------------------------------------------
  is_device_locked
 
-   accept:      char * filename.  The device in question including the path.
-   perform:     see if one of the many possible lock files is aready there
-		if there is a stale lock, remove it.
-   return:      1 if the device is locked or somethings wrong.
-		0 if its possible to create our own lock file.
-   exceptions:  none
-   comments:    check if the device is already locked
+	accept:		char * filename.  The device in question including the path.
+	perform:	see if one of the many possible lock files is aready there
+				if there is a stale lock, remove it.
+	return:		1 if the device is locked or somethings wrong.
+				0 if its possible to create our own lock file.
+	exceptions:	none
+	comments:	check if the device is already locked
 ----------------------------------------------------------*/
 int is_device_locked( const char *port_filename )
 {
@@ -5828,12 +6256,12 @@
 	while( lockdirs[i] )
 	{
 		/*
-		   Look for lockfiles in all known places other than the
-		   defined lock directory for this system
-		   report any unexpected lockfiles.
+			Look for lockfiles in all known places other than the
+			defined lock directory for this system
+			report any unexpected lockfiles.
 
-		   Is the suspect lockdir there?
-		   if it is there is it not the expected lock dir?
+			Is the suspect lockdir there?
+			if it is there is it not the expected lock dir?
 		*/
 		if( !stat( lockdirs[i], &buf2 ) &&
 			buf2.st_ino != lockbuf.st_ino &&
@@ -5842,7 +6270,7 @@
 			j = strlen( port_filename );
 			p = ( char *  ) port_filename + j;
 		/*
-		   SCO Unix use lowercase all the time
+			SCO Unix use lowercase all the time
 			taj
 		*/
 			while( *( p - 1 ) != '/' && j-- != 1 )
@@ -5860,7 +6288,8 @@
 					lockprefixes[k], p );
 				if( stat( file, &buf ) == 0 )
 				{
-					sprintf( message, UNEXPECTED_LOCK_FILE,
+					memset(&message[0], 0, sizeof(message));
+					sprintf( message, "%s%s\n", UNEXPECTED_LOCK_FILE,
 						file );
 					report_warning( message );
 					return 1;
@@ -5877,7 +6306,8 @@
 				);
 				if( stat( file, &buf ) == 0 )
 				{
-					sprintf( message, UNEXPECTED_LOCK_FILE,
+					memset(&message[0], 0, sizeof(message));
+					sprintf( message, "%s%s\n", UNEXPECTED_LOCK_FILE,
 						file );
 					report_warning( message );
 					return 1;
@@ -5934,13 +6364,15 @@
 
 		if( kill( (pid_t) pid, 0 ) && errno==ESRCH )
 		{
+			memset(&message[0], 0, sizeof(message));
 			sprintf( message,
-				"RXTX Warning:  Removing stale lock file. %s\n",
+				"RXTX Warning:	Removing stale lock file. %s\n",
 				file );
 			report_warning( message );
 			if( unlink( file ) != 0 )
 			{
-				snprintf( message, 80, "RXTX Error:  Unable to \
+				memset(&message[0], 0, sizeof(message));
+				snprintf( message, 80, "RXTX Error:	Unable to \
 					remove stale lock file: %s\n",
 					file
 				);
@@ -5956,11 +6388,11 @@
 /*----------------------------------------------------------
  system_does_not_lock
 
-   accept:      the filename the system thinks should be locked.
-   perform:     avoid trying to create lock files on systems that dont use them
-   return:      0 for success ;)
-   exceptions:  none
-   comments:    OS's like Win32 may not have lock files.
+	accept:		the filename the system thinks should be locked.
+	perform:	avoid trying to create lock files on systems that dont use them
+	return:		0 for success ;)
+	exceptions:	none
+	comments:	OS's like Win32 may not have lock files.
 ----------------------------------------------------------*/
 int system_does_not_lock( const char * filename, int pid )
 {
@@ -5970,11 +6402,11 @@
 /*----------------------------------------------------------
  system_does_not_unlock
 
-   accept:      the filename the system thinks should be locked.
-   perform:     avoid trying to create lock files on systems that dont use them
-   return:      none
-   exceptions:  none
-   comments:    OS's like Win32 may not have lock files.
+	accept:		the filename the system thinks should be locked.
+	perform:	avoid trying to create lock files on systems that dont use them
+	return:		none
+	exceptions:	none
+	comments:	OS's like Win32 may not have lock files.
 ----------------------------------------------------------*/
 void system_does_not_unlock( const char * filename, int openpid )
 {
@@ -5984,12 +6416,12 @@
 /*----------------------------------------------------------
  dump_termios
 
-   accept:      string to indicate where this was called.
-                termios struct
-   perform:     print the termios struct to stderr.
-   return:      none
-   exceptions:  none
-   comments:    used to debug the termios struct.
+	accept:		string to indicate where this was called.
+				termios struct
+	perform:	print the termios struct to stderr.
+	return:		none
+	exceptions:	none
+	comments:	used to debug the termios struct.
 ----------------------------------------------------------*/
 void dump_termios(char *foo,struct termios *ttyset)
 {
@@ -6012,12 +6444,12 @@
 /*----------------------------------------------------------
 get_java_environment
 
-   accept:      pointer to the virtual machine
-		flag to know if we are attached
-   return:      pointer to the Java Environment
-   exceptions:  none
-   comments:    see JNI_OnLoad.  For getting the JNIEnv in the thread
-		used to monitor for output buffer empty.
+	accept:		pointer to the virtual machine
+				flag to know if we are attached
+	return:		pointer to the Java Environment
+	exceptions:	none
+	comments:	see JNI_OnLoad.  For getting the JNIEnv in the thread
+				used to monitor for output buffer empty.
 ----------------------------------------------------------*/
 JNIEnv *get_java_environment(JavaVM *java_vm,  jboolean *was_attached){
 	void **env = NULL;
@@ -6045,15 +6477,15 @@
 /*----------------------------------------------------------
 JNI_OnLoad
 
-   accept:      JavaVM pointer to the Vertial Machine
-		void * reserved ???
-   return:      jint JNI version used.
-   exceptions:  none
-   comments:    http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-14.html
-		http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-12.html
-		grab the Java VM pointer when the library loads for later use
-		in the drain thread.  Also lets Java know we are using the
-		1.4 API so we can get pointers later.
+	accept:		JavaVM pointer to the Vertial Machine
+				void * reserved ???
+	return:		jint JNI version used.
+	exceptions:	none
+	comments:	http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-14.html
+				http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-12.html
+				grab the Java VM pointer when the library loads for later use
+				in the drain thread.  Also lets Java know we are using the
+				1.4 API so we can get pointers later.
 ----------------------------------------------------------*/
 JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *java_vm, void *reserved)
 {
@@ -6065,28 +6497,28 @@
 /*----------------------------------------------------------
 JNI_OnUnload
 
-   accept:      JavaVM pointer to the Vertial Machine
-		void * reserved ???
-   return:      none
-   exceptions:  none
-   comments:    http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-14.html
-		http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-12.html
-		final library cleanup here.
+	accept:		JavaVM pointer to the Vertial Machine
+				void * reserved ???
+	return:		none
+	exceptions:	none
+	comments:	http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-14.html
+				http://java.sun.com/j2se/1.4.2/docs/guide/jni/jni-12.html
+				final library cleanup here.
 ----------------------------------------------------------*/
 JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
 {
 	/* never called it appears */
-	printf("Experimental:  JNI_OnUnload called.\n");
+	printf("Experimental:	JNI_OnUnload called.\n");
 }
 
 #ifdef asdf
 /*----------------------------------------------------------
 printj
 
-   accept:      like vwprintf()
-   return:      number of jchars written or -1
-   exceptions:  none
-   comments:    prints data using System.out.print()
+	accept:		like vwprintf()
+	return:		number of jchars written or -1
+	exceptions:	none
+	comments:	prints data using System.out.print()
 ----------------------------------------------------------*/
 int printj(JNIEnv *env, wchar_t *fmt, ...)
 {
@@ -6158,4 +6590,3 @@
 	(*env)->CallStaticVoidMethod(env, cls, mid, 1);
 */
 #endif /* asdf */
-
