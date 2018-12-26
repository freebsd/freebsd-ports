# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snappy
PORTVERSION=	1.1.6
CATEGORIES=	archivers

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Fast compressor/decompressor library

LICENSE=	BSD3CLAUSE

USES=		autoreconf compiler:c++11-lang libtool pathfix pkgconfig
CONFIGURE_ARGS=	--disable-gtest
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-DNDEBUG
USE_GITHUB=	yes
GH_ACCOUNT=	google
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libsnappy.so.1.1.6

.include <bsd.port.mk>
