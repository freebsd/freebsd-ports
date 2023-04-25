PORTNAME=	whoami
DISTVERSION=	1.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Username, Full Name, Email Address, 'GitHub' Username of the Current User
WWW=		https://github.com/r-lib/whoami#readme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-httr>0:www/R-cran-httr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist

.include <bsd.port.mk>
