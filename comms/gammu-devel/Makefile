# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	1.00.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.kirill.spb.ru/gammu/

MAINTAINER=	kirill@solaris.ru
COMMENT=	GNU All Mobile Management Utilities

MAN1=		gammu.1
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
WANT_AUTOCONF_VER=259

CONFIGURE_ARGS=	--disable-bluerfsearch
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC"

.include <bsd.port.mk>
