PORTNAME=	brio
DISTVERSION=	1.1.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Basic R Input Output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
