# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	visNetwork
PORTVERSION=	0.2.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Network Visualization using 'vis.js' Library

LICENSE=	MIT

RUN_DEPENDS=	R-cran-htmlwidgets>0:${PORTSDIR}/www/R-cran-htmlwidgets \
		R-cran-htmltools>0:${PORTSDIR}/textproc/R-cran-htmltools \
		R-cran-jsonlite>0:${PORTSDIR}/converters/R-cran-jsonlite \
		R-cran-magrittr>0:${PORTSDIR}/devel/R-cran-magrittr

USES=	cran:auto-plist

.include <bsd.port.mk>
