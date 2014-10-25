# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	luminance-hdr
DISTVERSION=	2.4.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}
PKGNAMESUFFIX=	-qt5

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgsl.so:${PORTSDIR}/math/gsl \
		libraw_r.so:${PORTSDIR}/graphics/libraw \
		libboost_system.so:${PORTSDIR}/devel/boost-libs

USES=		cmake:outsource pkgconfig tar:bzip2
USE_QT5=	concurrent declarative gui printsupport sql webkit xml \
		buildtools_build linguist_build qmake_build \
		imageformats_run
INSTALLS_ICONS=	yes

MAKE_JOBS_UNSAFE=yes

CONFLICTS_INSTALL=	luminance-hdr-[0-9]*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
USE_GCC=	yes
.endif

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

pre-install:
	QT_BINDIR_REL=bin

.include <bsd.port.post.mk>
