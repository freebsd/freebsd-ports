# New ports collection makefile for:	xqf
# Version required:			0.8.99.2
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $Id: Makefile,v 1.3 1999/05/09 16:59:17 steve Exp $
#

DISTNAME=	xqf-0.8.99.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linuxgames.com/xqf/

MAINTAINER=	steve@farrell.org

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat
LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes

post-install:
	@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
