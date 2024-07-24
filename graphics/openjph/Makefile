PORTNAME=	openjph
PORTVERSION=	0.15.0
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source implementation of JPEG2000 Part-15
WWW=		https://github.com/aous72/OpenJPH

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang pathfix

CMAKE_OFF=	OJPH_BUILD_STREAM_EXPAND OJPH_BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS OJPH_BUILD_EXECUTABLES OJPH_ENABLE_TIFF_SUPPORT
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	aous72
GH_PROJECT=	OpenJPH
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} != amd64
CMAKE_ON+=	OJPH_DISABLE_SIMD
.endif

post-install:
	${LN} -s libopenjph.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopenjph.so.0

.include <bsd.port.mk>
