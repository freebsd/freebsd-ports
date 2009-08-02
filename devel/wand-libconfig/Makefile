# New ports collection makefile for:	wand-libconfig
# Date created:				Tue Oct  9 00:56:22 PDT 2007
# Whom:					Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	libconfig
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	http://research.wand.net.nz/software/libconfig/ \
		http://matt.peterson.org/FreeBSD/ports/
PKGNAMEPREFIX=	wand-

MAINTAINER=	matt@peterson.org
COMMENT=	C library for parsing config files

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	include/libconfig.h lib/libconfig.a lib/libconfig.la \
		lib/libconfig.so lib/libconfig.so.1

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.include <bsd.port.mk>
