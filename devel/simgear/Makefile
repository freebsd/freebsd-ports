# $FreeBSD$

PORTNAME=	simgear
PORTVERSION=	2.12.0
CATEGORIES=	devel games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/simgear/ftp/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/Source/ \
		ftp://goflyflightgear.com/simgear/Source/ \
		ftp://flightgear.wo0t.de/simgear-ftp/ftp/Source/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A toolkit for 3D games and simulations

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libosg.so:${PORTSDIR}/graphics/osg

USE_BZIP2=	yes
USE_XORG=	ice sm x11 xext xi xt xmu
USE_OPENAL=	al alut
USE_GL=		gl glu glut
USES=		cmake
CMAKE_ARGS+=	-DJPEG_FACTORY:BOOL=ON

.include <bsd.port.mk>
