PORTNAME=	pkgcache
DISTVERSION=	2.2.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Cache 'CRAN'-Like Metadata and R Packages
WWW=		https://cran.r-project.org/package=pkgcache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=2.0.4.9000:devel/R-cran-callr \
		R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-filelock>0:devel/R-cran-filelock \
		R-cran-prettyunits>0:devel/R-cran-prettyunits \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-curl>=3.2:ftp/R-cran-curl \
		R-cran-processx>=3.3.0.9001:sysutils/R-cran-processx

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
