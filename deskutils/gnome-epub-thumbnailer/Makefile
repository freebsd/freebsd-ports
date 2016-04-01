# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-epub-thumbnailer
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://git.gnome.org/browse/gnome-epub-thumbnailer/snapshot/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Thumbnailer for EPub and MOBI books

BUILD_DEPENDS=	gnome-autogen.sh:devel/gnome-common

USES=		autoreconf:build gettext gmake libarchive libtool pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 gnomedesktop3 gnomeprefix gtk30 \
		intlhack libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib -larchive

post-patch:
	@${REINPLACE_CMD} -e 's|gio-2.0 libarchive libxml-2.0|gio-2.0 libxml-2.0|g' \
		${WRKSRC}/configure.ac

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
