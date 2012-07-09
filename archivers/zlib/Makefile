# New ports collection makefile for:	zlib
# Date created:		17 April 2012
# Whom:			Muhammad Moinur Rahman <5u623l20@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zlib
PORTVERSION=	1.2.7
CATEGORIES=	archivers
MASTER_SITES=	SF/libpng/${PORTNAME}/${PORTVERSION} \
		http://zlib.net/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A Massively Spiffy Yet Delicately Unobtrusive Compression Library

USE_BZIP2=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		zlib.3
NO_MANCOMPRESS=	yes

PLIST_FILES=	include/zconf.h \
		include/zlib.h \
		lib/libz.so \
		lib/libz.a \
		lib/libz.so.1 \
		lib/libz.so.1.2.7 \
		lib/pkgconfig/zlib.pc
PLIST_DIRS=	lib/pkgconfig

post-patch:
	@${REINPLACE_CMD} -e '/mandir/s/share\///' ${WRKSRC}/configure

.include <bsd.port.mk>
