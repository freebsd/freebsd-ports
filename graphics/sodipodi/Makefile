# New ports collection makefile for:   sodipodi
# Date created:        28 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sodipodi
PORTVERSION=	0.32
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small vector based drawing program with GNOME libraries

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/frontline.pc:${PORTSDIR}/graphics/frontline
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/frontline.pc:${PORTSDIR}/graphics/frontline

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libglade2
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		sodipodi.1

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/helper/action.c

.include <bsd.port.mk>
