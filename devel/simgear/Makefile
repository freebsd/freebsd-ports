# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	simgear
PORTVERSION=	2.6.0
PORTREVISION=	4
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
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		osg:${PORTSDIR}/graphics/osg

USE_BZIP2=	yes
USE_XORG=	ice sm x11 xext xi xt xmu
USE_OPENAL=	al alut
USE_GL=		gl glu glut
USE_CMAKE=	yes
CMAKE_ARGS+=	-DJPEG_FACTORY:BOOL=ON

.include <bsd.port.mk>
