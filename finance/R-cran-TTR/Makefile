# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	TTR
DISTVERSION=	0.23-6
CATEGORIES=	finance
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Technical Trading Rules

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-xts>=0.10.0:math/R-cran-xts \
		R-cran-zoo>0:math/R-cran-zoo \
		R-cran-curl>0:ftp/R-cran-curl
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
