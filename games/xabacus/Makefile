# New ports collection makefile for:	xabacus
# Date created:				3 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xabacus
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.tux.org/pub/tux/bagleyd/xabacus/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/xabacus
USE_MOTIF=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		xabacus.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xabacus ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xmabacus ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xabacus.man ${PREFIX}/man/man1/xabacus.1
	${INSTALL_DATA} ${WRKSRC}/Abacus.ad ${X11BASE}/lib/X11/app-defaults/Abacus

.include <bsd.port.mk>
