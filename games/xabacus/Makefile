# New ports collection makefile for:	xabacus
# Version required:			5.4.4
# Date created:				3 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/27 23:24:48 asami Exp $
#

DISTNAME=		xabacus-5.4.4
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.tux.org/pub/people/david-bagley/xabacus/ \
			${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=		andy@icc.surw.chel.su

GNU_CONFIGURE=		yes
USE_X_PREFIX=		yes
REQUIRES_MOTIF=		yes
WRKSRC=			${WRKDIR}/xabacus

MAN1=			xabacus.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xabacus ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xmabacus ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/Abacus.ad ${X11BASE}/lib/X11/app-defaults/Abacus
	@ ${INSTALL_MAN} ${WRKSRC}/xabacus.man ${PREFIX}/man/man1/xabacus.1

.include <bsd.port.mk>
