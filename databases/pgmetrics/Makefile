PORTNAME=	pgmetrics
PORTVERSION=	1.19.0
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect and display info & stats from a running PostgreSQL server
WWW=		https://pgmetrics.io/

LICENSE=	APACHE20

USES=		go:modules,1.25+

GO_MODULE=	github.com/rapidloop/pgmetrics

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"
CGO_ENABLED=	0

.include <bsd.port.mk>
