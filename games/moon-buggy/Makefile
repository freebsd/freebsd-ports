# New ports collection Makefile for: moon-buggy
# Date created:		10 January 2002
# Whom:			Ralf Becker <ralf@akk.org>
#
# $FreeBSD$
#

PORTNAME=	moon-buggy
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	http://www.mathematik.uni-kl.de/~wwwstoch/voss/data/ \
		http://www.hangout.de/moon-buggy/

MAINTAINER=	ralf@akk.org
COMMENT=	Drive a buggy across the moons surface

USE_AUTOCONF_VER=	213
USE_CONFIGURE=	YES
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--sharedstatedir=/var/games \
		--with-setgid=games

MAN6=		moon-buggy.6 maint-buggy.6

# make package will fail without doing this
post-install:
	${CHMOD} u+r ${PREFIX}/bin/moon-buggy

.include <bsd.port.mk>
