# New ports collection makefile for:	p5-Algorithm-Bucketizer
# Date created:				06 Jul 2005
# Whom:				Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-Bucketizer
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distribute sized items to buckets with limited size

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Algorithm/Permute.pm:${PORTSDIR}/devel/p5-Algorithm-Permute
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		bucketize.1
MAN3=		Algorithm::Bucketizer.3

.include <bsd.port.mk>
