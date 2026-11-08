PORTNAME=	mold
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Modern Linker
WWW=		https://github.com/rui314/mold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd
TEST_DEPENDS=	bash:shells/bash \
		gcc${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT} \
		${LOCALBASE}/bin/readelf:devel/binutils

USES=		cargo shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	rui314
GH_TUPLE=	microsoft:mimalloc:02a2f5df9d7d46d30263b83832eebeeab62dc5fe:mimalloc_v2/../${WRKSRC_crate_mimalloc:T}/libmimalloc-sys/c_src/mimalloc/v2 \
		microsoft:mimalloc:d4881d338125e1cb7c47ba4cfb398d6f7c0c8d45:mimalloc_v3/../${WRKSRC_crate_mimalloc:T}/libmimalloc-sys/c_src/mimalloc/v3

SHEBANG_FILES=	tests/*.sh

CARGO_INSTALL=	no
CARGO_ENV=	TEST_GCC=${LOCALBASE}/bin/gcc${GCC_DEFAULT} \
		TEST_GXX=${LOCALBASE}/bin/g++${GCC_DEFAULT} \
		ZSTD_SYS_USE_PKG_CONFIG=1

PLIST_FILES=	bin/ld.${PORTNAME} \
		bin/${PORTNAME} \
		lib/${PORTNAME}/${PORTNAME}-wrapper.so \
		libexec/${PORTNAME}/ld \
		share/man/man1/ld.${PORTNAME}.1.gz \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

.if ${ARCH} == armv7 || ${ARCH} == i386
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L${LOCALBASE}/lib/gcc${GCC_DEFAULT} -latomic
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/${PORTNAME}-wrapper.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${RLN} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/ld.${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/ld
	${RLN} ${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/ld.${PORTNAME}.1

.include <bsd.port.post.mk>
