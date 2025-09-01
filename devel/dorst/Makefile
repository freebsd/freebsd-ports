PORTNAME=	dorst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.4
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	slowdive@me.com
COMMENT=	Codebase bootstrap/backup utility
WWW=		https://github.com/charlesrocket/dorst

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

FLAVORS=			default gtk
FLAVOR?=			${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	${PORTNAME}-gtk
gtk_PKGNAMESUFFIX=		-gtk
gtk_CONFLICTS_INSTALL=		${PORTNAME}

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	charlesrocket

.if ${FLAVOR:U} == gtk
USES+=			desktop-file-utils gnome
USE_GNOME=		glib20 gtk40 libadwaita
CARGO_FEATURES+=	gui

PLIST_FILES+=	share/applications/org.hellbyte.dorst.desktop \
		share/pixmaps/org.hellbyte.dorst.png

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/share/org.hellbyte.dorst.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/org.hellbyte.dorst.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/org.hellbyte.dorst.png
.endif

PLIST_FILES+=	bin/dorst

.include <bsd.port.mk>
