# $FreeBSD$

PORTNAME=	go-bindata-assetfs
PORTVERSION=	g20200509
CATEGORIES=	devel www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Serves embedded files from go-bindata with Go's net/http support

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	go-bindata>=0:devel/go-bindata

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	elazarl
GH_TAGNAME=	234c15e
GH_TUPLE=	golang:net:627f964:golang_net/golang.org/x/net \
		golang:sys:226ff32:golang_sys/golang.org/x/sys

GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

PORTSCOUT=	skipv:1.0.0

.include <bsd.port.mk>
