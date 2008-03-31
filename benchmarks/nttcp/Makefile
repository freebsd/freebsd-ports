# New ports collection makefile for:   nttcp
# Date created:        11 Nov 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	nttcp
PORTVERSION=	1.47
PORTREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://freeware.sgi.com/source/nttcp/ \
		http://reality.sgiweb.org/freeware/source/nttcp/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A client/server program for testing network performance

RESTRICTED=	No commercial use

ALL_TARGET=	nttcp
MAN1=		nttcp.1
PLIST_FILES=	bin/nttcp
USE_GMAKE=	yes
MAKE_ENV+=	OPT="${CFLAGS}"
NOPRECIOUSMAKEVARS=yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nttcp ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/nttcp.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
