PORTNAME=	Biobase
PORTVERSION=	2.62.0
CATEGORIES=	biology
MASTER_SITES=	https://www.bioconductor.org/packages/release/bioc/src/contrib/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Base functions for Bioconductor
WWW=		https://bioconductor.org/packages/Biobase

LICENSE=	ART20

CRAN_DEPENDS=	R-cran-BiocGenerics>=0.27.1:biology/R-cran-BiocGenerics
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
