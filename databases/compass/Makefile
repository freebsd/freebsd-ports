PORTNAME=	compass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.43.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	https://cloud.mongodb.com/static/font/:fonts \
		https://registry.npmjs.org/fs-xattr/-/:fs_xattr \
		https://registry.npmjs.org/kerberos/-/:kerberos \
		https://registry.npmjs.org/mongodb-client-encryption/-/:mongoclienc \
		https://registry.npmjs.org/os-dns-native/-/:dns
DISTFILES=	EuclidCircularA-Semibold-WebXL.woff2:fonts \
		EuclidCircularA-Semibold-WebXL.woff:fonts \
		EuclidCircularA-SemiboldItalic-WebXL.woff2:fonts \
		EuclidCircularA-SemiboldItalic-WebXL.woff:fonts \
		EuclidCircularA-Medium-WebXL.woff2:fonts \
		EuclidCircularA-Medium-WebXL.woff:fonts \
		EuclidCircularA-MediumItalic-WebXL.woff2:fonts \
		EuclidCircularA-MediumItalic-WebXL.woff:fonts \
		EuclidCircularA-Regular-WebXL.woff2:fonts \
		EuclidCircularA-Regular-WebXL.woff:fonts \
		EuclidCircularA-RegularItalic-WebXL.woff2:fonts \
		EuclidCircularA-RegularItalic-WebXL.woff:fonts \
		fs-xattr-${NPM_FSXATTR_VER}.tgz:fs_xattr \
		kerberos-${NPM_KERBEROS_VER}.tgz:kerberos \
		mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz:mongoclienc \
		os-dns-native-${NPM_OSDNSNATIVE_VER}.tgz:dns
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	The GUI for MongoDB
WWW=		https://www.mongodb.com/products/compass/

LICENSE=	SSPLv1
LICENSE_NAME=	Server Side Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DISTCACHEFILES=	${DISTCACHEFILE_npm} \
		${DISTCACHEFILE_gyp} \
		${DISTCACHEFILE_yarn} \
		${DISTCACHEFILE_cargo}
DISTCACHEFILE_npm=	${DISTDIR}/${DIST_SUBDIR}/dotnpm-${DISTVERSION}.tar.xz
DISTCACHEFILE_gyp=	${DISTDIR}/${DIST_SUBDIR}/dotgyp-${DISTVERSION}.tar.xz
DISTCACHEFILE_yarn=	${DISTDIR}/${DIST_SUBDIR}/dotyarn-${DISTVERSION}.tar.xz
DISTCACHEFILE_cargo=	${DISTDIR}/${DIST_SUBDIR}/dotcargo-${DISTVERSION}.tar.xz
APPMODFILE=	${WRKDIR}/compass_node_modules.tar

ONLY_FOR_ARCHS=	aarch64 amd64
USES=		gettext-runtime gl gnome iconv jpeg nodejs:env python:build \
		xorg
USE_GL=		gbm gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst
USE_LDCONFIG=	${DATADIR}

USE_GITHUB=	yes
GH_TUPLE=	mongodb-js:compass:${DISTVERSIONPREFIX}${DISTVERSION} \
		mongodb-js:reflux-state-mixin:e050454cb3be029c3e7fd2ee6a08111e4d15161f:reflux \
		mongodb-js:zstd:${DISTVERSIONPREFIX}${MONGO_ZSTD_VER}:zstd \
		napi-rs:napi-rs:@napi-rs/cli@${NPM_NAPI_VER}:napi

FETCH_DEPENDS=	npm-node${NODEJS_VERSION}>0:www/npm-node${NODEJS_VERSION} \
		yarn-node${NODEJS_VERSION}>0:www/yarn-node${NODEJS_VERSION} \
		cargo:lang/rust
# Do not use USES=cmake, because compass itself does not build with cmake.
# The npm module it depends on uses cmake to build.
BUILD_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm-node${NODEJS_VERSION}>0:www/npm-node${NODEJS_VERSION} \
		yarn-node${NODEJS_VERSION}>0:www/yarn-node${NODEJS_VERSION} \
		cmake:devel/cmake-core \
		cargo:lang/rust \
		pkg-config:devel/pkgconf \
		zip:archivers/zip
LIB_DEPENDS=	libmongocrypt.so:databases/libmongocrypt \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libdbus-1.so:devel/dbus \
		libicuuc.so:devel/icu \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
		libnotify.so:devel/libnotify \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libre2.so:devel/re2 \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libdav1d.so:multimedia/dav1d \
		libva.so:multimedia/libva \
		libopenh264.so:multimedia/openh264 \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig
