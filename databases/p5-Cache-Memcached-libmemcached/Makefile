PORTNAME=	Cache-Memcached-libmemcached
PORTVERSION=	0.02011
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dliakh@ukr.net
COMMENT=	Cache::Memcached compatible interface to libmemcached

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Memcached-libmemcached>=0.42.01:databases/p5-Memcached-libmemcached \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
