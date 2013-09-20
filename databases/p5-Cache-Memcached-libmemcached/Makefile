# Created by: Dmitry Liakh <dliakh@ukr.net>
# $FreeBSD$

PORTNAME=	Cache-Memcached-libmemcached
PORTVERSION=	0.02011
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dliakh@ukr.net
COMMENT=	Cache::Memcached compatible interface to libmemcached

BUILD_DEPENDS=	p5-Memcached-libmemcached>=0.42.01:${PORTSDIR}/databases/p5-Memcached-libmemcached \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Cache::Memcached::libmemcached.3

NO_STAGE=	yes
.include <bsd.port.mk>
