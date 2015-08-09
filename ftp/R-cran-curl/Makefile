# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	0.9.2
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Modern and Flexible Web Client for R

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:${PORTSDIR}/ftp/curl
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=	cran:auto-plist

.include <bsd.port.mk>
