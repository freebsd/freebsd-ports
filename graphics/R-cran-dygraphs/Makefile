# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dygraphs
PORTVERSION=	0.6
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Interface to Dygraphs Interactive Time Series Charting Library

LICENSE=	MIT

RUN_DEPENDS=	R-cran-magrittr>0:${PORTSDIR}/devel/R-cran-magrittr \
		R-cran-htmlwidgets>=0.3.2:${PORTSDIR}/www/R-cran-htmlwidgets \
		R-cran-zoo>=1.7.10:${PORTSDIR}/math/R-cran-zoo \
		R-cran-xts>=0.9.7:${PORTSDIR}/math/R-cran-xts

USES=	cran:auto-plist

.include <bsd.port.mk>
