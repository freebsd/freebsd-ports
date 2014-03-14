# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	fgrun
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://gitorious.org/${GO_ACCOUNT}/${GO_PROJECT}/archive/${GO_TAGNAME}.tar.gz?dummy=

MAINTAINER=	buganini@gmail.com
COMMENT=	A graphical frontend to run FlightGear Flight Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libosg.so:${PORTSDIR}/graphics/osg
BUILD_DEPENDS=	simgear>=2.10.0:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	simgear>=2.10.0:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear

WRKSRC=		${WRKDIR}/${GO_ACCOUNT}-${GO_PROJECT}

CMAKE_ARGS+=	-DLIB_DIR=${PREFIX}/lib

USE_GCC=	yes
USES=		cmake
USE_GL=		gl

GO_ACCOUNT=	fg
GO_PROJECT=	fgrun
GO_TAGNAME=	90e936c01e28feac4a9c3e28d5227980fb8f1e1d
FETCH_ARGS?=	-o ${DISTDIR}/${DISTFILES}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_ON=	-DENABLE_NLS=yes

.include <bsd.port.mk>
