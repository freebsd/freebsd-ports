# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Color-Palette
PORTVERSION=	0.100002
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Color
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Handle sets of named colors in Perl

BUILD_DEPENDS=	p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Graphics-Color>=0.21:${PORTSDIR}/graphics/p5-Graphics-Color \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=	Color::Palette.3 \
	Color::Palette::Schema.3 \
	Color::Palette::Types.3

NO_STAGE=	yes
.include <bsd.port.mk>
