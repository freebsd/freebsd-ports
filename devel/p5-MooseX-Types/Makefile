# New ports collection makefile for:	devel/p5-MooseX-Types
# Date created:				28 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Organise your Moose types in libraries

RUN_DEPENDS=	p5-Moose>=0.24:${PORTSDIR}/devel/p5-Moose \
		p5-Sub-Uplevel>=0.14:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-Sub-Install>=0.922:${PORTSDIR}/devel/p5-Sub-Install \
		p5-namespace-clean>=0.04:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::Types.3 \
	MooseX::Types::Base.3 \
	MooseX::Types::Moose.3 \
	MooseX::Types::UndefinedType.3 \
	MooseX::Types::Util.3 \
	MooseX::Types::Wrapper.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
