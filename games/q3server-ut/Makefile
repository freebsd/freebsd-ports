# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	b2.3
MASTER_SITES=	http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/quake3/modifications/urbanterror/ \
		http://www.clandvs.com/downloads/ \
		ftp://www.gamechannel.de/gcpro/ \
		http://files.gamesmania.de/gamesmania/urbanter/ \
		http://www.progamers.cz/files/ \
		http://hoffmann.laurent.free.fr/ \
		http://www.unigames.com.br/q3ut/ \
		http://62.180.57.56/files/
DISTFILES=	q3${PORTNAME}2.zip \
		q3${PORTNAME}2_patch20to23.zip

WRKSRC=			${WRKDIR}/q3ut2
EXTRACT_BEFORE_ARGS=	-o -qq
HAS_WIERDPATCHES=	yes
EXTRACT_ONLY=		q3${PORTNAME}2.zip

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
