PORTNAME=	gnome-shell-extension-panel-osd
PORTVERSION=	0.0.0.20220406
PORTREVISION=	1
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OSD extension for the GNOME shell
WWW=		https://gitlab.com/jenslody/gnome-shell-extension-panel-osd

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GITLAB=	yes
GL_ACCOUNT=	jenslody
GL_TAGNAME=	5697b8f10cc35db77c4456f431fad97ac8499b65
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.shell.extensions.panel-osd.gschema.xml

GNU_CONFIGURE=	yes

NO_ARCH=	yes

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

post-patch:
	@${REINPLACE_CMD} -e 's|"3.38"|"3.38", "40", "41", "42"|g' \
		${WRKSRC}/data/metadata.json.in

.include <bsd.port.mk>
