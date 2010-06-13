# New ports collection makefile for:	lzop
# Date created:				Fri 2 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	lzop
DISTVERSION=	1.02rc1
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Fast file compressor similar to gzip, using the LZO library

# prefer lzo2 if it is already installed or if no lzo is installed.
.if exists(${LOCALBASE}/lib/liblzo2.so.2) || !exists(${LOCALBASE}/lib/liblzo.so.1)
LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2
.else
LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		lzop.1
PLIST_FILES=	bin/lzop

.include <bsd.port.mk>
