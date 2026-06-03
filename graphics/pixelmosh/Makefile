PORTNAME=	pixelmosh
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	slowdive@me.com
COMMENT=	PNG corrupter
WWW=		https://github.com/charlesrocket/pixelmosh

LICENSE=	MIT

FLAVORS=			default gtk
FLAVOR?=			${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	${PORTNAME}-gtk
gtk_PKGNAMESUFFIX=		-gtk
gtk_CONFLICTS_INSTALL=		${PORTNAME}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	charlesrocket

.if ${FLAVOR:U} == gtk
USES+=			desktop-file-utils gnome
USE_GNOME=		glib20 gtk40 libadwaita
CARGO_FEATURES+=	gui

PLIST_FILES+=	share/applications/org.hellbyte.pixelmosh.desktop \
		share/pixmaps/org.hellbyte.pixelmosh.png

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/org.hellbyte.pixelmosh.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/org.hellbyte.pixelmosh.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/org.hellbyte.pixelmosh.png
.endif

PLIST_FILES+=	bin/pixelmosh

.include <bsd.port.mk>
