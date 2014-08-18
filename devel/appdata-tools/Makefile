# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/appdata-tools/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	appdata-tools
PORTVERSION=	0.1.7
CATEGORIES=	devel
DIST_SUBDIR=	gnome3

WRKSRC=		${WRKDIR}/hughsie-appdata-tools-b364e3e

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AppData is a subset of AppStream

BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GH_ACCOUNT=	hughsie
GH_PROJECT=	appdata-tools
GH_COMMIT=      b364e3e
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
#CONFIGURE_ARGS=	--enable-introspection=yes
USE_GITHUB=	yes
USES=		gmake libtool pathfix pkgconfig
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_GNOME=	gdkpixbuf2 glib20 gnomehier introspection:build
USE_LDCONFIG=	yes

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
