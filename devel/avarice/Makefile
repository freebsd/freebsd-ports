# New ports collection makefile for:	avarice
# Date created:				13 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avarice
PORTVERSION=	2.0.20030403
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bsd
DISTNAME=	${PORTNAME}-${PORTVERSION}cvs

MAINTAINER=	bsd@FreeBSD.org
COMMENT=	Atmel AVR JTAG programmer and debugging interface for avr-gdb

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}cvs

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_PERL5_BUILD=	yes

.include <bsd.port.mk>
