# New ports collection makefile for:   nttcp
# Version required:    1.45
# Date created:        11 Nov 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	nttcp-1.45
CATEGORIES=	net benchmarks
MASTER_SITES=	http://users.leo.org/~bartel/nttcp/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

ALL_TARGET=	nttcp
MAN1=		nttcp.1
USE_GMAKE=	yes
MAKE_ENV+=	OPT="${CFLAGS}"

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/nttcp ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/nttcp.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
