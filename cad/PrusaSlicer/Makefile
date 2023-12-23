PORTNAME=	PrusaSlicer
DISTVERSIONPREFIX=version_
DISTVERSION=	2.6.0
PORTREVISION=	7
CATEGORIES=	cad
DIST_SUBDIR=	PrusaSlicer

MAINTAINER=	teodorsigaev@gmail.com
COMMENT=	Slicing application for 3D printers
WWW=		https://www.prusa3d.com/prusaslicer/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cereal>=1.3.0.10:devel/cereal \
		cgal>=5.0.2:math/cgal \
		opencascade>=7.7.0:cad/opencascade

LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libboost_log.so:devel/boost-libs \
		libImath.so:math/Imath \
		libnlopt.so:math/nlopt \
		libqhull_r.so:math/qhull \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libiconv.so:converters/libiconv \
		libopenvdb.so:misc/openvdb \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libdbus-1.so:devel/dbus \
		libpng.so:graphics/png \
		libTKXDESTEP.so:cad/opencascade \
		libtiff.so:graphics/tiff \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libavcodec.so:multimedia/ffmpeg4 \
		libharfbuzz.so:print/harfbuzz \
		libwayland-egl.so:graphics/wayland

USES=		cmake cpe desktop-file-utils eigen:3 gettext gl pkgconfig jpeg iconv gnome xorg
CPE_VENDOR=	prusa3d
USE_GITHUB=	yes
GH_ACCOUNT=	prusa3d
USE_GL=		gl glu glew
USE_GNOME=	gtk30 pango atk cairo gdkpixbuf2 glib20
USE_WX=		3.2
USE_XORG=	x11

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DSLIC3R_GTK=3 \
		-DSLIC3R_FHS=1 \
                -DSLIC3R_PCH=OFF

PORTDATA=	*

.include <bsd.port.mk>
