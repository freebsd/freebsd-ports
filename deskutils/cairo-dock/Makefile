# $FreeBSD$

PORTNAME=	cairo-dock
PORTVERSION=	3.4.1
CATEGORIES=	deskutils

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock is a light and eye-candy dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libcurl.so:ftp/curl \
		libdbus-glib-1.so:devel/dbus-glib \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
RUN_DEPENDS=	bash:shells/bash \
		sox:audio/sox

USE_GITHUB=	yes
GH_ACCOUNT=	Cairo-Dock
GH_PROJECT=	${PORTNAME}-core

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender xtst
USES=		cmake gettext pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-Dinstall-pc-path:STRING="${LOCALBASE}/libdata/pkgconfig"
CMAKE_ARGS+=	-DROOT_PREFIX:PATH=${STAGEDIR}
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=man

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*" | ${XARGS} ${REINPLACE_CMD} -e \
	    's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|g; \
	     s|/usr/bin/cairo-dock|${LOCALBASE}/bin/cairo-dock|g; \
	     s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/icons|${LOCALBASE}/share/icons|g; \
	     s|%%LOCALBASE%%|${LOCALBASE}|g;'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgldi.so

.include <bsd.port.mk>
