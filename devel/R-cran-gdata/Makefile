PORTNAME=	gdata
PORTVERSION=	2.19.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Various R programming tools for data manipulation
WWW=		https://cran.r-project.org/web/packages/gdata/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-gtools>0:devel/R-cran-gtools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	inst/perl/*.pl

.include <bsd.port.mk>
