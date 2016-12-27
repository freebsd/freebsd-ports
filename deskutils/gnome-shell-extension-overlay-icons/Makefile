# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-overlay-icons
PORTVERSION=	0.0.0.20151015
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Show application icons on the windows overview

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.windowoverlay-icons.gschema.xml

GH_ACCOUNT=	sustmi
GH_PROJECT=	gnome-shell-extensions-sustmi
GH_TAGNAME=	e8200b3

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
		cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/windowoverlay-icons/schemas/org.gnome.shell.extensions.windowoverlay-icons.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${RM} -r ${WRKSRC}/windowoverlay-icons/schemas/
		cd ${WRKSRC}/windowoverlay-icons && ${COPYTREE_SHARE} . \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/windowoverlay-icons@sustmidown.centrum.cz

.include <bsd.port.mk>
