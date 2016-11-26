# $FreeBSD$

PORTNAME=	RedisDB
PORTVERSION=	2.53
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to access redis database

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-RedisDB-Parser>=2.21:databases/p5-RedisDB-Parser \
	p5-Try-Tiny>0:lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
