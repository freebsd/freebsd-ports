# New ports collection makefile for:	devel/p5-Test-TempDir
# Date created:				2008/09/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Test-TempDir
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Temporary files support for testing

RUN_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
  		p5-File-Path>=0:${PORTSDIR}/devel/p5-File-Path \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-File-NFSLock>=0:${PORTSDIR}/devel/p5-File-NFSLock \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types-Path-Class>=0:${PORTSDIR}/devel/p5-MooseX-Types-Path-Class \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::TempDir.3 Test::TempDir::Factory.3 Test::TempDir::Handle.3

.include <bsd.port.mk>
