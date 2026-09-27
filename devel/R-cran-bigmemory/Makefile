PORTNAME=	bigmemory
DISTVERSION=	4.6.6
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Manage Massive Matrices with Shared Memory and Memory-Mapped Files
WWW=		https://github.com/kaneplusplus/bigmemory

LICENSE=	APACHE20 LGPL3
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	R-cran-BH>0:devel/R-cran-BH \
			R-cran-bigmemory.sri>0:devel/R-cran-bigmemory.sri \
			R-cran-Rcpp>0:devel/R-cran-Rcpp \
			R-cran-uuid>=1.0.2:devel/R-cran-uuid

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
