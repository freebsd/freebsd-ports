PORTNAME=	mockery
DISTVERSION=	0.4.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Mocking Library for R
WWW=		https://cran.r-project.org/package=mockery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist

.include <bsd.port.mk>
