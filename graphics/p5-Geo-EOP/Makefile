PORTNAME=	Geo-EOP
DISTVERSION=	0.50
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Process Earth Observation Products Meta-data
WWW=		https://metacpan.org/release/MARKOV/Geo-EOP-0.50

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	p5-Geo-GML>=0.13:graphics/p5-Geo-GML \
		p5-XML-Compile>=1.50:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.14:textproc/p5-XML-Compile-Cache
TEST_DEPENDS=	p5-Test-Pod>=1.26:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
