# New ports collection makefile for:	Sven Co-Op Server
# Date created:				Thu May	3 22:04:21 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	svencoop
PORTVERSION=	1.19.1
MASTER_SITES=	http://www.smidge.com/files/sc/ \
		http://www.cfgn.net/files/files/ \
		http://ftp.ioerror.com/ftp/pub2/halflife/mods/svencoop/ \
		ftp://ftp.ioerror.com/pub2/halflife/mods/svencoop/ \
		http://www.svencoop.com/files/
DISTFILES=	svencoop19.tar.gz svencoop19_patch.tar.gz

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
