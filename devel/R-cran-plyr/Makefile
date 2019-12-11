# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plyr
PORTVERSION=	1.8.5
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for splitting, applying, and combining data

LICENSE=	MIT HW
LICENSE_COMB=	multi
LICENSE_NAME_HW=	Hadley Wickham COPYRIGHT
LICENSE_FILE_HW=	${WRKSRC}/LICENSE
LICENSE_PERMS_HW=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CRAN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
