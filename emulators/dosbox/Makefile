# Created by: Tom Carrick <knyghtmare@knyghtmare.com>
# $FreeBSD$

PORTNAME=	dosbox
PORTVERSION=	0.74
PORTREVISION=	11
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	knyght@gmail.com
COMMENT=	Emulator of a PC with DOS

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl net sound
PLIST_FILES=	bin/dosbox man/man1/dosbox.1.gz share/pixmaps/dosbox.ico
PORTDOCS=	NEWS README

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS+=	--enable-core-inline

DESKTOP_ENTRIES="DOSBox" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/dosbox.ico" "dosbox" \
		"System;Emulator;" "true"

OPTIONS_RADIO=	DEBUGGER
OPTIONS_RADIO_DEBUGGER=DEBUGGER_ENABLE DEBUGGER_HEAVY
DEBUGGER_ENABLE_DESC=Enable internal debugger
DEBUGGER_HEAVY_DESC=Enable internal debugger with extra features

DEBUGGER_ENABLE_CONFIGURE_ON=	--enable-debug=yes
DEBUGGER_HEAVY_CONFIGURE_ON=	--enable-debug=heavy

post-patch:
	@${REINPLACE_CMD} -e 's#\/usr\/share\/doc\/dosbox#${DOCSDIR}#g' \
		${WRKSRC}/docs/dosbox.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${STAGEDIR}${PREFIX}/bin/dosbox
	${INSTALL_DATA} ${WRKSRC}/src/dosbox.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/docs/dosbox.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
