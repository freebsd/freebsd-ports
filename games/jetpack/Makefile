# New ports collection makefile for:    jetpack
# Version required:     ?
# Date created:         21 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
DISTFILES=	jetpack.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAKE_FLAGS=	PREFIX=${PREFIX} -f
MAN6=		jetpack.6

post-install:
	@${CHOWN} games ${PREFIX}/bin/jetpack
	@${CHMOD} u+s ${PREFIX}/bin/jetpack
	@${CHOWN} games ${PREFIX}/lib/X11/jetpack
	@${CHMOD} go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000

.include <bsd.port.mk>
