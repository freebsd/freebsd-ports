Fixes the build with clang 6.0, which defaults to -std=gnu++14:

    /wrkdirs/usr/ports/graphics/digikam-kde4/work/digikam-4.14.0/core/libs/dimg/loaders/pgfloader.cpp:301:27: error: use of undeclared identifier 'NULL'
                              NULL,
                              ^
    /usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
    #define NULL    nullptr
                    ^
    /usr/local/include/libpgf/PGFplatform.h:488:20: note: expanded from macro 'nullptr'
    #define nullptr                         NULL
                                            ^
    /wrkdirs/usr/ports/graphics/digikam-kde4/work/digikam-4.14.0/core/libs/dimg/loaders/pgfloader.cpp:461:26: error: use of undeclared identifier 'NULL'
                             NULL,
                             ^
    /usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
    #define NULL    nullptr
                    ^
    /usr/local/include/libpgf/PGFplatform.h:488:20: note: expanded from macro 'nullptr'
    #define nullptr                         NULL
                                            ^
--- libs/dimg/loaders/pgfloader.cpp.orig	2018-01-16 12:23:12 UTC
+++ libs/dimg/loaders/pgfloader.cpp
@@ -298,7 +298,7 @@ bool PGFLoader::load(const QString& filePath, DImgLoad
             pgf.GetBitmap(m_sixteenBit ? width * 8 : width * 4,
                           (UINT8*)data,
                           m_sixteenBit ? 64 : 32,
-                          NULL,
+                          nullptr,
                           CallbackForLibPGF, this);
 
             if (observer)
@@ -458,7 +458,7 @@ bool PGFLoader::save(const QString& filePath, DImgLoad
         pgf.ImportBitmap(4 * imageWidth() * (imageSixteenBit() ? 2 : 1),
                          (UINT8*)imageData(),
                          imageBitsDepth() * 4,
-                         NULL,
+                         nullptr,
                          CallbackForLibPGF, this);
 
         UINT32 nWrittenBytes = 0;
