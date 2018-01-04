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
    "LibLZMA library to link against..")

# Modern FreeBSD systems are assumed to have libpkg installed,
# so enable its use in CPack for the direct generation of FreeBSD
# packages from software (outside of ports, say) that uses CMake.
set(CPACK_ENABLE_FREEBSD_PKG ON CACHE BOOL "Enable pkg(8) generator in CPack")

