PORTNAME=	advancecomp
DISTVERSION=	2.3
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/amadvance/advancecomp/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@fuz.su
COMMENT=	Recompression utilities for .ZIP, .PNG, .MNG, and .GZ files

LICENSE=	GPLv3

LIB_DEPENDS=	libzopfli.so:archivers/zopfli \
		libdeflate.so:archivers/libdeflate

USES=		autoreconf cpe
CPE_VENDOR=	advancemame

GNU_CONFIGURE=	yes
TEST_TARGET=	check
MAKE_ARGS=	zopfli_SOURCES="" am__objects_3="" \
		libdeflate_SOURCES="" am__objects_2=""
CPPFLAGS+=	-I${LOCALBASE}/include/zopfli
LDFLAGS+=	-L${LOCALBASE}/lib -lzopfli -ldeflate

OPTIONS_DEFINE=	BZIP2
BZIP2_CONFIGURE_ON=	--enable-bzip2

pre-test-BZIP2-on:
	@${ECHO_MSG} Warning: test suite is known to fail with option BZIP2 enabled

.include <bsd.port.mk>
