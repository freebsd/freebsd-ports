# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	astrometry
PORTVERSION=	0.34
PORTREVISION=	4
CATEGORIES=	astro
MASTER_SITES=	http://www.astrometry.net/downloads/
DISTNAME=	astrometry.net-${PORTVERSION}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Describes an astronomical image

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libnetpbm.so:${PORTSDIR}/graphics/netpbm
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy

NO_STAGE=	yes
USES=		gmake pkgconfig
USE_PYTHON=	yes
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${PREFIX}/astrometry
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/util/cairoutils.c
	${REINPLACE_CMD} -e 's|python setup|${PYTHON_CMD} setup|' \
		${WRKSRC}/util/Makefile \
		${WRKSRC}/libkd/Makefile \
		${WRKSRC}/blind/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
