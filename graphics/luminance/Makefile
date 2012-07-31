# New ports collection makefile for:	Luminance HDR (nee Qtpfsgui)
# Date created:				28 Jul 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	luminance
DISTVERSION=	2.0.1-1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION:S/-1//}/
DISTNAME=	${PORTNAME}-v${DISTVERSION}

MAINTAINER=	goffredo@gmail.com
COMMENT=	An open source workflow for HDR imaging

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	exiv2.12:${PORTSDIR}/graphics/exiv2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		gsl.16:${PORTSDIR}/math/gsl

USE_QT4=	gui xml webkit imageformats_run linguist_build \
		moc_build qmake_build rcc_build uic_build
QMAKE_ARGS=	PREFIX=${PREFIX} DOCDIR=${DOCSDIR} I18NDIR=${DATADIR}/i18n
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

.include <bsd.port.pre.mk>

post-patch:
# FreeBSD has log2() since recently, remove local #define's which conflict
# with prototypes in /usr/include/math.h (when applicable)
.if ${OSVERSION} > 802501
	@${REINPLACE_CMD} -e '/log2/d' ${WRKSRC}/src/arch/freebsd/math.h
.endif
	@cd ${WRKSRC}/src && ${REINPLACE_CMD} \
		-e 's|/usr/share/luminance|${DOCSDIR}|g' \
		-e 's|/usr/local/share/luminance|${DATADIR}|g' \
		MainWindow/MainWindow.cpp \
		Preferences/PreferencesDialog.cpp \
		TonemappingWindow/TonemappingWindow.cpp \
		TransplantExif/TransplantExifDialog.cpp
	@${REINPLACE_CMD} -e 's|%%HELPDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/src/HelpBrowser/LuminancePaths.cpp
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E '/INSTALLS/s,help|docs,,g' ${WRKSRC}/project.pro
.endif

do-configure:
	@${LRELEASE} ${WRKSRC}/project.pro
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS} ${QMAKEFLAGS}

.include <bsd.port.post.mk>
