# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	2.5
MASTER_SITES=	ftp://ut.petrovits.net/pub/UrbanTerror/ \
		http://ut.zdwebhosting.com/ \
		http://www.dailyfiles.dk/modifications/ \
		ftp://ftp.barrysworld.com/pub/games/quake3/mods/urbanterror/official_patches/win32/ \
		http://www.q3arena.gry.wp.pl/ut/pliki/ \
		http://62.180.57.56/files/mods/ut2/ \
		ftp://ftp.gcpro.de/mods/quake3/ut2/
DISTFILES=	q3ut24_full.zip beta25_upgrade.zip

WRKSRC=		${WRKDIR}/q3ut2
HAS_WIERDPATCHES=	yes
EXTRACT_ONLY=	q3ut24_full.zip

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
