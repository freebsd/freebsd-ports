PORTNAME=	gnome-shell-extension-openweather
PORTVERSION=	119
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenWeather extension for the GNOME3 shell
WWW=		https://gitlab.com/skrewball/openweather

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome
USE_GITLAB=	yes
GL_ACCOUNT=	skrewball
GL_PROJECT=	openweather
GL_TAGNAME=	dc4a165ffa7d11f19efd7f70401012b4d2c4b94f
USE_GNOME=	glib20
GLIB_SCHEMAS=	org.gnome.shell.extensions.openweather.gschema.xml

MAKE_ARGS+=	SHARE_PREFIX='$${DESTDIR}$${PREFIX}/share'

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

.include <bsd.port.mk>
