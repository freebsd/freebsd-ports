PORTNAME=	timescaledb-tune
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Tool for tuning TimescaleDB for better performance
WWW=		https://github.com/timescale/timescaledb-tune

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/timescale/timescaledb-tune
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/timescaledb-tune

.include <bsd.port.mk>
