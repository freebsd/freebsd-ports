PORTNAME=	x16-rom
DISTVERSION=	r47
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Commander X16 ROM
WWW=		https://github.com/X16Community

BUILD_DEPENDS=	lzsa:archivers/lzsa \
		cc65:devel/cc65 \
		bash:shells/bash

USES=		gmake python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	X16Community

SHEBANG_FILES=	findsymbols
MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/x16-emulator
BINARY_ALIAS=	make=${MAKE_CMD} \
		python3=${PYTHON_CMD}
PORTDATA=	rom.bin

post-patch:
	${REINPLACE_CMD} '1s,bash,sh,' ${WRKSRC}/scripts/symbolize.sh

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/x16/rom.bin ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
