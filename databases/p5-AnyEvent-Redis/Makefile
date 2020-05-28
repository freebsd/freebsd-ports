# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-Redis
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Non-blocking Redis client written in Perl

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-AnyEvent>=0:devel/p5-AnyEvent
TEST_DEPENDS=	p5-Test-Simple>=0.88:devel/p5-Test-Simple \
		p5-Test-TCP>=1.03:devel/p5-Test-TCP \
		redis>=0:databases/redis

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
