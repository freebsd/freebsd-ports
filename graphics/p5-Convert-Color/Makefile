# $FreeBSD$

PORTNAME=	Convert-Color
PORTVERSION=	0.09
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for color space conversions and named lookups

RUN_DEPENDS=	\
	p5-List-UtilsBy>0:${PORTSDIR}/devel/p5-List-UtilsBy
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
