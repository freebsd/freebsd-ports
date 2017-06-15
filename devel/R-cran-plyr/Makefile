# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plyr
PORTVERSION=	1.8.4
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for splitting, applying, and combining data

LICENSE=	MIT HW
LICENSE_COMB=	multi
LICENSE_NAME_HW=	Hadley Wickham COPYRIGHT
LICENSE_FILE_HW=	${WRKSRC}/LICENSE
LICENSE_PERMS_HW=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp

USES=	cran:auto-plist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/plyr/libs/plyr.so

.include <bsd.port.mk>
