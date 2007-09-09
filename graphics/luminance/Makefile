# New ports collection makefile for:	qtpfsgui
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtpfsgui
DISTVERSION=	1.8.10
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A graphical user interface that provides a workflow for HDR imaging

LIB_DEPENDS=	exiv2.0:${PORTSDIR}/graphics/exiv2 \
		fftw3f.4:${PORTSDIR}/math/fftw3-float \
		IlmImf.4:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	qmake-qt4:${PORTSDIR}/devel/qmake4 \
		uic-qt4:${PORTSDIR}/devel/qt4-uic \
		rcc:${PORTSDIR}/devel/qt4-rcc \
		moc-qt4:${PORTSDIR}/devel/qt4-moc \
		lrelease-qt4:${PORTSDIR}/devel/qt4-linguist \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui

LRELEASE=	${QT_PREFIX}/bin/lrelease-qt4

INSTALL_TARGET=	install_target install_menu install_icon
.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
INSTALL_TARGET+=install_i18n
.else
PLIST_SUB+=	NLS="@comment "
.endif
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=install_docs
.endif

pre-build:
	@${LRELEASE} ${BUILD_WRKSRC}/project.pro
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

.include <bsd.port.mk>
