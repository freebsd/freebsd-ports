# New ports collection makefile for:	Event-Lib
# Date created:				07 Jun 2006
# Whom:					Fabian Keil <fk@fabiankeil.de>
#
# $FreeBSD$
#

PORTNAME=	Event-Lib
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Makes libevent(3) accessible with Perl

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

PERL_CONFIGURE=	yes

MAN3=		Event::Lib.3

.include <bsd.port.mk>
