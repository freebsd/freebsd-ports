part of https://github.com/rstudio/rstudio/pull/6017 to fix the R-4.0.0 compatibility

--- src/cpp/r/session/REmbeddedPosix.cpp.orig	2020-04-01 16:16:24 UTC
+++ src/cpp/r/session/REmbeddedPosix.cpp
@@ -103,14 +105,14 @@ void runEmbeddedR(const core::FilePath& /*rHome*/,    
    //
    structRstart rp;
    Rstart Rp = &rp;
-   R_DefParams(Rp) ;
-   Rp->R_Slave = FALSE ;
+   R_DefParams(Rp);
+   Rp->R_NoEcho = FALSE;
    Rp->R_Quiet = quiet ? TRUE : FALSE;
-   Rp->R_Interactive = TRUE ;
-   Rp->SaveAction = defaultSaveAction ;
+   Rp->R_Interactive = TRUE;
+   Rp->SaveAction = defaultSaveAction;
    Rp->RestoreAction = SA_NORESTORE; // handled within initialize()
    Rp->LoadInitFile = loadInitFile ? TRUE : FALSE;
-   R_SetParams(Rp) ;
+   R_SetParams(Rp);
 
    // redirect console
    R_Interactive = TRUE; // should have also been set by call to Rf_initialize_R
