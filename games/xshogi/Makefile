# New ports collection makefile for:   xshogi 
# Version required:    1.2p03
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1999/01/12 16:51:28 vanilla Exp $
#

DISTNAME=	xshogi-1.2p03
PKGNAME=	xshogi-1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	xshogi

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	${LOCALBASE}/libexec/gnushogix:${PORTSDIR}/games/gnushogi

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.custom
MAN6=		xshogi.6

post-configure:
	@echo "DISTDIR=${WRKDIR}" >> ${WRKSRC}/${MAKEFILE}
	@echo "LOCALBASE=${LOCALBASE}" >> ${WRKSRC}/${MAKEFILE}

post-install:
	@strip ${PREFIX}/bin/xshogi
	@chmod 755 ${PREFIX}/bin/xshogi
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/xshogi
	${INSTALL_MAN} ${WRKSRC}/xshogi.man ${PREFIX}/man/man6/xshogi.6

.include <bsd.port.mk>
