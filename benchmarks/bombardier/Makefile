# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombardier
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	codesenberg
USES=		go

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}; \
		${LN} -s vendor src; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags "-X main.version=${PORTVERSION}" .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
