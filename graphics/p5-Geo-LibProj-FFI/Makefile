PORTNAME=	Geo-LibProj-FFI
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Foreign function interface to PROJ coordinate transformation software
WWW=		https://metacpan.org/dist/Geo-LibProj-FFI

LICENSE=	ART10 ART20 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	p5-Convert-Binary-C>=0.04:converters/p5-Convert-Binary-C \
		p5-Exporter-Easy>=0:devel/p5-Exporter-Easy \
		p5-FFI-C>=0.08:devel/p5-FFI-C \
		p5-FFI-Platypus>=1.50:devel/p5-FFI-Platypus
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warnings>=0.010:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/Geo/LibProj/FFI.pm
	@${RM} ${WRKSRC}/t/00-version.t

.include <bsd.port.mk>
