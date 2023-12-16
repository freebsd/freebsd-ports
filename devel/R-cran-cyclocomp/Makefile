PORTNAME=	cyclocomp
DISTVERSION=	1.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Cyclomatic Complexity of R Code
WWW=		https://github.com/gaborcsardi/cyclocomp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-remotes>0:devel/R-cran-remotes \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
