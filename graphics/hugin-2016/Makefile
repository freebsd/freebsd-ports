# Created by: Carlos Eduardo G. Carvalho <cartola@openit.com.br>
# $FreeBSD$

PORTNAME=	hugin
DISTVERSION=	2016.0.0.r2
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/hugin/2016.0/2016.0rc2/+download/
DISTFILES=	hugin-2016.0.0_rc2.tar.bz2
WRKSRC=		${WRKDIR}/hugin-2016.0.0

MAINTAINER=	grog@FreeBSD.org
COMMENT=	GUI for Panorama Tools, to stitch panoramic images

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libImath.so:${PORTSDIR}/graphics/ilmbase \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libpano13.so:${PORTSDIR}/graphics/libpano13 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libvigraimpex.so:${PORTSDIR}/graphics/vigra \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff
# gmake is really needed at _runtime_.   Do not remove it from this list.
RUN_DEPENDS=	enblend>=4.1.4:${PORTSDIR}/graphics/enblend \
		exiftool:${PORTSDIR}/graphics/p5-Image-ExifTool \
		gmake:${PORTSDIR}/devel/gmake

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext jpeg pkgconfig shared-mime-info tar:bzip2
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}
USE_WX=		2.8+
USE_GL=		glew glut
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		PANOMATIC AUTOPANOSIFTC PYTHON
OPTIONS_DEFAULT=	PANOMATIC AUTOPANOSIFTC PYTHON
OPTIONS_SUB=		yes

PANOMATIC_DESC=		Install graphics/panomatic
PANOMATIC_RUN_DEPENDS=	panomatic:${PORTSDIR}/graphics/panomatic

AUTOPANOSIFTC_DESC=	Install graphics/autopano-sift-c
AUTOPANOSIFTC_RUN_DEPENDS=	autopano:${PORTSDIR}/graphics/autopano-sift-c

PYTHON_DESC=		Python Scripting Interface
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
PYTHON_CMAKE_ON=	-DBUILD_HSI=ON
PYTHON_CMAKE_OFF=	-DBUILD_HSI=OFF

.include <bsd.port.mk>
