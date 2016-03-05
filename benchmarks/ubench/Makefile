# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ubench
PORTVERSION=	0.32
CATEGORIES=	benchmarks
MASTER_SITES=	SUNSITE/system/benchmark

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix Benchmark Utility for CPU(s) and memory

LICENSE=	GPLv2+

HAS_CONFIGURE=	yes
ALL_TARGET=	ubench

PLIST_FILES=	bin/ubench \
		man/man8/ubench.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ubench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ubench.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
