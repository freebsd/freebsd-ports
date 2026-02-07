PORTNAME=	pak
DISTVERSION=	0.9.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Another Approach to Package Installation
WWW=		https://pak.r-lib.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsecret-1.so:security/libsecret
TEST_DEPENDS=	R-cran-callr>=3.7.0:devel/R-cran-callr \
		R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>=4.3.2:ftp/R-cran-curl \
		R-cran-desc>=1.4.1:devel/R-cran-desc \
		R-cran-filelock>=1.0.2:devel/R-cran-filelock \
		R-cran-gitcreds>0:security/R-cran-gitcreds \
		R-cran-glue>=1.6.2:devel/R-cran-glue \
		R-cran-jsonlite>=1.8.0:converters/R-cran-jsonlite \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-pkgbuild>=1.4.2:devel/R-cran-pkgbuild \
		R-cran-pkgcache>=2.2.4:devel/R-cran-pkgcache \
		R-cran-pkgdepends>=0.9.0:devel/R-cran-pkgdepends \
		R-cran-pkgload>0:devel/R-cran-pkgload \
		R-cran-pkgsearch>=3.1.0:devel/R-cran-pkgsearch \
		R-cran-processx>=3.8.1:sysutils/R-cran-processx \
		R-cran-ps>=1.6.0:sysutils/R-cran-ps \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-webfakes>0:devel/R-cran-webfakes \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-yaml>0:textproc/R-cran-yaml

USES=		cran:auto-plist,compiles gettext-runtime gnome pkgconfig
USE_GNOME=	glib20

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/library" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/libs" >> ${TMPPLIST}
.for binfile in ps/bin/px processx/bin/sock processx/bin/px \
	processx/bin/supervisor zip/bin/cmdunzip zip/bin/cmdzip
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${R_MOD_DIR}/library/${binfile}
.endfor

.include <bsd.port.mk>
