# Created by: jhb
# $FreeBSD$

PORTNAME=	bfe2
PORTVERSION=	20030723
PORTREVISION=	8
CATEGORIES=	emulators
MASTER_SITES=	SF/bfe/source/23jul2003
DISTNAME=	${PORTNAME}-23jul2003

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 GUI for the bochs debugger (revision 2)

RUN_DEPENDS=	bochs:emulators/bochs

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		pkgconfig
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK1 GTK2
OPTIONS_DEFAULT=	GTK2

GTK1_USE=		GNOME=gtk12
GTK1_CONFIGURE_ON=	--gtk 1.2
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ON=	--gtk 2.0

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
