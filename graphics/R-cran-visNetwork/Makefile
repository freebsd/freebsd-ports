PORTNAME=	visNetwork
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Network Visualization using 'vis.js' Library
WWW=		https://cran.r-project.org/web/packages/visNetwork/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
