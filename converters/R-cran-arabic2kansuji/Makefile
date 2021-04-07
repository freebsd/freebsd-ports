PORTNAME=	arabic2kansuji
PORTVERSION=	0.1.1
CATEGORIES=	converters
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Convert Arabic Numerals to Kansuji

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-stringr>0:textproc/R-cran-stringr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
