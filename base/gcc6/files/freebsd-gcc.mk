XCC=/usr/bin/cc
XCXX=/usr/bin/c++
XCPP=/usr/bin/cpp
X_COMPILER_TYPE=gcc
export WITH_PORT_BASE_GCC=yes
export WITHOUT_GCC=yes
export WITHOUT_CLANG_IS_CC=yes
.sinclude "freebsd-binutils.mk"
