--- apps/ymir-sdl3/src/app/ui/windows/about_window.cpp.orig	2026-05-09 08:40:32 UTC
+++ apps/ymir-sdl3/src/app/ui/windows/about_window.cpp
@@ -32,9 +32,6 @@
 #include <zlib.h>
 #include <zstd.h>
 
-#define MINIZ_NO_ZLIB_COMPATIBLE_NAMES
-#include <miniz/miniz.h>
-
 #define _STR_IMPL(x) #x
 #define _STR(x) _STR_IMPL(x)
 #define _SEMVER_STR(major, minor, patch) _STR(major.minor.patch)
@@ -121,7 +118,6 @@ static const struct {
     {.name = "lz4",                           .version = LZ4_VERSION_STRING,         .license = licenseBSD2,          .repoURL = "https://github.com/lz4/lz4",                     .licenseURL = "https://github.com/lz4/lz4/blob/dev/lib/LICENSE",                        .homeURL = "https://lz4.org/",},
     {.name = "lzma",                          .version = LZMA_VERSION,               .license = licensePublicDomain,                                                                                                                                                       .homeURL = "https://www.7-zip.org/sdk.html",},
     {.name = "mio",                           .version = MIO_VERSION,                .license = licenseMIT,           .repoURL = "https://github.com/StrikerX3/mio",               .licenseURL = "https://github.com/StrikerX3/mio/blob/master/LICENSE"},
-    {.name = "miniz",                         .version = MZ_VERSION,                 .license = licenseMIT,           .repoURL = "https://github.com/richgel999/miniz",            .licenseURL = "https://github.com/richgel999/miniz/blob/master/LICENSE"},
     {.name = "moodycamel::\nConcurrentQueue", .version = "\n" MC_CONCQUEUE_VERSION,  .license = licenseBSD2,          .repoURL = "https://github.com/cameron314/concurrentqueue",  .licenseURL = "https://github.com/cameron314/concurrentqueue/blob/master/LICENSE.md"},
     {.name = "Neargye/semver",                .version = SEMVER_VERSION,             .license = licenseMIT,           .repoURL = "https://github.com/Neargye/semver",              .licenseURL = "https://github.com/Neargye/semver/blob/master/LICENSE"},
     {.name = "nghttp2",                       .version = NGHTTP2_VERSION,            .license = licenseMIT,           .repoURL = "https://github.com/nghttp2/nghttp2",             .licenseURL = "https://github.com/nghttp2/nghttp2/blob/master/COPYING",                 .homeURL = "https://nghttp2.org/"},
