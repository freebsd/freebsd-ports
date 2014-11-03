# $FreeBSD$

PORTNAME=	simgear
PORTVERSION=	3.2.0
CATEGORIES=	devel games
MASTER_SITES=	http://mirrors.ibiblio.org/simgear/ftp/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/Source/ \
		ftp://goflyflightgear.com/simgear/Source/ \
		ftp://flightgear.wo0t.de/simgear-ftp/ftp/Source/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Toolkit for 3D games and simulations

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libosg.so:${PORTSDIR}/graphics/osg

USE_XORG=	ice sm x11 xext xi xt xmu
USE_GL=		gl glu glut
USES=		tar:bzip2 cmake compiler openal:al,alut

.include <bsd.port.pre.mk>

# When building with Gcc, needs Gcc 4.6+
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	4.6+
.endif

.include <bsd.port.post.mk>
