--- vendor/xclannad/wavfile.cc~
+++ vendor/xclannad/wavfile.cc
@@ -23,6 +23,10 @@
  *
 */
 
+#ifdef HAVE_CONFIG_H
+#  include "config.h"
+#endif
+
 #include        <stdarg.h>
 #include  	<stdio.h>
 #include  	<stdlib.h>
@@ -738,7 +742,7 @@ void MP3FILE::Seek(int count) {
 	} while(pimpl->status != MP3FILE_impl::DONE && pimpl->write_pointer < pimpl->write_data_len);
 	return;
 }
-#elif USE_SMPEG
+#elif HAVE_LIBSMPEG
 #include<smpeg/smpeg.h>
 
 struct MP3FILE_impl {
