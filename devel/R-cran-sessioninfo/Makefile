# Created by: Guangyuan Yang <ygy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sessioninfo
DISTVERSION=	1.1.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	R Session Information

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-callr>0:devel/R-cran-callr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
