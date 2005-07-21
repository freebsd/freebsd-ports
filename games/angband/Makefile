# New ports collection makefile for:   angband
# Date created:        21 Feb 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	angband
PORTVERSION=	3.0.6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.thangorodrim.net/pub/angband/Source/ \
		ftp://ftp.sunet.se/pub/games/Angband/Source/ \
		ftp://ftp.planetmirror.com/pub/angband/Source/

MAINTAINER=	mph@freebsd.org
COMMENT=	Rogue-like game with color, X11 support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-setgid=games
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-fetch:
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "You could define WITHOUT_X11, if you don't want X support"
.else
	@${ECHO_MSG} "Building without X support"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
