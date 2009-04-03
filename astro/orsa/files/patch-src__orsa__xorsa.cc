--- src/orsa/xorsa.cc.orig	2005-01-05 07:31:25.000000000 +0900
+++ src/orsa/xorsa.cc	2009-04-02 13:48:37.000000000 +0900
@@ -580,25 +580,25 @@
      MPC_UNUSUALS));
   */
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/MPCORB.ZIP",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_MPCORB));
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/NEA.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_NEA));
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/DAILY.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_DAILY));
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/DistantObjects.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_DISTANT));
     
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/PHA.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_PHA));
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/Unusuals.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_UNUSUALS));
   
-  items.push_back(XOrsaDownloadItem("http://www.astro.cz/mpcorb/COMET.DAT",
+  items.push_back(XOrsaDownloadItem("",
 				    MPC_COMET));
   
   /* 
@@ -627,22 +627,22 @@
   items.push_back(XOrsaDownloadItem("http://www.amsat.org/amsat/ftp/keps/current/nasa.all",
 				    TLE_NASA));   
   
-  items.push_back(XOrsaDownloadItem("ftp://alphalma.cnrs-mrs.fr/pub/astro/geo.tle",
+  items.push_back(XOrsaDownloadItem("",
 				    TLE_GEO));   
   
   items.push_back(XOrsaDownloadItem("http://www.celestrak.com/NORAD/elements/gps-ops.txt",
 				    TLE_GPS));   
   
-  items.push_back(XOrsaDownloadItem("ftp://alphalma.cnrs-mrs.fr/pub/astro/iss.tle",
+  items.push_back(XOrsaDownloadItem("",
 				    TLE_ISS));   
   
-  items.push_back(XOrsaDownloadItem("http://www.orbitessera.com/data/orbital/kepele.txt",
+  items.push_back(XOrsaDownloadItem("",
 				    TLE_KEPELE));   
   
-  items.push_back(XOrsaDownloadItem("ftp://alphalma.cnrs-mrs.fr/pub/astro/visual.tle",
+  items.push_back(XOrsaDownloadItem("",
 				    TLE_VISUAL));   
   
-  items.push_back(XOrsaDownloadItem("ftp://alphalma.cnrs-mrs.fr/pub/astro/weather.tle",
+  items.push_back(XOrsaDownloadItem("",
 				    TLE_WEATHER));   
   
   // textures
