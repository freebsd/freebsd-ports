# New ports collection makefile for:	Data-Visitor
# Date created:		26 Mar 2006
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Visitor
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Visitor style traversal of Perl data structures

BUILD_DEPENDS=	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
		p5-Moose>=0.89:${PORTSDIR}/devel/p5-Moose \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Tie-ToObject>=0.01:${PORTSDIR}/devel/p5-Tie-ToObject \
		p5-namespace-clean>=0.19:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Data-Alias>=0:${PORTSDIR}/devel/p5-Data-Alias \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=	Data::Visitor.3 \
	Data::Visitor::Callback.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
