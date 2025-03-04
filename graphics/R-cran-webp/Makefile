PORTNAME=	webp
DISTVERSION=	1.3.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Reads and writes webp images
WWW=		https://cran.r-project.org/package=webp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwebp.so:graphics/webp
TEST_DEPENDS=	R-cran-jpeg>0:graphics/R-cran-jpeg \
		R-cran-png>0:graphics/R-cran-png

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
