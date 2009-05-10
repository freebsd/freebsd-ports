# New ports collection makefile for:	qtpfsgui
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtpfsgui
PORTVERSION=	1.9.3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical user interface that provides a workflow for HDR imaging

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	exiv2.7:${PORTSDIR}/graphics/exiv2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fftw3f.4:${PORTSDIR}/math/fftw3-float

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui imageformats \
		linguist_build moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
INSTALL_TARGET=	install_target install_menu install_icon install_i18n
INSTALLS_ICONS=	yes

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

.if !defined(NOPORTOOCS)
INSTALL_TARGET+=install_htmls
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^QMAKE_CXXFLAGS/d ; \
		 s|PREFIX =.*$$|PREFIX = ${PREFIX}|g' ${WRKSRC}/project.pro
.for file in src/MainWindow/mainWindow.cpp \
	src/Preferences/preferencesDialog.cpp \
	src/TransplantExif/transplant.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/qtpfsgui|${DOCSDIR}|g ; \
		 s|/usr/local/share/qtpfsgui|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	@${LRELEASE} ${WRKSRC}/project.pro
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtpfsgui ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/qtpfsgui.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/images/qtpfsgui.png \
		${PREFIX}/share/icons/hicolor/32x32/apps
	@${LN} -sf ${PREFIX}/share/icons/hicolor/32x32/apps/qtpfsgui.png \
		${PREFIX}/share/pixmaps/qtpfsgui.png
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DATADIR}
	@${MKDIR} ${DATADIR}/i18n
	${INSTALL_DATA} ${WRKSRC}/i18n/*.qm ${DATADIR}/i18n
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc_file in AUTHORS Changelog README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc_file} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}; ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>
