# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tools
DISTVERSION=	20180726
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Go Tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_TUPLE=	golang:tools:bfb5194:DEFAULT/src/golang.org/x/tools \
		golang:crypto:3cb0727:crypto/src/golang.org/x/crypto \
		golang:net:b6d7b13:net/src/golang.org/x/net

TARGETS=	benchcmp bundle callgraph compilebench cover digraph eg fiximports \
		getgo go-contrib-init godex godoc goimports gomvpkg gorename gotype \
		goyacc guru heapview html2article present ssadump stress stringer \
		tip toolstash

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
