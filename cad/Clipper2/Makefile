PORTNAME=	Clipper2
DISTVERSION=	1.4.0
#PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	mr@freebsd.org
COMMENT=	A Polygon Clipping and Offsetting library (in C++, C# & Delphi)
WWW=		https://github.com/AngusJohnson/Clipper2

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake

USE_GITHUB=	yes
GH_ACCOUNT=	AngusJohnson google:gtest
GH_PROJECT=	googletest:gtest
GH_TAGNAME=	2b665ac 71815bb:gtest
GH_SUBDIR=	CPP/Tests/googletest:gtest

CMAKE_SOURCE_PATH= ${WRKSRC}/CPP
#CMAKE_ON=	
CMAKE_OFF=	INSTALL_GTEST

.include <bsd.port.mk>
