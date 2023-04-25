PORTNAME=	classInt
DISTVERSION=	0.4-9
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Choose Univariate Class Intervals
WWW=		https://cran.r-project.org/web/packages/classInt/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-e1071>0:science/R-cran-e1071
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
