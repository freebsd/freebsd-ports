# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-Compare
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compare two images in a variety of ways

RUN_DEPENDS=	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common
BUILD_DEPENDS:=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		Image::Compare.3 \
		Image::Compare::AVG_THRESHOLD.3 \
		Image::Compare::Comparator.3 \
		Image::Compare::EXACT.3 \
		Image::Compare::IMAGE.3 \
		Image::Compare::THRESHOLD.3 \
		Image::Compare::THRESHOLD_COUNT.3

.include <bsd.port.mk>
