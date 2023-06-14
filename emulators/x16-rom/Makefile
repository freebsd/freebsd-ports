PORTNAME=	x16-rom
DISTVERSION=	r40
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Commander X16 ROM
WWW=		https://github.com/commanderx16

BUILD_DEPENDS=	cc65:devel/cc65

USES=		gmake python:build

USE_GITHUB=	yes
GH_ACCOUNT=	commanderx16

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
