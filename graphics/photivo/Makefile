# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	photivo
PORTVERSION=	0.0.2015.03.21
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-source/v2/code.google.com/${PORTNAME}/
DISTNAME=	source-archive
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free and open source photo processor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: error: constant expression evaluates to -2 which cannot be narrowed to type char

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libexiv2.so:graphics/exiv2 \
		liblqr-1.so:graphics/liblqr-1 \
		liblensfun.so:graphics/lensfun \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libfftw3.so:math/fftw3

USES=		cmake compiler:c++11-lib desktop-file-utils dos2unix \
		gettext-runtime jpeg pkgconfig zip
USE_GNOME=	glib20
DOS2UNIX_FILES=	Sources/ptImage.cpp Sources/ptCheck.cpp

WRKSRC=		${WRKDIR}/${PORTNAME}

_QT4_DEPS=	qmake_build moc_build rcc_build uic_build corelib gui network
_QT5_DEPS=	qmake_build buildtools_build core gui network widgets

OPTIONS_DEFINE=	QT4
QT4_DESC=	Build against Qt 4 instead of Qt 5

QT4_USE=	QT4=${_QT4_DEPS:ts,}
QT4_USE_OFF=	QT5=${_QT5_DEPS:ts,}
QT4_CMAKE_ON=	-DFORCE_QT4:BOOL=true

post-patch:
	@${REINPLACE_CMD} -e 's,#define cimg_use_openmp 1,//&,' \
		${WRKSRC}/Sources/ptCimg.cpp \
		${WRKSRC}/Sources/ptImage_Pyramid.cpp
	@${REINPLACE_CMD} -e '/#include "\.\.\/ptImage\.h"/ \
		{ x ; s/.*/#include <cmath>/ ; H ; x ; }' \
		${WRKSRC}/Sources/filters/ptFilter_EAWavelets.cpp \
		${WRKSRC}/Sources/filters/ptFilter_FilmGrain.cpp \
		${WRKSRC}/Sources/filters/ptFilter_HighpassSharpen.cpp \
		${WRKSRC}/Sources/filters/ptFilter_PyramidDenoise.cpp \
		${WRKSRC}/Sources/filters/ptFilter_StdCurve.cpp \
		${WRKSRC}/Sources/filters/ptFilter_WaveletDenoise.cpp

.include <bsd.port.mk>
