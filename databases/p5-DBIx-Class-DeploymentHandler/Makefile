# $FreeBSD$

PORTNAME=	DBIx-Class-DeploymentHandler
PORTVERSION=	0.002208
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for extensible DBIx::Class deployment

RUN_DEPENDS=	\
	p5-Carp-Clan>0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-Context-Preserve>0:${PORTSDIR}/devel/p5-Context-Preserve \
	p5-DBIx-Class>=0.08121:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-Log-Contextual>=0.005005:${PORTSDIR}/devel/p5-Log-Contextual \
	p5-Method-Signatures-Simple>=0.05:${PORTSDIR}/devel/p5-Method-Signatures-Simple \
	p5-Moo>=1.003:${PORTSDIR}/devel/p5-Moo \
	p5-Moose>=1.0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Role-Parameterized>=0.18:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
	p5-SQL-Translator>=0.11005:${PORTSDIR}/databases/p5-SQL-Translator \
	p5-Sub-Exporter-Progressive>0:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive \
	p5-Text-Brew>=0.02:${PORTSDIR}/textproc/p5-Text-Brew \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-parent>=0.225:${PORTSDIR}/devel/p5-parent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
