# $FreeBSD$

PORTNAME=	siril
DISTVERSION=	0.99.6
PORTREVISION=	1
CATEGORIES=	astro graphics
MASTER_SITES=	https://free-astro.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Astronomical image processing software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	undefined reference to `__atomic_load' and `__atomic_compare_exchange' #`

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libcfitsio.so:astro/cfitsio \
		libconfig.so:devel/libconfig \
		libcurl.so:ftp/curl \
		libexiv2.so:graphics/exiv2 \
		libffms2.so:multimedia/ffms2 \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libopencv_core.so:graphics/opencv-core \
		libpng.so:graphics/png \
		libraw.so:graphics/libraw \
		libtiff.so:graphics/tiff
LIB_DEPENDS+=	libopencv_photo.so:graphics/opencv # for some reason, configure fails without opencv, but executable only links to opencv-core

USES=		compiler:c++11-lang desktop-file-utils gettext \
		gnome meson pkgconfig jpeg shared-mime-info tar:bz2
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 intltool pango

NO_WRKSUBDIR=	yes

INSTALLS_ICONS=	yes

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_MESON_OFF=	-Dopenmp=false

.include <bsd.port.mk>
