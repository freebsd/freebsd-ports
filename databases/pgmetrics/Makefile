# Created by: Palle Girgensohn <girgen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgmetrics
PORTVERSION=	1.6.1
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect and display info & stats from a running PostgreSQL server

LICENSE=	APACHE20

USE_GITHUB=	yes

BUILD_DEPENDS=	go>=1.9:lang/go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GH_ACCOUNT=	rapidloop
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}
GH_TUPLE=	dustin:go-humanize:bb3d318650d4:go_humanize/src/github.com/dustin/go-humanize \
		howeyc:gopass:bf9dde6d0d2c:gopass/src/github.com/howeyc/gopass \
		pborman:getopt:7148bc3a4c30:getopt/src/github.com/pborman/getopt \
		rapidloop:pq:40e32c5:pq/src/github.com/rapidloop/pq \
		xdg-go:stringprep:v1.0.0:stringprepgo/src/github.com/xdg-go/stringprep \
		xdg:stringprep:v1.0.0:stringprepxdg/src/github.com/xdg/stringprep \
		golang:sys:37707fdb30a5:sys/src/golang.org/x/sys \
		golang:crypto:432090b8f568:crypto/src/golang.org/x/crypto \
		golang:text:v0.3.0:text/src/golang.org/x/text

BUILD_AS_NON_ROOT=yes
GO_ENV+=	"CGO_ENABLED=0"

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR}; ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -ldflags "-s -w -X main.version=${PORTVERSION}" ./cmd/${PORTNAME}

do-install:
	@cd ${WRKSRC}/${GH_SUBDIR}; ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
