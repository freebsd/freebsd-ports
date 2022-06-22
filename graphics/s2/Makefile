# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	s2
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	S2 Geometry Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libgtest.so:devel/googletest

USES=		cmake compiler:c++11-lang localbase ssl

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	WITH_PYTHON
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	google
GH_PROJECT=	s2geometry
USE_GITHUB=	yes

OPTIONS_DEFINE=	EXAMPLES GFLAGS GLOG
OPTIONS_DEFAULT=GFLAGS GLOG
GFLAGS_DESC=	Use gflags to change command line flags
GLOG_DESC=	Use glog for logging

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES
GFLAGS_CMAKE_BOOL=	WITH_GFLAGS
GFLAGS_LIB_DEPENDS=	libgflags.so:devel/gflags
GLOG_CMAKE_BOOL=	WITH_GLOG
GLOG_LIB_DEPENDS=	libglog.so:devel/glog

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 && !defined(CPUTYPE)
CXXFLAGS+=	-mcpu=power7
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point_index.cc ${WRKSRC}/doc/examples/term_index.cc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
