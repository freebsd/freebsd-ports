PORTNAME=	tzdb
PORTVERSION=	0.2.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Time Zone Database Information

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cpp11>=0.4.0:devel/R-cran-cpp11
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles shebangfix
SHEBANG_FILES=	inst/tzdata/zoneinfo2tdf.pl

.include <bsd.port.mk>
