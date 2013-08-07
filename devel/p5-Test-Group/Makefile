# $FreeBSD$

PORTNAME=	Test-Group
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Group together related tests in a test suite

BUILD_DEPENDS=	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Cmd>=0:${PORTSDIR}/devel/p5-Test-Cmd
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Test::Group.3 \
		Test::Group::Extending.3 \
		Test::Group::NoWarnings.3 \
		Test::Group::Plan.3 \
		Test::Group::Tester.3

.include <bsd.port.mk>
