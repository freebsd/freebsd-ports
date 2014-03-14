# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	structuresynth
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Structure%20Synth/Version%201.5%20%28Hinxton%29
DISTNAME=	StructureSynth-Source-v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Rule-based 3D structure generator

USES=		qmake zip
USE_GL=		glu
USE_QT4=	corelib gui opengl moc_build rcc_build xml script
WRKSRC=		${WRKDIR}/structure-synth
USE_DOS2UNIX=	*.cpp *.h

post-extract:
	@${MV} "${WRKDIR}/Structure Synth Source Code" ${WRKSRC}
	@${RM} -rf ${WRKSRC}/Examples/DontDeploy

post-patch:
	@${REINPLACE_CMD} -e '/examplesDir/ s|"Examples"|"${DATADIR}/Examples"|; \
		/miscDir/ s|"Misc"|"${DATADIR}/Misc"|' \
		${WRKSRC}/StructureSynth/GUI/MainWindow.cpp

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} -project \
		-after "CONFIG+=opengl" -after "QT+=xml opengl script" \
		-after "LIBS+=-lGLU"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/structure-synth ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Examples Misc" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/structure-synth.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/images/fileicons/StructureSynth-256.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/structure-synth.png

.include <bsd.port.mk>
