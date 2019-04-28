# $FreeBSD$

PORTNAME=	golint
PORTVERSION=	g20190409
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linter for Go source code

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/${GO_SUBDIR}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	nodefault
GH_ACCOUNT=	golang
GH_PROJECT=	lint
GH_TAGNAME=	959b441
GH_TUPLE=	golang:lint:959b441:main/src/golang.org/x/lint \
		golang:tools:e65039e:golang_tools/src/golang.org/x/tools

GO_SUBDIR=	src/golang.org/x/lint

PLIST_FILES=	bin/golint

do-build:
	@cd ${WRKSRC}/${GO_SUBDIR}/golint && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GO_SUBDIR}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
