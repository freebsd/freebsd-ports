# New ports collection makefile for:	Science and Industry Server
# Date created:				Wed May	2 23:25:19 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	1.1.b
PORTREVISION=	1
MASTER_SITES=	http://ocuspocus.free.fr/hlheroes/download/ \
		http://jolletx.free.fr/
DISTNAME=	hlh11b

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Heroes full server package for Linux

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

WRKSRC=		${WRKDIR}/Heroes

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
