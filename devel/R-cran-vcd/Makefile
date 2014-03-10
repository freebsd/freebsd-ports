# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vcd
DISTVERSION=	1.3-1
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualization techniques, data sets for categorical data

LICENSE=	GPLv2

BROKEN=		Does not find WRKSRC
DEPRECATED=	New port without proper maintainer
EXPIRATION_DATE=	2014-03-28

RUN_DEPENDS=	R-cran-colorspace>0:${PORTSDIR}/graphics/R-cran-colorspace

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
