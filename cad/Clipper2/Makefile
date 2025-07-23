PORTNAME=	Clipper2
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/AngusJohnson/${PORTNAME}/releases/download/${PORTNAME}_${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	mr@freebsd.org
COMMENT=	A Polygon Clipping and Offsetting library (in C++, C\# & Delphi)
WWW=		https://github.com/AngusJohnson/Clipper2

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/../License.txt

USES=	cmake compiler:c++17-lang dos2unix zip

WRKSRC_SUBDIR=	CPP
NO_WRKSUBDIR=	yes

CMAKE_OFF=	CLIPPER2_EXAMPLES \
		CLIPPER2_TESTS 
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
