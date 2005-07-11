# New ports collection makefile for:	p5-Algorithm-Bucketizer
# Date created:				06 Jul 2005
# Whom:				Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Bucketizer
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	boumenot@gmail.com
COMMENT=	Distribute sized items to buckets with limited size

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Algorithm/Permute.pm:${PORTSDIR}/devel/p5-Algorithm-Permute
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Algorithm::Bucketizer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8.0 or superior. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
