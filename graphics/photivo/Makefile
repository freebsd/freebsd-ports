# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	photivo
PORTVERSION=	0.0.2015.03.21
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
		gettext-runtime jpeg pkgconfig zip
USE_GNOME=	glib20
USE_QT5=	qmake_build buildtools_build core gui network widgets
DOS2UNIX_FILES=	Sources/ptImage.cpp Sources/ptCheck.cpp

WRKSRC=		${WRKDIR}/${PORTNAME}

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
