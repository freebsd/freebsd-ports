PORTNAME=	Geo-GDAL-FFI
PORTVERSION=	0.09
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Foreign function interface to GDAL

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgdal.so:graphics/gdal
RUN_DEPENDS=	p5-FFI-Platypus>=0:devel/p5-FFI-Platypus \
		p5-FFI-Platypus-Declare>=0:devel/p5-FFI-Platypus-Declare \
		p5-PkgConfig>=0.23026:devel/p5-PkgConfig \
		PDL>=0:math/PDL
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/Geo/GDAL/FFI.pm

.include <bsd.port.mk>
