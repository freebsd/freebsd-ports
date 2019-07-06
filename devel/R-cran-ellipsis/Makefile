# $FreeBSD$

PORTNAME=	ellipsis
PORTVERSION=	0.2.0.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Powerful tool for extending functions

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-rlang>=0.3.0:devel/R-cran-rlang
BUILD_DEPENS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
