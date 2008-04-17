# New ports collection makefile for:	p5-Danga-Socket
# Date created:		2005-08-08
# Whom:			Jacques Marneweck <jacques@php.net>
#
# $FreeBSD$
#

PORTNAME=	Danga-Socket
PORTVERSION=	1.57
CATEGORIES=	devel net
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Event loop and event-driven async socket base class

BUILD_DEPENDS=	${SITE_PERL}/Sys/Syscall.pm:${PORTSDIR}/devel/p5-Sys-Syscall \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/IO/KQueue.pm:${PORTSDIR}/devel/p5-IO-KQueue \
		${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Danga::Socket.3

.include <bsd.port.mk>
