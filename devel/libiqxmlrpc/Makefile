PORTNAME=	libiqxmlrpc
PORTVERSION=	0.13.5
PORTREVISION=	21
CATEGORIES=	devel net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, object-oriented XML-RPC implementation written in C++
WWW=		https://libiqxmlrpc.wikidot.com/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Fails to build with libxml2 2.13.0 (PR 279705)
EXPIRATION_DATE=2024-07-16

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake gnome localbase:ldflags ssl tar:bzip2
USE_CXXSTD=	c++14
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_OFF=	-Dbuild_docs=off

post-patch:
	${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/libiqxmlrpc/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/doc/libiqxmlrpc-$${Libiqxmlrpc_VERSION},${DOCSDIR_REL},' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
