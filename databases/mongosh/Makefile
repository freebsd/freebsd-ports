PORTNAME=	mongosh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.5
PORTREVISION=	1
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

ONLY_FOR_ARCHS=	amd64
# issue created upstream https://github.com/nrwl/nx/issues/29257

PATCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	objdump:devel/binutils \
		bash>0:shells/bash \
		git>0:devel/git
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libicui18n.so:devel/icu \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3 \
		libngtcp2.so:net/libngtcp2 \
		libsimdjson.so:devel/simdjson \
		libuv.so:devel/libuv \
		libzstd.so:archivers/zstd \
		libmongocrypt.so:databases/libmongocrypt
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		compiler:c++11-lang gmake gssapi:mit localbase nodejs:lts,build pkgconfig python:build ssl tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	VultureProject
GH_PROJECT=	mongosh

CUSTOM_ENV=	SEGMENT_API_KEY=dummy GYP_DEFINES="libmongocrypt_link_type=dynamic" PUPPETEER_SKIP_DOWNLOAD=1 NPM_CONFIG_CACHE=${NPM_CACHE_DIR}
CONFIGURE_ENV=	${CUSTOM_ENV}
MAKE_ENV=	${CUSTOM_ENV} \
		NODE_JS_VERSION=file://${DISTDIR}/${DIST_SUBDIR}/${NODEJS_TARBALL} \
		BOXEDNODE_CONFIGURE_ARGS="--prefix=${PREFIX:S|^${DESTDIR}||},--shared-brotli,--shared-cares,--shared-libuv,--shared-nghttp2,--shared-nghttp3,--shared-ngtcp2,--shared-simdjson,--shared-zlib,--shared-zstd,--shared-openssl,--openssl-use-def-ca-store,--with-intl=system-icu,--without-npm" \
		BOXEDNODE_MAKE_ARGS="V=0"
CXXFLAGS+=	-DNODE_API_EXPERIMENTAL \
		-DNODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT

REINPLACE_ARGS=	-i ''

MPROTECT_DISABLE=	bin/mongosh

MONGO_CRYPT_VER=6.4.0
KERBEROS_VER=	2.1.0
OSDNSNATIVE_VER=1.2.1
NODE_MODULES_DIR=	${WRKSRC}/node_modules
NODE_MODULES_TARBALL=	${PORTNAME}-${DISTVERSIONFULL}-${ARCH}-node-modules.tar.xz
NPM_CACHE_DIR=	${TMPDIR}/.npm
NODEJS_TARBALL=	node-v${NODEJS_PORTVERSION}.tar.gz
NODEJS_SHAFILE=	node-v${NODEJS_PORTVERSION}-SHASUMS256.txt

post-fetch:
	if [ ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_TARBALL} -o ! -r ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} ]; then \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR} https://nodejs.org/dist/v${NODEJS_PORTVERSION}/${NODEJS_TARBALL}; \
		${FETCH_CMD} -o ${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE} https://nodejs.org/dist/v${NODEJS_PORTVERSION}/SHASUMS256.txt; \
	fi

post-extract:
.if !exists(${NODE_MODULES_DIR})
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${NODE_MODULES_TARBALL} -C ${WRKSRC}
	${MKDIR} -v ${WRKDIR}/boxednode/mongosh
	${REINPLACE_CMD} -e "s|'make'|'${GMAKE}'|g" \
		-e "s/if (inputIsFileUrl)/if (false)/g" \
		-e 's/(await nv_1.default(range)).pop()/{"version":"${NODEJS_PORTVERSION}"}/g' \
		-e 's/path_1.default.join(dir, tarballName)/url_1.fileURLToPath(range)/g' \
		-e "s|\$${releaseBaseUrl}/SHASUMS256.txt|${DISTDIR}/${DIST_SUBDIR}/${NODEJS_SHAFILE}|g" \
		-e 's/await node_fetch_1.default(shaSumsUrl)/{"ok":1}/g' \
		-e "s/shaSums.text()/fs_1.promises.readFile(shaSumsUrl, 'utf8')/g" \
		-e "s/catch (_a) { }/catch (_a) { console.error(_a) }/g" \
		-e "s|os_1.default.tmpdir()|'${WRKDIR}'|g" \
		${NODE_MODULES_DIR}/boxednode/lib/index.js
	${GREP} -A36 "let version;" ${NODE_MODULES_DIR}/boxednode/lib/index.js
	${REINPLACE_CMD} -e "s|'install', '--ignore-scripts', '--production'|'--version'|g" \
		${NODE_MODULES_DIR}/boxednode/lib/native-addons.js
	${GREP} "version" ${NODE_MODULES_DIR}/boxednode/lib/native-addons.js
