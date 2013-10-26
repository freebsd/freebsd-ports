# Created by: alepulver
# $FreeBSD$

PORTNAME=	qmc2
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 based UNIX MAME/MESS frontend

RUN_DEPENDS=	mame:${PORTSDIR}/emulators/mame \
		mess:${PORTSDIR}/emulators/mess

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

USE_BZIP2=	yes
USE_XORG=	xmu
USE_GL=		glu
USE_QT4=	gui opengl phonon qtestlib webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_SDL=	sdl
USE_GMAKE=	yes
MAKE_ARGS=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}" \
		SYSCONFDIR="${PREFIX}/etc" ARCH="${OPSYS}" \
		CC_FLAGS="${CFLAGS}" CXX_FLAGS="${CXXFLAGS}" \
		CC="${CC}" CXX="${CXX}" LINK="${CXX}"

DESKTOP_ENTRIES="QMC2 (MAME)" "MAME frontend" "${DATADIR}/img/mame.png" \
		"${PORTNAME}-sdlmame" "Game;Emulator;Qt;" "true" \
		"QMC2 (MESS)" "MESS frontend" "${DATADIR}/img/mess.png" \
		"${PORTNAME}-sdlmess" "Game;Emulator;Qt;" "true"

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/qmc2-sdlmess
	@(cd ${WRKSRC}/qmc2; ${COPYTREE_SHARE} . ../qmc2-sdlmess)
	@${FIND} ${WRKSRC} -name "*.sh" | ${XARGS} ${CHMOD} ${BINMODE}

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@(cd ${WRKSRC}/qmc2/inst; ${SED} -e 's|DATADIR|${PREFIX}/share|' \
		< qmc2.ini.template > qmc2.ini)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qmc2/qmc2-sdlmame ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qmc2-sdlmess/qmc2-sdlmess ${PREFIX}/bin
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/qmc2/inst/qmc2.ini ${ETCDIR}
	@${MKDIR} ${DATADIR}/img
	@(cd ${WRKSRC}/qmc2/data/img; ${COPYTREE_SHARE} . ${DATADIR}/img)
	@${MKDIR} ${DATADIR}/lng
	${INSTALL_DATA} ${WRKSRC}/qmc2/data/lng/qmc2_*.qm ${DATADIR}/lng
	@${MKDIR} ${DATADIR}/opt
	@(cd ${WRKSRC}/qmc2/data/opt; ${COPYTREE_SHARE} . ${DATADIR}/opt)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/html
	@(cd ${WRKSRC}/qmc2/data/doc/html; ${COPYTREE_SHARE} . ${DOCSDIR}/html)
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
