# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libiqxmlrpc
PORTVERSION=	0.12.4
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	SF

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Free, object-oriented XML-RPC implementation written in C++

.if !defined(NOPORTDOCS)
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
.endif
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

LICENSE=	BSD

USE_BZIP2=	yes
USE_GNOME=	libxml2
USES=		cmake
.if defined(NOPORTDOCS)
CMAKE_ARGS=	-Dbuild_docs=off
.endif
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PORTDATA=	*

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/libiqxmlrpc/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/doc/libiqxmlrpc-$${Libiqxmlrpc_VERSION},share/libiqxmlrpc,' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
