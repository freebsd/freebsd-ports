# New ports collection makefile for:	Natural Selection Server
# Date created:				Tue Nov 12 03:27:08 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	1.0.2
MASTER_SITES=	http://gwforum.net/mirror/ns/ \
		http://files.games.eftel.com/halflife/ns/ \
		http://www.jetstreamgames.co.nz/files/pub/halflife/NaturalSelection/ \
		http://www.redphive.org/files/ns/ \
		ftp://ftp2.extreme-players.de/hl/mod/ns/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/ns/ \
		ftp://files.recongamer.com:2121/games/action/half-life/mods/natural-selection/ \
		http://mirror2.lanvancouver.com/:PATCH \
		http://mirror3.lanvancouver.com/:PATCH \
		http://www.helix-designs.com/files/:PATCH \
		http://www.cofrfps.com/downloads/:PATCH \
		http://gamefiles.blueyonder.co.uk/blueyondergames/halflife/modifications/naturalselection/server/win32/:PATCH \
		ftp://gaming.stny.com/files/:PATCH
DISTFILES=	ns_v1_linux_dedicated_server.tar.gz \
		ns-102.zip:PATCH
EXTRACT_ONLY=	ns_v1_linux_dedicated_server.tar.gz

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

MAINTAINER=	lioux@FreeBSD.org

UNZIP?=		${LOCALBASE}/bin/unzip

slaveport-post-extract:
	@cd ${WRKSRC} && ${UNZIP} -a -o -qq ${DISTDIR}/ns-102.zip

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
