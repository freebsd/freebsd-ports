# New ports collection makefile for:	nighthawk
# Date created:				Apr 4, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	nighthawk
PORTVERSION=	2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} http://lothar.arafura.net.au/~jsno/rel/unix_projects/
MASTER_SITE_SUBDIR=	games/arcade
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	markp@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-scores=/var/games/nighthawk.scores --enable-sound
MAN6=		nighthawk.6

post-patch:
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/src/floor.cc \
		${WRKSRC}/src/ship.cc ${WRKSRC}/src_sound/nighthawk_sound.c \
		${WRKSRC}/src_sound/funkload.c ${WRKSRC}/src_sound/dsp_mixxer.c 

post-install:
	${CHOWN} root:games ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${SH} pkg-install ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
