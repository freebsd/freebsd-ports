PORTNAME=	Clipper2
DISTVERSION=	2.0.1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/AngusJohnson/${PORTNAME}/releases/download/${PORTNAME}_${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	mr@freebsd.org
COMMENT=	A Polygon Clipping and Offsetting library (in C++, C\# & Delphi)
WWW=		https://github.com/AngusJohnson/Clipper2

LICENSE=	BSL

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang dos2unix pathfix zip

NO_WRKSUBDIR=	yes
WRKSRC_SUBDIR=	CPP

CMAKE_TESTING_ON=	USE_EXTERNAL_GTEST \
			CLIPPER2_TESTS

CMAKE_OFF=	CLIPPER2_EXAMPLES \
		CLIPPER2_TESTS 
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
