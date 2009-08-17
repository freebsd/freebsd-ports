# New ports collection makefile for:	MooseX-LazyRequire
# Date created:	   17 Aug 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-LazyRequire
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Required attributes which fail only when trying to use them

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::LazyRequire.3 \
		MooseX::LazyRequire::Meta::Attribute::Trait::LazyRequire.3

.include <bsd.port.mk>
