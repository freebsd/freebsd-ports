# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	2.1
MASTER_SITES=	http://www.redphive.org/files/ \
		ftp://ftp.dod-europe.com/dod/dod/2.1/linux/ \
		ftp://ftp.dodfrance.com/dod/dod/2.1/linux/ \
		ftp://209.239.96.42/ \
		ftp://gamefiles.blueyonder.co.uk/blueyondergames/halflife/modifications/dayofdefeat/patches/linux/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}_full

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
