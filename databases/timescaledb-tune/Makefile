# Created by Kevin Bowling <kbowling@FreeBSD.org>

PORTNAME=	timescaledb-tune
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Tool for tuning TimescaleDB for better performance

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/timescale/timescaledb-tune
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/timescaledb-tune

.include <bsd.port.mk>
