# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	nttcp
PORTVERSION=	1.47
PORTREVISION=	3
CATEGORIES=	benchmarks net
MASTER_SITES=	http://freeware.sgi.com/source/nttcp/ \
		http://reality.sgiweb.org/freeware/source/nttcp/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Client/server program for testing network performance

RESTRICTED=	No commercial use

ALL_TARGET=	nttcp
USES=		gmake
MAKE_ENV+=	OPT="${CFLAGS}"
NOPRECIOUSMAKEVARS=yes

PLIST_FILES=	bin/nttcp man/man1/nttcp.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nttcp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nttcp.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
