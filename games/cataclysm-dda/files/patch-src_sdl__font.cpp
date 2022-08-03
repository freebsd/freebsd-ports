--- src/sdl_font.cpp.orig	2021-07-03 05:00:06 UTC
+++ src/sdl_font.cpp
@@ -22,12 +22,12 @@ static int test_face_size( const std::string &f, int s
 {
     const TTF_Font_Ptr fnt( TTF_OpenFontIndex( f.c_str(), size, faceIndex ) );
     if( fnt ) {
-        char *style = TTF_FontFaceStyleName( fnt.get() );
+        const char *style = TTF_FontFaceStyleName( fnt.get() );
         if( style != nullptr ) {
             int faces = TTF_FontFaces( fnt.get() );
             for( int i = faces - 1; i >= 0; i-- ) {
                 const TTF_Font_Ptr tf( TTF_OpenFontIndex( f.c_str(), size, i ) );
-                char *ts = nullptr;
+                const char *ts = nullptr;
                 if( tf ) {
                     if( nullptr != ( ts = TTF_FontFaceStyleName( tf.get() ) ) ) {
                         if( 0 == strcasecmp( ts, style ) && TTF_FontHeight( tf.get() ) <= size ) {
