# New ports collection makefile for:	cairo-dock
# Date created:		2010-03-18
# Whom:			Ivan Klymenko <fidaj@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	cairo-dock
DISTVERSION=	2.3.0~3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/73753213/

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		curl.6:${PORTSDIR}/ftp/curl \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender xtst
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		cairo-dock.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|libdir}/pkgconfig|prefix}/libdata/pkgconfig| ; s|datadir}/man|prefix}/man|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/gldit/CMakeLists.txt

.include <bsd.port.mk>
