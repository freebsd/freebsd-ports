# $FreeBSD$

PORTNAME=	cherivis-devel
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	devel gnustep

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Visualisation tool for CHERI / BERI streamtraces

LICENSE=	MIT

BROKEN_FreeBSD_9=	does not build on FreeBSD 9.x

USES=		gnustep
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	CheriVis
GH_TAGNAME=	525aeb4

LLVM_VERSION?=	34
BUILD_DEPENDS+=	llvm-config${LLVM_VERSION}:${PORTSDIR}/devel/llvm${LLVM_VERSION}
LIB_DEPENDS+=	libdispatch.so:${PORTSDIR}/devel/libdispatch

MAKE_FLAGS+=		LLVM_CONFIG=llvm-config${LLVM_VERSION}
USE_GNUSTEP=		back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

.include <bsd.port.mk>
