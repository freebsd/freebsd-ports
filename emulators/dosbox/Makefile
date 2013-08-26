# Created by: Tom Carrick <knyghtmare@knyghtmare.com>
# $FreeBSD$

PORTNAME=	dosbox
PORTVERSION=	0.74
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	knyght@gmail.com
COMMENT=	Emulator of a PC with DOS

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl net sound
PLIST_FILES=	bin/dosbox share/pixmaps/dosbox.ico
PORTDOCS=	NEWS README

MAN1=		dosbox.1
PKGMESSAGE=	${WRKDIR}/pkg-message

CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-core-inline

DESKTOP_ENTRIES="DOSBox" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/dosbox.ico" "dosbox" \
		"System;Emulator;" "true"

OPTIONS_RADIO=	DEBUGGER
OPTIONS_RADIO_DEBUGGER=DEBUGGER_ENABLE DEBUGGER_HEAVY
DEBUGGER_ENABLE_DESC=Enable internal debugger
DEBUGGER_HEAVY_DESC=Enable internal debugger with extra features

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUGGER_ENABLE}
CONFIGURE_ARGS+=	--enable-debug=yes
.elif ${PORT_OPTIONS:MDEBUGGER_HEAVY}
CONFIGURE_ARGS+=	--enable-debug=heavy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#\/usr\/share\/doc\/dosbox#${DOCSDIR}#g' \
		${WRKSRC}/docs/dosbox.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${PREFIX}/bin/dosbox
	${INSTALL_DATA} ${WRKSRC}/src/dosbox.ico ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/docs/dosbox.1 ${MAN1PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
