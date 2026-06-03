PORTNAME=	ignition-utils
DISTVERSIONPREFIX=	gz-utils4_
DISTVERSION=	4.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General-purpose classes and functions for Gazebo projects
WWW=		https://gazebosim.org/libs/utils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ignition-cmake>=5:devel/ignition-cmake \
		${LOCALBASE}/include/CLI/CLI.hpp:devel/cli11
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING GZ_UTILS_VENDOR_CLI11

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-utils

PLIST_SUB+=	UTILS_IGN_VER=utils${DISTVERSION:R:R}

.include <bsd.port.mk>
