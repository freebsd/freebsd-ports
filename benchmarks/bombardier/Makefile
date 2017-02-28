# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombardier
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Fast cross-platform HTTP benchmarking tool written in Go

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.7:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	codesenberg
GH_TUPLE=	cheggaaa:pb:v1.0.7:pb/src/github.com/cheggaaa/pb \
		valyala:fasthttp:v20160617:fasthttp/src/github.com/valyala/fasthttp \
		klauspost:compress:v1.2.1:compress/src/github.com/klauspost/compress \
		klauspost:cpuid:v1.0:cpuid/src/github.com/klauspost/cpuid \
		klauspost:crc32:v1.1:crc32/src/github.com/klauspost/crc32 \
		alecthomas:kingpin:v2.2.3:kingpin/src/github.com/alecthomas/kingpin \
		alecthomas:template:a0175ee:template/src/github.com/alecthomas/template \
		alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		mattn:go-runewidth:v0.0.2:go_runewidth/src/github.com/mattn/go-runewidth

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags "-X main.version=${PORTVERSION}" .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-1.0 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
