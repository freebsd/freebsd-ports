# New ports collection makefile for: libFIRM
# Date created:         22 Nov 2008
# Whom:                 Christoph Mallon <christoph.mallon@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	libfirm
PORTVERSION=	1.16.0
CATEGORIES=	devel lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graph-based SSA intermediate representation library for compilers

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

OPTIONS=	DEBUG "Build a debug version of libFIRM" OFF

.include <bsd.port.pre.mk>

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.include <bsd.port.post.mk>
