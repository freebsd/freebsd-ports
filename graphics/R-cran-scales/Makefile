# New ports collection makefile for:	R-cran-scales
# Date created:		2012-02-08
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scales
PORTVERSION=	0.2.0
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Scale functions for graphics

LICENSE=	MIT

RUN_DEPENDS=	R-cran-RColorBrewer>=0:${PORTSDIR}/graphics/R-cran-RColorBrewer \
		R-cran-stringr>=0:${PORTSDIR}/textproc/R-cran-stringr \
		R-cran-dichromat>=0:${PORTSDIR}/graphics/R-cran-dichromat \
		R-cran-munsell>=0.2:${PORTSDIR}/graphics/R-cran-munsell \
		R-cran-plyr>=1.2:${PORTSDIR}/devel/R-cran-plyr

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
