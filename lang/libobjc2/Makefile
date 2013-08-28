# Created by: Pete French <pete@twisted.org.uk>
# $FreeBSD$

PORTNAME=	libobjc2
PORTVERSION=	1.7
CATEGORIES=	lang devel gnustep
MASTER_SITES=	http://download.gna.org/gnustep/

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Replacement Objective-C runtime supporting modern Objective-C features

.include <bsd.port.options.mk>

USES=		cmake

_CLANG!=	if [ -f /usr/bin/clang ] ; then  /usr/bin/clang --version | head -1 | \
		${SED} -e 's/.*clang version \([0-9]\)\.\([0-9]\).*/\1\2/' ; else ${ECHO} 0 ; fi

.if ${_CLANG} < 33
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang33:${PORTSDIR}/lang/clang33
CLANG=		${LOCALBASE}/bin/clang33
CLANGXX=	${LOCALBASE}/bin/clang++33
.else
CLANG=		/usr/bin/clang
CLANGXX=	/usr/bin/clang++
.endif

SHLIB_MAJOR=	4
SHLIB_MINOR=	6

USE_BZIP2=	yes
PLIST_SUB+=	SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

.if ${OSVERSION} < 902000
CMAKE_ARGS+=	-DFORCE_LIBOBJCXX=ON
PLIST_SUB+=	WITH_SEPARATECXX=""
.else
PLIST_SUB+=	WITH_SEPARATECXX="@comment "
.endif

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DLIB_INSTALL_PATH=lib -DCMAKE_ASM_COMPILER=${CLANG}
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CLANG} -DCMAKE_CXX_COMPILER=${CLANGXX}
CMAKE_ARGS+=	-DTESTS=OFF
# This shouldn't be needed, but our llvm port installs llvm-config with a silly
# name...
CMAKE_ARGS+=	-DLLVM_OPTS=OFF

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: Unsupported relocation type 10
.endif

.if ${OSVERSION} < 902000
post-install:
	${LN} -sf ${LOCALBASE}/lib/libobjc.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${LOCALBASE}/lib/libobjc.so.${SHLIB_MAJOR}
	${LN} -sf ${LOCALBASE}/lib/libobjcxx.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${LOCALBASE}/lib/libobjcxx.so.${SHLIB_MAJOR}
.else
post-install:
	${LN} -sf ${LOCALBASE}/lib/libobjc.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${LOCALBASE}/lib/libobjc.so.${SHLIB_MAJOR}
.endif


.include <bsd.port.post.mk>
