# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cli
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Helpers for Developing Command Line Interfaces

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-assertthat>0:math/R-cran-assertthat \
		R-cran-crayon>=1.3.4:devel/R-cran-crayon \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-fansi>0:devel/R-cran-fansi
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
