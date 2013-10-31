# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	luminance-hdr
PORTREVISION=	3
DISTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	SF/qtpfsgui/luminance/${DISTVERSION}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Complete open source solution for HDR photography

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		exiv2:${PORTSDIR}/graphics/exiv2 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		tiff:${PORTSDIR}/graphics/tiff \
		gsl:${PORTSDIR}/math/gsl \
		raw_r:${PORTSDIR}/graphics/libraw

USE_BZIP2=	yes
USES=		cmake
USE_QT4=	gui sql webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build imageformats_run
INSTALLS_ICONS=	yes

NO_STAGE=	yes
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

.include <bsd.port.mk>
