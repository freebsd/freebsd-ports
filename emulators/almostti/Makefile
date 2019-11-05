# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	almostti
PORTVERSION=	1.3
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/ATI85/
DISTNAME=	AlmostTI13-Unix-DougMelton-051409

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Texas Instruments Z80 series calculator emulator

USES=		gmake xorg
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/AlmostTI-DougMelton-Source
BUILD_WRKSRC=	${WRKSRC}/ATI85/Unix

DESKTOP_ENTRIES=	"ATI85" "${COMMENT}" "ati85" "ati85" \
			"Utility;Calculator;Emulator;" false

post-patch:
	@${REINPLACE_CMD} -e 's,\./,${DATADIR}/,' ${WRKSRC}/ATI85/TI85.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ati85 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for model in 82 83 83P 83SE 84SE 85 86
	${INSTALL_DATA} ${WRKSRC}/ATI85/Maemo/Package/TI${model}.png \
		${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/ATI85/Maemo/Package/ati85-64x64.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/ati85.png

.include <bsd.port.mk>
