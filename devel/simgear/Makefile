# New ports collection makefile for:	SimGear
# Date created:				2003-01-21
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	SimGear
PORTVERSION=	0.3.10
CATEGORIES=	devel games
MASTER_SITES=	ftp://ftp.simgear.org/pub/simgear/Source/ \
		ftp://ftp.de.flightgear.org/pub/simgear/Source/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A toolkit for 3D games and simulations

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-jpeg-factory

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
