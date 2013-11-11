# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxmp
PORTVERSION=	4.2.0
CATEGORIES=	audio
MASTER_SITES=	SF/xmp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module rendering library for xmp

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/xmp.h lib/libxmp.so lib/libxmp.so.4 \
		lib/libxmp.so.${PORTVERSION} libdata/pkgconfig/libxmp.pc

.include <bsd.port.mk>
