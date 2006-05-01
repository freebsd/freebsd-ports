# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/pkgconfig/Makefile,v 1.6 2005/10/14 20:39:57 adamw Exp $
#

PORTNAME=	pkgconfig
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/
DISTNAME=	pkg-config-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility to retrieve information about installed libraries

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

MAN1=		pkg-config.1

.include <bsd.port.pre.mk>

PC_PATH=${PREFIX}/libdata/pkgconfig
PC_PATH:=${PREFIX}/lib/pkgconfig
.if ${LOCALBASE} != ${PREFIX}
PC_PATH:=	${PC_PATH}:${LOCALBASE}/libdata/pkgconfig
PC_PATH:=	${PC_PATH}:${LOCALBASE}/lib/pkgconfig
.endif
.if ${X11BASE} != ${PREFIX}
PC_PATH:=	${PC_PATH}:${X11BASE}/libdata/pkgconfig
PC_PATH:=	${PC_PATH}:${X11BASE}/lib/pkgconfig
.endif

CONFIGURE_ARGS=	--disable-threads \
		--with-pc-path="${PC_PATH}"

.include <bsd.port.post.mk>
