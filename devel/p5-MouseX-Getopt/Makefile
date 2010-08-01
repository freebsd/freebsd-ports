# New ports collection makefile for:	MouseX::Getopt
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Getopt
PORTVERSION=	${DISTVERSION}00
DISTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TO/TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for a Mouse role to process command line options

RUN_DEPENDS=	\
	p5-Mouse>=0.64:${PORTSDIR}/devel/p5-Mouse \
	p5-Getopt-Long-Descriptive>=0.081:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MouseX::Getopt.3 \
		MouseX::Getopt::Basic.3 \
		MouseX::Getopt::Dashes.3 \
		MouseX::Getopt::GLD.3 \
		MouseX::Getopt::Meta::Attribute.3 \
		MouseX::Getopt::Meta::Attribute::NoGetopt.3 \
		MouseX::Getopt::Meta::Attribute::Trait.3 \
		MouseX::Getopt::Meta::Attribute::Trait::NoGetopt.3 \
		MouseX::Getopt::OptionTypeMap.3 \
		MouseX::Getopt::Strict.3

.include <bsd.port.mk>
