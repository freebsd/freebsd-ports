PORTNAME=	reshape2
PORTVERSION=	1.4.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Flexibly reshape data: a reboot of the reshape package
WWW=		https://cran.r-project.org/web/packages/reshape2/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-plyr>=1.8.1:devel/R-cran-plyr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-stringr>0:textproc/R-cran-stringr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
