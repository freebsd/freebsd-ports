# New ports collection makefile for:	xqf
# Version required:			0.8.99.2
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $Id: Makefile,v 1.2 1999/04/22 03:20:14 mharo Exp $
#

DISTNAME=	xqf-0.8.99.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linuxgames.com/xqf/

MAINTAINER=	steve@farrell.org

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat
LIB_DEPENDS=    gtk12:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes

post-install:
	@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
