# $FreeBSD$

PORTNAME=	go-bindata-assetfs
PORTVERSION=	g20191027
CATEGORIES=	devel www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Serves embedded files from go-bindata with Go's net/http support

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	go-bindata>=0:devel/go-bindata

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	elazarl
GH_TAGNAME=	d0111fe
GH_TUPLE=	golang:net:1617124:golang_net/golang.org/x/net \
		golang:sys:d101bd2:golang_sys/golang.org/x/sys

GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
