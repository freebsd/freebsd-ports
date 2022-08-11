PORTNAME=	lubridate
PORTVERSION=	1.8.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Make Dealing with Dates a Little Easier

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-generics>0:devel/R-cran-generics \
		R-cran-cpp11>=0.2.7:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
