# New ports collection makefile for:	xtruco
# Version required:			1.0
# Date created:				14 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		xtruco
PKGNAME=		xtruco-1.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		andy@icc.surw.chel.su

USE_X11=		yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xtruco ${PREFIX}/bin

.include <bsd.port.mk>
