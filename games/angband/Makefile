# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	3.0.3
CATEGORIES=	games
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Source/  \
		ftp://ftp.sunet.se/pub/games/Angband/Source/

MAINTAINER=	mph@freebsd.org

GNU_CONFIGURE=	yes
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS=	--with-setgid=games --with-x
.else
CONFIGURE_ARGS=	--with-setgid=games --with-x=no
.endif

pre-fetch:
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "You could define WITHOUT_X11, if you don't want X support"
.else
	@${ECHO_MSG} "Building without X support"
.endif

.include <bsd.port.mk>
