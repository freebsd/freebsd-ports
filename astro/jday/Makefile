# $FreeBSD$

PORTNAME=	jday
PORTVERSION=	2.4
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical Julian date calculator

USE_AUTOTOOLS=	libtool
USES=		pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dbd bin/j2d bin/jday \
		include/jday.h lib/libjday.a \
		lib/libjday.la lib/libjday.so \
		lib/libjday.so.2 libdata/pkgconfig/jday.pc \
		man/man1/jday.1.gz

.include <bsd.port.mk>
