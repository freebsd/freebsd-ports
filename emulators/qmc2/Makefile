# New ports collection makefile for:	qmc2
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qmc2
PORTVERSION=	0.2.b8
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	Qt 4 based UNIX MAME/MESS frontend supporting SDLMAME/SDLMESS

RUN_DEPENDS=	sdlmame:${PORTSDIR}/emulators/sdlmame
RUN_DEPENDS+=	sdlmess:${PORTSDIR}/emulators/sdlmess

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build gui qtestlib xml phonon opengl
USE_XORG=	xmu
MAKE_ENV=	QTDIR="${QTDIR}" QMAKE="${QMAKE}" SYSCONFDIR="${PREFIX}/etc"
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.qmc2
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qmc2-sdlmame ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qmc2-sdlmess ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/qmc2/
	${MKDIR} ${PREFIX}/share/qmc2/lng/
	${CP} ${WRKSRC}/data/lng/qmc2_*.qm ${PREFIX}/share/qmc2/lng/
	${CP} -r ${WRKSRC}/data/opt ${PREFIX}/share/qmc2/
	${CP} -r ${WRKSRC}/data/img ${PREFIX}/share/qmc2/
	${MKDIR} ${PREFIX}/etc/qmc2/
	${REINPLACE_CMD} -e 's|DATADIR|${PREFIX}/share|' ${WRKSRC}/inst/qmc2.ini.template
	${CP} ${WRKSRC}/inst/qmc2.ini.template ${PREFIX}/etc/qmc2/qmc2.ini
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/data/doc/html ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
