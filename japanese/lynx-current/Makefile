# New ports collection makefile for:	ja-lynx-current
# Version required:     2.8.1dev.X
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=       lynx2.8.1dev.20
PKGNAME=        ja-lynx-2.8.1.20
CATEGORIES=	japanese www
MASTER_SITES=   ftp://sol.slcc.edu/pub/lynx/current/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

NO_LATEST_LINK=	YES
WRKSRC=         ${WRKDIR}/lynx2-8-1
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
