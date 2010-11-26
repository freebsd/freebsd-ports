# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	SimGear
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	devel games
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/simgear/ftp/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/Source/ \
		ftp://goflyflightgear.com/simgear/Source/ \
		ftp://flightgear.wo0t.de/simgear-ftp/ftp/Source/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A toolkit for 3D games and simulations

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

.if defined(WITH_OSG_DEVEL)
LIB_DEPENDS+=	osg.59:${PORTSDIR}/graphics/osg-devel
.else
LIB_DEPENDS+=	osg.55:${PORTSDIR}/graphics/osg
.endif

LICENSE=	GPLv2

USE_XORG=	ice sm x11 xext xi xt xmu
USE_OPENAL=	al alut
USE_GL=		gl glu glut
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-jpeg-factory

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
