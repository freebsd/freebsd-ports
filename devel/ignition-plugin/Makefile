PORTNAME=	ignition-plugin
DISTVERSIONPREFIX=	ignition-plugin_
DISTVERSION=	1.4.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for registering plugins and dynamically loading them
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ignition-cmake>=2:devel/ignition-cmake

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-plugin

PLIST_SUB+=	PLUGIN_IGN_VER=plugin${DISTVERSION:R:R}

.include <bsd.port.mk>
