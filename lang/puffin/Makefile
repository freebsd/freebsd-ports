PORTNAME=	puffin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	lang
MASTER_SITES=	https://puffinlang.org/alpha/freebsd/

MAINTAINER=	gcw@robottank.one
COMMENT=	AWK-derived language with interpreter, AOT and C backends
WWW=		https://puffinlang.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/nim/bin/nim:lang/nim
LIB_DEPENDS=	libsodium.so:security/libsodium \
		libsqlite3.so:databases/sqlite3 \
		libzstd.so:archivers/zstd

USES=		gmake pkgconfig ssl

MAKE_ARGS=	AWKTUA_WITH_TRACE=1 \
		MANDIR=${PREFIX}/share/man \
		PREFIX=${PREFIX} \
		STDLIBDIR=${STAGEDIR}${PREFIX}/share/puffin/stdlib
MAKE_ENV=	AWKTUA_LIBRESSL_HOST=1 \
		AWKTUA_LIBSODIUM_HOST=1 \
		PATH=${LOCALBASE}/nim/bin:${PATH}
TEST_ENV=	${MAKE_ENV} \
		AWKTUA_EXE=${WRKSRC}/bin/awktua \
		AWKTUA_STDLIB=${WRKSRC}/stdlib \
		PUFFINCC_RUNTIME_DIR=${WRKSRC}/bin

# drop the vendored copies so the build can only link the host libraries
post-extract:
	${RM} -r ${WRKSRC}/tools/vendor/libressl ${WRKSRC}/tools/vendor/libsodium \
		${WRKSRC}/tools/vendor/sqlite ${WRKSRC}/lib/runtime/sqlite3_opt.c \
		${WRKSRC}/lib/runtime/zstddeclib.c ${WRKSRC}/lib/runtime/bzlib*.[ch] \
		${WRKSRC}/lib/runtime/blocksort.c ${WRKSRC}/lib/runtime/compress.c \
		${WRKSRC}/lib/runtime/crctable.c ${WRKSRC}/lib/runtime/decompress.c \
		${WRKSRC}/lib/runtime/huffman.c ${WRKSRC}/lib/runtime/randtable.c

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/iawktuarc \
		${STAGEDIR}${PREFIX}/etc/iawktuarc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awktua \
		${STAGEDIR}${PREFIX}/bin/awktua-trace \
		${STAGEDIR}${PREFIX}/bin/puffin \
		${STAGEDIR}${PREFIX}/bin/puffin-lsp \
		${STAGEDIR}${PREFIX}/bin/puffin-fmt \
		${STAGEDIR}${PREFIX}/bin/puffin-lint

# one program through all three backends, output must match and agree
do-test:
	${SETENV} ${TEST_ENV} ${SH} ${FILESDIR}/smoke-test.sh ${WRKSRC} \
		${WRKDIR}/smoke ${FILESDIR}/smoke.pfn

.include <bsd.port.mk>
