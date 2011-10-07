# New ports collection makefile for:	devel/p5-MooseX-POE
# Date created:				27 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-POE
PORTVERSION=	0.214
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Illicit Love Child of Moose and POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Async>=0.01:${PORTSDIR}/devel/p5-MooseX-Async \
		p5-POE>=1.004:${PORTSDIR}/devel/p5-POE \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Simple>=0.89:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=	MooseX::POE.3 \
	MooseX::POE::Aliased.3 \
	MooseX::POE::Meta::Trait::Instance.3 \
	MooseX::POE::Meta::Trait::Class.3 \
	MooseX::POE::Meta::Method::State.3 \
	MooseX::POE::Meta::Trait::Object.3 \
	MooseX::POE::Meta::Role.3 \
	MooseX::POE::Meta::Trait.3 \
	MooseX::POE::Meta::Trait::SweetArgs.3 \
	MooseX::POE::Role.3 \
	MooseX::POE::SweetArgs.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
