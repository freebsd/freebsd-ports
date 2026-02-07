PORTNAME=	cli
DISTVERSION=	3.6.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Helpers for Developing Command Line Interfaces
WWW=		https://cran.r-project.org/package=cli

LICENSE=	MIT

USES=		cran:auto-plist,compiles

TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-glue>=1.6.0:devel/R-cran-glue \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-processx>0:sysutils/R-cran-processx \
		R-cran-ps>=1.3.4.9000:sysutils/R-cran-ps \
		R-cran-rlang>=1.0.2.9003:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-whoami>0:devel/R-cran-whoami \
		R-cran-withr>0:devel/R-cran-withr

TESTING_UNSAFE=	PR 280006

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
