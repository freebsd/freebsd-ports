# New ports collection makefile for:	Snow War Server
# Date created:				Fri Oct 5 01:13:28 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snow
PORTVERSION=	0.0.94
MASTER_SITES=	ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/snowwar/ \
		http://www.ancient.co.jp/~game/files/
DISTNAME=	sw${PORTVERSION:S/.//g:S/^0//}
EXTRACT_SUFX=	.exe

MAINTAINER=	lioux@FreeBSD.org

USE_ZIP=	yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
