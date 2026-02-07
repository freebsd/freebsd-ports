PORTNAME=	protobuf-c
DISTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/protobuf-c/protobuf-c/releases/download/v${DISTVERSION}/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Code generator and libraries to use Protocol Buffers from pure C
WWW=		https://github.com/protobuf-c/protobuf-c

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libabsl_log_internal_check_op.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		compiler:c++17-lang gmake libtool pkgconfig
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

HAS_SYMBOL_VERSION=	${PREFIX}/lib/libprotobuf-c.so.1.0.0

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_DEFAULT=	DOXYGEN

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
