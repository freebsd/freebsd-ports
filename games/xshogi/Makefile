# New ports collection makefile for:   xshogi 
# Version required:    1.2p03
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/17 11:53:34 asami Exp $
#

DISTNAME=	xshogi-1.2p03
PKGNAME=        xshogi-1.2.3
CATEGORIES=     games
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=     Nakai@Mlab.t.u-tokyo.ac.jp

RUN_DEPENDS=    ${LOCALBASE}/libexec/gnushogix:${PORTSDIR}/games/gnushogi

USE_X11=	yes
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
