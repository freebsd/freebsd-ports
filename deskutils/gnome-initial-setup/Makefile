PORTNAME=	gnome-initial-setup
PORTVERSION=	47.5
PORTREVISION=	0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	First boot setup tool for GNOME
WWW=		https://gitlab.gnome.org/GNOME/gnome-initial-setup

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gdm>=3.0.0:x11/gdm \
		gnome-autogen.sh:devel/gnome-common \
		krb5>0:security/krb5
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libadwaita-1.so:x11-toolkits/libadwaita \
		libfontconfig.so:x11-fonts/fontconfig \
		libgeoclue-2.so:net/geoclue \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgweather-4.so:net/libgweather4 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60
RUN_DEPENDS=	gdm>=3.0.0:x11/gdm \
		krb5>0:security/krb5

USES=		compiler:c++11-lib gettext gnome meson pkgconfig tar:xz
#USE_GNOME=	gdkpixbuf gnomedesktop4 intlhack
USE_GNOME=	gdkpixbuf gnomedesktop4

MESON_ARGS=	-Dibus=disabled \
		-Dparental_controls=disabled \
		-Dsystemd=false

PORTSCOUT=	limit:^47\.

.include <bsd.port.mk>
