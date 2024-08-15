PORTNAME=	clock
PORTVERSION=	0.7.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Date-Time Types and Tools
WWW=		https://cran.r-project.org/web/packages/clock/

LICENSE=	MIT

RUN_DEPENDS=	R-cran-cpp11>=0.4.3:devel/R-cran-cpp11 \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-tzdb>=0.4.0:devel/R-cran-tzdb \
		R-cran-vctrs>=0.6.1:devel/R-cran-vctrs

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
