--- ros/src/WOKsite/wokinit.csh.orig	Fri May  6 20:12:00 2005
+++ ros/src/WOKsite/wokinit.csh	Wed Aug  9 21:56:14 2006
@@ -5,24 +5,26 @@
 set OS_PLATFORM=""
 if ( $OS_NAME == "SunOS" ) then
    set OS_PLATFORM="sun"
+else if ( $OS_NAME == "FreeBSD" ) then
+   set OS_PLATFORM="bsd"
 else if ( $OS_NAME == "Linux" ) then
    set OS_PLATFORM="lin"
 endif
 
 setenv WOKHOME ${CASROOT}/../wok
 setenv HOME ${WOKHOME}/site
-setenv WOK_LIBPATH ${WOKHOME}/lib/${OS_PLATFORM}
+setenv WOK_LIBPATH ${WOKHOME}/lib/
 
 setenv WOK_ROOTADMDIR ${WOKHOME}/wok_entities
 setenv WOK_SESSIONID ${HOME}
 
-setenv TCLHOME ${CASROOT}/../3rdparty/${OS_NAME}/tcltk
-setenv TCLLIBPATH "${TCLHOME}/lib:${WOK_LIBPATH}"
+setenv TCLHOME ${WOK_LIBPATH}
+setenv TCLLIBPATH "${WOK_LIBPATH}"
 
 set TCLLIB=${TCLHOME}/lib
 set TCLBIN=${TCLHOME}/bin
 
-setenv LD_LIBRARY_PATH "/usr/lib:/usr/X11R6/lib:/lib:${TCLLIB}:${WOKHOME}/lib/:${WOKHOME}/lib/${OS_PLATFORM}"
+setenv LD_LIBRARY_PATH "/usr/lib:/usr/X11R6/lib:/lib:${TCLLIB}:${WOKHOME}/lib/:${WOKHOME}/lib/${OS_PLATFORM}/"
 setenv path "/usr/bin /bin /usr/bin /sbin /usr/sbin /usr/local/bin /usr/local/sbin /usr/X11R6/bin /etc"
 setenv PATH "/usr/bin:/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin:/usr/local/sbin:/usr/X11R6/bin:/etc"
 
@@ -32,5 +34,8 @@
 
 cd ${WOK_ROOTADMDIR}
 
+if ( $OS_NAME == "FreeBSD" ) then
+/usr/local/bin/tclsh8.4 < ${WOKHOME}/site/CreateFactory.tcl
+else
 ${TCLBIN}/tclsh < ${WOKHOME}/site/CreateFactory.tcl
-
+endif
