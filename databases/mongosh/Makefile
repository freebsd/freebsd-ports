PORTNAME=	mongosh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	databases shells net
MASTER_SITES=	https://registry.npmjs.org/mongodb-client-encryption/-/:mongocrypt \
		https://registry.npmjs.org/kerberos/-/:kerberos \
		https://registry.npmjs.org/os-dns-native/-/:dns \
		https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONFULL}/:modules
#		https://nodejs.org/dist/latest-v${NODEJS_VERSION}.x/:node
DISTFILES=	mongodb-client-encryption-${MONGO_CRYPT_VER}.tgz:mongocrypt \
		kerberos-${KERBEROS_VER}.tgz:kerberos \
		os-dns-native-${OSDNSNATIVE_VER}.tgz:dns \
		${NODE_MODULES_TARBALL}:modules
#		${NODEJS_TARBALL}:node \
#		SHASUMS256.txt:node
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	fabien.amelinck+freebsd@advens.fr
COMMENT=	MongoDB Shell CLI REPL
WWW=		https://github.com/mongodb-js/mongosh/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 aarch64
ONLY_FOR_ARCHS_REASON=	nx node_module error: Unsupported architecture on FreeBSD: ${ARCH}
# issue created upstream https://github.com/nrwl/nx/issues/29257

PATCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
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

USES=		compiler:c++20-lang cpe gmake gssapi:mit localbase nodejs:24,build \
		pkgconfig python:build shebangfix sqlite ssl tar:xz

CPE_VENDOR=	mongodb
USE_GITHUB=	yes
GH_ACCOUNT=	VultureProject
GH_PROJECT=	mongosh

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
		CI=true \
		NODE_OPTIONS=--max-old-space-size=8192 \
		CC="${CCACHE_BIN} ${CC}" \
		CFLAGS="${CFLAGS}" \
		CXX="${CCACHE_BIN} ${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LINK="${CXX}"
# CXXFLAGS+=	-DNODE_API_EXPERIMENTAL \
# 		-DNODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions
REINPLACE_ARGS=	-i ''

MONGO_CRYPT_VER=7.2.0
KERBEROS_VER=	7.0.0
OSDNSNATIVE_VER=2.0.1
MODULES=	mongodb-client-encryption ${MONGO_CRYPT_VER} \
		kerberos ${KERBEROS_VER} \
		os-dns-native ${OSDNSNATIVE_VER}

NODE_MODULES_DIR=	${WRKSRC}/node_modules
BOXEDNODE_DIR=		${NODE_MODULES_DIR}/boxednode
NODE_MODULES_TARBALL=	${PORTNAME}-${DISTVERSIONFULL}-${ARCH}-node-modules.tar.xz
NPM_CACHE_DIR=		${TMPDIR}/.npm
NODEJS_TARBALL=		node-v${NODEJS_PORTVERSION}.tar.gz
NODEJS_SHAFILE=		node-v${NODEJS_PORTVERSION}-SHASUMS256.txt

post-fetch:
	if [ ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_TARBALL} -o \
	     ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} ]; then \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR} \
			https://nodejs.org/dist/v${NODEJS_PORTVERSION}/${NODEJS_TARBALL}; \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} \
			https://nodejs.org/dist/v${NODEJS_PORTVERSION}/SHASUMS256.txt; \
	fi

post-extract:
.if !exists(${NODE_MODULES_DIR})
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${NODE_MODULES_TARBALL} -C ${WRKSRC}
	${MKDIR} -v ${WRKDIR}/boxednode/mongosh
	${REINPLACE_CMD} -e "s|%%GMAKE%%|${GMAKE}|g" \
		-e "s|%%NODEJS_PORTVERSION%%|${NODEJS_PORTVERSION}|g" \
		-e "s|%%NODEJS_SHAFILE%%|${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE}|g" \
		-e "s|%%WRKDIR%%|${WRKDIR}|g" \
		${BOXEDNODE_DIR}/lib/index.js
	${GREP} -A36 "let version;" ${BOXEDNODE_DIR}/lib/index.js
.endif

