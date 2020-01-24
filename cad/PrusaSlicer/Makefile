# $FreeBSD$

PORTNAME=		PrusaSlicer
DISTVERSIONPREFIX=	version_
DISTVERSION=		2.1.1
CATEGORIES=		cad

MAINTAINER=	teodor@sigaev.ru
COMMENT=	Slicing application for 3D printers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/tbb \
		libnlopt.so:math/nlopt \
		libwx_gtk3u_core-3.1.so:x11-toolkits/wxgtk31 \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2
BUILD_DEPENDS=	cereal>=1.2.2:devel/cereal \
		eigen>=3.3:math/eigen3 \
		googletest>=1.7:devel/googletest \
		boost-libs>=1.64:devel/boost-libs \
		wx31-gtk3>=3.1:x11-toolkits/wxgtk31 \
		cmake>=3.2:devel/cmake \
		ninja>=1.8.2:devel/ninja

USES=		cmake gettext

CMAKE_ARGS+=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wxgtk3u-3.1-config
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

USE_GITHUB=	yes
USE_GL=		glew
GH_ACCOUNT=	prusa3d

.include <bsd.port.mk>
