# Created by: Brian Dean <bsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avarice
PORTVERSION=	2.14
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Atmel AVR JTAG programmer and debugging interface for avr-gdb

LICENSE=	GPLv2

USES=		compiler:c11 perl5 tar:bzip2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_pathperl=${PERL}

.include <bsd.port.mk>
