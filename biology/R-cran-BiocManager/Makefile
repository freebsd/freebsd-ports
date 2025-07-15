PORTNAME=	BiocManager
DISTVERSION=	1.30.26
CATEGORIES=	biology
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Convenient tool to install and update Bioconductor packages
WWW=		https://cran.r-project.org/web/packages/BiocManager/

LICENSE=	ART20

TEST_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

TESTING_UNSAFE=	yes

PORTSCOUT=	skipv:1.30.24

.include <bsd.port.mk>
