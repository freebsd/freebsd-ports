# New ports collection makefile for:	Q3 Mod: Weapons Factory Arena
# Date created:				Sun Jun  3 15:03:11 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	wfa
PORTVERSION=	3.3
MASTER_SITES=	ftp://ftp.ogl.org/pub/q3/wfa/ \
		ftp://urgentfury.org/pub/quake3/ \
		http://wfa.themelon.net/wfa/ \
		ftp://mirror1.planetice.net/pub/wfa/ \
		ftp://mirror2.planetice.net/pub/wfa/ \
		http://www.quakeshit.com/files/ \
		ftp://ftp2.extreme-players.de/q3/mod/wfa/
DISTFILES=	WFA_Media_v33.zip WFA_MapPack1_v33.zip \
		WFA_MapPack2_v33.zip

COMMENT=	Quake III Arena Mod: Weapons Factory Arena for Linux

EXTRACT_BEFORE_ARGS=	-o -qq
NO_WRKSUBDIR=	yes

Q3_MOD_MASTER=	${.CURDIR}/../q3server-ra3

.include "${Q3_MOD_MASTER}/Makefile"
