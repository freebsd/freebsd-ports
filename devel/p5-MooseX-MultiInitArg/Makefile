# New ports collection makefile for:    MooseX-MultiInitArg
# Date created:                         31 July 2009
# Whom:                                 Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	MooseX-MultiInitArg
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Attributes with aliases for constructor arguments for MooseX

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::MultiInitArg.3 \
		MooseX::MultiInitArg::Trait.3 \
		MooseX::MultiInitArg::Attribute.3

.include <bsd.port.mk>
