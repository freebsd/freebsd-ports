# $FreeBSD$

PORTNAME=	Sereal
PORTVERSION=	3.014
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary (de-)serialization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Sereal-Decoder>=3.007:converters/p5-Sereal-Decoder \
	p5-Sereal-Encoder>=3.007:converters/p5-Sereal-Encoder
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Deep>=0:devel/p5-Test-Deep \
	p5-Test-LongString>=0:devel/p5-Test-LongString \
	p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
