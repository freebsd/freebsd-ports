PORTNAME=	libbigwig
DISTVERSION=	0.4.7
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for handling bigWig files (containing genomic data)
WWW=		https://github.com/dpryan79/libBigWig

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:testing localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dpryan79
GH_PROJECT=	libBigWig

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	ENABLE_TESTING # unclear how to run tests, see https://github.com/dpryan79/libBigWig/issues/63
CMAKE_TESTING_TARGET=

PLIST_FILES=	include/libbigwig/bigWig.h \
		include/libbigwig/bigWigIO.h \
		include/libbigwig/bwCommon.h \
		include/libbigwig/bwValues.h \
		lib/libBigWig.so

.include <bsd.port.mk>
