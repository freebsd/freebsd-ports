# New ports collection makefile for:	xtruco
# Version required:			1.0
# Date created:				14 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/15 17:11:15 jseger Exp $
#

DISTNAME=		xtruco
PKGNAME=		xtruco-1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		andy@icc.surw.chel.su

USE_X11=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xtruco ${PREFIX}/bin

.include <bsd.port.mk>
