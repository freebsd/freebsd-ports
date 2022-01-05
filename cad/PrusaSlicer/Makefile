PORTNAME=	PrusaSlicer
DISTVERSIONPREFIX=version_
DISTVERSION=	2.3.3
PORTREVISION=	3
CATEGORIES=	cad

MAINTAINER=	teodorsigaev@gmail.com
COMMENT=	Slicing application for 3D printers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libboost_log.so:devel/boost-libs \
		libImath.so:math/Imath \
		libnlopt.so:math/nlopt \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libopenvdb.so:misc/openvdb \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libdbus-1.so:devel/dbus \
		libpng.so:graphics/png
BUILD_DEPENDS=	cereal>=1.3.0.10:devel/cereal \
		cgal>=5.0.2:math/cgal

USES=		cmake cpe desktop-file-utils eigen:3 gettext gl iconv pkgconfig
CPE_VENDOR=	prusa3d
CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DSLIC3R_GTK=3 \
		-DSLIC3R_FHS=1
USE_GITHUB=	yes
GH_ACCOUNT=	prusa3d
USE_WX=		3.1
USE_GL=		gl glu glew

PORTDATA=	*

.include <bsd.port.mk>
