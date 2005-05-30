# New ports collection Makefile for: moon-buggy
# Date created:		10 January 2002
# Whom:			Ralf Becker <ralf@akk.org>
#
# $FreeBSD$
#

PORTNAME=	moon-buggy
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.seehuhn.de/data/

MAINTAINER=	ralf@akk.org
COMMENT=	Drive a buggy across the moons surface

USE_AUTOCONF_VER=	259
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--sharedstatedir=/var/games\
		--with-setgid=games

MAN6=		moon-buggy.6
INFO=		moon-buggy

PLIST_FILES=	bin/moon-buggy

# make package will fail without doing this
post-install:
	${CHMOD} 0555 ${PREFIX}/bin/moon-buggy

.include <bsd.port.mk>
