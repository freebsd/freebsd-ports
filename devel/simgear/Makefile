# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	SimGear
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	ftp://ftp.de.simgear.org/pub/simgear/Source/ \
		ftp://ftp.simgear.org/pub/simgear/Source/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A toolkit for 3D games and simulations

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		alut.1:${PORTSDIR}/audio/freealut \
		boost_thread.4:${PORTSDIR}/devel/boost

.if defined(WITH_OSG_DEVEL)
LIB_DEPENDS+=	osg.59:${PORTSDIR}/graphics/osg-devel
.else
LIB_DEPENDS+=	osg.55:${PORTSDIR}/graphics/osg
.endif

USE_XORG=	ice sm x11 xext xi xt xmu
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
