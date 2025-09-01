PORTNAME=	spidermonkey
DISTVERSION=	115.22.0
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source \
		MOZILLA/firefox/candidates/${DISTVERSION}esr-candidates/build1/source
PKGNAMESUFFIX=	${SP_VER}
DISTNAME=	firefox-${DISTVERSION}esr.source

PATCH_SITES=	https://hg.mozilla.org/mozilla-central/raw-rev/
PATCHFILES+=	223087fdc29f18678f6174e9807b8780e439acf6:-p1 # https://bugzilla.mozilla.org/1894423
PATCHFILES+=	68ff4d3f7338248b4d67cf03aade5a73f8d396b2:-p1 # https://bugzilla.mozilla.org/1849070

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 115-esr
WWW=		https://spidermonkey.dev/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gm4:devel/m4 \
		${RUST_DEFAULT}>=1.81:lang/${RUST_DEFAULT} \
		rust-cbindgen>=0.26.0:devel/rust-cbindgen
LIB_DEPENDS=	libicudata.so:devel/icu \
		libnspr4.so:devel/nspr

USES=		compiler:c++17-lang gmake llvm:noexport localbase pathfix pkgconfig \
		python:build tar:xz
USE_LDCONFIG=	yes
SP_VER=		115
HAS_CONFIGURE=	yes

WRKSRC=			${WRKDIR}/firefox-${DISTVERSION}/
PATCH_WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}/
CONFIGURE_OUTSOURCE=	yes

CONFIGURE_ARGS=	--enable-application=js \
		--disable-debug \
		--disable-debug-symbols \
		--disable-jemalloc \
		--disable-tests \
		--enable-optimize \
		--enable-readline \
		--enable-shared-js \
		--prefix=${PREFIX:Q} \
		--target=${CONFIGURE_TARGET} \
		--with-intl-api \
		--with-system-icu \
		--with-system-nspr \
		--with-system-zlib

CONFIGURE_ENV=	HOST_CC=${CC} \
		HOST_CXX=${CXX}

BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_SUB=	SP_VER=${SP_VER}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ENV+=	LLVM_CONFIG=${LLVM_CONFIG} \
		LLVM_OBJDUMP=llvm-objdump${LLVM_VERSION}
BUILD_DEPENDS+=	${LOCALBASE}/bin/llvm-objdump${LLVM_VERSION}:${LLVM_PORT}
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/js/moz.configure
	@${REINPLACE_CMD} -e 's|icu-i18n|icu-uc icu-i18n|g' ${WRKSRC}/js/moz.configure

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*

.include <bsd.port.post.mk>
