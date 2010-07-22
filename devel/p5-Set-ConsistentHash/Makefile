# New ports collection makefile for:	p5-Set-ConsistentHash
# Date created:		2008-01-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Set-ConsistentHash
PORTVERSION=	0.92
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for doing consistent hashing

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

PERL_CONFIGURE=	yes

MAN3=		Set::ConsistentHash.3

.include <bsd.port.mk>
