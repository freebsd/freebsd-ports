# $FreeBSD$

PORTNAME=	DBIx-Class-DeploymentHandler
PORTVERSION=	0.002218
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for extensible DBIx::Class deployment

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Carp-Clan>0:devel/p5-Carp-Clan \
	p5-Context-Preserve>0:devel/p5-Context-Preserve \
	p5-DBIx-Class>=0.08121:databases/p5-DBIx-Class \
	p5-Log-Contextual>=0.005005:devel/p5-Log-Contextual \
	p5-Method-Signatures-Simple>=0.05:devel/p5-Method-Signatures-Simple \
	p5-Moo>=1.003:devel/p5-Moo \
	p5-Moose>=1.0:devel/p5-Moose \
	p5-MooseX-Role-Parameterized>=0.18:devel/p5-MooseX-Role-Parameterized \
	p5-SQL-Translator>=0.11005:databases/p5-SQL-Translator \
	p5-Sub-Exporter-Progressive>0:devel/p5-Sub-Exporter-Progressive \
	p5-Text-Brew>=0.02:textproc/p5-Text-Brew \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-namespace-autoclean>0:devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
