# New ports collection makefile for:	databases/p5-AnyEvent-Redis
# Date created:				25 January 2011
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-Redis
PORTVERSION=	0.23
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/../../authors/id/D/DG/DGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	AnyEvent::Redis - Non-blocking Redis client

BUILD_DEPENDS=	p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-TCP>=1.03:${PORTSDIR}/devel/p5-Test-TCP \
		redis>=0:${PORTSDIR}/databases/redis

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::Redis.3 \
	AnyEvent::Redis::Protocol.3

.include <bsd.port.mk>
