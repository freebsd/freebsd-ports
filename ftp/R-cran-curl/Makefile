PORTNAME=	curl
PORTVERSION=	5.0.0
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Modern and Flexible Web Client for R
WWW=		https://cran.r-project.org/web/packages/curl/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
