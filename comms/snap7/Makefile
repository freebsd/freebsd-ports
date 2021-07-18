# Created by: Vladimir Grebenschikov

PORTNAME=	snap7
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	full-
CATEGORIES=	comms
MASTER_SITES=	SF/snap7/${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	vova@fbsd.ru
COMMENT=	Multi-platform Ethernet S7 PLC communication suite

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 armv6 i386 mips powerpc64 powerpc64le powerpc

USES=		gmake
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	build/unix

MAKE_ARGS=	CC=${CC} CXX=${CXX} LinkerName=${CXX} SharedObjectLinkerName="${CXX} -shared -fPIC"

PLIST_FILES=	lib/libsnap7.so include/snap7.h share/examples/snap7/c-cpp/snap7.cpp

SNAP_ARCH=	${ARCH:S/amd64/x86_64/:S/armv6/arm_v6/}
MAKEFILE=	${SNAP_ARCH}_bsd.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsnap7.so

.include <bsd.port.mk>