TEST_DEPENDS=	Xvfb:x11-servers/xorg-server@xvfb
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
CUPS_LIB_DEPENDS=	libcups.so:print/cups
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
SNDIO_PREVENTS=		ALSA PULSEAUDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

PORTDOCS=	AUTHORS \
		CODE_OF_CONDUCT.md \
		CONTRIBUTING.md \
		README.md \
		THIRD-PARTY-NOTICES.md

# Options have to be in accord with electron29.
OPTIONS_DEFINE=		DOCS CUPS PIPEWIRE
OPTIONS_DEFAULT=	DOCS CUPS PIPEWIRE SNDIO GSSAPI_BASE
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA PULSEAUDIO SNDIO
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

PATCH_STRIP=	-p1

CXXFLAGS+=	-DNODE_API_EXPERIMENTAL \
		-DNODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT
MAKE_ENV+=	${PATH_ENV}
MAKE_ENV+=	HOME=${WRKDIR}
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
.if defined(QUIET)
MAKE_ENV+=	QUIET=yes
.else
MAKE_ENV+=	DEBUG=true
.endif
PATH_ENV=	PATH=$${PATH}:${WRKSRC}/node_modules/.bin
PATH_ENV_zstd=	PATH=$${PATH}:${MONGO_ZSTD_DIR}/node_modules/.bin
TEST_ENV+=	HOME=${WRKDIR}
TEST_ENV+=	PATH=$${PATH}:${WRKSRC}/node_modules/.bin
HADRON_ENV+=	PATH=$${PATH}:${WRKSRC}/node_modules/.bin
HADRON_ENV+=	HADRON_SKIP_INSTALLER=true
HADRON_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
HADRON_ENV+=	APPMOD=${APPMODFILE}
HADRON_ENV+=	DEBUG=hadron*

ELECTRON_DIR=	${.CURDIR}/../../devel/electron29
.include	"${ELECTRON_DIR}/Makefile.version"
ELECTRON_DOWNLOAD_URL=	https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	/sbin/sha256 -q -s ${ELECTRON_DOWNLOAD_URL}
.if defined(ARCH) && ${ARCH} == amd64
ELECTRON_ARCH=	x64
NAPI_TARGET=	x86_64-unknown-freebsd
.elif defined(ARCH) && ${ARCH} == arm64
ELECTRON_ARCH=	arm64
NAPI_TARGET=	aarch64-unknown-freebsd
.endif

MONGO_CLIENC_VER=	6.0.0
MONGO_ZSTD_VER=		1.0.0
NPM_FSXATTR_VER=	0.3.1
NPM_KERBEROS_VER=	2.1.0
NPM_NAPI_VER=		2.9.0
COMPASS_DIR=		${WRKSRC}/packages/compass
MONGO_ZSTD_DIR=		${WRKDIR}/zstd-${MONGO_ZSTD_VER}
NODE_MODULES_DIR=       ${WRKSRC}/node_modules
NPM_NAPI_DIR=	${WRKDIR}/napi-rs--napi-rs-cli-${NPM_NAPI_VER}
DISTTMP_DIR=		${WRKDIR}/dist-tmp

NPM_OSDNSNATIVE_VER=	1.2.1

post-fetch: ${DISTCACHEFILES}

