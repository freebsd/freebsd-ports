# Created by: Jesse Smith <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	SearchAndRescue
PORTVERSION=	1.4.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:tl}/Program/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Flight simulator in which the player rescues people

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/searchandrescue/human.ini:games/searchandrescue-data

USES=		gl sdl xorg
USE_GL=		gl glu
USE_SDL=	mixer
USE_XORG=	ice sm x11 xau xdmcp xext xmu xpm xxf86vm
WRKSRC=		${WRKDIR}/${PORTNAME:tl}_${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${DESKTOPDIR:S,${PREFIX}/,,}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.xpm

#Respect PREFIX, LOCALBASE, CC, etc.
post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/sar/config.h
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,/usr/X11R6,${LOCALBASE},g' \
		-e '/^CFLAGS = /s,=,= ${CFLAGS},g' \
		-e '/^CPPFLAGS = /s, = .*, = ${CPPFLAGS},g' \
		-e '/^CC = /s, = .*, = ${CC},' \
		-e '/^CPP = /s, = .*, = ${CXX},' \
		-e 's,-O6,,' \
		${WRKSRC}/sar/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sar/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/sar/icons/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
