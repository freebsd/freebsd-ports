# New ports collection makefile for:	structuresynth
# Date created:		06 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	structuresynth
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	StructureSynth-Source-v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rule-based 3D structure generator

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build corelib gui opengl moc_build rcc_build xml script
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/structure-synth

post-extract:
	@${MV} "${WRKDIR}/Structure Synth Source Code" ${WRKSRC}
	@${RM} -rf ${WRKSRC}/Examples/DontDeploy

post-patch:
	@${REINPLACE_CMD} -e '/examplesDir/ s|"Examples"|"${DATADIR}/Examples"|; \
		/miscDir/ s|"Misc"|"${DATADIR}/Misc"|' \
		${WRKSRC}/StructureSynth/GUI/MainWindow.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -project \
		-after "CONFIG+=opengl" -after "QT+=xml opengl script"
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/structure-synth ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Examples Misc" ${DATADIR}/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/structure-synth.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/images/fileicons/StructureSynth-256.png \
		${PREFIX}/share/pixmaps/structure-synth.png

.include <bsd.port.mk>
