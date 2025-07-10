PORTNAME=	libnjs
DISTVERSION=	0.9.1
CATEGORIES=	devel www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript static library
WWW=		https://nginx.org/en/docs/njs/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libquickjs.so:lang/quickjs

USES=		compiler:c11 cpe ssl

CPE_VENDOR=	f5

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:${DISTVERSION}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc-opt="-I${LOCALBASE}/include/quickjs" \
		--ld-opt="-L${LOCALBASE}/lib" \
		--with-quickjs

.include <bsd.port.pre.mk>

# Fixes build failed for Clang 19.1.3+
.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 191
CFLAGS+=	-Wno-error=cast-function-type-mismatch
.endif

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/njs.pc.in

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} libnjs

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/njs_auto_config.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libnjs.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/build/njs.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
