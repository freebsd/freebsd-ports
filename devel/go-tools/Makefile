# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tools
PORTVERSION=	20170328
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Go Tools

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_TUPLE=	golang:tools:d63e2b2:DEFAULT/src/golang.org/x/tools \
		golang:crypto:3cb0727:crypto/src/golang.org/x/crypto \
		golang:net:b6d7b13:net/src/golang.org/x/net

TARGETS=	benchcmp bundle callgraph cover digraph eg fiximports godex \
		godoc goimports gomvpkg gorename gotype guru html2article \
		present ssadump stress stringer

do-build:
.for TARGET in ${TARGETS}
	cd ${WRKSRC}/cmd/${TARGET} ; \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build golang.org/x/tools/cmd/${TARGET}
.endfor

do-install:
.for TARGET in ${TARGETS}
	${STRIP_CMD} ${WRKSRC}/cmd/${TARGET}/${TARGET}
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/${TARGET}/${TARGET} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
