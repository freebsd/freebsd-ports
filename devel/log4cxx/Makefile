PORTNAME=	log4cxx
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	https://archive.apache.org/dist/logging/log4cxx/${PORTVERSION}/
DISTNAME=	apache-log4cxx-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ port of the Log4j project
WWW=		https://logging.apache.org/log4cxx/ \
		https://github.com/apache/logging-log4cxx

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libfmt.so:devel/libfmt
TEST_DEPENDS=	zip:archivers/zip

USES=		cmake:testing compiler:c++17-lang pathfix

CMAKE_OFF=	APACHE_MAINTAINER \
		APR_STATIC \
		APU_STATIC \
		BUILD_TESTING \
		ENABLE_COVERAGE \
		LIBESMTP_STATIC \
		LOG4CXX_ENABLE_ESMTP \
		LOG4CXX_ENABLE_ODBC \
		LOG4CXX_UNICHAR
CMAKE_ON=	BUILD_SHARED_LIBS \
		ENABLE_FMT_LAYOUT \
		LOG4CXX_INSTALL_PDB \
		LOG4CXX_WCHAR_T
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	BOOST

BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/regex.hpp:devel/boost-libs
BOOST_CMAKE_BOOL=	PREFER_BOOST

.include <bsd.port.mk>
