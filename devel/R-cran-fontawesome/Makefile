PORTNAME=	fontawesome
PORTVERSION=	0.3.0
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Work with 'Font Awesome' Icons

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-htmltools>=0.5.1.1:textproc/R-cran-htmltools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
