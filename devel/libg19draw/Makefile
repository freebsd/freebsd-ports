# New ports collection makefile for:	libg19draw
# Date created:				Apr 15 2011
# Whom:					Armin Pirkovitsch <armin@frozen-zone.org>
#
# $FreeBSD$
#

PORTNAME=	libg19draw
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	SF/g19linux/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	armin@frozen-zone.org
COMMENT=	G19 draw library

LIB_DEPENDS=	g19.1:${PORTSDIR}/devel/libg19 \
		freetype.9:${PORTSDIR}/print/freetype2

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -pthread"

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	include/libg19draw.h \
		lib/libg19draw.a \
		lib/libg19draw.la \
		lib/libg19draw.so \
		lib/libg19draw.so.1

.include <bsd.port.mk>
