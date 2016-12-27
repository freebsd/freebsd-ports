# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-dashtodock
PORTVERSION=	0.0.0.20151112
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convert the dash into a dock

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.dash-to-dock.gschema.xml

GH_ACCOUNT=	micheleg
GH_PROJECT=	dash-to-dock
GH_TAGNAME=	d058574

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com
		${INSTALL_DATA} ${WRKSRC}/schemas/org.gnome.shell.extensions.dash-to-dock.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		cd ${WRKSRC} && ${COPYTREE_SHARE} . \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com

.include <bsd.port.mk>
