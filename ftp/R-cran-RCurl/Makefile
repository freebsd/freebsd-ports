# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RCurl
DISTVERSION=	1.98-1.3
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	General network client interface for R

LICENSE=	BSD3CLAUSE

CRAN_DEPENDS=	R-cran-bitops>0:devel/R-cran-bitops
BUILD_DEPENDS=	curl-config:ftp/curl \
		${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cran:auto-plist,compiles gnome
USE_GNOME=	libxml2

.include <bsd.port.mk>
