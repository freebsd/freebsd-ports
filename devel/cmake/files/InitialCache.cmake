# Disable CMake's tests while building. We are not interested in them when
# building packages/ports, and it may create problems if part of some
# dependencies are installed (for example, devel/qmake4 is installed, but
# devel/qt4-corelib is not).
# See https://mail.kde.org/pipermail/kde-freebsd/2013-July/015703.html
set(BUILD_TESTING OFF CACHE BOOL "Build the testing tree.")

# Explicitly enable use of OpenSSL in the bundled copy of libcurl, as it
# defaults to off. See ports/187374.
set(CMAKE_USE_OPENSSL ON CACHE BOOL "Use OpenSSL code with curl.")
