PORTNAME=	OrcaSlicer
DISTVERSIONPREFIX=v
DISTVERSION=	2.3.1
CATEGORIES=	cad

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Slicing Software for Precision 3D Prints
WWW=		https://www.orcaslicer.com

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cereal>=0:devel/cereal \
		cgal>=0:math/cgal

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libglfw.so:graphics/glfw \
		libnlopt.so:math/nlopt \
		libnoise.so:audio/libnoise \
		libopencv_core.so:graphics/opencv \
		libopenvdb.so:misc/openvdb \
		libpango-1.0.so:x11-toolkits/pango \
		libpng16.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libspnav.so:misc/libspnav \
		libtbb.so:devel/onetbb \
		libTKernel.so:cad/opencascade \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libwx_baseu-3.2.so:x11-toolkits/wxgtk32

USES=	cmake desktop-file-utils gl gnome gstreamer jpeg \
	localbase:ldflags pkgconfig ssl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	OrcaSlicer

USE_GL=		gl glew
USE_GNOME=	gtk30
USE_XORG=	x11

CMAKE_ARGS=	-DSLIC3R_FHS=1 \
		-DSLIC3R_GTK=3 \
		-DORCA_TOOLS=1 \
		-DBBL_RELEASE_TO_PUBLIC=1 \
		-DBBL_INTERNAL_TESTING=0

CXXFLAGS+=	-DwxDEBUG_LEVEL=0

post-patch:
	${CP} ${FILESDIR}/hid.c ${WRKSRC}/deps_src/hidapi/linux/hid.c
	@${REINPLACE_CMD} -e '/Boost/s| system | |' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>

