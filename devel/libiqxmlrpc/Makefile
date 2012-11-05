# New ports collection makefile for:	libiqxmlrpc
# Date created:				1 Apr 2008
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiqxmlrpc
PORTVERSION=	0.11.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Free, object-oriented XML-RPC implementation written in C++

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GNOME=	libxml2
USE_CMAKE=	yes
.if defined(NOPORTDOCS)
CMAKE_ARGS=	-Dbuild_docs=off
.endif
LDFLAGS=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PORTDATA=	*

post-patch:
	${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/libiqxmlrpc/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/doc/libiqxmlrpc-$${Libiqxmlrpc_VERSION},share/libiqxmlrpc,' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
