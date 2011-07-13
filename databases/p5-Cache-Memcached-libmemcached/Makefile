# New ports collection makefile for:	p5-Cache-Memcached-libmemcached
# Date created:		Jun 06 2011
# Whom:			Dmitry Liakh <dliakh@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-libmemcached
PORTVERSION=	0.02011
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dliakh@ukr.net
COMMENT=	Cache::Memcached compatible interface to libmemcached

RUN_DEPENDS=	p5-Memcached-libmemcached>=0.42.01:${PORTSDIR}/databases/p5-Memcached-libmemcached \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken

PERL_CONFIGURE=	yes

MAN3=		Cache::Memcached::libmemcached.3

.include <bsd.port.mk>
