PORTNAME=	x16-emulator
DISTVERSION=	r43
CATEGORIES=	emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Emulator for the Commander X16 8-bit computer
WWW=		https://github.com/X16Community

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${DATADIR}/rom.bin:emulators/x16-rom

USES=		compiler:c++11-lang gmake sdl

USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	X16Community

DESKTOP_ENTRIES=	"Commander X16" \
			"" \
			"" \
			"x16emu" \
			"" \
			true

PLIST_FILES=	bin/x16emu

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/main.c
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS=-Wno-error=deprecated-non-prototype |g' \
		${WRKSRC}/Makefile
.endif


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x16emu ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
