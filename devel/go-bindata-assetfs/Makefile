# $FreeBSD$

PORTNAME=	go-bindata-assetfs
PORTVERSION=	g20180223
PORTREVISION=	1
CATEGORIES=	devel www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Serves embedded files from go-bindata with Go's net/http support

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	go-bindata>=0:devel/go-bindata

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	elazarl
GH_TAGNAME=	38087fe
GH_TUPLE=	golang:net:ca1201d:golang_net/golang.org/x/net \
		golang:sys:51ab0e2:golang_sys/golang.org/x/sys

GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
