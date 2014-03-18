# $FreeBSD$

PORTNAME=	RedisDB
PORTVERSION=	2.30
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to access redis database

RUN_DEPENDS=	\
	p5-RedisDB-Parser>=2.2:${PORTSDIR}/databases/p5-RedisDB-Parser \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
