
# New ports collection makefile for:    astrometry
# Date created:                         7 July 2009
# Whom:                                 Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	astrometry
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.astrometry.net/downloads/
DISTNAME=	astrometry.net-${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Describes an astronomical image

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		netpbm.1:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

USE_PYTHON=	2.4+
USE_GMAKE=	yes
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${PREFIX}/astrometry
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

post-extract:
	${CP} ${FILESDIR}/gnu-specific-config.h ${WRKSRC}/util/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
