# New ports collection makefile for:	MASM/NASM/TASM to GAS converter
# Date created:		Thu Dec 22 14:46:11 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	intel2gas
PORTVERSION=	1.3.3
CATEGORIES=	converters devel
MASTER_SITES=	http://www.niksula.cs.hut.fi/~mtiihone/intel2gas/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	MASM/NASM/TASM to GNU asm syntax converter

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

pre-install:
	@${MKDIR} ${DATADIR}

.include <bsd.port.mk>