post-patch:
	${CP} -v ${FILESDIR}/node-patches/* ${WRKSRC}/scripts/nodejs-patches

do-configure:
	${FIND} ${WRKSRC}/scripts -name "*.orig" -delete
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${NODE_MODULES_DIR}/mongodb-client-encryption/binding.gyp
.for module ver in ${MODULES}
	cd ${NODE_MODULES_DIR}/${module} && \
		${CONFIGURE_ENV} node-gyp configure --nodedir=${LOCALBASE}
.endfor

do-build:
.for module ver in ${MODULES}
	cd ${NODE_MODULES_DIR}/${module} && \
		${MAKE_ENV} ${MAKE_CMD} BUILDTYPE=Release -C build -d
.endfor
	${REINPLACE_CMD} -E 's/"version": ".*"/"version": "${DISTVERSION}"/g' \
		${WRKSRC}/packages/cli-repl/package.json
#	Race condition randomly happening with Lerna/Nx that I don't have the time to dig in
#	thread 'tui-logger::move_events' panicked at ./parking_lot_core-0.9.12/src/thread_parker/wasm.rs:26:9:
#	Parking not supported on this platform
#	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm run compile-cli || \
#		(cat ${WRKSRC}/lerna-debug.log && false)
.for dir in errors history js-multiline-to-singleline types async-rewriter2 i18n \
logging shell-bson arg-parser service-provider-core service-provider-node-driver \
shell-api autocomplete shell-evaluator snippet-manager editor cli-repl
	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm run compile --workspace=@mongosh/${dir}
.endfor
	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm run compile-exec || \
		(cat ${WRKSRC}/lerna-debug.log && false)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/mongosh ${STAGEDIR}${PREFIX}/bin

do-test:
	${STAGEDIR}${PREFIX}/bin/mongosh mongodb://0.0.0.0:1 2>&1 | \
		${GREP} -e "\(ECONNREFUSED\|ENETUNREACH\) 0.0.0.0:1"
	${STAGEDIR}${PREFIX}/bin/mongosh --nodb --eval "print('ok')" | ${GREP} "ok"
	${STAGEDIR}${PREFIX}/bin/mongosh --smokeTests | ${GREP} "all tests passed"

npm-pkg-list: extract
	${GREP} registry.npmjs.org ${WRKSRC}/package-lock.json | \
		| ${SED} -E 's/^[[:space:]]+//g' \
		| ${SED} -E 's#^.*org/|.tgz",##g' \
		| ${SORT} \
		| /usr/bin/uniq \
		| ${SED} -E 's/(.*)-([^-])/\1@\2/g' \
		| ${SED} -E 's|/-/.*@|@|g' \
		> ${FILESDIR}/npm-pkg.list

.for module in mongodb-client-encryption kerberos os-dns-native \
		mongodb-crypt-library-version glibc-version
	cd ${NODE_MODULES_DIR}/${module} && ${LOCALBASE}/bin/npm list 2>/dev/null \
		| ${GREP} UNMET \
		| ${AWK} 'BEGIN{FS="UNMET DEPENDENCY "}{print $$2}' \
		> ${FILESDIR}/npm-pkg-${module}.list
.endfor

node-modules-archive: patch
#	Comment ${NODE_MODULES_TARBALL}:modules and post-extract
.for module ver in ${MODULES}
	${MKDIR} -v ${NODE_MODULES_DIR}/${module}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${module}-${ver}.tgz \
		-C ${NODE_MODULES_DIR}/${module} --strip-components 1
.endfor
	cd ${WRKSRC} && ${LOCALBASE}/bin/npx --yes cross-env ${CONFIGURE_ENV} \
		${LOCALBASE}/bin/npm clean-install \
			--cache ${NPM_CACHE_DIR} --no-audit --no-fund

	# cpu-features 0.0.10 bundles an old google/cpu_features revision with no
	# FreeBSD/aarch64 backend, so its addon has an undefined GetAarch64Info and
	# aborts the dynamic loader. It is only an optional ssh2 accelerator (ssh2
	# falls back to its JS implementation), so drop it on non-amd64.
	if [ "${ARCH}" != amd64 ]; then ${RM} -r ${NODE_MODULES_DIR}/cpu-features; fi

	${REINPLACE_CMD} "s|'install', '--ignore-scripts', '--production'|'--version'|g" \
		${BOXEDNODE_DIR}/lib/native-addons.js
	${GREP} "version" ${BOXEDNODE_DIR}/lib/native-addons.js
	for f in ${FILESDIR}/node-modules-patches/*; do ${PATCH} -Nd ${WRKSRC} < $$f; done
	${FIND} ${WRKSRC} -name "*.orig" -or -name "*.bak" -delete

	cd ${WRKSRC} && ${TAR} cf - node_modules packages/*/node_modules | \
		${LOCALBASE}/bin/pv -s $$(/usr/bin/du -sAk node_modules packages/*/node_modules | \
		${AWK} '{sum += $$1} END {print sum}')K | \
		${XZ_CMD} > ${TMPDIR}/${NODE_MODULES_TARBALL}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/www/node${NODEJS_VERSION}/Makefile.version"

NODE_WITH_JIT!=	${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} showconfig \
			| ${GREP} -o "JIT=on" || ${TRUE}
.if empty(NODE_WITH_JIT)
IGNORE=	www/node${NODEJS_VERSION} must be built with JIT enabled. Run '${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} config' to enable it
.endif

.include <bsd.port.post.mk>
