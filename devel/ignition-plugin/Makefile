PORTNAME=	ignition-plugin
DISTVERSIONPREFIX=	gz-plugin4_
DISTVERSION=	4.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for registering plugins and dynamically loading them
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cli11>0:devel/cli11 \
		ignition-cmake>=5:devel/ignition-cmake
LIB_DEPENDS=	libgz-utils.so:devel/ignition-utils

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-plugin

PLIST_SUB+=	PLUGIN_IGN_VER=plugin${DISTVERSION:R:R}

.include <bsd.port.mk>
