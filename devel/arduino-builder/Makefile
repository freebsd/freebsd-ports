# $FreeBSD$

PORTNAME=	arduino-builder
PORTVERSION=	1.3.21
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Command line tool for building Arduino sketches

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TUPLE=	go-errors:errors:a418503:goerrors/src/github.com/go-errors/errors \
		stretchr:testify:v1.1.3:stretchr/src/github.com/stretchr/testify \
		jstemmer:go-junit-report:833f8ea:jstemmer/src/github.com/jstemmer/go-junit-report

STRIP=		# stripping can break go binaries

PLIST_FILES=	arduino/hardware/platform.keys.rewrite.txt \
		arduino/hardware/platform.txt \
		bin/${PORTNAME}

do-build:
	@( cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build arduino.cc/arduino-builder )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	(cd ${WRKSRC}/src/arduino.cc/builder && ${COPYTREE_SHARE} "hardware" ${STAGEDIR}${PREFIX}/arduino ${FIND_EXPR})

.include <bsd.port.mk>
