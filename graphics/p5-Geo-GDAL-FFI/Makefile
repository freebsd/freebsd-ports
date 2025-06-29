PORTNAME=	Geo-GDAL-FFI
PORTVERSION=	0.13
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Foreign function interface to GDAL
WWW=		https://metacpan.org/release/Geo-GDAL-FFI

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgdal.so:graphics/gdal
RUN_DEPENDS=	p5-FFI-Platypus>=0:devel/p5-FFI-Platypus \
		p5-PDL>=0:math/p5-PDL \
		p5-PkgConfig>=0.23026:devel/p5-PkgConfig \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-TempDir-Tiny>=0:devel/p5-Test-TempDir-Tiny

USES=		dos2unix perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	skipv:0.0501,0.0502,0.0503,0.0601

.include <bsd.port.mk>
