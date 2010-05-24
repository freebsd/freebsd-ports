## New ports collection makefile for:   hexxagon
# Date created:			08 April 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	hexxagon
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.nesqi.se/hexxagon/hexxagon/download/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A strategy hexagon game

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="Hexxagon" "Strategy Game" "" \
		"hexxagon" "Application;Game;" false

.include <bsd.port.mk>
