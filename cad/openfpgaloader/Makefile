# $FreeBSD$

PORTNAME=	openfpgaloader
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal utility for programming FPGA

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	trabucayre
GH_PROJECT=	openFPGALoader

PLIST_FILES=	bin/openFPGALoader \
		share/openFPGALoader/test_sfl.svf \
		share/openFPGALoader/spiOverJtag_xc7a100.bit \
		share/openFPGALoader/spiOverJtag_xc7a200.bit \
		share/openFPGALoader/spiOverJtag_xc7a35.bit \
		share/openFPGALoader/spiOverJtag_xc7a50t.bit \
		share/openFPGALoader/spiOverJtag_xc7s50.bit

.include <bsd.port.mk>
