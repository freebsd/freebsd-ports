# New ports collection makefile for:	p5-MooseX-StrictConstructor
# Date created:		2008-10-23
# Whom:			glarkin
#
# $FreeBSD$
#

PORTNAME=	MooseX-StrictConstructor
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Make your MooseX object constructors blow up on unknown attributes

RUN_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple \
		${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::StrictConstructor.3 \
		MooseX::StrictConstructor::Role::Meta::Method::Constructor.3 \
		MooseX::StrictConstructor::Role::Object.3

.include <bsd.port.mk>
