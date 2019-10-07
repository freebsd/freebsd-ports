# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgmetrics
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect and display info & stats from a running PostgreSQL server

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes

GH_ACCOUNT=	rapidloop
GH_TUPLE=	dustin:go-humanize:bb3d318650d4:go_humanize/vendor/github.com/dustin/go-humanize \
		howeyc:gopass:bf9dde6d0d2c:gopass/vendor/github.com/howeyc/gopass \
		pborman:getopt:7148bc3a4c30:getopt/vendor/github.com/pborman/getopt \
		rapidloop:pq:40e32c5:pq/vendor/github.com/rapidloop/pq \
		xdg-go:stringprep:v1.0.0:stringprepgo/vendor/github.com/xdg-go/stringprep \
		xdg:stringprep:v1.0.0:stringprepxdg/vendor/github.com/xdg/stringprep \
		golang:sys:37707fdb30a5:sys/vendor/golang.org/x/sys \
		golang:crypto:432090b8f568:crypto/vendor/golang.org/x/crypto \
		golang:text:v0.3.0:text/vendor/golang.org/x/text

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"
CGO_ENABLED=	0

.include <bsd.port.mk>
