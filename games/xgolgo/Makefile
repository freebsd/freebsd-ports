# New ports collection makefile for:   xgolgo
# Version required:    1.0
# Date created:        1 July 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/10/15 04:56:39 max Exp $
#

DISTNAME=	xeyes-g
PKGNAME=	xgolgo-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cc.saga-u.ac.jp/pub/X/xeyes/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

WRKSRC=		${WRKDIR}/xeyes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
MAN1=		xgolgo.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/xeyes.man ${PREFIX}/man/man1/xgolgo.1

.include <bsd.port.mk>
