# New ports collection makefile for:    ja-lynx
# Version required:     2.8rel.3
# Date created:         25 April 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=       lynx2.8rel.3
PKGNAME=        ja-lynx-2.8.0.3
CATEGORIES=	japanese www
MASTER_SITES=   ftp://sol.slcc.edu/pub/lynx/current/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

WRKSRC=         ${WRKDIR}/lynx2-8
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
MAKEFILE=       makefile
INSTALL_TARGET= install install-help
MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/lynx_help

.include <bsd.port.mk>
