# New ports collection makefile for:	traindirector
# Date created:				09/08/2003
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	traindirector
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.backerstreet.com/traindir/
DISTNAME=	tdir35src

MAINTAINER=	mad@madpilot.net
COMMENT=	Train controller simulation

NO_WRKSUBDIR=	yes

USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_ZIP=	yes

USE_WX=		2.8
WX_COMPS=	wx
WX_UNICODE=	yes

DESKTOP_ENTRIES="Train Director" "${COMMENT}" "" "traindir3" \
		"Game;Simulation;StrategyGame;" false

PLIST_FILES=	bin/traindir3

MAKEFILE=	Makefile.fc9

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/traindir3 ${PREFIX}/bin

.include <bsd.port.mk>
