PORTNAME=	dsymbol
PORTVERSION=	0.14.1
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Symbol lookup support for libdparse
WWW=		https://github.com/dlang-community/dsymbol

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libmir-core.a:devel/mir-core \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dlang-community

DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d
DC=		${PREFIX}/bin/ldmd2

post-patch:
	${REINPLACE_CMD} -e '7,11d' ${WRKSRC}/dub.json
	${REINPLACE_CMD} -e 's@cache.clear@cache.destroy@g' \
		${WRKSRC}/src/dsymbol/modulecache.d

do-build:
	@cd ${WRKSRC} && \
		${SETENV} DUB_HOME=${WRKDIR}/dub_home DC=${DC} ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/build/libdsymbol.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
