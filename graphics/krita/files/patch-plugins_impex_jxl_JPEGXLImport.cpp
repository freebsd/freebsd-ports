plugins/impex/jxl/JPEGXLImport.cpp:513:20: error: no matching function for call to 'JxlDecoderGetColorAsEncodedProfile'
                == JxlDecoderGetColorAsEncodedProfile(dec.get(),
                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/jxl/decode.h:749:29: note: candidate function not viable: requires 3 arguments, but 4 were provided
JXL_EXPORT JxlDecoderStatus JxlDecoderGetColorAsEncodedProfile(
                            ^
plugins/impex/jxl/JPEGXLImport.cpp:638:24: error: no matching function for call to 'JxlDecoderGetICCProfileSize'
                    != JxlDecoderGetICCProfileSize(dec.get(), nullptr, JXL_COLOR_PROFILE_TARGET_DATA, &iccSize)) {
                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/jxl/decode.h:775:29: note: candidate function not viable: requires 3 arguments, but 4 were provided
JXL_EXPORT JxlDecoderStatus JxlDecoderGetICCProfileSize(
                            ^
plugins/impex/jxl/JPEGXLImport.cpp:645:24: error: no matching function for call to 'JxlDecoderGetColorAsICCProfile'
                    != JxlDecoderGetColorAsICCProfile(dec.get(),
                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/jxl/decode.h:793:29: note: candidate function not viable: requires 4 arguments, but 5 were provided
JXL_EXPORT JxlDecoderStatus JxlDecoderGetColorAsICCProfile(
                            ^
plugins/impex/jxl/JPEGXLImport.cpp:659:28: error: no matching function for call to 'JxlDecoderGetICCProfileSize'
                        != JxlDecoderGetICCProfileSize(dec.get(),
                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/jxl/decode.h:775:29: note: candidate function not viable: requires 3 arguments, but 4 were provided
JXL_EXPORT JxlDecoderStatus JxlDecoderGetICCProfileSize(
                            ^
plugins/impex/jxl/JPEGXLImport.cpp:669:28: error: no matching function for call to 'JxlDecoderGetColorAsICCProfile'
                        != JxlDecoderGetColorAsICCProfile(dec.get(),
                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/jxl/decode.h:793:29: note: candidate function not viable: requires 4 arguments, but 5 were provided
JXL_EXPORT JxlDecoderStatus JxlDecoderGetColorAsICCProfile(
                            ^

--- plugins/impex/jxl/JPEGXLImport.cpp.orig	2023-12-06 11:38:26 UTC
+++ plugins/impex/jxl/JPEGXLImport.cpp
@@ -511,7 +511,6 @@ JPEGXLImport::convert(KisDocument *document, QIODevice
             JxlColorEncoding colorEncoding{};
             if (JXL_DEC_SUCCESS
                 == JxlDecoderGetColorAsEncodedProfile(dec.get(),
-                                                      nullptr,
                                                       JXL_COLOR_PROFILE_TARGET_DATA,
                                                       &colorEncoding)) {
                 const TransferCharacteristics transferFunction = [&]() {
@@ -635,7 +634,7 @@ JPEGXLImport::convert(KisDocument *document, QIODevice
                 size_t iccSize = 0;
                 QByteArray iccProfile;
                 if (JXL_DEC_SUCCESS
-                    != JxlDecoderGetICCProfileSize(dec.get(), nullptr, JXL_COLOR_PROFILE_TARGET_DATA, &iccSize)) {
+                    != JxlDecoderGetICCProfileSize(dec.get(), JXL_COLOR_PROFILE_TARGET_DATA, &iccSize)) {
                     errFile << "ICC profile size retrieval failed";
                     document->setErrorMessage(i18nc("JPEG-XL errors", "Unable to read the image profile."));
                     return ImportExportCodes::ErrorWhileReading;
@@ -643,7 +642,6 @@ JPEGXLImport::convert(KisDocument *document, QIODevice
                 iccProfile.resize(static_cast<int>(iccSize));
                 if (JXL_DEC_SUCCESS
                     != JxlDecoderGetColorAsICCProfile(dec.get(),
-                                                      nullptr,
                                                       JXL_COLOR_PROFILE_TARGET_DATA,
                                                       reinterpret_cast<uint8_t *>(iccProfile.data()),
                                                       static_cast<size_t>(iccProfile.size()))) {
@@ -657,7 +655,6 @@ JPEGXLImport::convert(KisDocument *document, QIODevice
                 if (!d.m_info.uses_original_profile) {
                     if (JXL_DEC_SUCCESS
                         != JxlDecoderGetICCProfileSize(dec.get(),
-                                                       nullptr,
                                                        JXL_COLOR_PROFILE_TARGET_ORIGINAL,
                                                        &iccTargetSize)) {
                         errFile << "ICC profile size retrieval failed";
@@ -667,7 +664,6 @@ JPEGXLImport::convert(KisDocument *document, QIODevice
                     iccTargetProfile.resize(static_cast<int>(iccTargetSize));
                     if (JXL_DEC_SUCCESS
                         != JxlDecoderGetColorAsICCProfile(dec.get(),
-                                                          nullptr,
                                                           JXL_COLOR_PROFILE_TARGET_ORIGINAL,
                                                           reinterpret_cast<uint8_t *>(iccTargetProfile.data()),
                                                           static_cast<size_t>(iccTargetProfile.size()))) {
