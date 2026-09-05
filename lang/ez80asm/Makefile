PORTNAME=		ez80asm
DISTVERSIONPREFIX=	v
DISTVERSION=		2.2
CATEGORIES=		lang

MAINTAINER=	alexey@pentode.fi
COMMENT=	Z80/Z180/eZ80 assembler for Agon Light platform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix gmake
USE_GITHUB=	yes
GH_ACCOUNT=	AgonPlatform
GH_PROJECT=	agon-ez80asm

ALL_TARGET=	linux

PLIST_FILES=	bin/ez80asm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ez80asm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
