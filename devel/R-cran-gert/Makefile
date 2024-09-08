PORTNAME=	gert
DISTVERSION=	2.1.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jpbeconne@free.fr
COMMENT=	Simple Git Client for R
WWW=		https://docs.ropensci.org/gert/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass \
		R-cran-credentials>=1.2.1:security/R-cran-credentials \
		R-cran-openssl>=2.0.3:security/R-cran-openssl \
		R-cran-rstudioapi>=0.11:devel/R-cran-rstudioapi \
		R-cran-sys>0:devel/R-cran-sys \
		R-cran-zip>=2.1.0:archivers/R-cran-zip
BUILD_DEPENDS=	${CRAN_DEPENDS}
LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
