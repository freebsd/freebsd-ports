PORTNAME=	x16-rom
DISTVERSION=	r40
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Commander X16 ROM

BUILD_DEPENDS=	cc65:devel/cc65

USES=		gmake python:3.7+,build

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
