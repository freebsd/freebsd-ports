PORTNAME=	mongosh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.5
CATEGORIES=	databases shells net
MASTER_SITES=	https://registry.npmjs.org/mongodb-client-encryption/-/:mongocrypt \
		https://registry.npmjs.org/kerberos/-/:kerberos \
		https://registry.npmjs.org/os-dns-native/-/:dns \
		https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONFULL}/:modules
		# https://nodejs.org/dist/latest-v${NODEJS_VERSION}.x/:node
DISTFILES=	mongodb-client-encryption-${MONGO_CRYPT_VER}.tgz:mongocrypt \
		kerberos-${KERBEROS_VER}.tgz:kerberos \
		os-dns-native-${OSDNSNATIVE_VER}.tgz:dns \
		${NODE_MODULES_TARBALL}:modules \
		# ${NODEJS_TARBALL}:node \
		# SHASUMS256.txt:node
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	fabien.amelinck+freebsd@advens.fr
COMMENT=	MongoDB Shell CLI REPL
WWW=		https://github.com/mongodb-js/mongosh/

LICENSE=	APACHE20

BROKEN_aarch64=	fails to compile: nx/src/native/index.js:147 throw new Error(`Unsupported architecture on FreeBSD: ${arch}`)
BROKEN_i386=	fails to compile: nx/src/native/index.js:147 throw new Error(`Unsupported architecture on FreeBSD: ${arch}`)

FETCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	bash>0:shells/bash \
		brotli>=1.0.9,1:archivers/brotli \
		c-ares>=1.17.2:dns/c-ares \
		libnghttp2>=1.45.1:www/libnghttp2 \
		libuv>=1.42.0:devel/libuv \
		objdump:devel/binutils \
		git>0:devel/git
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss
LIB_DEPENDS=	libmongocrypt.so:databases/libmongocrypt \
		libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv

USES=		compiler:c++11-lib gmake gssapi:mit localbase pkgconfig nodejs:20,build python:build ssl

USE_GITHUB=	yes
GH_ACCOUNT=	VultureProject
GH_PROJECT=	mongosh

MPROTECT_DISABLE=	bin/mongosh

CXXFLAGS+=	-DNODE_API_EXPERIMENTAL \
		-DNODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT

CUSTOM_ENV=	SEGMENT_API_KEY=dummy BUILD_TYPE=dynamic
CONFIGURE_ENV=	${CUSTOM_ENV}
MAKE_ENV=	${CUSTOM_ENV} \
		NODE_JS_VERSION=file://${_DISTDIR}/${NODEJS_TARBALL} \
		BOXEDNODE_CONFIGURE_ARGS="--shared-brotli,--shared-cares,--shared-libuv,--shared-nghttp2,--shared-zlib,--shared-openssl,--openssl-use-def-ca-store,--without-npm"
REINPLACE_ARGS=	-i ''

MONGO_CRYPT_VER=6.0.0
KERBEROS_VER=	2.1.0
OSDNSNATIVE_VER=1.2.0
NODE_MODULES_DIR=	${WRKSRC}/node_modules
NODE_MODULES_TARBALL=	${PORTNAME}-${DISTVERSIONFULL}-node-modules.tar.xz
NPM_CACHE_DIR=	/tmp/.npm
NODEJS_TARBALL=	node-v${NODEJS_PORTVERSION}.tar.gz

post-fetch:
.if !exists(/tmp/checkpoint)
	${FETCH_CMD} -o ${_DISTDIR} https://nodejs.org/dist/v${NODEJS_PORTVERSION}/${NODEJS_TARBALL}
	${FETCH_CMD} -o ${_DISTDIR} https://nodejs.org/dist/v${NODEJS_PORTVERSION}/SHASUMS256.txt
	${TOUCH} /tmp/checkpoint
.endif

