# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-panel-osd
PORTVERSION=	0.0.0.20171023
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OSD extension for the GNOME3 shell

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=	glib20 intltool
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	org.gnome.shell.extensions.panel-osd.gschema.xml

GH_ACCOUNT=	jenslody
GH_TAGNAME=	43d5f29

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

post-patch:
	@${REINPLACE_CMD} -e 's|"3.26"|"3.26", "3.28"|g' \
		${WRKSRC}/data/metadata.json.in

.include <bsd.port.mk>
