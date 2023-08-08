PORTNAME=	msgpack
PORTVERSION=	6.1.0
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel
PKGNAMESUFFIX=	-cxx

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Efficient binary serialization protocol (C++ version)
WWW=		https://msgpack.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake pathfix
USE_GITHUB=	yes
GH_PROJECT=	msgpack-c
NO_ARCH=	yes

CMAKE_OFF=	MSGPACK_BUILD_EXAMPLES MSGPACK_USE_BOOST

# Link to original cmake files because upstream keeps changing its name.
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/msgpackc-cxx
.for tgt in config-version config targets
	${LN} -sf ../msgpack-cxx/msgpack-cxx-${tgt}.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/msgpackc-cxx/msgpackc-cxx-${tgt}.cmake
	${LN} -sf ../msgpack-cxx/msgpack-cxx-${tgt}.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/msgpackc-cxx/msgpack-cxx-${tgt}.cmake
.endfor

.include <bsd.port.mk>
