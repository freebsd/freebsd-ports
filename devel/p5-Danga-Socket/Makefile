# New ports collection makefile for:	p5-Danga-Socket
# Date created:		2005-08-08
# Whom:			Jacques Marneweck <jacques@php.net>
#
# $FreeBSD$
#

PORTNAME=	Danga-Socket
PORTVERSION=	1.56
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Danga
PKGNAMEPREFIX=	p5-

MAINTAINER=	jacques@php.net
COMMENT=	Event loop and event-driven async socket base class

BUILD_DEPENDS=	${SITE_PERL}/Sys/Syscall.pm:${PORTSDIR}/devel/p5-Sys-Syscall

PERL_CONFIGURE=	yes

MAN3=	Danga::Socket.3

.include <bsd.port.mk>
