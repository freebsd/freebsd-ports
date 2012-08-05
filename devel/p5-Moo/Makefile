# New ports collection makefile for:	devel/p5-Moo
# Date created:				Feb 25, 2011
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Moo
PORTVERSION=	1.000002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSTROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Minimalist Object Orientation (with Moose compatibility)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=1.04:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-Devel-GlobalDestruction>=0.08:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Role-Tiny>=1.001.003:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-strictures>=1.001001:${PORTSDIR}/devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		Moo.3 \
		Moo::Role.3 \
		Sub::Defer.3 \
		Sub::Quote.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
