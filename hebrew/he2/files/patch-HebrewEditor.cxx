--- HebrewEditor.cxx.orig	Tue Aug 17 13:49:15 2004
+++ he2/HebrewEditor.cxx	Tue Aug 17 13:49:27 2004
@@ -224,7 +224,7 @@
    screen->Refresh() ;
    screen->GetMaxYX(&sizey, &sizex) ;
 
-   buffers = new (Edit *)[MAX_BUFFER_COUNT] ;
+   buffers = new Edit *[MAX_BUFFER_COUNT] ;
    aString filename ;
    bufferCount = 0 ;
    if (argc > 1) {
