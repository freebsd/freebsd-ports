# New ports collection makefile for:   jday
# Date created:                2000-11-27
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	jday
PORTVERSION=	2.4
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Astronomical julian date calculator

USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	jday.1

PLIST_FILES=	bin/jday bin/j2d bin/dbd \
		include/jday.h lib/libjday.a \
		lib/libjday.so lib/libjday.so.2 \
		lib/libjday.la libdata/pkgconfig/jday.pc

.include <bsd.port.mk>
