# New ports collection makefile for:   sodipodi
# Date created:        28 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sodipodi
PORTVERSION=	0.31
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
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		sodipodi.1

.include <bsd.port.mk>
