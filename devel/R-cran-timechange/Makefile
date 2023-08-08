PORTNAME=	timechange
PORTVERSION=	0.2.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient Manipulation of Date-Times
WWW=		https://cran.r-project.org/web/packages/timechange/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-cpp11>=0.2.7:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
