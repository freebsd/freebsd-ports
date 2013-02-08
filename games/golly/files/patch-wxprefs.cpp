--- ./wxprefs.cpp.orig	2012-06-29 21:55:00.000000000 +0000
+++ ./wxprefs.cpp	2012-12-31 11:36:29.488992923 +0000
@@ -1761,7 +1761,7 @@
    InitPaths();                        // init datadir, tempdir and prefspath
    InitAlgorithms();                   // init algoinfo data
 
-   rulesdir = gollydir + wxT("Rules");
+   rulesdir = wxString(DATADIR) + wxT("Rules");
    rulesdir += wxFILE_SEP_PATH;
 
    userrules = datadir + wxT("Rules");
@@ -1770,12 +1770,12 @@
    downloaddir = datadir + wxT("Downloads");
    downloaddir += wxFILE_SEP_PATH;
    
-   opensavedir = gollydir + PATT_DIR;
-   rundir = gollydir + SCRIPT_DIR;
-   icondir = gollydir;
-   choosedir = gollydir;
-   patterndir = gollydir + PATT_DIR;
-   scriptdir = gollydir + SCRIPT_DIR;
+   opensavedir = wxString(DATADIR) + PATT_DIR;
+   rundir = wxString(DATADIR) + SCRIPT_DIR;
+   icondir = wxString(DATADIR);
+   choosedir = wxString(DATADIR);
+   patterndir = wxString(DATADIR) + PATT_DIR;
+   scriptdir = wxString(DATADIR) + SCRIPT_DIR;
 
    // init the text editor to something reasonable
    #ifdef __WXMSW__
