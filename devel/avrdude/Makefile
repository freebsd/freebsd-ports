# New ports collection makefile for:	avrdude
# Date created:				8 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avrdude
PORTVERSION=	4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.0.0/
MASTER_SITE_SUBDIR=	bsd

MAINTAINER=	bsd@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

MAN1=		avrdude.1
MANCOMPRESSED=	no

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-versioned-doc

.include <bsd.port.mk>
