# New ports collection makefile for:	libpixman
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libpixman
PORTVERSION=	0.1.6
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Pixel region library

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	pkgconfig gnometarget gnomehack
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/pixman.h \
		lib/libpixman.a \
		lib/libpixman.so \
		lib/libpixman.so.1 \
		libdata/pkgconfig/libpixman.pc

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/src/pixman.h
.endif

.include <bsd.port.post.mk>