${DISTCACHEFILE_npm}:
	# Cache npm modules to avoid network connection at later stages
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm cache add \
		$$(cat ${FILESDIR}/package-*.list)

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_DEFAULT} -C ${WRKDIR}
	${MKDIR} ${NODE_MODULES_DIR}
	${REINPLACE_CMD} -E ' \
		s,^( *"electron"): *"[0-9~^].*"(.*)$$,\1: "${ELECTRON_VER}"\2,; \
		' ${WRKSRC}/package-lock.json
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm --ignore-scripts -- install
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm cache add \
		electron@${ELECTRON_VER} \
		$$(npm view electron@${ELECTRON_VER:C/\.[^\.]*$//} version | \
		${TAIL} -1 | ${SED} -E 's, .*,,')
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm --ignore-scripts -- install \
		electron@~${ELECTRON_VER}

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/fs-xattr-${NPM_FSXATTR_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --ignore-scripts install node-gyp-cache@0.2.1
	${RM} -rd ${WRKDIR}/package

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --ignore-scripts install
	${RM} -rd ${WRKDIR}/package

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/os-dns-native-${NPM_OSDNSNATIVE_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --ignore-scripts install
	${RM} -rd ${WRKDIR}/package

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_zstd} -C ${WRKDIR}
	${MKDIR} ${MONGO_ZSTD_DIR}/node_modules
	cd ${MONGO_ZSTD_DIR} && \
		${PATCH} -p1 < ${FILESDIR}/mongodb-js-zstd.patch
	cd ${MONGO_ZSTD_DIR} && \
		${SETENV} ${MAKE_ENV} ${PATH_ENV_zstd} \
		npm --ignore-scripts -- install
	${RM} -rd ${MONGO_ZSTD_DIR}

	# Without npm cache verify, installing
	# mongodb-tools@https://codeload... fails.
	# if npm cache verify fails by 'too many open files',
	# set MAX_FILES_compass=16384 in poudriere.conf.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm cache verify

	# Back up npm cache
	cd ${WRKDIR} && ${TAR} cJf ${DISTCACHEFILE_npm} .npm

${DISTCACHEFILE_gyp}:
	# To prepare cache cached by node-gyp-cache when rebuilding
	# fs-xattr, mongodb-client-encryption and os-dns-native,
	# install node-gyp-cache and do
	# npm exec node-gyp-cache rebuild for fs-xattr,
	# npm run install for mongodb-client-encryption and
	# npm run install for os-dns-native
	# which is OK to fail here (because of python absent).
	${ECHO} "node_gyp = node-gyp-cache" >> ${WRKDIR}/.npmrc

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/fs-xattr-${NPM_FSXATTR_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm install node-gyp-cache@0.2.1
	-cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm exec node-gyp-cache rebuild
	${RM} -rd ${WRKDIR}/package /tmp/work

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm install node-gyp-cache@0.2.1
	-cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm run install
	${RM} -rd ${WRKDIR}/package /tmp/work

	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/os-dns-native-${NPM_OSDNSNATIVE_VER}.tgz \
		-C ${WRKDIR}
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm install node-gyp-cache@0.2.1
	-cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm run install

	# Back up node-gyp-cache cache
	cd ${WRKDIR} && ${TAR} cJf ${DISTCACHEFILE_gyp} .cache

${DISTCACHEFILE_yarn}:
	# Do yarn install to cache node modules for napi-rs-cli.
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_napi} -C ${WRKDIR}
	${MKDIR} ${NPM_NAPI_DIR}/node_modules
	cd ${NPM_NAPI_DIR} && ${PATCH} -p1 < ${FILESDIR}/napi-cli.patch
	cd ${NPM_NAPI_DIR} && ${SETENV} ${MAKE_ENV} yarn install

	# Back up yarn cache
	cd ${NPM_NAPI_DIR} && ${TAR} cJf ${DISTCACHEFILE_yarn} .yarn

${DISTCACHEFILE_cargo}:
	# Cache cargo crates for zstd.
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_zstd} -C ${WRKDIR}
	cd ${MONGO_ZSTD_DIR} && ${SETENV} ${MAKE_ENV} \
		cargo fetch
	# Back up cargo cache
	cd ${WRKDIR} && ${TAR} cJf ${DISTCACHEFILE_cargo} .cargo

post-extract:
	# Restore npm and node-gyp-cache cache
	${TAR} xf ${DISTCACHEFILE_npm} -C ${WRKDIR}
	${TAR} xf ${DISTCACHEFILE_gyp} -C ${WRKDIR}
	${TAR} xf ${DISTCACHEFILE_cargo} -C ${WRKDIR}

	# Fonts
	-${MKDIR} ${WRKSRC}/packages/compass/src/app/fonts
	for font in ${DISTDIR}/${DIST_SUBDIR}/*.woff*; do \
		${INSTALL_DATA} $${font} \
			${WRKSRC}/packages/compass/src/app/fonts; \
	done

pre-build:
	# Prepare kerberos
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/kerberos-${NPM_KERBEROS_VER}.tgz \
		-C ${WRKDIR}
	cd ${WRKDIR}/package && ${PATCH} -p1 < ${FILESDIR}/kerberos.patch
.  if empty(PORT_OPTIONS:MGSSAPI_MIT)
	cd ${WRKDIR}/package && ${PATCH} -p1 < ${FILESDIR}/kerberos-heimdal.patch
.  endif
	${FIND} ${WRKDIR}/package -name \*.orig -or -name \*.bak -delete
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${WRKDIR}/package
	${RM} -rd ${WRKDIR}/package

	# Prepare mongodb-client-encryption
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz \
		-C ${WRKDIR}
	cd ${WRKDIR}/package && ${PATCH} -p1 < ${FILESDIR}/mongodb-client-encryption.patch
	${REINPLACE_CMD} -E \
		's|^(.*\.include_dir.*)$$|\1 "/usr/include", "${PREFIX}/include"|' \
		${WRKDIR}/package/binding.gyp
	${REINPLACE_CMD} -E \
		"s|^( *').*(lib.*-static.*\.a)('.*)$$|\1${PREFIX}/lib/\2\3|" \
		${WRKDIR}/package/binding.gyp
	${REINPLACE_CMD} -E \
		-e 's|("chai"): "\^4\.3\.7"|\1: "^4.0.0"|' \
		-e 's|("eslint"): "\^8\.46\.0"|\1: "^8.0.0"|' \
		-e 's|("@typescript-eslint\/parser"): "\^6\.3\.0"|\1: "^6.0.0"|' \
		${WRKDIR}/package/package.json
	${FIND} ${WRKDIR}/package -name \*.orig -or -name \*.bak -delete
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --offline -- install node-gyp-cache@0.2.1
	${ECHO} "node_gyp = node-gyp-cache" >> ${WRKDIR}/.npmrc
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		node-gyp rebuild --python=${PYTHON_CMD}
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${WRKDIR}/package
	${RM} -rd ${WRKDIR}/package

	# Prepare fs-xattr
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/fs-xattr-${NPM_FSXATTR_VER}.tgz \
		-C ${WRKDIR}
	cd ${WRKDIR}/package && ${PATCH} -p1 < ${FILESDIR}/fs-xattr.patch
	${CP} ${FILESDIR}/xattr.h ${WRKDIR}/package/src
	${CP} ${FILESDIR}/xattr_api.c ${WRKDIR}/package/src
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --offline -- install node-gyp-cache@0.2.1
	# ${ECHO} "node_gyp = node-gyp-cache" >> ${WRKDIR}/.npmrc
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm exec node-gyp-cache rebuild --python=${PYTHON_CMD}
	${FIND} ${WRKDIR}/package -name \*.orig -or -name \*.bak -delete
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${WRKDIR}/package
	${RM} -rd ${WRKDIR}/package

	# Prepare os-dns-native
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/os-dns-native-${NPM_OSDNSNATIVE_VER}.tgz \
		-C ${WRKDIR}
	cd ${WRKDIR} && ${PATCH} -p0 < ${FILESDIR}/os-dns-native.patch
	${MKDIR} ${WRKDIR}/package/node_modules
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm --offline -- install node-gyp-cache@0.2.1
	${ECHO} "node-gyp = node-gyp-cache" >> ${WRKDIR}/.npmrc
	cd ${WRKDIR}/package && ${SETENV} ${MAKE_ENV} \
		PATH=${PATH}:${WRKDIR}/package/node_modules/.bin \
		npm run install
	${FIND} ${WRKDIR}/package -name \*.orig -or -name \*.bak -delete
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${WRKDIR}/package
	${RM} -rd ${WRKDIR}/package

	# Prepare napi-rs-cli (for mongodb-js-zstd)
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_napi} -C ${WRKDIR}
	${TAR} xf ${DISTCACHEFILE_yarn} -C ${NPM_NAPI_DIR}
	${MKDIR} ${NPM_NAPI_DIR}/node_modules
	cd ${NPM_NAPI_DIR} && ${PATCH} -p1 < ${FILESDIR}/napi-cli.patch
	cd ${NPM_NAPI_DIR} && ${SETENV} ${MAKE_ENV} yarn install
	cd ${NPM_NAPI_DIR} && ${SETENV} ${MAKE_ENV} \
		PATH=$${PATH}:${NPM_NAPI_DIR}/node_modules/.bin npm run build
	${FIND} ${NPM_NAPI_DIR} -name \*.orig -or -name \*.bak -delete
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${NPM_NAPI_DIR}/cli

	# Prepare mongodb-js-zstd.
	${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_zstd} -C ${WRKDIR}

	# Install node_modules for zstd.
	${MKDIR} ${MONGO_ZSTD_DIR}/node_modules
	cd ${MONGO_ZSTD_DIR} && \
		${PATCH} -p1 < ${FILESDIR}/mongodb-js-zstd.patch
	cd ${MONGO_ZSTD_DIR} && \
		${SETENV} ${MAKE_ENV} ${PATH_ENV_zstd} \
		npm --offline -- install \
		${WRKDIR}/napi-rs-cli-${NPM_NAPI_VER}.tgz
	cd ${MONGO_ZSTD_DIR} && \
		${SETENV} ${MAKE_ENV} ${PATH_ENV_zstd} CARGO_NET_OFFLINE=true \
		napi build --platform --release --target ${NAPI_TARGET} && \
		${SETENV} ${MAKE_ENV} ${PATH_ENV_zstd} ${INSTALL_LIB} \
		zstd.freebsd-${ELECTRON_ARCH}.node npm/freebsd-${ELECTRON_ARCH}/
	${FIND} ${MONGO_ZSTD_DIR} -name \*.orig -or -name \*.bak -delete
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack file:${MONGO_ZSTD_DIR}
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} npm pack \
		file:${MONGO_ZSTD_DIR}/npm/freebsd-${ELECTRON_ARCH}

	# Replace "git+ssh:" and "github:" entry with "file:"
	# to exported tarballs.
	${REINPLACE_CMD} -E ' \
		s,"(resolved|from|version)": "git\+ssh:.*/reflux-state-mixin\.git.*","\1": "file://${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_reflux}",; \
		s,"(reflux-state-mixin|resolved|from)": "(.+@)?github:mongodb-js/reflux-state-mixin(.[0-9a-f]+)?","\1": "file://${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_reflux}",; \
		' ${WRKSRC}/package-lock.json

	for pjson in $$(find ${WRKSRC} -name package.json -print); do \
		${REINPLACE_CMD} -E ' \
		s,"(reflux-state-mixin)": "github:mongodb-js/reflux-state-mixin","\1": "file://${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_reflux}",; \
		' $${pjson}; done

	# Install node modules
	${MKDIR} ${NODE_MODULES_DIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --offline \
		${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_reflux} \
		${WRKDIR}/fs-xattr-${NPM_FSXATTR_VER}.tgz \
		${WRKDIR}/kerberos-${NPM_KERBEROS_VER}.tgz \
		${WRKDIR}/napi-rs-cli-${NPM_NAPI_VER}.tgz \
		${WRKDIR}/mongodb-js-zstd-*.tgz \
		${WRKDIR}/mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz \
		${WRKDIR}/os-dns-native-${NPM_OSDNSNATIVE_VER}.tgz

	# Install electron without build.
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npm --offline --omit-dev --ignore-scripts -- install \
		electron@${ELECTRON_VER}

	# Install node modules for production (APPMOD)
	${MKDIR} ${DISTTMP_DIR}/node_modules
	cd ${DISTTMP_DIR} && ${SETENV} ${MAKE_ENV} \
		npm --offline --omit-dev -- install \
		${WRKDIR}/kerberos-${NPM_KERBEROS_VER}.tgz \
		${WRKDIR}/mongodb-client-encryption-${MONGO_CLIENC_VER}.tgz
	-${RM} ${APPMODFILE}
	${TAR} -cf ${APPMODFILE} --exclude python3 \
		-C ${DISTTMP_DIR} node_modules

do-build:
	# Set up download zip file for electron-packager
	cd ${WRKSRC}/node_modules/electron-packager/src && \
		${PATCH} -p1 < ${FILESDIR}/electron-packager.patch
	cd ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} && \
		zip -q -r ${WRKDIR}/electron-v${ELECTRON_VER}-freebsd-${ELECTRON_ARCH}.zip .

	# Install electron
	${CP} -R ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		${NODE_MODULES_DIR}/electron/dist
	${ECHO} "electron" > ${NODE_MODULES_DIR}/electron/path.txt

	# Build MongoDB Compass
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} lerna run bootstrap --stream
	cd ${WRKSRC} && ${SETENV} ${HADRON_ENV} npm run package-compass

