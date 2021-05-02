# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS_i386=	libatomic_ops>0:devel/libatomic_ops

USES=		cmake compiler:gcc-c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
USE_LDCONFIG=	yes

CMAKE_ON=	MI_INSTALL_TOPLEVEL

LDFLAGS_i386+=	-latomic

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

post-install: # workaround for https://github.com/microsoft/mimalloc/issues/398
	cd ${STAGEDIR}${PREFIX} && \
		${MV} libmimalloc.a lib && \
		${RM} mimalloc.o

.include <bsd.port.mk>
