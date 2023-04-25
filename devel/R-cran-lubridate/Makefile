PORTNAME=	lubridate
PORTVERSION=	1.9.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make Dealing with Dates a Little Easier
WWW=		https://cran.r-project.org/web/packages/lubridate/

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-generics>0:devel/R-cran-generics \
		R-cran-timechange>=0.1.1:devel/R-cran-timechange
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
