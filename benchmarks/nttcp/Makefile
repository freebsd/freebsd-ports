# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	nttcp
PORTVERSION=	1.47
PORTREVISION=	2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://freeware.sgi.com/source/nttcp/ \
		http://reality.sgiweb.org/freeware/source/nttcp/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A client/server program for testing network performance

RESTRICTED=	No commercial use

ALL_TARGET=	nttcp
PLIST_FILES=	bin/nttcp man/man1/nttcp.1.gz
USES=		gmake
MAKE_ENV+=	OPT="${CFLAGS}"
NOPRECIOUSMAKEVARS=yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nttcp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/nttcp.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
