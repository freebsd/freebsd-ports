# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-shell-extension-weather/Makefile 19807 2014-08-14 07:04:43Z gusi $

PORTNAME=	gnome-shell-extension-weather
PORTVERSION=	0.0.0.20140520
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Weather extension for the GNOME3 shell

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell

WRKSRC=		${WRKDIR}/Neroth-gnome-shell-extension-weather-489aaa0

USES=		gettext gmake libtool pkgconfig tar:xz
USE_GNOME=	intltool
USE_GITHUB=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GH_ACCOUNT=	Neroth
GH_TAGNAME=	489aaa0a7a
GH_COMMIT=	489aaa0a7a

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

pre-configure:
		cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
