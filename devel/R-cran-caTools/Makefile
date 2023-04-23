PORTNAME=	caTools
PORTVERSION=	1.18.2
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools: moving window statistics, GIF, Base64, ROC AUC, etc
WWW=		https://cran.r-project.org/web/packages/caTools/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-bitops>0:devel/R-cran-bitops
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
