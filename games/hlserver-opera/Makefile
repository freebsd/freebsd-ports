# New ports collection makefile for:	The Opera
# Date created:				Mon May 27 17:52:12 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	1.2
PORTREVISION=	1
MASTER_SITES=	ftp://ftp2.extreme-players.de/hl/mod/opera/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/opera/ \
		http://distribution.redeemedsoft.com/r12/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}0

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod The Opera full server package for Linux

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

slaveport-post-extract:
	@${CP} ${WRKDIR}/opera_hlds ${WRKSRC}

.include "${HALFLIFE_PORT_MASTER}/Makefile"
