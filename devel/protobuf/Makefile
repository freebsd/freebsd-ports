# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	2.5.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Data interchange format library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig tar:bzip2 libtool:keepla
ONLY_FOR_ARCHS=	i386 amd64

# clang will generate code that just doesn't work with clementine-player
# if this isn't compiled as though it were C99.
CFLAGS+=	-std=c99 -DGOOGLE_PROTOBUF_NO_RTTI

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libprotobuf-lite.so.8
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libprotobuf.so.8
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libprotoc.so.8

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
