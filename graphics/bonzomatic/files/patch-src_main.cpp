--- src/main.cpp.orig	2022-07-08 20:07:06 UTC
+++ src/main.cpp
@@ -503,7 +503,7 @@ int main( int argc, const char * argv[] )
         if ( !consumed && Renderer::keyEventBuffer[ i ].character )
         {
           char    utf8[ 5 ] = { 0,0,0,0,0 };
-          wchar_t utf16[ 2 ] = { Renderer::keyEventBuffer[ i ].character, 0 };
+          wchar_t utf16[ 2 ] = { static_cast<wchar_t>(Renderer::keyEventBuffer[ i ].character), 0 };
           Scintilla::UTF8FromUTF16( utf16, 1, utf8, 4 * sizeof( char ) );
           mShaderEditor.AddCharUTF( utf8, (unsigned int) strlen( utf8 ) );
         }
