# New ports collection makefile for:	cairo
# Date created:		2004-10-06
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Cairo is a vector graphics library with cross-device output support

LIB_DEPENDS=	pixman.1:${PORTSDIR}/graphics/libpixman \
		glitz-glx.1:${PORTSDIR}/graphics/glitz \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget gnomehack
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CLFAGS}" \
		LDFLAGS="${PTHREAD_LDFLAGS}"

PLIST_FILES=	include/cairo-features.h \
		include/cairo.h \
		lib/libcairo.a \
		lib/libcairo.so \
		lib/libcairo.so.1 \
		libdata/pkgconfig/cairo.pc

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/src/*.*
.endif

.include <bsd.port.post.mk>
