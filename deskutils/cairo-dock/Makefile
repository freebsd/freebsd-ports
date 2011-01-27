# New ports collection makefile for:	cairo-dock
# Date created:		2010-03-18
# Whom:			Ivan Klymenko <fidaj@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	cairo-dock
DISTVERSION=	2.2.0-4
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/56954298/

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		curl.6:${PORTSDIR}/ftp/curl \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender xtst
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		cairo-dock.1

post-patch:
	@${REINPLACE_CMD} -e 's|libdir}/pkgconfig|prefix}/libdata/pkgconfig| ; s|datadir}/man|prefix}/man|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/gldit/CMakeLists.txt
	${REINPLACE_CMD} -e 's,/usr,${PREFIX},g'	\
		${WRKSRC}/src/gldit/cairo-dock-gui-factory.c

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/cairo/cairo-glitz.h)
# Glitz support can only be enabled if cairo is built with glitz support
CONFIGURE_ARGS+=--enable-glitz
LIB_DEPENDS+=	glitz:${PORTSDIR}/graphics/glitz
.else
CONFIGURE_ARGS+=--disable-glitz
.endif

.include <bsd.port.post.mk>
