PORTNAME=	timescaledb-parallel-copy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Parallel copying of CSV data into a TimescaleDB hypertable
WWW=		https://github.com/timescale/timescaledb-parallel-copy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/timescale/timescaledb-parallel-copy
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/timescaledb-parallel-copy

.include <bsd.port.mk>
