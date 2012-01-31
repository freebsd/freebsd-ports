# New ports collection makefile for:	p5-Test-Spec
# Date created:		2011-09-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Spec
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write tests in a declarative specification style

BUILD_DEPENDS=	p5-Package-Stash>=0.23:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Test-Deep>=0.103:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	p5-Package-Stash>=0.23:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Test-Deep>=0.103:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

PERL_CONFIGURE=	yes

MAN3=		Test::Spec.3 \
		Test::Spec::Mocks.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	Test-Harness>=0:${PORTSDIR}/devel/p5-Test-Harness
.endif

.include <bsd.port.post.mk>
