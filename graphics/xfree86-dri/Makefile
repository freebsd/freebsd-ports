# New ports collection makefile for:    dri
# Date created:		8 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xfree86-dri
PORTVERSION=	4.5.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	XFree86-${PORTVERSION}-src-1.tgz \
		XFree86-${PORTVERSION}-src-2.tgz \
		XFree86-${PORTVERSION}-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers for XFree86

CONFLICTS=	dri-[5-9].*

EXTRA_PATCHES+=		${FILESDIR}/patch-GL-Imakefile

ONLY_FOR_ARCHS=		i386 alpha amd64

XBUILD_DIRS=		lib/GL
XINSTALL_DIRS=		lib/GL/mesa/drivers/dri

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86. For X.Org use graphics/dri port. See ports/UPDATING entry 20040723 for further information.
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
.endif
.if ${ARCH} == amd64
PLIST_SUB+=	AMD64_NA="@comment "
.else
PLIST_SUB+=	AMD64_NA=""
.endif
.include <bsd.port.post.mk>
