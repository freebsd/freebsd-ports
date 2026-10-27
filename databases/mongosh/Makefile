PORTNAME=	mongosh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	databases shells net
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fabien.amelinck+freebsd@advens.fr
COMMENT=	MongoDB Shell CLI REPL
WWW=		https://github.com/mongodb-js/mongosh/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	nx node_module error: Unsupported architecture on FreeBSD: ${ARCH}
# issue created upstream https://github.com/nrwl/nx/issues/29257

BUILD_DEPENDS=	objdump:devel/binutils \
		bash>0:shells/bash \
		git:devel/git@tiny
LIB_DEPENDS=	libada.so:devel/libada \
		libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libgtest.so:devel/googletest \
		libhdr_histogram.so:graphics/hdr_histogram \
		libicui18n.so:devel/icu \
		libllhttp.so:www/llhttp \
		libmerve.so:devel/merve \
		libnbytes.so:www/nbytes \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3 \
		libngtcp2.so:net/libngtcp2 \
		libsimdjson.so:devel/simdjson \
		libuv.so:devel/libuv \
		libuvwasi.so:devel/uvwasi \
		libzstd.so:archivers/zstd \
		libmongocrypt.so:databases/libmongocrypt
RUN_DEPENDS=	corepack>=0:www/corepack

USES=		compiler:c++20-lang cpe gmake gssapi:mit localbase \
		nodejs:24,build npm:npm,fetch,build pkgconfig python:build \
		shebangfix sqlite ssl

CPE_VENDOR=	mongodb
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb-js
GH_PROJECT=	mongosh

# Node modules are installed from registry.npmjs.org during the fetch phase and
# archived locally by post-fetch, so the port only depends on the upstream
# mongodb-js repository and the npm registry; no fork-hosted tarball and no
# pre-generated node_modules in the ports tree.
#
# The archive is per-architecture because npm installs different platform-
# specific optional dependencies.  It is produced with --ignore-scripts, so the
# native addons are rebuilt in do-build (see NATIVE_ADDONS below).

CUSTOM_ENV=	SEGMENT_API_KEY=dummy \
		GYP_DEFINES="libmongocrypt_link_type=dynamic" \
		PUPPETEER_SKIP_DOWNLOAD=1 \
		NPM_CONFIG_CACHE=${NPM_CACHE_DIR}
CONFIGURE_ENV=	${CUSTOM_ENV}
MAKE_ENV=	${CUSTOM_ENV} \
		NODE_JS_VERSION=file://${DISTDIR}/${DIST_SUBDIR}/${NODEJS_TARBALL} \
		BOXEDNODE_CONFIGURE_ARGS="--prefix=${PREFIX:S|^${DESTDIR}||},--shared-ada,--shared-brotli,--shared-cares,--shared-gtest,--shared-hdr-histogram,--shared-http-parser,--shared-libuv,--shared-merve,--shared-nbytes,--shared-nghttp2,--shared-nghttp3,--shared-ngtcp2,--shared-simdjson,--shared-sqlite,--shared-uvwasi,--shared-uvwasi-includes=${LOCALBASE}/include,--shared-zlib,--shared-zstd,--shared-openssl,--openssl-use-def-ca-store,--with-intl=system-icu,--without-corepack,--without-npm" \
		BOXEDNODE_MAKE_ARGS="V=0" \
		RUST_BACKTRACE=full \
		NODE_OPTIONS=--max-old-space-size=8192 \
		npm_config_nodedir=${LOCALBASE} \
		PYTHON=${PYTHON_CMD} \
		CC="${CCACHE_BIN} ${CC}" \
		CFLAGS="${CFLAGS}" \
		CXX="${CCACHE_BIN} ${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LINK="${CXX}"
# CXXFLAGS+=	-DNODE_API_EXPERIMENTAL \
# 		-DNODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT

REINPLACE_ARGS=	-i ''

# Native modules built by the port itself instead of during the (script-less)
# npm prefetch, because they need FreeBSD-specific spackling.
MODULES=	mongodb-client-encryption kerberos os-dns-native

# Remaining native addons from node_modules that npm would normally build via
# their install scripts.  Versions are pinned by files/packagejsons/package-lock.json.
NATIVE_ADDONS=	@mongodb-js/native-machine-id \
		glibc-version \
		interruptor \
		mongodb-crypt-library-dummy \
		mongodb-crypt-library-version

NODE_MODULES_DIR=	${WRKSRC}/node_modules
BOXEDNODE_DIR=		${NODE_MODULES_DIR}/boxednode
NPM_CACHE_DIR=		${TMPDIR:U/tmp}/.npm
NODEJS_TARBALL=		node-v${NODEJS_PORTVERSION}.tar.gz
NODEJS_SHAFILE=		node-v${NODEJS_PORTVERSION}-SHASUMS256.txt
NODE_MODULES_TARBALL=	${PORTNAME}-${DISTVERSION}-node-modules-${ARCH}.tar.gz

