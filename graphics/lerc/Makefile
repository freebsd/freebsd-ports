PORTNAME=	lerc
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ library for Limited Error Raster Compression
WWW=		https://esri.github.io/lerc/ \
		https://github.com/Esri/lerc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang dos2unix

CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

GH_ACCOUNT=	Esri
USE_GITHUB=	yes

.include <bsd.port.mk>
