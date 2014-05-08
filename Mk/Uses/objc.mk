# $FreeBSD$
#
# Objective C support
#
# Feature:	objc
# Usage:	USES=objc
#
# MAINTAINER:	objc@FreeBSD.org

.if !defined(_INCLUDE_USES_OBJC_MK)
_INCLUDE_USES_OBJC_MK=	yes

.if defined(objc_ARGS)
IGNORE=	USES=objc takes no arguments
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

# We do always need clang
.if (${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 33) || ${COMPILER_TYPE} != clang
.if ${ALT_COMPILER_TYPE} == clang && ${ALT_COMPILER_VERSION} >= 33
CC=	/usr/bin/clang
CPP=	/usr/bin/clang-cpp
CXX=	/usr/bin/clang++
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang33:${PORTSDIR}/lang/clang33
CPP=	${LOCALBASE}/bin/clang-cpp33
CC=	${LOCALBASE}/bin/clang33
CXX=	${LOCALBASE}/bin/clang++33
.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif
.endif
.endif

LIB_DEPENDS+=	libobjc.so.4.6:${PORTSDIR}/lang/libobjc2
OBJCFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	OBJC="${CC}" OBJCFLAGS="${OBJCFLAGS}"
MAKE_ENV+=	OBJC="${CC}" OBJCFLAGS="${OBJCFLAGS}"

.endif
