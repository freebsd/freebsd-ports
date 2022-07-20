PORTNAME=	pillar
PORTVERSION=	1.8.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Coloured Formatting for Columns

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>=2.3.0:devel/R-cran-cli \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.0.2:devel/R-cran-rlang \
		R-cran-utf8>=1.1.0:textproc/R-cran-utf8 \
		R-cran-vctrs>=0.3.8:devel/R-cran-vctrs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
