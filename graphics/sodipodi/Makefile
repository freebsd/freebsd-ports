# New ports collection makefile for:   sodipodi
# Date created:        28 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sodipodi
PORTVERSION=	0.29
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/frontline.pc:${PORTSDIR}/graphics/frontline
LIB_DEPENDS=	gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/frontline.pc:${PORTSDIR}/graphics/frontline

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		sodipodi.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
