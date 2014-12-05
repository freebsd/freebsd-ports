# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	fgrun
PORTVERSION=	3.2.0
CATEGORIES=	games
MASTER_SITES=	LOCAL/martymac

MAINTAINER=	buganini@gmail.com
COMMENT=	Graphical frontend to run FlightGear Flight Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libosg.so:${PORTSDIR}/graphics/osg
BUILD_DEPENDS=	simgear>=2.10.0:${PORTSDIR}/devel/simgear \
		${LOCALBASE}/include/boost/version.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	simgear>=2.10.0:${PORTSDIR}/devel/simgear \
		fgfs:${PORTSDIR}/games/flightgear

WRKSRC=		${WRKDIR}/${GO_ACCOUNT}-${GO_PROJECT}

CMAKE_ARGS+=	-DLIB_DIR=${PREFIX}/lib

USES=		cmake compiler
USE_GL=		gl

GO_ACCOUNT=	fg
GO_PROJECT=	fgrun
GO_TAGNAME=	00580a1c6b64b46fe430b0f1c0caafb4f63448fb
FETCH_ARGS?=	-o ${DISTDIR}/${DISTFILES}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CMAKE_ON=	-DENABLE_NLS=yes

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} < 46
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
