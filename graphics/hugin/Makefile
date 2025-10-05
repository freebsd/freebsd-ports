PORTNAME=	hugin
DISTVERSION=	2025.0.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	GUI for Panorama Tools, to stitch panoramic images
WWW=		http://hugin.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
		libImath.so:math/Imath \
		liblcms2.so:graphics/lcms2 \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libpano13.so:graphics/libpano13 \
		libvigraimpex.so:graphics/vigra \
		libtiff.so:graphics/tiff \
		libflann.so:math/flann \
		liblz4.so:archivers/liblz4
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=4.1.4:graphics/enblend \
		exiftool:graphics/p5-Image-ExifTool \
		gmake:devel/gmake

# compiler:c++17-lang
USES=		cmake desktop-file-utils gettext gl gnome \
		pkgconfig shared-mime-info shebangfix sqlite tar:bzip2 xorg
USE_GL=		gl glew glu glut
USE_WX=		3.2+
USE_XORG=	x11

SHEBANG_FILES=	src/hugin_script_interface/hpi.py \
		src/hugin_script_interface/plugins/*.py \
		src/hugin_script_interface/plugins-dev/*.py

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}
CFLAGS+=	-I${LOCALBASE}/include/Imath

OPTIONS_DEFINE=		AUTOPANOSIFTC LAPACK PANOMATIC PYTHON
OPTIONS_DEFAULT=	LAPACK PANOMATIC PYTHON
OPTIONS_SUB=		yes

AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c
AUTOPANOSIFTC_RUN_DEPENDS=	autopano:graphics/autopano-sift-c

LAPACK_DESC=		Use LAPACK based solver in levmar
LAPACK_CMAKE_BOOL=	ENABLE_LAPACK
LAPACK_USES=		blaslapack

PANOMATIC_DESC=		Install graphics/panomatic
PANOMATIC_RUN_DEPENDS=	panomatic:graphics/panomatic

PYTHON_DESC=		Python Scripting Interface
PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	BUILD_HSI

.include <bsd.port.mk>
