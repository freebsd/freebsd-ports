PORTNAME=	spidermonkey
DISTVERSION=	91.13.0
PORTREVISION=	32
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source
PKGNAMESUFFIX=	${SP_VER}
DISTNAME=	firefox-${DISTVERSION}esr.source

PATCH_SITES=	https://hg.mozilla.org/mozilla-central/raw-rev/
PATCHFILES+=	223087fdc29f18678f6174e9807b8780e439acf6:-p1 # https://bugzilla.mozilla.org/1894423
PATCHFILES+=	68ff4d3f7338248b4d67cf03aade5a73f8d396b2:-p1 # https://bugzilla.mozilla.org/1849070

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 91-esr
WWW=		https://spidermonkey.dev/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.35:lang/${RUST_DEFAULT} \
		autoconf2.13:devel/autoconf2.13 \
		rust-cbindgen>=0.8.7:devel/rust-cbindgen
LIB_DEPENDS=	libffi.so:devel/libffi \
		libicudata.so:devel/icu \
		libnspr4.so:devel/nspr

USES=		compiler:c++17-lang gmake localbase pathfix pkgconfig \
		python:build readline tar:xz
USE_LDCONFIG=	yes
SP_VER=		91
HAS_CONFIGURE=	yes

WRKSRC=			${WRKDIR}/firefox-${DISTVERSION}/
PATCH_WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}/
CONFIGURE_OUTSOURCE=	yes

CONFIGURE_ARGS=	--enable-application=js \
		--disable-debug \
		--disable-debug-symbols \
		--disable-gold \
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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=15
CONFIGURE_ENV+=	LLVM_CONFIG=llvm-config${LLVM_VERSION} \
		LLVM_OBJDUMP=llvm-objdump${LLVM_VERSION}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ENV+=	LLVM_CONFIG=llvm-config${LLVM_DEFAULT} \
		LLVM_OBJDUMP=llvm-objdump${LLVM_DEFAULT}
BUILD_DEPENDS+=	${LOCALBASE}/bin/llvm-objdump${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/js/moz.configure
	@${REINPLACE_CMD} -e 's|icu-i18n|icu-uc icu-i18n|g' ${WRKSRC}/js/moz.configure
	@${FIND} ${WRKSRC}/python/mozbuild -name *.py -exec \
		${REINPLACE_CMD} 's|"rU"|"r"|g' {} \;

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf2.13)

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*

.include <bsd.port.post.mk>
