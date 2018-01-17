Disable the Mapbox code.

It contains several bundled libraries (including Boost) and the code seems to
contain Linuxisms (as of 5.9.3):

platform/default/thread.cpp:14:5: error: use of undeclared identifier 'pthread_getname_np'
    pthread_getname_np(pthread_self(), name, sizeof(name));
    ^
platform/default/thread.cpp:21:9: error: use of undeclared identifier 'pthread_setname_np'
        pthread_setname_np(pthread_self(), name.substr(0, 15).c_str());
        ^
platform/default/thread.cpp:23:9: error: use of undeclared identifier 'pthread_setname_np'
        pthread_setname_np(pthread_self(), name.c_str());
        ^
platform/default/thread.cpp:31:31: error: use of undeclared identifier 'SCHED_IDLE'
    if (sched_setscheduler(0, SCHED_IDLE, &param) != 0) {
                              ^
--- src/plugins/geoservices/geoservices.pro.orig	2017-11-10 10:54:34 UTC
+++ src/plugins/geoservices/geoservices.pro
@@ -7,12 +7,3 @@ qtConfig(geoservices_mapbox): SUBDIRS += mapbox
 qtConfig(geoservices_esri): SUBDIRS += esri
 qtConfig(geoservices_itemsoverlay): SUBDIRS += itemsoverlay
 qtConfig(geoservices_osm): SUBDIRS += osm
-
-qtConfig(geoservices_mapboxgl) {
-    !exists(../../3rdparty/mapbox-gl-native/mapbox-gl-native.pro) {
-        warning("Submodule mapbox-gl-native does not exist. Run 'git submodule update --init' on qtlocation.")
-    } else {
-        SUBDIRS += mapboxgl ../../3rdparty/mapbox-gl-native
-        mapboxgl.depends = ../../3rdparty/mapbox-gl-native
-    }
-}
