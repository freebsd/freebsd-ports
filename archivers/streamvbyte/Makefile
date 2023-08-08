PORTNAME=	streamvbyte
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Integer compression with SIMD based on Google's varint
WWW=		https://github.com/lemire/streamvbyte

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# From 0.5.2.  Retest with 1.0.0.
BROKEN_powerpc=		test fails on big-endian systems
BROKEN_powerpc64=	test fails on big-endian systems

USES=		cmake
USE_GITHUB=	yes

GH_ACCOUNT=	lemire

CFLAGS+=	-fPIC	# For vbz-compression using static lib

PLIST_FILES=	include/streamvbyte.h include/streamvbyte_zigzag.h \
		include/streamvbytedelta.h lib/libstreamvbyte.a

do-test:
	cd ${WRKDIR}/.build && ./unit

.include <bsd.port.mk>
