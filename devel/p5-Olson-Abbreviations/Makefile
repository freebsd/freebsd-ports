# New ports collection makefile for:	devel/p5-Olson-Abbreviations
# Date created:				23 Jun 2009
# Whom:					Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Olson-Abbreviations
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/E/EC/ECARROLL
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Globally unique timezones abbreviation handling

RUN_DEPENDS=	p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-ClassAttribute>=0:${PORTSDIR}/devel/p5-MooseX-ClassAttribute
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Olson::Abbreviations.3

.include <bsd.port.mk>
