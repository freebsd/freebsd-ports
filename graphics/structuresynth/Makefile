# New ports collection makefile for:	structuresynth
# Date created:		06 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	structuresynth
PORTVERSION=	0.9.0
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	StructureSynth-Source-v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rule-based 3D structure generator

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build corelib gui opengl moc_build rcc_build xml script

WRKSRC=		${WRKDIR}/structuresynth

post-extract:
	@${MV} ${WRKDIR}/"Structure Synth Source" ${WRKDIR}/structuresynth

post-patch:
	@${REINPLACE_CMD} -e '/examplesDir/ s|"Examples"|"${DATADIR}/Examples"|; \
		/miscDir/ s|"Misc"|"${DATADIR}/Misc"|' \
		${WRKSRC}/StructureSynth/GUI/MainWindow.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -project
	@${ECHO_CMD} "QT+=opengl xml script" >> ${WRKSRC}/structuresynth.pro
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} structuresynth.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/structuresynth ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}/Examples
	${INSTALL_DATA} ${WRKSRC}/Examples/*.es ${DATADIR}/Examples
	${MKDIR} ${DATADIR}/Misc
	${INSTALL_DATA} ${WRKSRC}/Misc/* ${DATADIR}/Misc

.include <bsd.port.mk>
