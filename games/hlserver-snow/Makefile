# New ports collection makefile for:	Snow War Server
# Date created:				Fri Oct 5 01:13:28 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snow
PORTVERSION=	0.0.94.b
MASTER_SITES=	ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/snowwar/ \
		http://gamedesign.4players.de:1026/downloads/ \
		http://www1.cod2001.com/Downloads-5371-/Half-Life_default/Mods/SnowWar/ \
		http://www.ancient.co.jp/~game/files/
DISTFILES=	sw094.exe hl_i386.so
DIST_SUBDIR=	snow
EXTRACT_ONLY=	sw094.exe

MAINTAINER=	lioux@FreeBSD.org

USE_ZIP=	yes

slaveport-post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/hl_i386.so ${WRKSRC}/dlls

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
