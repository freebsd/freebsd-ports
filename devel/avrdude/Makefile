# New ports collection makefile for:	avrdude
# Date created:				8 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avrdude
PORTVERSION=	4.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bsd@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

BUILD_DEPENDS=	pdftex:${PORTSDIR}/print/teTeX

MAN1=		avrdude.1
MANCOMPRESSED=	no

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-versioned-doc

.include <bsd.port.mk>
