# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	3.0
MASTER_SITES=	http://gamefiles.blueyonder.co.uk/blueyondergames/quake3arena/modifications/urbanterror/patches/win32/ \
		ftp://www.playdedicated.com/pub/sid/quake3/ \
		http://ftp.club-internet.fr/pub/games/nofrag/quake3/mods/urbanterror/patches/ \
		ftp://ftp.edome.net/online/clientit/ \
		http://clanhosted.clix.pt/files/clanhosted/quake3/ut/
DISTNAME=	urbanterror3

COMMENT=	Quake III Arena Mod: Urban Terror for Linux

NO_PACKAGE=	"Distfile is >256MB; define FORCE_PACKAGE if you really want this."

WRKSRC=		${WRKDIR}/q3ut3

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
