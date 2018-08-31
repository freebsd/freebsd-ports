# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protobuf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	go-

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Protocol Buffers for Go with Gadgets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	gogo
GH_SUBDIR=	src/github.com/gogo/protobuf

TARGETS=	protoc-gen-combo \
		protoc-gen-gofast \
		protoc-gen-gogo \
		protoc-gen-gogofast \
		protoc-gen-gogofaster \
		protoc-gen-gogoslick \
		protoc-gen-gogotypes \
		protoc-gen-gostring \
		protoc-min-version

do-build:
.for TARGET in ${TARGETS}
	@cd ${WRKSRC}/${TARGET} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build
.endfor

do-install:
.for TARGET in ${TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET}/${TARGET} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
