# Created by: Carlos Eduardo G. Carvalho <cartola@openit.com.br>

PORTNAME=	hugin
PORTVERSION=	2019.2.0
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	grog@FreeBSD.org
COMMENT=	GUI for Panorama Tools, to stitch panoramic images

LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
		libImath.so:math/Imath \
		libboost_thread.so:devel/boost-libs \
		liblcms2.so:graphics/lcms2 \
		libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libpano13.so:graphics/libpano13 \
		libvigraimpex.so:graphics/vigra \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=4.1.4:graphics/enblend \
		exiftool:graphics/p5-Image-ExifTool \
		gmake:devel/gmake

LICENSE=	GPLv2

CFLAGS+=	-I${LOCALBASE}/include/Imath

BROKEN_i386=	Fails to build: ld: error: src/hugin_base/libhuginbase.so.0.0: undefined reference to __atomic_load

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl gnome \
	jpeg pkgconfig shared-mime-info shebangfix sqlite tar:bzip2 xorg
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}
USE_GL=		gl glew glu glut
USE_WX=		3.0+
USE_XORG=	x11

INSTALLS_ICONS=	yes

SHEBANG_FILES=	src/hugin_script_interface/hpi.py \
		src/hugin_script_interface/plugins/*.py \
		src/hugin_script_interface/plugins-dev/*.py

OPTIONS_DEFINE=		PANOMATIC AUTOPANOSIFTC PYTHON
OPTIONS_DEFAULT=	PANOMATIC PYTHON
OPTIONS_SUB=		yes

PANOMATIC_DESC=		Install graphics/panomatic
PANOMATIC_RUN_DEPENDS=	panomatic:graphics/panomatic

AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c
AUTOPANOSIFTC_RUN_DEPENDS=	autopano:graphics/autopano-sift-c

PYTHON_DESC=		Python Scripting Interface
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_CMAKE_ON=	-DBUILD_HSI=ON
PYTHON_CMAKE_OFF=	-DBUILD_HSI=OFF

.include <bsd.port.mk>
