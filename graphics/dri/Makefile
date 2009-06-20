# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	${MESAVERSION}
PORTEPOCH=	2
CATEGORIES=	graphics

COMMENT=	OpenGL hardware acceleration drivers for the DRI

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm \
		expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

CONFLICTS=	dri-6.2.2005* dri-6.5.2006*
MAKE_JOBS_UNSAFE=	yes

USE_XORG=	glproto x11 xext xxf86vm xdamage xfixes dri2proto

do-install:
	cd ${WRKSRC}/src/mesa; ${GMAKE} install-dri

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
