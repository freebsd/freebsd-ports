# New ports collection makefile for:	pkgconf
# Date created:		2012-07-22
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgconf
PORTVERSION=	0.8.5
CATEGORIES=	devel
MASTER_SITES=	http://nenolod.net/~nenolod/distfiles/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	pkg-config compatible utility which does not depend on glib

LICENSE=	BSD

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/libdata/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include
USE_BZIP2=	yes

CONFLICTS_INSTALL=	pkg-config-*

post-install:
	${LN} -sf ${PREFIX}/bin/pkgconf ${PREFIX}/bin/pkg-config

.include <bsd.port.mk>
