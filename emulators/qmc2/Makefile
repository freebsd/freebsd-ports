# Created by: alepulver
# $FreeBSD$

PORTNAME=	qmc2
PORTVERSION=	0.64
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Qt4 based UNIX MAME/MESS frontend

RUN_DEPENDS=	mame>=0.154:emulators/mame \
		mess>=0.154:emulators/mess

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

USES=		gmake tar:bzip2
USE_XORG=	x11 xmu
USE_GL=		gl glu
USE_QT4=	corelib declarative gui moc_build \
		network opengl phonon qmake_build \
		qtestlib rcc_build script scripttools \
		sql svg uic_build webkit xml xmlpatterns
USE_SDL=	sdl

CXXFLAGS+=	-I${LOCALBASE}/include/SDL/
MAKE_ARGS=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}" \
		SYSCONFDIR="${PREFIX}/etc" ARCH="${OPSYS}" \
		CC_FLAGS="${CFLAGS} -DUSE_FILE32API" \
		CXX_FLAGS="${CXXFLAGS} -DUSE_FILE32API" \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}"

DESKTOP_ENTRIES="QMC2" "MAME frontend" "${DATADIR}/img/mame.png" \
		"${PORTNAME}-sdlmame" "Game;Emulator;Qt;" "true" \
		"QMC2 Arcade" "QMC2 Arcade Mode" "${DATADIR}/img/qmc2-arcade.png" \
		"${PORTNAME}-arcade" "Game;Emulator;Qt;" "true" \
		"CHDMAN GUI" "Qt CHDMAN GUI" "${DATADIR}/img/qchdman.png" \
		"qchdman" "Game;Emulator;Qt;" "true" \

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@(cd ${WRKSRC}/qmc2/inst; ${SED} -e 's|DATADIR|${PREFIX}/share|' \
		< qmc2.ini.template > qmc2.ini)
	@${REINPLACE_CMD} -e 's/bash/sh/' ${WRKSRC}/qmc2/scripts/sdl-libs.sh

do-install:
	(cd ${WRKSRC}/qmc2 && ${INSTALL_PROGRAM} qmc2-sdlmame \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/qmc2/arcade && ${INSTALL_PROGRAM} qmc2-arcade \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/qmc2/tools/qchdman && ${INSTALL_PROGRAM} qchdman \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/qmc2/inst && ${INSTALL_DATA} qmc2.ini \
		${STAGEDIR}${ETCDIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/img
	@(cd ${WRKSRC}/qmc2/data/img; ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/img)
	@${MKDIR} ${STAGEDIR}${DATADIR}/lng
	(cd ${WRKSRC}/qmc2/data/lng && ${INSTALL_DATA} qmc2_*.qm \
		${STAGEDIR}${DATADIR}/lng)
	@${MKDIR} ${STAGEDIR}${DATADIR}/opt
	@(cd ${WRKSRC}/qmc2/data/opt; ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/opt)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@(cd ${WRKSRC}/qmc2/data/doc/html; ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
