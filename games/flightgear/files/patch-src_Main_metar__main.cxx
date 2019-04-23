# games/flightgear: METAR data won't download
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=237400

--- src/Main/metar_main.cxx.orig	2019-04-20 07:48:18 UTC
+++ src/Main/metar_main.cxx
@@ -539,7 +539,7 @@ int main(int argc, char *argv[])
 			try
 			{
               static const std::string NOAA_BASE_URL =
-                "http://tgftp.nws.noaa.gov/data/observations/metar/stations/";
+                "https://tgftp.nws.noaa.gov/data/observations/metar/stations/";
                 HTTP::MemoryRequest* mr = new HTTP::MemoryRequest
                 (
                     NOAA_BASE_URL
