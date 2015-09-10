# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RCurl
DISTVERSION=	1.95-4.7
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	General network client interface for R

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	curl-config:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	R-cran-bitops>0:${PORTSDIR}/devel/R-cran-bitops
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=	cran:auto-plist

.include <bsd.port.mk>
