# New ports collection makefile for:	Q3 Mod: Urban Terror
# Date created:				Sun Jun  3 11:49:27 EDT 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	ut
PORTVERSION=	2.6a
MASTER_SITES=	http://houston.jeffs-place.org/urbanterror/ \
		ftp://ut.petrovits.net/pub/UrbanTerror/ \
		http://digitalrhapsody.com/ \
		http://www.thedatasource.net/~gleam/ \
		http://www.midwestmayhem.com/ \
		http://64.246.40.38/
DISTFILES=	beta26_full.zip \
		beta26a_upgrade.zip

NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