post-extract:
.if !exists(${NODE_MODULES_DIR})
	${TAR} -xzf /${_DISTDIR}/${NODE_MODULES_TARBALL} -C ${WRKSRC}
	${REINPLACE_CMD} -e "s/'make'/'gmake'/g" \
		-e "s/'V='/'V=0'/g" \
		-e 's/(await (0, nv_1.default)(range)).pop()/{"version": "${NODEJS_PORTVERSION}"}/g' \
		-e "s|\$${releaseBaseUrl}/\(SHASUMS256.txt\)|${_DISTDIR}/\1|g" \
		-e 's/await (0, node_fetch_1.default)(shaSumsUrl)/{"ok":1}/g' \
		-e "s/shaSums.text()/fs_1.promises.readFile(shaSumsUrl, 'utf8')/g" \
		-e "s/catch (_a) { }/catch (_a) { console.error(_a) }/g" \
		${NODE_MODULES_DIR}/boxednode/lib/index.js
	${GREP} -A20 "const shaSumsUrl" ${NODE_MODULES_DIR}/boxednode/lib/index.js
	${REINPLACE_CMD} -e "s|\('install',\) \('--ignore-scripts'\)|\1 '--offline', '--cache ${NPM_CACHE_DIR}', \2|g" \
		${NODE_MODULES_DIR}/boxednode/lib/native-addons.js
	${GREP} "ignore-scripts" ${NODE_MODULES_DIR}/boxednode/lib/native-addons.js
.endif

post-patch:
	${FIND} ${WRKSRC}/scripts -name "*.orig" -delete
	${CP} -v ${FILESDIR}/node-patches/* ${WRKSRC}/scripts/nodejs-patches

do-configure:
.for module in mongodb-client-encryption kerberos os-dns-native
	cd ${NODE_MODULES_DIR}/${module} && ${CONFIGURE_ENV} node-gyp configure --nodedir=${LOCALBASE}
.endfor

do-build:
.for module in mongodb-client-encryption kerberos os-dns-native
	cd ${NODE_MODULES_DIR}/${module} && ${MAKE_ENV} ${MAKE_CMD} BUILDTYPE=Release -C build -d
.endfor
	${REINPLACE_CMD} 's/"version": "0.0.0-dev.0"/"version": "${DISTVERSION}"/g' ${WRKSRC}/packages/cli-repl/package.json
	cd ${WRKSRC} && ${MAKE_ENV} /usr/local/bin/npm run compile-exec

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
	cd ${NODE_MODULES_DIR}/${module} && /usr/local/bin/npm list 2>/dev/null \
		| ${GREP} UNMET \
		| ${AWK} 'BEGIN{FS="UNMET DEPENDENCY "}{print $$2}' \
		> ${FILESDIR}/npm-pkg-${module}.list
.endfor

node-modules-archive: build
	${RM} -R ${NODE_MODULES_DIR}
.for module in mongodb-client-encryption kerberos os-dns-native
	${MKDIR} -v ${NODE_MODULES_DIR}/${module}
	${TAR} -xzf ${_DISTDIR}/${module}-*.tgz -C ${NODE_MODULES_DIR}/${module} --strip-components 1
.endfor
	for f in ${FILESDIR}/node-modules-patches/*; do patch -N -d ${WRKSRC} < $$f; done

	cd ${WRKSRC} && npx cross-env PUPPETEER_SKIP_DOWNLOAD=1 /usr/local/bin/npm install --cache ${NPM_CACHE_DIR}

.for module in mongodb-client-encryption kerberos os-dns-native mongodb-crypt-library-version glibc-version
	/usr/local/bin/npm cache add $$(cat ${FILESDIR}/npm-pkg-${module}.list) --cache ${NPM_CACHE_DIR} || true
	cd ${NODE_MODULES_DIR}/${module} && ${CONFIGURE_ENV} /usr/local/bin/npm install --ignore-scripts --cache ${NPM_CACHE_DIR}
.endfor
	${FIND} ${WRKSRC} -name "*.orig" -or -name "*.bak" -delete

	cd ${WRKSRC} && ${TAR} -cJf /tmp/${NODE_MODULES_TARBALL} node_modules

.include <bsd.port.mk>
.include "${PORTSDIR}/www/node${NODEJS_VERSION}/Makefile.version"
