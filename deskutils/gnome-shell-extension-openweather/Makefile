PORTNAME=	gnome-shell-extension-openweather
PORTVERSION=	0.0.0.20171126
PORTREVISION=	1
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenWeather extension for the GNOME3 shell

BROKEN=		does not fetch

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=	glib20 intltool
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	org.gnome.shell.extensions.openweather.gschema.xml

GH_ACCOUNT=	jenslody
GH_TAGNAME=	851d680

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

.include <bsd.port.mk>
