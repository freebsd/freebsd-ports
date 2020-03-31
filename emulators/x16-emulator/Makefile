# $FreeBSD$

PORTNAME=	x16-emulator
DISTVERSION=	r37
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Emulator for the Commander X16 8-bit computer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${DATADIR}/rom.bin:emulators/x16-rom

USES=		compiler:c++11-lang gmake sdl

USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	commanderx16

DESKTOP_ENTRIES=	"Commander X16" \
			"" \
			"" \
			"x16emu" \
			"" \
			true

PLIST_FILES=	bin/x16emu

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x16emu ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
