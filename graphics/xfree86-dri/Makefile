# New ports collection makefile for:    dri
# Date created:		08 Nov 2003
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	4.3.0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	X430src-1.tgz \
		X430src-2.tgz \
		X430src-3.tgz

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers for XFree86

.for pf in \
	patch-GL-Imakefile \
	patch-radeondri \
	patch-r200_vtxtmp_x86.S \
	patch-radeon_vtxtmp_x86.S \
	patch-dri_util.c
EXTRA_PATCHES+=		${FILESDIR}/${pf}
.endfor

ONLY_FOR_ARCHS=		i386 alpha

XBUILD_DIRS=		lib/GL
XINSTALL_DIRS=		lib/GL/mesa/src/drv

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif
.include <bsd.port.post.mk>
