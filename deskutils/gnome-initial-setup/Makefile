PORTNAME=	gnome-initial-setup
PORTVERSION=	43.2
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	First boot setup tool for GNOME
WWW=		https://live.gnome.org/GnomeOS/Design/Whiteboards/InitialSetup

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gdm>=3.0.0:x11/gdm \
		gnome-autogen.sh:devel/gnome-common \
		krb5>0:security/krb5
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libadwaita-1.so:x11-toolkits/libadwaita \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgweather-4.so:net/libgweather4 \
		libhandy-1.so:x11-toolkits/libhandy \
		libpwquality.so:security/libpwquality \
		librest-1.0.so:net/librest1 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60
RUN_DEPENDS=	gdm>=3.0.0:x11/gdm \
		krb5>0:security/krb5

USES=		compiler:c++11-lib gettext gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack

MESON_ARGS=	-Dibus=disabled \
		-Dparental_controls=disabled \
		-Dsystemd=false

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
