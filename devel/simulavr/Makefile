# Ports collection makefile for:	simulavr
# Date created:				3 Sep 2002
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	simulavr
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A simulator for AVR microcontrollers

BUILD_DEPENDS=	${LOCALBASE}/avr/include/avr/io.h:${PORTSDIR}/devel/avr-libc \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-versioned-doc

.include <bsd.port.mk>
