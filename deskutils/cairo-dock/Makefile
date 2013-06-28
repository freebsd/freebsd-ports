# $FreeBSD$

PORTNAME=	cairo-dock
DISTVERSION=	3.2.1
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/137290048/ \
		http://pazzle.otdux.com.ua/

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		curl:${PORTSDIR}/ftp/curl \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gtkglext-x11-1:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-3.2.1

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender xtst
USES=		cmake gettext pkgconfig
MAKE_JOBS_SAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=    -Dinstall-pc-path:STRING="${LOCALBASE}/libdata/pkgconfig"

MAN1=		cairo-dock.1
MANCOMPRESSED=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*" | ${XARGS} ${REINPLACE_CMD} -i.orig -e \
	    's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|g; \
	     s|/usr/bin/cairo-dock|${LOCALBASE}/bin/cairo-dock|g; \
	     s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/bin/*lay|${LOCALBASE}/bin/*lay|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/icons|${LOCALBASE}/share/icons|g'

.include <bsd.port.mk>
