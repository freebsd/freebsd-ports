# New ports collection makefile for:    jetpack
# Version required:     ?
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.16 1997/01/03 09:36:43 obrien Exp $
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
	@/usr/sbin/chown games ${PREFIX}/bin/jetpack
	@chmod u+s ${PREFIX}/bin/jetpack
	@/usr/sbin/chown games ${PREFIX}/lib/X11/jetpack
	@chmod go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000

.include <bsd.port.mk>
