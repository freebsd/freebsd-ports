# $FreeBSD$

PORTNAME=	libbigwig
DISTVERSION=	0.4.6
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for handling bigWig files (containing genomic data)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dpryan79
GH_PROJECT=	libBigWig

MAKE_ARGS=	LDFLAGS=-L${LOCALBASE}/lib

PLIST_FILES=	include/bigWig.h \
		include/bigWigIO.h \
		include/bwCommon.h \
		include/bwValues.h \
		lib/libBigWig.a \
		lib/libBigWig.so

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libBigWig.so

.include <bsd.port.mk>
