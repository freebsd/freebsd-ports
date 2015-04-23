# Origin: https://github.com/naev/naev/commit/9fd2a7dcb3690bc1befe7f9a05d02e204dcfe8a1
# Subject: Avoid regenerating the land tabs over top of themselves

--- src/land_shipyard.c.orig	2015-03-05 22:11:11 UTC
+++ src/land_shipyard.c
@@ -61,6 +61,9 @@ void shipyard_open( unsigned int wid )
    int y;
    const char *buf;
 
+   /* Mark as generated. */
+   land_tabGenerate(LAND_WINDOW_SHIPYARD);
+
    /* Init vars. */
    shipyard_selected = NULL;
 
