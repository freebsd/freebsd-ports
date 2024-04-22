PORTNAME=	MST-Bench
DISTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Maximum sustainable throughput benchmark
WWW=		https://github.com/outpaddling/MST-Bench

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

MAKE_ARGS=	MANDIR=${PREFIX}/share/man

PLIST_FILES=	bin/mst-bench share/man/man1/mst-bench.1.gz

.include <bsd.port.mk>
