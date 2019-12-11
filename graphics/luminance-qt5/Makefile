# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	luminance-hdr
DISTVERSION=	2.5.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}
PKGNAMESUFFIX=	-qt5

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libHalf.so:graphics/ilmbase \
		libtiff.so:graphics/tiff \
		libraw_r.so:graphics/libraw \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl \
		libexiv2.so:graphics/exiv2 \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/openexr \
		libboost_date_time.so:devel/boost-libs

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
