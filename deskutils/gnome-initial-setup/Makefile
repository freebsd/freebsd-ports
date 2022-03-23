# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	gnome-initial-setup
PORTVERSION=	42.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	First boot setup tool for GNOME

BUILD_DEPENDS=	gdm>=3.0.0:x11/gdm \
		gnome-autogen.sh:devel/gnome-common \
		krb5>0:security/krb5
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgweather-4.so:net/libgweather4 \
		libhandy-1.so:x11-toolkits/libhandy \
		libpwquality.so:security/libpwquality
RUN_DEPENDS=	gdm>=3.0.0:x11/gdm \
		krb5>0:security/krb5

USES=		compiler:c++11-lib gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gtk30 intlhack

MESON_ARGS=	-Dcheese=disabled \
		-Dparental_controls=disabled \
		-Dsystemd=false

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
