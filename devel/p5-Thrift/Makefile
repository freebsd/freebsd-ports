PORTNAME=	Thrift
PORTVERSION=	0.22.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKING/thrift
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to Thrift
WWW=		https://metacpan.org/dist/Thrift

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		cpe perl5
USE_PERL5=	configure

NO_ARCH=	yes

CPE_VENDOR=	apache

.include <bsd.port.mk>
