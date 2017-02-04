# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	Event-Lib
PORTVERSION=	1.03
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Makes libevent(3) accessible with Perl

LIB_DEPENDS=	libevent.so:devel/libevent2

BROKEN=		fails to build with libevent 2.1

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
