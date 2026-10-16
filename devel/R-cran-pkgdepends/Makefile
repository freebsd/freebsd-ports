PORTNAME=	pkgdepends
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Package Dependency Resolution and Downloads
WWW=		https://cran.r-project.org/package=pkgdepends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	R-cran-callr>=3.3.1:devel/R-cran-callr \
			R-cran-cli>=3.6.0:devel/R-cran-cli \
			R-cran-curl>0:ftp/R-cran-curl \
			R-cran-desc>=1.4.3:devel/R-cran-desc \
			R-cran-filelock>=1.0.2:devel/R-cran-filelock \
			R-cran-glue>0:devel/R-cran-glue \
			R-cran-jsonlite>0:converters/R-cran-jsonlite \
			R-cran-lpSolve>0:math/R-cran-lpSolve \
			R-cran-pkgbuild>=1.0.2:devel/R-cran-pkgbuild \
			R-cran-pkgcache>=2.2.0:devel/R-cran-pkgcache \
			R-cran-prettyunits>=1.1.1:devel/R-cran-prettyunits \
			R-cran-processx>=3.4.2:sysutils/R-cran-processx \
			R-cran-ps>0:sysutils/R-cran-ps \
			R-cran-R6>0:devel/R-cran-R6 \
			R-cran-rprojroot>0:devel/R-cran-rprojroot \
			R-cran-zip>=2.3.0:archivers/R-cran-zip

USES=		cran:auto-plist,compiles

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/pkgdepends/libs/pkgdepends.so
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
