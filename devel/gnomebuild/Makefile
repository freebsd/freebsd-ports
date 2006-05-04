# New ports collection makefile for:	gnomebuild
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebuild
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/gnome/gnome-/}/0.1
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	A GNOME Build Framework (GBF)

LIB_DEPENDS=	gdl-1.0:${PORTSDIR}/x11-toolkits/gdl

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack lthack gnometarget libgnomeui gnomevfs2
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES+=	${FILESDIR}/current-src_backends_libgbf_am_gbf-am-project.c
.elif ${ARCH} != "i386"
EXTRA_PATCHES+=	${FILESDIR}/stable-src_backends_libgbf_am_gbf-am-project.c
.endif

.include <bsd.port.post.mk>
