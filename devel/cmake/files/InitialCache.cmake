# Disable CMake's tests while building. We are not interested in them when
# building packages/ports, and it may create problems if part of some
# dependencies are installed (for example, devel/qmake4 is installed, but
# devel/qt4-corelib is not).
# See https://mail.kde.org/pipermail/kde-freebsd/2013-July/015703.html
set(BUILD_TESTING OFF CACHE BOOL "Build the testing tree.")
