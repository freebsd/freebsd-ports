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
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
