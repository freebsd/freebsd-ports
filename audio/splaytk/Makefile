# New ports collection makefile for:    splaytk
# Version required:     2.0
# Date created:         19 Apr 1998
# Whom:                 brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.1.1.1 1998/04/24 02:33:34 mph Exp $
#

DISTNAME=		splaytk-2.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=		brett@peloton.physics.montana.edu

RUN_DEPENDS=	splay:${PORTSDIR}/audio/splay \
		wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC= ${WRKDIR}/splay-tk-2.0

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/splay-tk.tcl ${PREFIX}/bin/splay-tk
	@${MKDIR} ${PREFIX}/lib/splay-tk
	@${INSTALL_DATA} ${WRKSRC}/*.xbm ${PREFIX}/lib/splay-tk
	@${INSTALL_DATA} ${WRKSRC}/splay-tk.gif ${PREFIX}/lib/splay-tk

.include <bsd.port.mk>
