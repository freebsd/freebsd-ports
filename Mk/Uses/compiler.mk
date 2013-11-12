# $FreeBSD$
#
# Allows to feature determine the compiler used
#
# MAINTAINER: portmgr@FreeBSD.org
#
# Feature:	compiler
# Usage:	USES=compiler or USES=compiler:ARGS
# Valid ARGS:	env (default, implicit) c++11-lib c++11-lang c11 openmp features
#
# c++11-lang:	The port need a compiler understanding C++11
# c++11-lib:	The port need a compiler understanding C++11 and with a C++11 ready standard library
# c11:		The port need a compiler understanding c11
# openmp:	The port need a compiler understanding openmp
# features:	The port will determine the features supported by the default compiler
#
# Variable to test after <bsd.port.pre.mk>
#
# COMPILER_TYPE:	can be gcc or clang
# COMPILER_VERSION:	2 first digit of the version: 33 for clang 3.3.*, 46 for gcc 4.6.*
#
# COMPILER_FEATURES:	the list of features supported by the compiler include the standard C++ library.

.if !defined(_INCLUDE_USES_COMPILER_MK)
_INCLUDE_USES_COMPILER_MK=	yes

.if !defined(compiler_ARGS)
compiler_ARGS=	env
.endif

VALID_ARGS=	c++11-lib c++11-lang c11 features openmp env

.if ${compiler_ARGS} == c++11-lib
_COMPILER_ARGS+=	features c++11-lib
.elif ${compiler_ARGS} == c++11-lang
_COMPILER_ARGS+=	features c++11-lang
.elif ${compiler_ARGS} == c11
_COMPILER_ARGS+=	features c11
.elif ${compiler_ARGS} == features
_COMPILER_ARGS+=	features
.elif ${compiler_ARGS} == env
_COMPILER_ARGS+=	env
.elif ${compiler_ARGS} == openmp
_COMPILER_ARGS+=	env openmp
.else
IGNORE=	Invalid argument "${compiler_ARGS}", valid arguments are: ${VALID_ARGS}
_COMPILER_ARGS=	#
.endif

.if ${_COMPILER_ARGS:Mc++11*} || ${_COMPILER_ARGS:Mc11}
_COMPILER_ARGS+=	features
.endif

_CCVERSION!=	${CC} --version
COMPILER_VERSION=	${_CCVERSION:M[0-9].[0-9]*:C/([0-9]).([0-9]).*/\1\2/g}
.if ${_CCVERSION:Mclang}
COMPILER_TYPE=	clang
.else
COMPILER_TYPE=	gcc
.endif

ALT_COMPILER_VERSION=	0
ALT_COMPILER_TYPE=	none
_ALTCCVERSION=	
.if ${COMPILER_TYPE} == gcc && exists(/usr/bin/clang)
_ALTCCVERSION!=	/usr/bin/clang --version
.elif ${COMPILER_TYPE} == clang && exists(/usr/bin/gcc)
_ALTCCVERSION!=	/usr/bin/gcc --version
.endif

ALT_COMPILER_VERSION=	${_ALTCCVERSION:M[0-9].[0-9]*:C/([0-9]).([0-9]).*/\1\2/g}
.if ${_ALTCCVERSION:Mclang}
ALT_COMPILER_TYPE=	clang
.elif !empty(_ALTCCVERSION)
ALT_COMPILER_TYPE=	gcc
.endif

.if ${_COMPILER_ARGS:Mopenmp}
.if ${COMPILER_TYPE} == clang
USE_GCC=	yes
.endif
.endif

.if ${_COMPILER_ARGS:Mfeatures}
_CXXINTERNAL!=	${CXX} -\#\#\# /dev/null 2>&1
.if ${_CXXINTERNAL:M\"-lc++\"}
COMPILER_FEATURES=	libc++
.else
COMPILER_FEATURES=	libstdc++
.endif

CSTD=	c89 c99 c11 gnu89 gnu99 gnu11
CXXSTD=	c++98 c++11 gnu++98 gnu++11

.for std in ${CSTD} ${CXXSTD}
_LANG=c
.if ${CXXSTD:M${std}}
_LANG=c++
.endif
OUTPUT_${std}!=	echo | ${CC} -std=${std} -c -x ${_LANG} /dev/null -o /dev/null 2>&1; echo
.if !${OUTPUT_${std}:M*error*}
COMPILER_FEATURES+=	${std}
.endif
.endfor
.endif

.if ${_COMPILER_ARGS:Mc++11-lib}
.if !${COMPILER_FEATURES:Mc++11}
USE_GCC=	yes
.elif ${COMPILER_TYPE} == clang && ${COMPILER_FEATURES:Mlibstdc++}
USE_GCC=	yes
.endif
.endif

.if ${_COMPILER_ARGS:Mc++11-lang}
.if !${COMPILER_FEATURES:Mc++11}
.if defined(FAVORITE_COMPILER) && ${FAVORITE_COMPILER} == gcc
USE_GCC=	yes
.elif (${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 33) || ${COMPILER_TYPE} == gcc
.if ${ALT_COMPILER_TYPE} == clang && ${ALT_COMPILER_VERSION} >= 33
CPP=	clang-cpp
CC=	clang
CXX=	clang++
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang33:${PORTSDIR}/lang/clang33
CPP=	${LOCALBASE}/bin/clang-cpp33
CC=	${LOCALBASE}/bin/clang33
CXX=	${LOCALBASE}/bin/clang++33
.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
.endif
.endif
.endif
.endif
.endif

.if ${_COMPILER_ARGS:Mc11}
.if !${COMPILER_FEATURES:Mc11}
.if defined(FAVORITE_COMPILER) && ${FAVORITE_COMPILER} == gcc
USE_GCC=	yes
.elif (${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 33) || ${COMPILER_TYPE} == gcc
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang33:${PORTSDIR}/lang/clang33
CPP=	${LOCALBASE}/bin/clang-cpp33
CC=	${LOCALBASE}/bin/clang33
CXX=	${LOCALBASE}/bin/clang++33
.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
.endif
.endif
.endif
.endif

.endif
