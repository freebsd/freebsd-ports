# New ports collection makefile for:	xqf
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $FreeBSD$
#

PORTNAME=	xqf
PORTVERSION=	0.9.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.linuxgames.com/xqf/

MAINTAINER=	steve@farrell.org

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat
LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
.ifdef CC
MAKE_ENV+=	CC="${CC}"
.endif

.include <bsd.port.mk>
