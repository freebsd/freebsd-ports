# New ports collection makefile for:	lzop
# Date created:				Fri 2 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	lzop
PORTVERSION=	1.00
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzop/download/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

PORTCOMMENT=	Fast file compressor similar to gzip, using the LZO library

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		lzop.1

.include <bsd.port.mk>
