# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	B-Hooks-Parser
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to perls parser variables

BUILD_DEPENDS=	p5-B-Hooks-OP-Check>=0:${PORTSDIR}/devel/p5-B-Hooks-OP-Check \
		p5-ExtUtils-Depends>=0.302:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS=	p5-B-Hooks-OP-Check>=0:${PORTSDIR}/devel/p5-B-Hooks-OP-Check
TEST_DEPENDS=	p5-B-Hooks-EndOfScope>=0.05:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
