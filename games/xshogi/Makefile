# New ports collection makefile for:   xshogi 
# Version required:    1.2p03
# Date created:        20 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	xshogi-1.2p03
PKGNAME=        xshogi-1.2.3
CATEGORIES=     games
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=     Nakai@Mlab.t.u-tokyo.ac.jp

RUN_DEPENDS=    ${LOCALBASE}/libexec/gnushogix:${PORTSDIR}/games/gnushogi

USE_X11=	yes
MAKEFILE=	Makefile.custom
MAN1=		xshogi.1

post-install:
	@strip ${PREFIX}/bin/xshogi
	@chmod 755 ${PREFIX}/bin/xshogi
	@chown bin.bin ${PREFIX}/bin/xshogi
	${INSTALL_MAN} ${WRKSRC}/xshogi.man ${PREFIX}/man/man1/xshogi.1

.include <bsd.port.mk>
