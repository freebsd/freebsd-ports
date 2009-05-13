# New ports collection makefile for:	MooseX-MethodAttributes
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-MethodAttributes
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Code attribute introspection

BUILD_DEPENDS=	p5-Moose>=0.70:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.06:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::MethodAttributes.3 \
		MooseX::MethodAttributes::Inheritable.3 \
		MooseX::MethodAttributes::Role::AttrContainer.3 \
		MooseX::MethodAttributes::Role::AttrContainer::Inheritable.3 \
		MooseX::MethodAttributes::Role::Meta::Class.3 \
		MooseX::MethodAttributes::Role::Meta::Method.3 \
		MooseX::MethodAttributes::Role::Meta::Method::MaybeWrapped.3 \
		MooseX::MethodAttributes::Role::Meta::Method::Wrapped.3

.include <bsd.port.mk>
