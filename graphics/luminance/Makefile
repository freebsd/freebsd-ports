# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	luminance-hdr
DISTVERSION=	2.3.1
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libexiv2.so:graphics/exiv2 \
		libIlmImf.so:graphics/OpenEXR \
		libtiff.so:graphics/tiff \
		libgsl.so:math/gsl \
		libraw_r.so:graphics/libraw \
		libboost_system.so:devel/boost-libs

USES=		cmake jpeg tar:bzip2
USE_QT4=	gui sql webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build imageformats_run
INSTALLS_ICONS=	yes

CONFLICTS_INSTALL=	luminance-hdr-qt5-*

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

# Allow builds from release distfile to display correct git hash in "About"
# dialog window
	@${REINPLACE_CMD} -e \
		's,@GIT_SHA1@,be5409f2ed028b0a509d3f4cd44a970a09d2ef6c,' \
			${WRKSRC}/src/Common/GitSHA1.cpp.in

# Include <string> in addition to <string.h> where necessary, as this
# is required for building with libc++
	@${REINPLACE_CMD} -E '1s|^|#include \<string\>|;' \
	${WRKSRC}/src/TonemappingOperators/drago03/pfstmo_drago03.cpp \
	${WRKSRC}/src/TonemappingOperators/reinhard02/pfstmo_reinhard02.cpp \
	${WRKSRC}/src/TonemappingOperators/reinhard05/pfstmo_reinhard05.cpp \
	${WRKSRC}/src/TonemappingOperators/mantiuk08/display_function.cpp \
	${WRKSRC}/src/TonemappingOperators/mantiuk08/display_size.cpp \
	${WRKSRC}/src/TonemappingOperators/mantiuk08/pfstmo_mantiuk08.cpp \
	${WRKSRC}/src/TonemappingOperators/fattal02/pfstmo_fattal02.cpp \
	${WRKSRC}/src/TonemappingOperators/durand02/pfstmo_durand02.cpp \
	${WRKSRC}/src/TonemappingOperators/pattanaik00/pfstmo_pattanaik00.cpp \
	${WRKSRC}/src/Libpfs/io/pfsreader.cpp \
	${WRKSRC}/src/Libpfs/io/rgbereader.cpp \
	${WRKSRC}/src/Libpfs/colorspace/colorspace.cpp

.include <bsd.port.mk>
