PORTNAME=	timechange
DISTVERSION=	0.4.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Efficient Manipulation of Date-Times
WWW=		https://cran.r-project.org/package=timechange

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-cpp11>=0.2.7:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

# Tests need /etc/localtime symlink configured

.include <bsd.port.mk>
