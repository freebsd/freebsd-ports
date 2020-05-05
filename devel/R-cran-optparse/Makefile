# $FreeBSD$

PORTNAME=	optparse
DISTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line flag parser inspired by Python's optparse

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CRAN_DEPENDS=	R-cran-getopt>=1.20.2:devel/R-cran-getopt
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
