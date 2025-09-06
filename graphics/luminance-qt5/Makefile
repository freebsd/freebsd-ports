PORTNAME=	luminance-hdr
DISTVERSION=	2.6.1.1
PORTREVISION=	32
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography
WWW=		https://qtpfsgui.sourceforge.net/

LICENSE=	GPLv2

BROKEN=		fails to build with Boost>=1.87

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libImath.so:math/Imath \
		libtiff.so:graphics/tiff \
		libraw_r.so:graphics/libraw \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl \
		libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libOpenEXR.so:graphics/openexr \
		libboost_date_time.so:devel/boost-libs

CFLAGS+=	-I${LOCALBASE}/include/Imath

USES=		cmake desktop-file-utils eigen:3 jpeg pkgconfig qt:5 tar:bzip2
USE_QT=		concurrent core declarative gui location network \
		printsupport sql svg widgets xml \
		buildtools:build linguisttools:build qmake:build

USE_CXXSTD=	c++14

OPTIONS_DEFINE=		CFITSIO DOCS HELPBROWSER
OPTIONS_DEFAULT=	CFITSIO
OPTIONS_DEFAULT_aarch64=	HELPBROWSER
OPTIONS_DEFAULT_amd64=	HELPBROWSER
OPTIONS_DEFAULT_i386=	HELPBROWSER

CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

HELPBROWSER_DESC=	Build help browser (requires QtWebEngine)
HELPBROWSER_USE=	QT=webchannel,webengine
HELPBROWSER_CMAKE_BOOL=	WITH_HELPBROWSER

.if !exists(/usr/include/omp.h)
USES+=	compiler:gcc-c++11-lib
.else
USES+=	compiler:c++14-lang
.endif

.include <bsd.port.options.mk>

post-patch:
# Do not install yet another copy of GPL (we use license framework instead)
# and fix installation path for docs (but not for internal help files)
	@${REINPLACE_CMD} -e '/LICENSE/d ; \
		/#info files/s,share/luminance-hdr/doc,${DOCSDIR_REL},' \
			${WRKSRC}/CMakeLists.txt
# Point to the right location for program where to look for GPL text
	@${REINPLACE_CMD} -e 's,LICENSE,${LICENSE}, ; \
		s,share/luminance-hdr/doc,share/licenses/${PKGNAME},' \
			${WRKSRC}/src/UI/UMessageBox.cpp

post-patch-HELPBROWSER-off:
	@${REINPLACE_CMD} -e 's,name="documentationAction">,& \
		<property name="enabled"><bool>false</bool></property>,' \
			${WRKSRC}/src/MainWindow/MainWindow.ui

.include <bsd.port.mk>
