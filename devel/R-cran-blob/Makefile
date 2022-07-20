PORTNAME=	blob
DISTVERSION=	1.2.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	A Simple S3 Class for Representing Vectors of Binary Data ('BLOBS')

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>=0.2.1:devel/R-cran-vctrs
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-pillar>=1.2.1:devel/R-cran-pillar \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
