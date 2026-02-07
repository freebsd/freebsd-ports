PORTNAME=	urlchecker
DISTVERSION=	1.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	URL checking tools
WWW=		https://cran.r-project.org/web/packages/urlchecker/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-cli>=2.4.0:devel/R-cran-cli \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-xml2>0:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
