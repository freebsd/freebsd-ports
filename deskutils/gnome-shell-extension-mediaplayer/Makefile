# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-mediaplayer
PORTVERSION=	0.0.0.20180316
PORTREVISION=	1
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MPRIS2 extension for the GNOME3 shell

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gnome meson pkgconfig python:3.4+,build
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.mediaplayer.gschema.xml

USE_GITHUB=	yes
GH_ACCOUNT=	JasonLG1979
GH_PROJECT=	gnome-shell-extensions-mediaplayer
GH_TAGNAME=	9653b7d

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MV} "${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/mediaplayer@patapon.info/schemas/org.gnome.shell.extensions.mediaplayer.gschema.xml" \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/mediaplayer@patapon.info/schemas

.include <bsd.port.mk>
