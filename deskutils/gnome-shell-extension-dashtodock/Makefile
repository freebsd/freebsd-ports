# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-dashtodock
PORTVERSION=	65
DISTVERSIONPREFIX=	extensions.gnome.org-v
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Convert the dash into a dock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-shell>=3.28:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=3.28:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome localbase pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes

GLIB_SCHEMAS=	org.gnome.shell.extensions.dash-to-dock.gschema.xml

GH_ACCOUNT=	micheleg
GH_PROJECT=	dash-to-dock

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com
	${INSTALL_DATA} ${WRKSRC}/schemas/org.gnome.shell.extensions.dash-to-dock.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/dash-to-dock@micxgx.gmail.com
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.po -delete

.include <bsd.port.mk>
