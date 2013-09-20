# Created by: Armin Pirkovitsch <armin@frozen-zone.org>
# $FreeBSD$

PORTNAME=	libg19
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	SF/g19linux/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	armin@frozen-zone.org
COMMENT=	G19 library

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	include/libg19.h \
		lib/libg19.a \
		lib/libg19.la \
		lib/libg19.so \
		lib/libg19.so.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
BROKEN=	libusb 1.0 or newer required.
.endif

.include <bsd.port.post.mk>
