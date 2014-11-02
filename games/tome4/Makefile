# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	tome4
PORTVERSION=	1.2.4
CATEGORIES=	games
MASTER_SITES=	http://te4.org/dl/t-engine/ \
		SF/lifanov-ports-distfiles/${PORTNAME}/:icons
DISTFILES=	t-engine4-src-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	t-engine4-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Epic tactical turn-based roguelike adventure

LICENSE=	GPLv3

BUILD_DEPENDS=	premake4:${PORTSDIR}/devel/premake4
LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis

DESKTOP_ENTRIES="ToME 4" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;RolePlaying;" ""

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/t-engine4-src-${PORTVERSION}
MAKE_ARGS+=	config=release verbose=yes ARCH=""
USES=		gmake openal:al tar:bzip2
USE_SDL=	image2 sdl2 ttf2
USE_GL=		gl glu
USE_CSTD=	gnu89
SUB_FILES=	tome4
MAKE_JOBS_UNSAFE=yes

pre-build:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/premake4.lua
	(cd ${WRKSRC} && premake4 gmake)
	@${REINPLACE_CMD} 's|gcc|${CC}|' ${WRKSRC}/build/*.make
	@${REINPLACE_CMD} 's|-lpthread|-pthread|' ${WRKSRC}/build/TEngine.make

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/t-engine ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/tome4 ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}; ${COPYTREE_SHARE} "bootstrap game" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
