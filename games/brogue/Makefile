PORTNAME=	brogue
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Much-loved minimalist roguelike game (community edition)
WWW=		https://sites.google.com/site/broguegame/

LICENSE=	AGPLv3+ CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_AGPLv3+ = ${WRKSRC}/LICENSE.txt
LICENSE_FILE_CC-BY-SA-4.0= ${WRKSRC}/bin/assets/LICENSE.txt

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tmewett
GH_PROJECT=	BrogueCE

.if ${FLAVOR} == x11
USES+=		sdl
USE_SDL=	image2 sdl2
CONFLICTS_INSTALL=	brogue-nox11
.else
CONFLICTS_INSTALL=	brogue
.endif

MAKE_ARGS=	DATADIR=${DATADIR} \
		RELEASE=YES \
		GRAPHICS=${${FLAVOR:U} == x11:?YES:NO}
ALL_TARGET=	bin/brogue
SUB_FILES=	brogue.desktop brogue.sh
PLIST_SUB=	DISTVERSION=${DISTVERSION}

PLIST_FILES=	bin/brogue \
		libexec/brogue \
		share/applications/brogue.desktop
PORTDATA=	assets/LICENSE.txt \
		assets/tiles.bin \
		assets/icon.png \
		assets/tiles.png \
		keymap.txt

OPTIONS_DEFINE=	DEBUG NCURSES WEBUI
OPTIONS_DEFAULT=	NCURSES WEBUI
DEBUG_MAKE_ARGS=	DEBUG=YES
DEBUG_MAKE_ARGS_OFF=	DEBUG=NO
NCURSES_USES=		ncurses
NCURSES_MAKE_ARGS=	TERMINAL=YES
NCURSES_MAKE_ARGS_OFF=	TERMINAL=NO
WEBUI_MAKE_ARGS=	WEBUI=YES
WEBUI_MAKE_ARGS_OFF=	WEBUI=NO

post-patch:
	${REINPLACE_CMD} -e 's,/opt/brogue,${DATADIR},' ${WRKSRC}/linux/brogue-multiuser.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/brogue ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/brogue.sh ${STAGEDIR}${PREFIX}/bin/brogue
	${MKDIR} ${STAGEDIR}${DATADIR}/assets
	${INSTALL_DATA} ${WRKSRC}/bin/keymap.txt ${STAGEDIR}${DATADIR}
.for f in ${PORTDATA:Massets/*}
	${INSTALL_DATA} ${WRKSRC}/bin/$f ${STAGEDIR}${DATADIR}/assets/
.endfor
	${INSTALL_DATA} ${WRKDIR}/brogue.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
