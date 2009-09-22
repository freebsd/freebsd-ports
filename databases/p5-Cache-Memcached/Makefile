# New ports collection makefile for:	p5-Cache-Memcached
# Date created:		2004-04-15
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached
PORTVERSION=	1.27
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN \
		http://www.danga.com/memcached/dist/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl API for memcached, a distributed memory cache daemon

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32

PERL_CONFIGURE=	yes

MAN3=	Cache::Memcached.3

.include <bsd.port.mk>
