# New ports collection makefile for:	SearchAndRescue
# Date created:			10 June 2010
# Whom:				Jesse Smith <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	SearchAndRescue
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/Program/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A flight simulator in which the player rescues people

RUN_DEPENDS=	${LOCALBASE}/share/searchandrescue/human.ini:${PORTSDIR}/games/searchandrescue-data

USE_SDL=	mixer
USE_XORG=	x11 xau xdmcp xext xmu xpm xxf86vm
USE_GL=		glu
WRKSRC=		${WRKDIR}/${PORTNAME:L}_${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${DESKTOPDIR:S,${PREFIX}/,,}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.xpm
PLIST_DIRS=	${DESKTOPDIR:S,${PREFIX}/,,}

#Respect PREFIX, LOCALBASE, CC, etc.
post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/sar/config.h
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,/usr/X11R6,${LOCALBASE},g' \
		-e '/^CFLAGS = /s,=,= ${CFLAGS},g' \
		-e '/^CC = /s, = .*, = ${CC},' \
		-e '/^CPP = /s, = .*, = ${CXX},' \
		${WRKSRC}/sar/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sar/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/sar/icons/${PORTNAME}.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
