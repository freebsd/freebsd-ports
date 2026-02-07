PORTNAME=	x16-rom
DISTVERSION=	r49
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Commander X16 ROM
WWW=		https://github.com/X16Community

BUILD_DEPENDS=	lzsa:archivers/lzsa \
		cc65:devel/cc65 \
		bash:shells/bash

USES=		gmake python:build

USE_GITHUB=	yes
GH_ACCOUNT=	X16Community

MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/x16-emulator
BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTDATA=	rom.bin

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/x16/rom.bin ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
