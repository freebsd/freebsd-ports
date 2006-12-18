# New ports collection makefile for:	The Opera
# Date created:				Mon May 27 17:52:12 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	1.2
PORTREVISION=	1
MASTER_SITES=	http://distribution.redeemedsoft.com/r12/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Half-Life mod The Opera full server package for Linux

DEPRECATED=	distfile and homepage disappeared
EXPIRATION_DATE=	2007-01-17

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

slaveport-post-extract:
	@${CP} ${WRKDIR}/opera_hlds ${WRKSRC}

.include "${HALFLIFE_PORT_MASTER}/Makefile"
