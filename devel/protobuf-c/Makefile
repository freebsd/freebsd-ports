PORTNAME=	protobuf-c
DISTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Code generator and libraries to use Protocol Buffers from pure C
WWW=		https://github.com/protobuf-c/protobuf-c

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		compiler:c++17-lang gmake libtool pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CXXSTD=	c++17
PORTDOCS=	*

CONFIGURE_ARGS=	--disable-static

OPTIONS_DEFINE=	DOXYGEN DOCS
OPTIONS_DEFAULT=	DOXYGEN

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	html-local

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
