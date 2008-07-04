# New ports collection makefile for:	qtpfsgui
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtpfsgui
PORTVERSION=	1.9.2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical user interface that provides a workflow for HDR imaging

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	exiv2.3:${PORTSDIR}/graphics/exiv2 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fftw3f.4:${PORTSDIR}/math/fftw3-float

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui imageformats \
		linguist_build moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

post-patch:
	@${REINPLACE_CMD} -e '/^QMAKE_CXXFLAGS/d ; \
		 s|PREFIX =.*$$|PREFIX = ${PREFIX}|g ; \
		 /^INSTALLS/s|docs||g' ${WRKSRC}/project.pro
.for file in src/MainWindow/mainWindow.cpp \
	src/Preferences/preferencesDialog.cpp \
	src/TransplantExif/transplant.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/share/qtpfsgui/|${DATADIR}/|g' \
		${WRKSRC}/${file}
.endfor
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '316s|htmls||' ${WRKSRC}/project.pro
.endif

do-configure:
	@${LRELEASE} ${WRKSRC}/project.pro
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qtpfsgui
	${INSTALL} -d ${PREFIX}/share/icons/hicolor/48x48/apps
	@${LN} -sf ${PREFIX}/share/pixmaps/qtpfsgui.png \
		${PREFIX}/share/icons/hicolor/48x48/apps/qtpfsgui.png
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc_file in AUTHORS Changelog README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc_file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
