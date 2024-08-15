PORTNAME=	chk
PORTVERSION=	0.9.2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Check User-Supplied Function Arguments
WWW=		https://github.com/poissonconsulting/chk

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-lifecycle>0:devel/R-cran-lifecycle
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
