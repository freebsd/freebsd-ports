# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillar
PORTVERSION=	1.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Coloured Formatting for Columns

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-cli>=1.0.0:devel/R-cran-cli \
		R-cran-crayon>=1.3.4:devel/R-cran-crayon \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-rlang>=0.2.0:devel/R-cran-rlang \
		R-cran-utf8>=1.1.3:textproc/R-cran-utf8
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
