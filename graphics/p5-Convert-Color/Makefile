# New ports collection makefile for:	Convert::Color
# Date created:		26 Feb 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Convert-Color
PORTVERSION=	0.07
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for color space conversions and named lookups

RUN_DEPENDS=	\
	p5-List-UtilsBy>0:${PORTSDIR}/devel/p5-List-UtilsBy
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Convert::Color.3 \
	Convert::Color::CMY.3 \
	Convert::Color::CMYK.3 \
	Convert::Color::HSL.3 \
	Convert::Color::HSV.3 \
	Convert::Color::RGB.3 \
	Convert::Color::RGB16.3 \
	Convert::Color::RGB8.3 \
	Convert::Color::VGA.3 \
	Convert::Color::X11.3

.include <bsd.port.mk>
