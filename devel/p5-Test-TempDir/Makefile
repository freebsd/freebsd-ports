# Created by: chinsan
# $FreeBSD$

PORTNAME=	Test-TempDir
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Temporary files support for testing

BUILD_DEPENDS=	p5-Directory-Scratch>=0:${PORTSDIR}/devel/p5-Directory-Scratch \
		p5-File-NFSLock>=0:${PORTSDIR}/devel/p5-File-NFSLock \
		p5-Moose>=0.87:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-CheckDeps>=0.007:${PORTSDIR}/devel/p5-Test-CheckDeps \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
