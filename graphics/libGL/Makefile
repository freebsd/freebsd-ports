# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGL
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL library that renders using GLX or DRI

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS+=	drm:${PORTSDIR}/graphics/libdrm

USE_XORG=	glproto xxf86vm xext xfixes xdamage
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/drm

SRCDIR=		glx/x11
HEADERS=	gl.h glext.h glx.h glxext.h
HEADERSDIR=	include/GL

.include "${.CURDIR}/../../graphics/libGL/bsd.mesalib.mk"
.include <bsd.port.mk>
