# New ports collection makefile for:	MouseX::AttributeHelpers
# Date created:		14 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-AttributeHelpers
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to extend your attribute interfaces

RUN_DEPENDS=	\
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
	p5-Mouse>=0.37:${PORTSDIR}/devel/p5-Mouse
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MouseX::AttributeHelpers.3 \
	MouseX::AttributeHelpers::Base.3 \
	MouseX::AttributeHelpers::Bool.3 \
	MouseX::AttributeHelpers::Collection::Array.3 \
	MouseX::AttributeHelpers::Collection::Bag.3 \
	MouseX::AttributeHelpers::Collection::Hash.3 \
	MouseX::AttributeHelpers::Collection::ImmutableHash.3 \
	MouseX::AttributeHelpers::Collection::List.3 \
	MouseX::AttributeHelpers::Counter.3 \
	MouseX::AttributeHelpers::Number.3 \
	MouseX::AttributeHelpers::String.3

.include <bsd.port.mk>
