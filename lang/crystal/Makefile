PORTNAME=	crystal
DISTVERSION=	1.22.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	LOCAL/dch/crystal:bootstrap
DISTFILES=	${_BOOTSTRAP_NAME}.tar.xz:bootstrap
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Language with Ruby-like syntax and static type checking
WWW=		https://crystal-lang.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		git:devel/git
LIB_DEPENDS=	libevent.so:devel/libevent \
		libLLVM-${_LLVM_VERSION}.so:devel/llvm${_LLVM_VERSION} \
		libffi.so:devel/libffi \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libgmp.so:math/gmp \
		libpcre2-8.so:devel/pcre2 \
		libyaml.so:textproc/libyaml
RUN_DEPENDS=	pkg-config:devel/pkgconf

USES=		compiler gmake gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	crystal-lang
USE_GNOME=	libxml2

_BOOTSTRAP_LLVM_VERSION=	20
_BOOTSTRAP_NAME=		crystal-${_BOOTSTRAP_VERSION}-${ARCH}-llvm${_BOOTSTRAP_LLVM_VERSION}
_BOOTSTRAP_VERSION=		1.22.2
_COMMIT_ID=			84f389ac5424
_LLVM_VERSION?=			20

MAKE_ARGS=	CRYSTAL_CACHE_DIR="${WRKDIR}/cache" \
		CRYSTAL_CONFIG_BUILD_COMMIT="${_COMMIT_ID}" \
		CRYSTAL_CONFIG_PATH="lib:${PREFIX}/lib/${PORTNAME}" \
		FLAGS="--progress --stats --threads ${MAKE_JOBS_NUMBER} ${_OPT_FLAGS}" \
		LLVM_CONFIG="${LOCALBASE}/bin/llvm-config${_LLVM_VERSION}"

TEST_ARGS=	${MAKE_ARGS:S/release=1//}
TEST_TARGET=	spec

# NB no need to re-add PORTDOCS to pkg-plist
PORTDOCS=	*

OPTIONS_DEFINE=		DEBUG DOCS INTERPRETER
OPTIONS_DEFAULT=	DOCS INTERPRETER

INTERPRETER_DESC=	Enable interpreter (experimental)

DEBUG_VARS=		_OPT_FLAGS+="--debug" STRIP=
DEBUG_VARS_OFF=		_OPT_FLAGS+="--release --no-debug"
DOCS_MAKE_ARGS=		docs_sanitizer=1
INTERPRETER_MAKE_ARGS=	interpreter=1

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

.if ${_LLVM_VERSION} != ${_BOOTSTRAP_LLVM_VERSION}
BUILD_DEPENDS+=	libLLVM-${_BOOTSTRAP_LLVM_VERSION}.so:devel/llvm${_BOOTSTRAP_LLVM_VERSION}
.endif

post-extract:
	@${RLN} ${WRKDIR}/.build ${WRKSRC}
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-freebsd
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-portbld-freebsd
	@${RLN} x86_64-freebsd ${WRKSRC}/src/lib_c/aarch64-unknown-freebsd

pre-test:
	@${CHMOD} +x ${WRKSRC}/src/llvm/ext/find-llvm-config

# since 1.21.0 upstream ships only asciidoc sources, man pages are generated
post-build:
	@${MKDIR} ${WRKSRC}/man
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} man/)

