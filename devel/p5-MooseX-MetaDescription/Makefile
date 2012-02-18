# New ports collection makefile for:	p5-MooseX-MetaDescription
# Date created:		2011-05-31
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-MetaDescription
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A framework for adding additional metadata to Moose classes

RUN_DEPENDS=	p5-Moose>=0.4:${PORTSDIR}/devel/p5-Moose
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		MooseX::MetaDescription.3 \
		MooseX::MetaDescription::Description.3 \
		MooseX::MetaDescription::Meta::Attribute.3 \
		MooseX::MetaDescription::Meta::Class.3 \
		MooseX::MetaDescription::Meta::Trait.3

.include <bsd.port.mk>
