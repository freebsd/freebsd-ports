# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	photivo
PORTVERSION=	0.0.2015.03.21
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-source/v2/code.google.com/${PORTNAME}/
DISTNAME=	source-archive
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free and open source photo processor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libexiv2.so:graphics/exiv2 \
		liblqr-1.so:graphics/liblqr-1 \
		liblensfun.so:graphics/lensfun \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libfftw3.so:math/fftw3

USES=		cmake compiler:c++11-lib desktop-file-utils dos2unix \
		gettext-runtime gnome jpeg pkgconfig zip
USE_GNOME=	glib20
DOS2UNIX_FILES=	Sources/ptImage.cpp Sources/ptCheck.cpp Sources/filemgmt/ptFileMgrWindow.h \
		Sources/ptImageHelper.h Sources/ptMainWindow.h

WRKSRC=		${WRKDIR}/${PORTNAME}

FLAVORS=	qt5 qt4

qt4_CONFLICTS_INSTALL=	${PORTNAME}
qt4_PKGNAMESUFFIX=	-qt4
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt4

.if ${FLAVOR:U} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		qt:4
USE_QT=		qmake_build moc_build rcc_build uic_build corelib gui network
CMAKE_ON=	FORCE_QT4
.else
USES+=		qt:5
USE_QT=		qmake_build buildtools_build core gui network widgets
.endif

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
	@${REINPLACE_CMD} -e '/static const char src/s,char,int8_t,' \
		${WRKSRC}/Sources/ptDcRaw.cpp

.include <bsd.port.mk>
