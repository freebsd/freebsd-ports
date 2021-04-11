# Created by: Yinghong Liu <relaxbsd@gmail.com>

PORTNAME=	luminance-hdr
DISTVERSION=	2.5.1
PORTREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}
PKGNAMESUFFIX=	-qt5

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

DEPRECATED=	Uses EOL Python 2.7 via www/qt5-webengine
EXPIRATION_DATE=2021-06-23

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libImath.so:math/Imath \
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

USES=		cmake desktop-file-utils jpeg pkgconfig qt:5 tar:bzip2
USE_QT=		concurrent core declarative gui location network printsupport \
		sql svg webchannel webengine widgets xml \
		buildtools_build linguisttools_build qmake_build

CONFLICTS_INSTALL=	luminance-hdr-[0-9]*

OPTIONS_DEFINE=	DOCS

post-patch:
# Do not install yet another copy of GPL (we use license framework instead)
# and fix installation path for docs (but not for internal help files)
	@${REINPLACE_CMD} -e '/LICENSE/d ; \
		/#info files/s,share/luminance-hdr,${DOCSDIR_REL},' \
			${WRKSRC}/CMakeLists.txt
# Point to the right location for program where to look for GPL text
	@${REINPLACE_CMD} -e 's,LICENSE,${LICENSE}, ; \
		s,share/doc/luminance-hdr,share/licenses/${PKGNAME},' \
			${WRKSRC}/src/UI/UMessageBox.cpp

.include <bsd.port.mk>
