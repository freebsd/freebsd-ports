# New ports collection makefile for:	devel/p5-MooseX-POE
# Date created:				27 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-POE
PORTVERSION=	0.202
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	The Illicit Love Child of Moose and POE

RUN_DEPENDS=	p5-Moose>=0.73:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Async>=0.01:${PORTSDIR}/devel/p5-MooseX-Async \
		p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::POE.3 \
	MooseX::POE::Aliased.3 \
	MooseX::POE::Meta::Trait::Instance.3 \
	MooseX::POE::Meta::Trait::Object.3 \
	MooseX::POE::Role.3 \
	MooseX::POE::SweetArgs.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
