# $FreeBSD$

PORTNAME=	golint
PORTVERSION=	g20190409
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linter for Go source code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	golang
GH_PROJECT=	lint
GH_TAGNAME=	959b441
GH_TUPLE=	golang:tools:e65039e:golang_tools/vendor/golang.org/x/tools

GO_TARGET=	./golint

PLIST_FILES=	bin/golint

.include <bsd.port.mk>
