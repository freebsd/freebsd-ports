# New ports collection makefile for:	MouseX::Getopt
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MouseX-Getopt
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MA/MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for a Mouse role to process command line options

RUN_DEPENDS=	\
	p5-Mouse>=0.20:${PORTSDIR}/devel/p5-Mouse
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MouseX::Getopt.3 \
		MouseX::Getopt::Meta::Attribute::Getopt.3 \
		MouseX::Getopt::Meta::Attribute::NoGetopt.3 \
		MouseX::Getopt::OptionTypeMap.3 \
		MouseX::Getopt::Strict.3

.include <bsd.port.mk>
