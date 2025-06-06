PORTNAME=	crystal
DISTVERSION=	1.16.3
CATEGORIES=	lang
MASTER_SITES=	https://github.com/dmgk/crystal-bootstrap/releases/download/${_BOOTSTRAP_VERSION}/:bootstrap \
		LOCAL/dmgk/crystal:bootstrap
DISTFILES=	${_BOOTSTRAP_NAME}.tar.xz:bootstrap
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Language with Ruby-like syntax and static type checking
WWW=		https://crystal-lang.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

BUILD_DEPENDS=	${LOCALBASE}/bin/llvm-config${_BOOTSTRAP_LLVM_VERSION}:devel/llvm${_BOOTSTRAP_LLVM_VERSION} \
		git:devel/git
LIB_DEPENDS=	libevent.so:devel/libevent \
		libffi.so:devel/libffi \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libgmp.so:math/gmp \
		libLLVM-${_LLVM_VERSION}.so:devel/llvm${_LLVM_VERSION} \
		libpcre.so:devel/pcre \
		libpcre2-8.so:devel/pcre2 \
		libyaml.so:textproc/libyaml
RUN_DEPENDS=	pkg-config:devel/pkgconf

USES=		compiler gmake gnome pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	crystal-lang
USE_GNOME=	libxml2

_BOOTSTRAP_LLVM_VERSION=	14
_BOOTSTRAP_NAME=		crystal-${_BOOTSTRAP_VERSION}-${ARCH}-llvm${_BOOTSTRAP_LLVM_VERSION}
_BOOTSTRAP_VERSION=		1.5.1
_COMMIT_ID=			84f389ac5424
_LLVM_VERSION?=			20

MAKE_ARGS=	CRYSTAL_CACHE_DIR="${WRKDIR}/cache" \
		CRYSTAL_CONFIG_BUILD_COMMIT="${_COMMIT_ID}" \
		CRYSTAL_CONFIG_PATH="lib:${PREFIX}/lib/${PORTNAME}" \
		FLAGS="--progress --stats --threads ${MAKE_JOBS_NUMBER} ${OPT_FLAGS}" \
		LLVM_CONFIG="${LOCALBASE}/bin/llvm-config${_LLVM_VERSION}"

TEST_ARGS=	${MAKE_ARGS:S/release=1//}
TEST_TARGET=	spec

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES INTERPRETER STATIC
OPTIONS_DEFAULT=	INTERPRETER

INTERPRETER_DESC=	Enable interpreter (experimental)

DEBUG_VARS=		OPT_FLAGS+="--debug" \
			STRIP=
DEBUG_VARS_OFF=		OPT_FLAGS+="--release --no-debug"
INTERPRETER_MAKE_ARGS=	interpreter=1
STATIC_MAKE_ARGS=	static=1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

post-extract:
	@${RLN} ${WRKDIR}/.build ${WRKSRC}
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-freebsd
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-portbld-freebsd
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-unknown-freebsd

post-patch:
.if ${SSL_DEFAULT} == "base" && ${OSREL:R} <= 13
	@${REINPLACE_CMD} -i '' \
		-e 's|CRYSTAL_SSL_VERSION|1.1.1|g' \
		-e 's|CRYSTAL_SSL_LDFLAGS|${OPENSSLLIB}|g' \
		${WRKSRC}/src/openssl/lib_ssl.cr \
		${WRKSRC}/src/openssl/lib_crypto.cr
.endif
.if ${SSL_DEFAULT} == "base" && ${OSREL:R} >= 14
	@${REINPLACE_CMD} -i '' \
		-e 's|CRYSTAL_SSL_VERSION|3.0.10|g' \
		-e 's|CRYSTAL_SSL_LDFLAGS|${OPENSSLLIB}|g' \
		${WRKSRC}/src/openssl/lib_ssl.cr \
		${WRKSRC}/src/openssl/lib_crypto.cr
.endif

pre-test:
	@${CHMOD} +x ${WRKSRC}/src/llvm/ext/find-llvm-config

post-build-DOCS-on:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} docs)

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/.build/crystal \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${INSTALL_WRKSRC}/man/crystal.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	(cd ${INSTALL_WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/bash_completion.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/zsh/site-functions
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.bash \
		${STAGEDIR}${LOCALBASE}/etc/bash_completion.d/_crystal.bash
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.zsh \
		${STAGEDIR}${LOCALBASE}/share/zsh/site-functions/_crystal

do-install-DOCS-on:
	(cd ${INSTALL_WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	(cd ${INSTALL_WRKSRC}/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.if !defined(_CRYSTAL_MAKESUM_GUARD)
makesum:
	${MAKE} -D_CRYSTAL_MAKESUM_GUARD makesum ARCH=${ONLY_FOR_ARCHS:O:[1]} \
		DISTINFO_FILE=${DISTINFO_FILE}.tmp
.for arch in ${ONLY_FOR_ARCHS:O:[2..-1]}
	${MAKE} -D_CRYSTAL_MAKESUM_GUARD makesum ARCH=${arch} DISTINFO_FILE=${DISTINFO_FILE}.${arch}
	${SED} 1d \
		${DISTINFO_FILE}.${arch} \
		>> \
		${DISTINFO_FILE}.tmp
	${RM} ${DISTINFO_FILE}.${arch}
.endfor
	${AWK} '!seen[$$0]++' ${DISTINFO_FILE}.tmp > ${DISTINFO_FILE}
	${RM} ${DISTINFO_FILE}.tmp
.endif

.include <bsd.port.mk>
