# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	luminance-hdr
DISTVERSION=	2.4.0
PORTREVISION=	26
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}
PKGNAMESUFFIX=	-qt5

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libexiv2.so:graphics/exiv2 \
		libIlmImf.so:graphics/openexr \
		libtiff.so:graphics/tiff \
		libgsl.so:math/gsl \
		libraw_r.so:graphics/libraw \
		libboost_system.so:devel/boost-libs

USES=		cmake jpeg pkgconfig qt:5 tar:bzip2
USE_QT=		concurrent gui printsupport sql webkit xml \
		buildtools_build linguist_build qmake_build \
		imageformats_run
INSTALLS_ICONS=	yes

MAKE_JOBS_UNSAFE=yes

CONFLICTS_INSTALL=	luminance-hdr-[0-9]*

OPTIONS_DEFINE=	DOCS

post-patch:
# Remove the non-required dependency on Qt5 Declarative. This can be dropped
# once www/qt5-webengine lands in the portstree and this port can be updated to
# a version >= 2.5.0.
	@${REINPLACE_CMD} -e '/Qt5Declarative/d' \
		${WRKSRC}/CMakeLists.txt
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

pre-install:
	QT_BINDIR_REL=bin

.include <bsd.port.mk>
