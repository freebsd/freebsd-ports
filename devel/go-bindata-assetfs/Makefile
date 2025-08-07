PORTNAME=	go-bindata-assetfs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	28
CATEGORIES=	devel www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Serves embedded files from go-bindata with Go's net/http support
WWW=		https://github.com/elazarl/go-bindata-assetfs

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	go-bindata>=0:devel/go-bindata

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	elazarl
GH_TUPLE=	golang:net:ab34263:golang_net/golang.org/x/net \
		golang:sys:ddb9806:golang_sys/golang.org/x/sys

GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