.endif

post-patch:
	${CP} -v ${FILESDIR}/node-patches/* ${WRKSRC}/scripts/nodejs-patches

do-configure:
	${FIND} ${WRKSRC}/scripts -name "*.orig" -delete
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${NODE_MODULES_DIR}/mongodb-client-encryption/binding.gyp ${NODE_MODULES_DIR}/kerberos/binding.gyp
.for module in mongodb-client-encryption kerberos os-dns-native
	cd ${NODE_MODULES_DIR}/${module} && ${CONFIGURE_ENV} node-gyp configure --nodedir=${LOCALBASE}
.endfor

do-build:
.for module in mongodb-client-encryption kerberos os-dns-native
	cd ${NODE_MODULES_DIR}/${module} && ${MAKE_ENV} ${MAKE_CMD} BUILDTYPE=Release -C build -d
.endfor
	${REINPLACE_CMD} -E 's/"version": ".*"/"version": "${DISTVERSION}"/g' ${WRKSRC}/packages/cli-repl/package.json
	${RM} -v \
		${WRKSRC}/scripts/nodejs-patches/005-windows-escape-product-dir-abs-in-openssl-node-56111.patch \
		${WRKSRC}/scripts/nodejs-patches/006-windows-virtual-terminal-input-libuv-4688.patch
	cd ${WRKSRC} && ${MAKE_ENV} ${LOCALBASE}/bin/npm run compile-exec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/mongosh ${STAGEDIR}${PREFIX}/bin

npm-pkg-list: extract
	${GREP} registry.npmjs.org ${WRKSRC}/package-lock.json | \
		| ${SED} -E 's/^[[:space:]]+//g' \
		| ${SED} -E 's#^.*org/|.tgz",##g' \
		| ${SORT} \
		| /usr/bin/uniq \
		| ${SED} -E 's/(.*)-([^-])/\1@\2/g' \
		| ${SED} -E 's|/-/.*@|@|g' \
		> ${FILESDIR}/npm-pkg.list

.for module in mongodb-client-encryption kerberos os-dns-native mongodb-crypt-library-version glibc-version
	cd ${NODE_MODULES_DIR}/${module} && ${LOCALBASE}/bin/npm list 2>/dev/null \
		| ${GREP} UNMET \
		| ${AWK} 'BEGIN{FS="UNMET DEPENDENCY "}{print $$2}' \
		> ${FILESDIR}/npm-pkg-${module}.list
.endfor

node-modules-archive: patch
#	Comment DISTFILES, post-extract
	cd ${WRKSRC} && ${LOCALBASE}/bin/npx cross-env ${CONFIGURE_ENV} ${LOCALBASE}/bin/npm clean-install --cache ${NPM_CACHE_DIR} --no-audit --no-fund
	cd ${WRKSRC} && ${LOCALBASE}/bin/npx cross-env ${CONFIGURE_ENV} ${LOCALBASE}/bin/npm install ipv6-normalize mongodb-redact --cache ${NPM_CACHE_DIR} --no-audit --no-fund

.for module in mongodb-client-encryption kerberos os-dns-native
	${MKDIR} -v ${NODE_MODULES_DIR}/${module}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${module}-*.tgz -C ${NODE_MODULES_DIR}/${module} --strip-components 1
.endfor
	for f in ${FILESDIR}/node-modules-patches/*; do ${PATCH} -Nd ${WRKSRC} < $$f; done
	${FIND} ${WRKSRC} -name "*.orig" -or -name "*.bak" -delete

.for module in mongodb-client-encryption kerberos os-dns-native mongodb-crypt-library-version glibc-version native-machine-id
	cd ${NODE_MODULES_DIR}/${module} && ${CONFIGURE_ENV} ${LOCALBASE}/bin/npm install --ignore-scripts --cache ${NPM_CACHE_DIR} --no-audit --no-fund
.endfor

	cd ${WRKSRC} && ${TAR} cf - node_modules packages/*/node_modules | ${LOCALBASE}/bin/pv -s $$(/usr/bin/du -sAk node_modules | ${AWK} '{print $$1}')000 | ${XZ_CMD} > ${TMPDIR}/${NODE_MODULES_TARBALL}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/node${NODEJS_VERSION}/Makefile.version"
NODE_WITH_JIT!= ${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} showconfig | ${GREP} -o "JIT=on" || ${TRUE}
.if empty(NODE_WITH_JIT)
IGNORE=	www/node${NODEJS_VERSION} must be built with JIT enabled. Run '${BSDMAKE} -C ${PORTSDIR}/www/node${NODEJS_VERSION} config' to enable it.
.endif
.include <bsd.port.post.mk>
