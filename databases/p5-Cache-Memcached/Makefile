# New ports collection makefile for:	p5-Cache-Memcached
# Date created:		2004-04-15
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached
PORTVERSION=	1.14
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.danga.com/memcached/dist/
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl API for memcached, a distributed memory cache daemon

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32 \
		memcached:${PORTSDIR}/databases/memcached

PERL_CONFIGURE=	yes

MAN3=	Cache::Memcached.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.if ${PERL_LEVEL} <= 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
