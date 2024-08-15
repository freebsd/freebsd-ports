PORTNAME=	s2
PORTVERSION=	0.11.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	S2 Geometry Library
WWW=		https://s2geometry.io/ \
		https://github.com/google/s2geometry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake compiler:c++17-lang localbase ssl

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_OFF=	BUILD_TESTS S2_USE_SYSTEM_INCLUDES WITH_PYTHON
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	google
GH_PROJECT=	s2geometry
USE_GITHUB=	yes

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 && !defined(CPUTYPE)
CXXFLAGS+=	-mcpu=power7
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point_index.cc ${WRKSRC}/doc/examples/term_index.cc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
