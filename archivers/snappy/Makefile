# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snappy
PORTVERSION=	1.1.6
CATEGORIES=	archivers

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Fast compressor/decompressor library

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

USES=		autoreconf libtool pathfix pkgconfig
CONFIGURE_ARGS=	--disable-gtest
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-DNDEBUG
USE_GITHUB=	yes
GH_ACCOUNT=	google

BROKEN_sparc64=	Does not compile on sparc64

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libsnappy.so.1.1.6

.include <bsd.port.mk>
