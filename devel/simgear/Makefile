# $FreeBSD$

PORTNAME=	simgear
PORTVERSION=	2017.3.1
CATEGORIES=	devel games
MASTER_SITES=	SF/flightgear/release-${PORTVERSION:R}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Toolkit for 3D games and simulations

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libosg.so:graphics/osg

USE_XORG=	ice sm x11 xext xi xmu xt
USE_GL=		gl glu glut
USES=		alias cmake compiler:c++11-lib cpe jpeg openal:al,alut tar:bzip2

.include <bsd.port.pre.mk>

# Work around "'to_string' is not a member of 'std'" when building with Gcc < 6
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 60
CFLAGS+=	-D_GLIBCXX_USE_C99
.endif

.include <bsd.port.post.mk>
