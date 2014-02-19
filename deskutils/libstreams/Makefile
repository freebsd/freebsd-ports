# $FreeBSD$

PORTNAME=	libstreams
PORTVERSION=	${STRIGI_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${STRIGI_MASTER_SITES}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi desktop search: streams library

USES=		iconv
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e \
		's,$${LIB_DESTINATION}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/libstreams/CMakeLists.txt

.include <${.CURDIR}/../strigi/Makefile.common>
.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CMAKE_ARGS+=	-DICONV_LIBRARIES:STRING="/usr/lib/libc.so"
.endif

.include <bsd.port.post.mk>
