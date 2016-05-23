# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBICx-MapMaker
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl 5 module to automatically create a DBIx::Class mapping table

RUN_DEPENDS=	p5-Moose>=0.39:devel/p5-Moose
BUILD_DEPENDS=	p5-DBIx-Class>=0.07003:databases/p5-DBIx-Class \
		p5-DBICx-TestDatabase>=0.02:databases/p5-DBICx-TestDatabase \
		p5-Moose>=0.39:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
