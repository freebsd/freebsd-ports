# New ports collection makefile for:	devel/p5-MooseX-Getopt
# Date created:				28 Jul 2008
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Getopt
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Moose role for processing command line options

RUN_DEPENDS=	p5-Moose>=0.56:${PORTSDIR}/devel/p5-Moose \
		p5-Getopt-Long>=2.37:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Getopt-Long-Descriptive>=0:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	MooseX::Getopt.3 \
	MooseX::Getopt::Dashes.3 \
	MooseX::Getopt::Meta::Attribute.3 \
	MooseX::Getopt::Meta::Attribute::NoGetopt.3 \
	MooseX::Getopt::Meta::Attribute::Trait.3 \
	MooseX::Getopt::Meta::Attribute::Trait::NoGetopt.3 \
	MooseX::Getopt::OptionTypeMap.3 \
	MooseX::Getopt::Strict.3

post-extract:
	@${PERL} -i -ne 'print unless m,build_requires,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
