PORTNAME=	joplin
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.12
CATEGORIES=	deskutils
PKGNAMESUFFIX=	-desktop
DISTFILES=	${DEFAULT_PLUGINS_NODE_MODULES_FILE}:prefetch \
		${APP_CLIPPER_NODE_MODULES_FILE}:prefetch

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Note taking and to-do application with synchronisation capabilities
WWW=		https://joplinapp.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	7zz:archivers/7-zip \
		git:devel/git \
		rsync:net/rsync \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libvips.so:graphics/vips \
		libsecret-1.so:security/libsecret

USES=		cargo electron:39 gmake localbase:ldflags nodejs:22,build \
		python:build

USE_GITHUB=	yes
GH_ACCOUNT=	laurent22
GH_TUPLE=	rollup:rollup:v4.9.1:rollup/rollup \
		rustwasm:wasm-pack:v0.13.1:wasm_pack/wasm-pack
# See ${WRKSRC}/packages/default-plugins/pluginRepositories.json for GH_TUPLEs for default plugins
GH_TUPLE+=	JackGruber:joplin-plugin-backup:2c3da7056e7ac39c86c2051a4fdb99d9534dd0a1:joplin_plugin_backup/packages/default-plugins/plugin-sources/io.github.jackgruber.backup

CARGO_CARGOTOML_ROLLUP=	${WRKSRC}/rollup/rust/Cargo.toml
CARGO_CARGOLOCK_ROLLUP=	${WRKSRC}/rollup/rust/Cargo.lock
CARGO_CARGOTOML_WASM_PACK=	${WRKSRC}/wasm-pack/Cargo.toml
CARGO_CARGOLOCK_WASM_PACK=	${WRKSRC}/wasm-pack/Cargo.lock
CARGO_CARGOTOML=	${CARGO_CARGOTOML_ROLLUP}
CARGO_CARGOLOCK=	${CARGO_CARGOLOCK_ROLLUP}
CARGO_CARGOLOCKS=	${CARGO_CARGOLOCK_ROLLUP} \
			${CARGO_CARGOLOCK_WASM_PACK}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

BINARY_ALIAS=	python3=${PYTHON_CMD}
SUB_FILES=	${PORTNAME}${PKGNAMESUFFIX}

BUILD_WRKSRC=	${WRKSRC}/packages/app-desktop
TEST_WRKSRC=	${WRKSRC}/packages/app-desktop

PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

USE_ELECTRON=	npm:yarn4 appbuilder prefetch extract build:builder

DEFAULT_PLUGINS_NODE_MODULES_FILE=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-default-plugins-node-modules${EXTRACT_SUFX}
APP_CLIPPER_NODE_MODULES_FILE=		${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-app-clipper-node-modules${EXTRACT_SUFX}

pre-fetch:
	@if [ ! -f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for default plugins"; \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/default-plugins/* ${WRKDIR}/node-modules-cache; \
		for dir in `${FIND} ${FILESDIR}/default-plugins -type d -depth 1 -print | ${SED} -e 's|${FILESDIR}/default-plugins||'`; do \
			cd ${WRKDIR}/node-modules-cache/$${dir} && \
			${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
				npm ci --ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error; \
			${RM} package.json package-lock.json; \
		done; \
		cd ${WRKDIR} && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/electron-create-mtree.sh node-modules-cache > \
			node-modules-cache.mtree && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} @node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}/node-modules-cache; \
	fi
	@if [ ! -f ${DISTDIR}/${APP_CLIPPER_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for app-clipper"; \
		${MKDIR} ${WRKDIR}/node-modules-cache-app-clipper; \
		${CP} -R ${FILESDIR}/app-clipper/* ${WRKDIR}/node-modules-cache-app-clipper; \
		cd ${WRKDIR}/node-modules-cache-app-clipper && \
		${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			npm ci --ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error && \
		${RM} package.json package-lock.json; \
		cd ${WRKDIR} && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/electron-create-mtree.sh node-modules-cache-app-clipper > \
			node-modules-cache-app-clipper.mtree && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${APP_CLIPPER_NODE_MODULES_FILE} @node-modules-cache-app-clipper.mtree; \
		${RM} -r ${WRKDIR}/node-modules-cache-app-clipper; \
	fi

post-extract:
	@${ECHO_MSG} "===>  Moving prefetched node modules for default plugins to ${WRKSRC}"
	@for dir in `${FIND} ${WRKDIR}/node-modules-cache -type d -depth 1 -print | ${SED} -e 's|${WRKDIR}/node-modules-cache||'`; do \
		${MV} ${WRKDIR}/node-modules-cache/$${dir}/node_modules \
			${WRKSRC}/packages/default-plugins/plugin-sources/$${dir}; \
	done
	@${ECHO_MSG} "===>  Moving prefetched node modules for app-clipper to ${WRKSRC}"
	@${MV} ${WRKDIR}/node-modules-cache-app-clipper/node_modules \
		${WRKSRC}/packages/app-clipper/popup

post-configure:
	@${ECHO_MSG} "===>   Updating Cargo.lock for ${CARGO_CARGOTOML_WASM_PACK}"
	@${CARGO_CARGO_RUN} update --manifest-path ${CARGO_CARGOTOML_WASM_PACK} \
		--verbose --verbose ${CARGO_UPDATE_ARGS}

pre-build:
	cd ${WRKSRC}/rollup/rust && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML_ROLLUP} \
		--release --verbose --verbose
	${CP} ${CARGO_TARGET_DIR}/*/libbindings_napi.so \
		${WRKSRC}/packages/turndown/node_modules/rollup/dist/rollup.freebsd-${ELECTRON_ARCH}.node
	cd ${WRKSRC}/wasm-pack && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML_WASM_PACK} \
		--release --verbose --verbose
	@${MKDIR} ${WRKSRC}/packages/onenote-converter/node_modules/binary-install/node_modules/.bin
	${CP} ${CARGO_TARGET_DIR}/*/wasm-pack \
		${WRKSRC}/packages/onenote-converter/node_modules/binary-install/node_modules/.bin
	@${MKDIR} ${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}
	${CP} ${LOCALBASE}/bin/7zz \
		${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}/7za
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn exec gulp build
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} yarn run electronRebuild
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} yarn exec gulp before-dist
	# dirty hack to avoid "EACCES: permission denied" error during electron-builder execution
	@${RM} ${WRKDIR}/.bin/python3
	@${CP} ${PYTHON_CMD} ${WRKDIR}/.bin/python3
	@${CHMOD} u+w ${WRKDIR}/.bin/python3

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}${PKGNAMESUFFIX}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 24 32 48 72 96 128 144 256 512 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${BUILD_WRKSRC}/build/icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${ELECTRON_BUILDER_APP_OUT_DIR} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR}/resources -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} yarn run test

#
# targets for port maintainer(s)
#
cargo-crates-from-multiple-lockfiles: extract
	@for lf in ${CARGO_CARGOLOCKS}; do \
		${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates.awk $${lf}; \
	done | \
	${SED} -E 's/^CARGO_CRATES=\t+/\t\t/; s/ \\$$//' | \
	${SORT} | \
	uniq | \
	${SED} -e '1s/^\t\t/CARGO_CRATES=\t/; s/$$/ \\/' | \
	${SED} -e '$$s/ \\//'

.include <bsd.port.mk>
