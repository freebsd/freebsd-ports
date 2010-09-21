# New ports collection makefile for:	p5-Data-Throttler-Memcached
# Date created:		2008-01-30
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Data-Throttler-Memcached
PORTVERSION=	0.00003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Memcached-Based Data::Throttler

BUILD_DEPENDS=	p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler
RUN_DEPENDS=	p5-Cache-Memcached-Managed>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Managed \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler

PERL_CONFIGURE=	yes

MAN3=		Data::Throttler::Memcached.3 \
		Data::Throttler::BucketChain::Memcached.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
