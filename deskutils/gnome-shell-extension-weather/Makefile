PORTNAME=	gnome-shell-extension-weather
PORTVERSION=	0.0.0.20180411
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Weather extension for the GNOME3 shell
WWW=		https://github.com/Neroth/gnome-shell-extension-weather

BROKEN=		Does not support recent gnome-shell

RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell

USES=		autoreconf gettext gmake gnome libtool pkgconfig
USE_GNOME=	glib20 intlhack
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

GH_ACCOUNT=	Neroth
GH_TAGNAME=	ea2d56a

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

GLIB_SCHEMAS=	org.gnome.shell.extensions.weather.gschema.xml

.include <bsd.port.mk>
