# New ports collection makefile for:	Science and Industry Server
# Date created:				Wed May	2 23:25:19 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	1.1.b
MASTER_SITES=	http://ocuspocus.free.fr/hlheroes/download/ \
		http://jolletx.free.fr/
DISTNAME=	hlh11b

MAINTAINER=	lioux@FreeBSD.org

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

WRKSRC=		${WRKDIR}/Heroes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
