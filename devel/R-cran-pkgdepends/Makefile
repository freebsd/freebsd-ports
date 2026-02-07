PORTNAME=	pkgdepends
DISTVERSION=	0.9.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Package Dependency Resolution and Downloads
WWW=		https://cran.r-project.org/package=pkgdepends

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-zip>=2.3.0:archivers/R-cran-zip \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-callr>=3.3.1:devel/R-cran-callr \
		R-cran-cli>=3.6.0:devel/R-cran-cli \
		R-cran-desc>=1.4.3:devel/R-cran-desc \
		R-cran-filelock>=1.0.2:devel/R-cran-filelock \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-pkgbuild>=1.0.2:devel/R-cran-pkgbuild \
		R-cran-pkgcache>=2.2.0:devel/R-cran-pkgcache \
		R-cran-prettyunits>=1.1.1:devel/R-cran-prettyunits \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-lpSolve>0:math/R-cran-lpSolve \
		R-cran-processx>=3.4.2:sysutils/R-cran-processx \
		R-cran-ps>0:sysutils/R-cran-ps

USES=		cran:auto-plist

NO_ARCH_IGNORE=	pkgdepends.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/pkgdepends/libs/pkgdepends.so
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
