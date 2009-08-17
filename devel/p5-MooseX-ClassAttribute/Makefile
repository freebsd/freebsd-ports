# New ports collection makefile for:	MooseX-ClassAttribute
# Date created:	   07 Jun 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-ClassAttribute
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Declare class attributes Moose-style

BUILD_DEPENDS=	p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.13:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MooseX::ClassAttribute.3 \
		MooseX::ClassAttribute::Meta::Method::Accessor.3 \
		MooseX::ClassAttribute::Role::Meta::Attribute.3 \
		MooseX::ClassAttribute::Role::Meta::Class.3

.include <bsd.port.mk>
