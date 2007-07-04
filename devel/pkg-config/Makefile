# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/pkg-config/Makefile,v 1.9 2007/07/01 20:46:42 mezz Exp $
#

PORTNAME=	pkg-config
PORTVERSION=	0.22
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A utility to retrieve information about installed libraries

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

MAN1=		pkg-config.1

.include <bsd.port.pre.mk>

PC_PATH=${PREFIX}/libdata/pkgconfig
PC_PATH:=${PC_PATH}:${PREFIX}/lib/pkgconfig
.if ${LOCALBASE} != ${PREFIX}
PC_PATH:=	${PC_PATH}:${LOCALBASE}/libdata/pkgconfig
PC_PATH:=	${PC_PATH}:${LOCALBASE}/lib/pkgconfig
.endif

CONFIGURE_ARGS=	--disable-threads \
		--with-pc-path="${PC_PATH}" \
		--mandir=${MANPREFIX}/man

.include <bsd.port.post.mk>
