# New ports collection makefile for:    gnome-vfsmm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gnome-vfsmm
PORTVERSION=	1.3.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@mail.ru
COMMENT=	C++ wrapper for gnomevfs2 library

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomevfs2
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_gcc_bugs
.endif

.include <bsd.port.post.mk>
