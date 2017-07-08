# Created by: Brad Davis <brd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hey
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Tiny program that sends some load to a web application

BUILD_DEPENDS=	go>=1.7:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	rakyll

GH_TUPLE=	golang:net:41bba8d:net/src/golang.org/x/net

PLIST_FILES=	bin/hey

do-build:
	( cd ${WRKSRC}; \
		${MKDIR} src/github.com/rakyll/hey; \
		cd src/github.com/rakyll/hey; \
		${LN} -s ../../../../requester . )
	( cd ${WRKSRC}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} CC=clang \
		go build ${BUILD_FLAGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
