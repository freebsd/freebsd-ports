# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	s2
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	S2 Geometry Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	is currently 64-bit only

LIB_DEPENDS=	libgtest.so:devel/googletest

USES=		cmake compiler:c++11-lang localbase ssl

CMAKE_ON=	BUILD_SHARED_LIBS
CXXFLAGS_powerpc64=	-mcpu=power7
USE_LDCONFIG=	yes

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

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/examples/point_index ${INSTALL_WRKSRC}/examples/term_index ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/point_index.cc ${WRKSRC}/doc/examples/term_index.cc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
