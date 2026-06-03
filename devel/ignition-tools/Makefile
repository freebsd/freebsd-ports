PORTNAME=	ignition-tools
DISTVERSIONPREFIX=	gz-tools2_
DISTVERSION=	2.0.3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ignition entry point (ign) for using all the suite of ignition tools
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ignition-cmake>=5:devel/ignition-cmake

USES=		cmake compiler:c++11-lang pkgconfig ruby shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/gz.in

USE_GITHUB=	yes
GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-tools

CMAKE_OFF=	BUILD_TESTING
.include <bsd.port.mk>
