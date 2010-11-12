# New ports collection makefile for:	qtpfsgui
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	luminance
DISTVERSION=	2.0.1-1
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION:S/-1//}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	goffredo@gmail.com
COMMENT=	A graphical user interface that provides a workflow for HDR imaging

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	exiv2.9:${PORTSDIR}/graphics/exiv2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fftw3f.5:${PORTSDIR}/math/fftw3-float \
		gsl.15:${PORTSDIR}/math/gsl

USE_QT_VER=	4
QT_COMPONENTS=	gui xml webkit imageformats_run linguist_build \
		moc_build qmake_build rcc_build uic_build
QMAKE_ARGS=	PREFIX=${PREFIX} DOCDIR=${DOCSDIR} I18NDIR=${DATADIR}/i18n
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

post-patch:
	cd ${WRKSRC}/src && ${REINPLACE_CMD} \
		-e 's|/usr/share/luminance|${DOCSDIR}|g' \
		-e 's|/usr/local/share/luminance|${DATADIR}|g' \
		MainWindow/MainWindow.cpp \
		Preferences/PreferencesDialog.cpp \
		TonemappingWindow/TonemappingWindow.cpp \
		TransplantExif/TransplantExifDialog.cpp
	${REINPLACE_CMD} -e 's|%%HELPDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/src/HelpBrowser/LuminancePaths.cpp
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/INSTALL/s,help,,' \
		-e '/INSTALL/s,docs,,' \
		${WRKSRC}/project.pro
.endif

do-configure:
	@${LRELEASE} ${WRKSRC}/project.pro
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS} ${QMAKEFLAGS}

.include <bsd.port.mk>
