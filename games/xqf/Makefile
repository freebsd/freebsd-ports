# New ports collection makefile for:	xqf
# Version required:			0.9.0
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $Id: Makefile,v 1.4 1999/05/29 03:56:09 steve Exp $
#

DISTNAME=	xqf-0.9.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linuxgames.com/xqf/

MAINTAINER=	steve@farrell.org

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat
LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"

.include <bsd.port.mk>
