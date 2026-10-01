PORTNAME=	arg
PORTVERSION=	0.2.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Clean and Simple Argument Checking
WWW=		https://cran.r-project.org/package=arg

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	R-cran-cli>=0:devel/R-cran-cli \
		R-cran-rlang>=0:devel/R-cran-rlang
RUN_DEPENDS=	R-cran-cli>=0:devel/R-cran-cli \
		R-cran-rlang>=0:devel/R-cran-rlang

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
