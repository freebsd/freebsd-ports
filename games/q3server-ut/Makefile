# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	b2.2
MASTER_SITES=	http://www.masterblaster.dk/ \
		http://files.gamesmania.de/gamesmania/urbanter/ \
		http://www.progamers.cz/files/ \
		http://www.unigames.com.br/q3ut/
DISTFILES=	q3${PORTNAME}2.zip \
		q3${PORTNAME}2_patch20to22.zip

WRKSRC=			${WRKDIR}/q3ut2
HAS_WIERDPATCHES=	yes
EXTRACT_ONLY=		q3${PORTNAME}2.zip

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