post-fetch:
	${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	if [ ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_TARBALL} -o \
	     ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} ]; then \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR} \
			https://nodejs.org/dist/v${NODEJS_PORTVERSION}/${NODEJS_TARBALL}; \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} \
			https://nodejs.org/dist/v${NODEJS_PORTVERSION}/SHASUMS256.txt; \
	fi
	if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${NODE_MODULES_TARBALL} ]; then \
		${ECHO_MSG} "===>  Generating node_modules archive"; \
		${RM} -rf ${WRKDIR}/node-modules-src; \
		${MKDIR} ${WRKDIR}/node-modules-src; \
		${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_DEFAULT} \
			-C ${WRKDIR}/node-modules-src; \
		cd ${WRKDIR}/node-modules-src/${GH_PROJECT}-${DISTVERSION} && \
			${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/npm ci \
				--ignore-scripts --no-audit --no-fund; \
		cd ${WRKDIR}/node-modules-src/${GH_PROJECT}-${DISTVERSION} && \
			${TAR} -cz --options 'gzip:!timestamp' \
				-f ${DISTDIR}/${DIST_SUBDIR}/${NODE_MODULES_TARBALL} \
				node_modules packages/*/node_modules; \
		${RM} -rf ${WRKDIR}/node-modules-src; \
	fi

post-extract:
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${NODE_MODULES_TARBALL} -C ${WRKSRC}
	${MKDIR} -v ${WRKDIR}/boxednode/mongosh
	${REINPLACE_CMD} -e "s|'make'|'${GMAKE}'|g" \
		-e "s/if (inputIsFileUrl)/if (false)/g" \
		-e 's/(await (0, nv_1.default)(range)).pop()/{"version":"${NODEJS_PORTVERSION}"}/g' \
		-e 's/path_1.default.join(dir, tarballName)/url_1.fileURLToPath(range)/g' \
		-e "s|\$${releaseBaseUrl}/SHASUMS256.txt|${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE}|g" \
		-e 's/await (0, node_fetch_1.default)(shaSumsUrl)/{"ok":1}/g' \
		-e "s/shaSums.text()/fs_1.promises.readFile(shaSumsUrl, 'utf8')/g" \
		-e "s/catch (_a) { }/catch (_a) { console.error(_a) }/g" \
		-e "s|os_1.default.tmpdir()|'${WRKDIR}'|g" \
		${BOXEDNODE_DIR}/lib/index.js
	${GREP} -A36 "let version;" ${BOXEDNODE_DIR}/lib/index.js
	${REINPLACE_CMD} -e "s|'install', '--ignore-scripts', '--production'|'--version'|g" \
		${BOXEDNODE_DIR}/lib/native-addons.js
	${GREP} "version" ${BOXEDNODE_DIR}/lib/native-addons.js

post-patch:
	${CP} -v ${FILESDIR}/node-patches/* ${WRKSRC}/scripts/nodejs-patches

do-configure:
	${FIND} ${WRKSRC}/scripts -name "*.orig" -delete
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${NODE_MODULES_DIR}/mongodb-client-encryption/binding.gyp
.for module in ${MODULES}
	cd ${NODE_MODULES_DIR}/${module} && \
		${CONFIGURE_ENV} node-gyp configure --nodedir=${LOCALBASE}
.endfor
	@if [ "${ARCH}" != amd64 ]; then \
		${ECHO_MSG} "Dropping cpu-features on ${ARCH}"; \
		${RM} -rf ${NODE_MODULES_DIR}/cpu-features; \
	fi

do-build:
# The npm prefetch runs with --ignore-scripts, so build the addons npm would
# have built.  --dangerously-allow-all-scripts only affects the packages named
# here; npm 12 otherwise blocks unreviewed install scripts.
	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm rebuild \
		--dangerously-allow-all-scripts ${NATIVE_ADDONS}
.for module in ${MODULES}
	cd ${NODE_MODULES_DIR}/${module} && \
		${MAKE_ENV} ${MAKE_CMD} BUILDTYPE=Release -C build -d
.endfor
	${REINPLACE_CMD} -E 's/"version": ".*"/"version": "${DISTVERSION}"/g' \
		${WRKSRC}/packages/cli-repl/package.json
	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm run compile-exec || \
		(cat ${WRKSRC}/lerna-debug.log && false)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/mongosh ${STAGEDIR}${PREFIX}/bin

do-test:
	${STAGEDIR}${PREFIX}/bin/mongosh mongodb://0.0.0.0:1 2>&1 | \
		${GREP} -e "\(ECONNREFUSED\|ENETUNREACH\) 0.0.0.0:1"
	${STAGEDIR}${PREFIX}/bin/mongosh --nodb --eval "print('ok')" | ${GREP} "ok"
	${STAGEDIR}${PREFIX}/bin/mongosh --smokeTests | ${GREP} "all tests passed"

.include <bsd.port.pre.mk>

# cpu-features 0.0.10 bundles an old google/cpu_features revision with no
# FreeBSD/aarch64 backend, so its addon has an undefined GetAarch64Info and
# aborts the dynamic loader.  It is only an optional ssh2 accelerator (ssh2
# falls back to its JS implementation), so it is only built on amd64.
.if ${ARCH} == amd64
NATIVE_ADDONS+=	cpu-features
.endif

.include "${PORTSDIR}/www/node${NODEJS_VERSION}/Makefile.version"

NODE_WITH_JIT!=	${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} showconfig \
			| ${GREP} -o "JIT=on" || ${TRUE}
.if empty(NODE_WITH_JIT)
IGNORE=	www/node${NODEJS_VERSION} must be built with JIT enabled. Run '${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} config' to enable it
.endif

.include <bsd.port.post.mk>
