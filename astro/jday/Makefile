# New ports collection makefile for:   jday
# Date created:                2000-11-27
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	jday
PORTVERSION=	2.4
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical julian date calculator

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN1=	jday.1

PLIST_FILES=	bin/jday bin/j2d bin/dbd \
		include/jday.h lib/libjday.a \
		lib/libjday.so lib/libjday.so.2 \
		lib/libjday.la libdata/pkgconfig/jday.pc

.include <bsd.port.mk>
