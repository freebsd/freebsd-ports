# New ports collection makefile for:	MooseX-Types-Structured
# Date created:	   11 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Structured
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Moose Type Constraint classes for Structured Types

BUILD_DEPENDS=	p5-Moose>=0.63:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.08:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Devel-PartialDump>=0.07:${PORTSDIR}/devel/p5-Devel-PartialDump \
		p5-Sub-Exporter>=0.982:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Meta::TypeCoercion::Structured.3 \
		MooseX::Meta::TypeConstraint::Structured.3 \
		MooseX::Types::Structured.3

post-patch:
	@${REINPLACE_CMD} -e '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
