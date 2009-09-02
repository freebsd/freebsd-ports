# New ports collection makefile for:	graphics/p5-Color-Palette
# Date created:				02 September 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Color-Palette
PORTVERSION=	0.091400
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Color
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Handle sets of named colors in Perl

BUILD_DEPENDS=	p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Graphics-Color>=0.21:${PORTSDIR}/graphics/p5-Graphics-Color \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose.pm>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Color::Palette.3 \
	Color::Palette::Schema.3 \
	Color::Palette::Types.3

.include <bsd.port.mk>
