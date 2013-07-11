# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-MultiInitArg
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Attributes with aliases for constructor arguments for MooseX

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Module-Build-Tiny>=0.023:${PORTSDIR}/devel/p5-Module-Build-Tiny

PERL_MODBUILD=	yes

MAN3=		MooseX::MultiInitArg.3 \
		MooseX::MultiInitArg::Trait.3 \
		MooseX::MultiInitArg::Attribute.3

.include <bsd.port.mk>
