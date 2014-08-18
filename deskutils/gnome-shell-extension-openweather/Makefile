# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-openweather/Makefile 19807 2014-08-14 07:04:43Z gusi $

PORTNAME=	gnome-shell-extension-openweather
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenWeather extension for the GNOME3 shell

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/jenslody-gnome-shell-extension-openweather-b20768a

USES=		gettext gmake libtool pkgconfig tar:xz
USE_GNOME=	glib20 intltool
USE_GITHUB=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.openweather.gschema.xml

GH_ACCOUNT=	jenslody
GH_PROJECT=	gnome-shell-extension-openweather
GH_TAGNAME=	b20768a010
GH_COMMIT=	b20768a010

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

pre-configure:
		cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
