# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	5.0.2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src3.tar.gz

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers for the DRI

EXTRA_PATCHES+=		${CF_PATCHES}

ONLY_FOR_ARCHS=		i386 alpha

XBUILD_DIRS=		lib/GL
XINSTALL_DIRS=		lib/GL/mesa/src/drv

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.include <bsd.port.post.mk>
