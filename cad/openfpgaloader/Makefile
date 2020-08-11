# $FreeBSD$

PORTNAME=	openfpgaloader
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal utility for programming FPGA

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libftdi1.so:devel/libftdi1 \
		libudev.so:devel/libudev-devd

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	trabucayre
GH_PROJECT=	openFPGALoader

PLIST_FILES=	bin/openFPGALoader \
		share/openFPGALoader/spiOverJtag_xc7a35.bit \
		share/openFPGALoader/test_sfl.svf

.include <bsd.port.mk>
