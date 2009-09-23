# New ports collection makefile for:	devel/p5-MooseX-Aliases
# Date created:				10 September 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Aliases
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	MooseX
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Easy aliasing of methods and attributes in Moose

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::Aliases.3 \
	MooseX::Aliases::Meta::Trait::Attribute.3 \
	MooseX::Aliases::Meta::Trait::Method.3

.include <bsd.port.mk>
