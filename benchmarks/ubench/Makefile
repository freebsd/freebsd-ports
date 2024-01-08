PORTNAME=	ubench
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SUNSITE/system/benchmark

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix Benchmark Utility for CPU(s) and memory
WWW=		http://www.phystech.com/download/ubench.html

LICENSE=	GPLv2+

HAS_CONFIGURE=	yes
ALL_TARGET=	ubench

PLIST_FILES=	bin/ubench \
		share/man/man8/ubench.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ubench ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ubench.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
