PORTNAME=	gnome-shell-extension-dashtopanel
DISTVERSIONPREFIX=	v
DISTVERSION=	70
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Icon taskbar for the Gnome Shell
WWW=		https://github.com/home-sweet-gnome/dash-to-panel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell

USES=		gettext-tools gmake gnome
USE_GNOME=	glib20 intltool:build

USE_GITHUB=	yes
GH_ACCOUNT=	home-sweet-gnome
GH_PROJECT=	dash-to-panel

UUID_EXTENSION=	dash-to-panel@jderose9.github.com

SUB_FILES=	pkg-message
SUB_LIST=	UUID=${UUID_EXTENSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.dash-to-panel.gschema.xml

post-patch:
	${REINPLACE_CMD} -e 's|: 9999|: ${DISTVERSION}|' \
		${WRKSRC}/metadata.json
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/schemas/*.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas

.include <bsd.port.mk>
