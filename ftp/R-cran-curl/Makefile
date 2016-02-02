# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	0.9.5
CATEGORIES=	ftp
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Modern and Flexible Web Client for R

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/curl/curl.h:${PORTSDIR}/ftp/curl
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=	cran:auto-plist

post-patch:
	@${REINPLACE_CMD} -e '/bin\//s|bash|sh|' ${WRKSRC}/configure

.include <bsd.port.mk>
