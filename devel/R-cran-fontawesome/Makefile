PORTNAME=	fontawesome
PORTVERSION=	0.5.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily Work with 'Font Awesome' Icons
WWW=		https://cran.r-project.org/web/packages/fontawesome/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>=1.0.6:devel/R-cran-rlang \
		R-cran-htmltools>=0.5.1.1:textproc/R-cran-htmltools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
