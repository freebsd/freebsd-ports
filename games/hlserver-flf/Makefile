# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.2a
MASTER_SITES=	ftp://ftp2.3ddownloads.com/90380/valveworld/mods/frontline/ \
		ftp://ftp.3ddownloads.com/90380/valveworld/mods/frontline/ \
		ftp://ftp.gamesurf.de/pub/gamesurf/halflife/mods/frontlineforce/ \
		ftp://ftp.jolt.co.uk/pub/dls/ \
		ftp://fileplanet.blueyonder.co.uk/ftp1.gamespy.com/fpnew/action/half-life/modifications/frontlineforce/ \
		ftp://ftp.task.gda.pl/vol/d33/ftp.extreme-players.de/exp/hl/mod/frontlineforce/ \
		http://laddermonkey.net/files/ \
		http://62.27.37.102/ftp1_1/halflife/multiplayermods/flf/server/
DISTFILES=	frontline_linux_12a.zip \
		frontline_12a_fix_linux.zip

USE_ZIP=	yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
