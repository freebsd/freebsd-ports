PORTNAME=	msgpack
PORTVERSION=	6.1.0
DISTVERSIONPREFIX=	c-
CATEGORIES=	devel
PKGNAMESUFFIX=	-c

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Efficient binary serialization, like JSON but smaller and faster
WWW=		https://msgpack.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

TEST_DEPENDS=	googletest>0:devel/googletest \
		libcjson>0:devel/libcjson

USES=		cmake pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_PROJECT=	msgpack-c

CMAKE_OFF=	MSGPACK_BUILD_EXAMPLES MSGPACK_BUILD_TESTS
TEST_TARGET=	test

.include <bsd.port.pre.mk>

pre-test:
	cd ${WRKSRC} && ${CMAKE_BIN} . && ${MAKE_CMD}

# msgpack keeps changing its name and I'm over it. Link from the old filenames
# until upstream makes up its mind.
post-install:
	${LN} -sf msgpack-c.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/msgpack.pc
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/msgpackc
.for tgt in config-version config targets-${CMAKE_BUILD_TYPE:tl} targets
	${LN} -sf ../msgpack-c/msgpack-c-${tgt}.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/msgpackc/msgpackc-${tgt}.cmake
.endfor
.for ext in a so so.2 so.2.0.0
	${LN} -sf libmsgpack-c.${ext} ${STAGEDIR}${PREFIX}/lib/libmsgpackc.${ext}
.endfor

.include <bsd.port.post.mk>
