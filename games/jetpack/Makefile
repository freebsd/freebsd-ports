# New ports collection makefile for:    jetpack
# Version required:     ?
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
CATEGORIES+=	games
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
DISTFILES=	jetpack.tar.Z

USE_IMAKE=	yes
MAKE_FLAGS=	PREFIX=${PREFIX} -f

.include <bsd.port.mk>

install:
	@chown games ${PREFIX}/bin/jetpack
	@chmod u+s ${PREFIX}/bin/jetpack
	@chown games ${PREFIX}/lib/X11/jetpack
	@chmod go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000
