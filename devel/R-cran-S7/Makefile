PORTNAME=	S7
DISTVERSION=	0.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Object Oriented System, Successor to S3 and S4
WWW=		https://cran.r-project.org/package=S7

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.2.0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist,compiles

pre-test:
	${LOCALBASE}/bin/Rscript -e \
		'install.packages("bench", repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
