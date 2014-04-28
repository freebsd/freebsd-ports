# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-epub-thumbnailer/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	gnome-epub-thumbnailer
PORTVERSION=	1.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://git.gnome.org/browse/gnome-epub-thumbnailer/snapshot/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Thumbnailer for EPub and MOBI books

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common

USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 gnomedesktop3 gnomeprefix gtk30 \
		intlhack libxml2
USE_AUTOTOOLS=	libtoolize autoconf automake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib -larchive

post-patch:
	@${REINPLACE_CMD} -e 's|gio-2.0 libarchive libxml-2.0|gio-2.0 libxml-2.0|g' \
		${WRKSRC}/configure.ac

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
