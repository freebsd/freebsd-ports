# New ports collection makefile for:	Q3 Mod: Weapons Factory Arena
# Date created:				Sun Jun  3 15:03:11 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	wfa
PORTVERSION=	3.3
MASTER_SITES=	ftp://flanders.worldogl.com/wfa/ \
		ftp://urgentfury.org/pub/quake3/ \
		http://www.thunderdome.ws/files/quake3/mods/wfa_33/linux-mac/
DISTFILES=	WFA_Media_v33.zip WFA_MapPack1_v33.zip \
		WFA_MapPack2_v33.zip

EXTRACT_BEFORE_ARGS=	-o -qq
NO_WRKSUBDIR=	yes

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
