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
MASTER_SITES=	http://home.leo.org/~bartel/nttcp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	billf

MAINTAINER=	billf@FreeBSD.org
COMMENT=	A client/server program for testing network performance

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
