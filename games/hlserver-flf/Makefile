# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.3
MASTER_SITES=	ftp://ftp2.3ddownloads.com/90380/valveworld/mods/frontline/ \
		ftp://ftp.3ddownloads.com/90380/valveworld/mods/frontline/ \
		http://www.flfmod.net/site/info/files/ \
		ftp://ftp.jolt.co.uk/pub/dls/ \
		ftp://ftp.task.gda.pl/vol/d33/ftp.extreme-players.de/exp/hl/mod/frontlineforce/ \
		http://www.spies.com/flf/downloads/ \
		http://62.27.37.102/ftp1_1/halflife/multiplayermods/flf/server/
DISTFILES=	frontline_linux_12a.zip \
		frontline13_up.zip

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

WRKSRC=		${WRKDIR}/frontline

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
