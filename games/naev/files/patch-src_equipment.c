# Origin: https://github.com/naev/naev/commit/9fd2a7dcb3690bc1befe7f9a05d02e204dcfe8a1
# Subject: Avoid regenerating the land tabs over top of themselves

--- src/equipment.c.orig	2015-03-18 02:22:35 UTC
+++ src/equipment.c
@@ -234,6 +234,9 @@ void equipment_open( unsigned int wid )
    GLfloat colour[4*4];
    const char *buf;
 
+   /* Mark as generated. */
+   land_tabGenerate(LAND_WINDOW_EQUIPMENT);
+
    /* Set global WID. */
    equipment_wid = wid;
 
