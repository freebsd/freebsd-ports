# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	rversions
DISTVERSION=	2.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Query 'R' Versions, Including 'r-release' and 'r-oldrel'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-xml2>=1.0.0:textproc/R-cran-xml2
TEST_DEPENDS=	R-cran-mockery>0:devel/R-cran-mockery \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