post-build-DOCS-on:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} docs)

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/.build/crystal \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${INSTALL_WRKSRC}/man/*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	(cd ${INSTALL_WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/bash_completion.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/fish/vendor_completions.d
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/zsh/site-functions
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.bash \
		${STAGEDIR}${LOCALBASE}/etc/bash_completion.d/_crystal.bash
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.fish \
		${STAGEDIR}${LOCALBASE}/share/fish/vendor_completions.d/crystal.fish
	${INSTALL_DATA} ${INSTALL_WRKSRC}/etc/completion.zsh \
		${STAGEDIR}${LOCALBASE}/share/zsh/site-functions/_crystal

do-install-DOCS-on:
	(cd ${INSTALL_WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

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

# maintainer flow for a new bootstrap compiler, on each arch in ONLY_FOR_ARCHS
# set _BOOTSTRAP_VERSION to DISTVERSION & pkg install crystal, it builds the new one
# make _tarball                     # build this arch's bootstrap into _DISTDIR
# make _upload                      # push every arch found in _DISTDIR to freefall
# make makesum                      # once all arches are published

_BOOTSTRAP_WRKDIR=	${WRKDIR}/bootstrap
_BOOTSTRAP_SRC=		${_BOOTSTRAP_WRKDIR}/${GH_PROJECT}-${DISTVERSION}

_tarball: build-depends
	@if [ "${_BOOTSTRAP_VERSION}" != "${DISTVERSION}" ]; then \
		${ECHO_CMD} "===> set _BOOTSTRAP_VERSION=${DISTVERSION} first"; \
		exit 1; \
		fi
	@if [ -f ${_DISTDIR}/${_BOOTSTRAP_NAME}.tar.xz ]; then \
		${ECHO_CMD} "===> ${_BOOTSTRAP_NAME}.tar.xz already exists;"; \
		${ECHO_CMD} "===> a published bootstrap must not be rebuilt"; \
		exit 1; \
		fi
	@if [ ! -x ${LOCALBASE}/bin/crystal ]; then \
		${ECHO_CMD} "===> pkg install crystal first, it compiles the bootstrap"; \
		exit 1; \
		fi
	cd ${.CURDIR} && \
		${MAKE} fetch DISTFILES=${DISTNAME}${EXTRACT_SUFX}
	${RM} -r ${_BOOTSTRAP_WRKDIR}
	${MKDIR} ${_BOOTSTRAP_WRKDIR}
	${TAR} -xf ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${_BOOTSTRAP_WRKDIR}
.for d in aarch64-freebsd aarch64-portbld-freebsd aarch64-unknown-freebsd
	${RLN} x86_64-freebsd ${_BOOTSTRAP_SRC}/src/lib_c/${d}
.endfor
# a minimal compiler: no docs (libxml2), no interpreter, pcre2 only
	(cd ${_BOOTSTRAP_SRC} && \
		${SETENV} -u USE_PCRE1 PATH=${LOCALBASE}/bin:${PATH} \
		${MAKE_CMD} CRYSTAL_CACHE_DIR=${_BOOTSTRAP_WRKDIR}/cache \
		FLAGS="--progress --threads ${MAKE_JOBS_NUMBER} --release --no-debug" \
		LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${_BOOTSTRAP_LLVM_VERSION} \
		crystal)
	@ldd ${_BOOTSTRAP_SRC}/.build/crystal > ${_BOOTSTRAP_WRKDIR}/ldd.txt
	@${GREP} -q 'libLLVM.*\.so\.${_BOOTSTRAP_LLVM_VERSION}\.' ${_BOOTSTRAP_WRKDIR}/ldd.txt || \
		{ ${ECHO_CMD} "===> not linked to LLVM ${_BOOTSTRAP_LLVM_VERSION}"; exit 1; }
	@${GREP} -q 'libpcre2-8\.so' ${_BOOTSTRAP_WRKDIR}/ldd.txt || \
		{ ${ECHO_CMD} "===> not linked to pcre2"; exit 1; }
	@! ${GREP} -q 'libpcre\.so' ${_BOOTSTRAP_WRKDIR}/ldd.txt || \
		{ ${ECHO_CMD} "===> linked to pcre1"; exit 1; }
	${_BOOTSTRAP_SRC}/.build/crystal --version
	${CHMOD} -R u=rwX,go=rX ${_BOOTSTRAP_SRC}/.build
	${TAR} -cJf ${_DISTDIR}/${_BOOTSTRAP_NAME}.tar.xz -C ${_BOOTSTRAP_SRC} \
		--uid 0 --gid 0 --uname root --gname wheel ./.build
	${CHMOD} 644 ${_DISTDIR}/${_BOOTSTRAP_NAME}.tar.xz
	@${ECHO_MSG} "===> ${_BOOTSTRAP_NAME}.tar.xz built; run \"make _upload\" to publish"

# copy the other arch's tarball into _DISTDIR first to upload both at once
_upload:
	(cd ${_DISTDIR} && \
		rsync -Phriv --times --chmod=F644 \
		$$(${LS} ${ONLY_FOR_ARCHS:@a@crystal-${_BOOTSTRAP_VERSION}-${a}-llvm${_BOOTSTRAP_LLVM_VERSION}.tar.xz@} 2>/dev/null) \
		freefall.freebsd.org:public_distfiles/${PORTNAME}/)

.include <bsd.port.mk>
