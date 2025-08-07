PORTNAME=	pgmetrics
PORTVERSION=	1.17.1
DISTVERSIONPREFIX=v
PORTREVISION=	5
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Collect and display info & stats from a running PostgreSQL server
WWW=		https://pgmetrics.io/

LICENSE=	APACHE20

USES=		go:modules

GO_MODULE=	github.com/rapidloop/pgmetrics
#USE_GITHUB=	yes

#GH_ACCOUNT=	rapidloop
#GH_TUPLE=	\
		aws:aws-sdk-go:v1.29.29:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		dustin:go-humanize:bb3d318650d4:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		golang:crypto:e9b2fee46413:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		pborman:getopt:7148bc3a4c30:pborman_getopt/vendor/github.com/pborman/getopt \
		rapidloop:pq:66681b501d6d:rapidloop_pq/vendor/github.com/rapidloop/pq \
		xdg-go:stringprep:v1.0.0:xdg_go_stringprep/vendor/github.com/xdg-go/stringprep

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${PORTVERSION}"
CGO_ENABLED=	0

.include <bsd.port.mk>
