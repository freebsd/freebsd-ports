PORTNAME=	bfe2
PORTVERSION=	20030723
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	SF/bfe/source/23jul2003
DISTNAME=	${PORTNAME}-23jul2003

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 GUI for the bochs debugger (revision 2)

RUN_DEPENDS=	bochs:emulators/bochs

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gnome pkgconfig
USE_GNOME=	gtk20

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		--gtk 2.0

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%CFLAGS%%|"${CFLAGS}"|g ; \
		 s|%%CC%%|"${CC}"|g ; \
		 s|%%PREFIX%%|"${PREFIX}"|g ; \
		 s|gtk-config --libs|pkg-config --libs gtk+|g ; \
		 s|gtk-config --cflags|pkg-config --cflags gtk+|g' \
				${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfe2 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${STAGEDIR}${DATADIR}/bferc.sample
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
