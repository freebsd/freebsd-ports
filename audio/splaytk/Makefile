# New ports collection makefile for:    splaytk
# Date created:         19 Apr 1998
# Whom:                 brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=		splaytk
PORTVERSION=		2.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A tk based interface for splay

RUN_DEPENDS=	splay:${PORTSDIR}/audio/splay \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/splay-tk-2.0

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/splay-tk.tcl ${PREFIX}/bin/splay-tk
	@${MKDIR} ${PREFIX}/lib/splay-tk
	@${INSTALL_DATA} ${WRKSRC}/*.xbm ${PREFIX}/lib/splay-tk
	@${INSTALL_DATA} ${WRKSRC}/splay-tk.gif ${PREFIX}/lib/splay-tk

.include <bsd.port.mk>
