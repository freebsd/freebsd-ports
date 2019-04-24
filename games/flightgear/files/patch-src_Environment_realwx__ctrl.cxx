# games/flightgear: METAR data won't download
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=237400

--- src/Environment/realwx_ctrl.cxx.orig	2019-04-20 07:47:41 UTC
+++ src/Environment/realwx_ctrl.cxx
@@ -426,7 +426,7 @@ void NoaaMetarRealWxController::requestMetar
 )
 {
   static const std::string NOAA_BASE_URL =
-    "http://tgftp.nws.noaa.gov/data/observations/metar/stations/";
+    "https://tgftp.nws.noaa.gov/data/observations/metar/stations/";
   class NoaaMetarGetRequest:
     public simgear::HTTP::MemoryRequest
   {
