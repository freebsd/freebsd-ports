--- src/InputFile.hh.orig	2019-06-23 12:39:20 UTC
+++ src/InputFile.hh
@@ -42,7 +42,7 @@ struct InputFile
    InputFile(const UTF8_string & _filename, FILE * _file,
                      bool _test, bool _echo, bool _is_script, LX_mode LX)
    : file     (_file),
-     filename (&_filename[0], _filename.size()),
+     filename (_filename),
      test     (_test),
      echo     (_echo),
      is_script(_is_script),
