# $FreeBSD$

PORTNAME=	arduino-builder
PORTVERSION=	1.3.25
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Command line tool for building Arduino sketches

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_TUPLE=	go-errors:errors:8fa88b0:goerrors/src/github.com/go-errors/errors \
		stretchr:testify:v1.1.4:stretchr/src/github.com/stretchr/testify \
		jstemmer:go-junit-report:6aeed67:jstemmer/src/github.com/jstemmer/go-junit-report

GO_PKGNAME=	arduino.cc
GO_TARGET=	./arduino-builder

OPTIONS_DEFINE=	TOOLS
OPTIONS_DEFAULT=TOOLS

TOOLS_DESC=		Add arduino-tools for a standalone build setup
TOOLS_RUN_DEPENDS=	arduino-tools>=${_COMPAT_VER}:devel/arduino-tools
TOOLS_PLIST_FILES=	arduino/arduino-builder.options

_COMPAT_VER=	1.6.12
_IDE_VER=	10612

PLIST_FILES=	arduino/hardware/platform.keys.rewrite.txt \
		arduino/hardware/platform.txt \
		bin/${PORTNAME}

# override, upstream expects GOROOT in ${WRKSRC}, not ${WRKDIR}
post-extract:
	${LN} -s ${WRKSRC}/src ${WRKDIR}

do-patch-TOOLS-on:
	${CP} ${FILESDIR}/arduino-builder.options.in ${WRKSRC}/arduino-builder.options
	${REINPLACE_CMD} -e 's|%%IDEVER%%|${_IDE_VER}|' \
			-e 's|%%PREFIX%%|${PREFIX}|' \
			${WRKSRC}/arduino-builder.options

post-install:
	(cd ${GO_WRKSRC}/builder && ${COPYTREE_SHARE} "hardware" ${STAGEDIR}${PREFIX}/arduino ${FIND_EXPR})

post-install-TOOLS-on:
	${INSTALL_DATA} ${WRKSRC}/arduino-builder.options ${STAGEDIR}${PREFIX}/arduino/arduino-builder.options

.include <bsd.port.mk>
