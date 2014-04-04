# $FreeBSD$

PORTNAME=	cairo-dock
DISTVERSION=	3.2.1
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/137290048/ \
		http://pazzle.otdux.com.ua/

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		sox:${PORTSDIR}/audio/sox

WRKSRC=		${WRKDIR}/${PORTNAME}-3.2.1

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender xtst
USES=		cmake gettext pathfix pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-Dinstall-pc-path:STRING="${LOCALBASE}/libdata/pkgconfig"
CMAKE_ARGS+=	-DROOT_PREFIX:PATH=${STAGEDIR}

MANCOMPRESSED=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*" | ${XARGS} ${REINPLACE_CMD} -e \
	    's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|g; \
	     s|/usr/bin/cairo-dock|${LOCALBASE}/bin/cairo-dock|g; \
	     s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/icons|${LOCALBASE}/share/icons|g; \
	     s|%%LOCALBASE%%|${LOCALBASE}|g;'

.include <bsd.port.mk>
