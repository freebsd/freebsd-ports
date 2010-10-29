# New ports collection makefile for:	paintlib
# Date created:				18 June 2004
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	paintlib
PORTVERSION=	2.6.2
PORTREVISION=	5
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.paintlib.de/paintlib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for processing images

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		ungif:${PORTSDIR}/graphics/libungif

DEPRECATED=	does not compile with new tiff and no more maintained upstream
EXPIRATION_DATE=	2010-12-30
BROKEN=		does not compile with new tiff

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-SDL --disable-dfb
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		paintlib-config.1

post-patch:
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_dest|paintlib_jpeg_mem_dest|' \
		${WRKSRC}/common/jmemdest.cpp \
		${WRKSRC}/common/jmemdest.h \
		${WRKSRC}/common/pljpegenc.cpp \
		${WRKSRC}/doc/reference/html/jmemdest_8h-source.html

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800501
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
