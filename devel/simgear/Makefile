# $FreeBSD$

PORTNAME=	simgear
PORTVERSION=	2020.3.6
CATEGORIES=	devel games
MASTER_SITES=	SF/flightgear/release-${PORTVERSION:R}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Toolkit for 3D games and simulations

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libosg.so:graphics/osg \
		libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

USES=		alias cmake compiler:c++11-lib cpe gl jpeg openal:al,alut \
		tar:bzip2 xorg
USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu glut

USE_LDCONFIG=	yes

LDFLAGS_gcc=	-losgDB
LDFLAGS+=	${LDFLAGS_${CHOSEN_COMPILER_TYPE}}

CMAKE_ARGS+=	-DSYSTEM_EXPAT:BOOL=ON \
		-DENABLE_TESTS:BOOL=OFF

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DENABLE_SIMD:BOOL=OFF
.endif

.include <bsd.port.post.mk>
