PORTNAME=	remotes
DISTVERSION=	2.5.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	R Package Installation from Remote Repositories, Including 'GitHub'
WWW=		https://remotes.r-lib.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-brew>0:textproc/R-cran-brew \
		R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-curl>0:ftp/R-cran-curl \
		R-cran-git2r>=0.23.0:devel/R-cran-git2r \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-pingr>0:net/R-cran-pingr \
		R-cran-pkgbuild>=1.0.1:devel/R-cran-pkgbuild \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
