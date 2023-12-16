--- he2/HebrewEditor.cxx.orig	2001-03-24 08:36:42 UTC
+++ he2/HebrewEditor.cxx
@@ -224,7 +224,7 @@ HebrewEditor::HebrewEditor(int argc, char **argv){
    screen->Refresh() ;
    screen->GetMaxYX(&sizey, &sizex) ;
 
-   buffers = new (Edit *)[MAX_BUFFER_COUNT] ;
+   buffers = new Edit *[MAX_BUFFER_COUNT] ;
    aString filename ;
    bufferCount = 0 ;
    if (argc > 1) {
