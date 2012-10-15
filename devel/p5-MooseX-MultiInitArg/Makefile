# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	MooseX-MultiInitArg
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Attributes with aliases for constructor arguments for MooseX

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::MultiInitArg.3 \
		MooseX::MultiInitArg::Trait.3 \
		MooseX::MultiInitArg::Attribute.3

.include <bsd.port.mk>
