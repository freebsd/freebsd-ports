# $FreeBSD$

PORTNAME=	arduino-builder
PORTVERSION=	1.3.21
PORTREVISION=	3
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

OPTIONS_DEFINE=	TOOLS
OPTIONS_DEFAULT=TOOLS

TOOLS_DESC=		Add arduino-tools for a standalone build setup
TOOLS_RUN_DEPENDS=	arduino-tools>=${_COMPAT_VER}:devel/arduino-tools
TOOLS_PLIST_FILES=	arduino/arduino-builder.options

GO_ENV+=	GOPATH=${WRKSRC}
STRIP=		# stripping can break go binaries
_COMPAT_VER=	1.6.12
_IDE_VER=	10612

PLIST_FILES=	arduino/hardware/platform.keys.rewrite.txt \
		arduino/hardware/platform.txt \
		bin/${PORTNAME}

do-patch-TOOLS-on:
	${CP} ${FILESDIR}/arduino-builder.options.in ${WRKSRC}/arduino-builder.options
	${REINPLACE_CMD} -e 's|%%IDEVER%%|${_IDE_VER}|' \
			-e 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/arduino-builder.options

do-build:
	@( cd ${WRKSRC} ; ${SETENV} ${GO_ENV} go build arduino.cc/arduino-builder )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	(cd ${WRKSRC}/src/arduino.cc/builder && ${COPYTREE_SHARE} "hardware" ${STAGEDIR}${PREFIX}/arduino ${FIND_EXPR})

do-install-TOOLS-on:
	${INSTALL_DATA} ${WRKSRC}/arduino-builder.options ${STAGEDIR}${PREFIX}/arduino/arduino-builder.options

.include <bsd.port.mk>
