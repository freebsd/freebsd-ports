PORTNAME=	RCurl
DISTVERSION=	1.98-1.17
PORTREVISION=	1
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	General network client interface for R
WWW=		https://cran.r-project.org/web/packages/RCurl/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	curl-config:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	R-cran-bitops>0:devel/R-cran-bitops

USES=		cran:auto-plist,compiles gnome
USE_GNOME=	libxml2

.include <bsd.port.mk>
