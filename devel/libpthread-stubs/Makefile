# New ports collection makefile for:   libpthread-stubs
# Date created:		24 January 2007
# Whom:			wahjava
#
# $FreeBSD$
#

PORTNAME=	libpthread-stubs
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	wahjava@gmail.com
COMMENT=	This library provides weak aliases for pthread functions

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
