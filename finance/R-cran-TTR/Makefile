PORTNAME=	TTR
DISTVERSION=	0.24.4
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Technical Trading Rules
WWW=		https://cran.r-project.org/web/packages/TTR/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-curl>0:ftp/R-cran-curl \
		R-cran-xts>=0.10.0:math/R-cran-xts \
		R-cran-zoo>0:math/R-cran-zoo

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