do-install:
	# Install MongoDB Compass
	-${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/packages/compass/app-icons/linux/mongodb-compass.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	-${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${FILESDIR}/mongodb-compass.desktop \
		${STAGEDIR}${DESKTOPDIR}/
	-${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${COMPASS_DIR}/dist/MongoDB* && ${TAR} cf - .  | \
		${TAR} xf - -C ${STAGEDIR}${DATADIR}
.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/gen
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${RLN} ${STAGEDIR}${DATADIR}/MongoDB* \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${FIND} ${STAGEDIR}${DATADIR} -name \*.node -exec ${STRIP_CMD} {} \;

	# Install documents
do-install-DOCS-on:
	-${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-stage:
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR_REL}/resources/app.asar.unpacked/build \
		-type f -o -type l > ${WRKDIR}/PLIST.unpacked
	cd ${WRKDIR} && ${SED} -i -e "/PLIST.unpacked/r PLIST.unpacked" ${TMPPLIST}

do-test:
	cd ${WRKSRC}/packages/compass && \
		${SETENV} ${TEST_ENV} \
		xvfb-maybe electron-mocha --no-sandbox "./src/main/*.spec.*"

post-clean:
.for file in ${DISTCACHEFILES} compass_node_modules.tar
	${RM} ${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor

.include <bsd.port.mk>
