# New ports collection makefile for:	libsvg
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libsvg
PORTVERSION=	0.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A parser for SVG content in files or buffers

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_LIBTOOL_VER=15
USE_GNOME=	libxml2 gnomehack gnometarget
USE_ICONV=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/svg.h \
		lib/libsvg.a \
		lib/libsvg.so \
		lib/libsvg.so.1 \
		libdata/pkgconfig/libsvg.pc

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/src/svg_ascii.h
.endif

.include <bsd.port.post.mk>
