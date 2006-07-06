# New ports collection makefile for:	liboil
# Date created:				Nov 24, 2004
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	liboil
PORTVERSION=	0.3.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library of optimized inner loops

USE_GNOME=	glib20 gnomehack
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
CFLAGS+=	-O2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000 && ${OSVERSION} > 500000
#USE_GCC=	3.4
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
RUN_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
CC:=	gcc34
CXX:=	g++34
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\\$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint\.h|<inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboilprofile.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.post.mk>
