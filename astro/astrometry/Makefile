# New ports collection makefile for:    astrometry
# Date created:                         7 July 2009
# Whom:                                 Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	astrometry
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.astrometry.net/downloads/
DISTNAME=	astrometry.net-${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Describes an astronomical image

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		netpbm.1:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

USE_PYTHON=	2.5+
USE_GMAKE=	yes
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${PREFIX}/astrometry
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-extract:
.if ${OSVERSION} < 700000 && ${ARCH} == "amd64"
	${CP} ${FILESDIR}/os-features-config.h ${WRKSRC}/util/
.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/util/cairoutils.c

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

.include <bsd.port.post.mk>
