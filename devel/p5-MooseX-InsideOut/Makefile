# New ports collection makefile for:  MooseX-InsideOut
# Whom: gugu
# Date created: 03 December 2009
# $FreeBSD$
# Generated with portupload. Do not edit directly, please

PORTNAME=	MooseX-InsideOut
PORTVERSION=	0.104
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Inside-out objects with Moose

BUILD_DEPENDS=	p5-Class-MOP>=0.80:${PORTSDIR}/devel/p5-Class-MOP \
		p5-Hash-Util-FieldHash-Compat>=0:${PORTSDIR}/devel/p5-Hash-Util-FieldHash-Compat \
		p5-Moose>=0.73:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-clean>=0.11:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		MooseX::InsideOut.3 \
		MooseX::InsideOut::Role::Meta::Instance.3

.include <bsd.port.mk>
