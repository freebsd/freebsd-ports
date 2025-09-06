PORTNAME=	hugin
DISTVERSION=	2024.0.1
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	GUI for Panorama Tools, to stitch panoramic images
WWW=		http://hugin.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
		libImath.so:math/Imath \
		libboost_thread.so:devel/boost-libs \
		liblcms2.so:graphics/lcms2 \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libpano13.so:graphics/libpano13 \
		libvigraimpex.so:graphics/vigra \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libflann.so:math/flann \
		liblz4.so:archivers/liblz4
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=4.1.4:graphics/enblend \
		exiftool:graphics/p5-Image-ExifTool \
		gmake:devel/gmake

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl gnome \
		jpeg pkgconfig shared-mime-info shebangfix sqlite tar:bzip2 xorg
USE_GL=		gl glew glu glut
USE_WX=		3.2+
USE_XORG=	x11

SHEBANG_FILES=	src/hugin_script_interface/hpi.py \
		src/hugin_script_interface/plugins/*.py \
		src/hugin_script_interface/plugins-dev/*.py

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}
CFLAGS+=	-I${LOCALBASE}/include/Imath

OPTIONS_DEFINE=		PANOMATIC AUTOPANOSIFTC PYTHON
OPTIONS_DEFAULT=	PANOMATIC PYTHON
OPTIONS_SUB=		yes

PANOMATIC_DESC=		Install graphics/panomatic
PANOMATIC_RUN_DEPENDS=	panomatic:graphics/panomatic

AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c
AUTOPANOSIFTC_RUN_DEPENDS=	autopano:graphics/autopano-sift-c

PYTHON_DESC=		Python Scripting Interface
PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_USES=		python
PYTHON_CMAKE_ON=	-DBUILD_HSI=ON
PYTHON_CMAKE_OFF=	-DBUILD_HSI=OFF

.include <bsd.port.mk>
