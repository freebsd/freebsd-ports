# Disable CMake's tests while building. We are not interested in them when
# building packages/ports, and it may create problems if part of some
# dependencies are installed (for example, devel/qmake4 is installed, but
# devel/qt4-corelib is not).
# See https://mail.kde.org/pipermail/kde-freebsd/2013-July/015703.html
set(BUILD_TESTING OFF CACHE BOOL "Build the testing tree.")

# Force CMake to look for base's liblzma, otherwise the configuration process
# will fail if archivers/lzmalib is installed, as CMake will try to use its
# liblzma.so.
# Note that this is necessary only for `make configure' to work, as liblzma is
# only ever used if CMake's bundled libarchive is being used.
set(LIBLZMA_INCLUDE_DIR "/usr/include" CACHE PATH
    "Directory where LibLZMA headers are located.")
set(LIBLZMA_LIBRARY "/usr/lib/liblzma.so" CACHE PATH
    "LibLZMA library to link against.")

# Set (or not) by the CPACK option by replacing @@CPACK_OPTION_VALUE@@
# with the value of the option itself.
#
set(CPACK_ENABLE_FREEBSD_PKG @@CPACK_OPTION_VALUE@@ CACHE BOOL "Enable pkg(8) generator in CPack")
# Use base libarchive instead of ports, because libpkg uses base
@@CPACK_OPTION_COMMENT@@set(LibArchive_INCLUDE_DIR "/usr/include" CACHE PATH
@@CPACK_OPTION_COMMENT@@    "Directory where LibArchive headers are located.")
# Hack to (a) prevent using either ports libarchive or the bundled version 
#     and (b) libpkg links to base libarchive.
@@CPACK_OPTION_COMMENT@@set(LibArchive_LIBRARY "/usr/lib/libthr.so;/usr/lib/libarchive.so" CACHE PATH
@@CPACK_OPTION_COMMENT@@    "LibArchive library to link against.")

