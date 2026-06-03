PORTNAME=	qmd
DISTVERSION=	2.1.0
CATEGORIES=	deskutils
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	On-device hybrid search for markdown files
WWW=		https://github.com/tobi/qmd

LICENSE=	MIT

FETCH_DEPENDS=	jq:textproc/jq \
		npm:www/npm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		gmake nodejs:build,run sqlite

PACKAGE_NAME=	@tobilu/qmd

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

NODE_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/:S/i386/ia32/:S/powerpc64le/ppc64le/:S/powerpc64/ppc64/:C/armv[67]/arm/}
PLIST_SUB=	NODE_ARCH=${NODE_ARCH}

# Native modules that require building
DEP_MODULES=			better_sqlite3 node_llama_cpp sqlite_vec tree_sitter_go tree_sitter_javascript tree_sitter_python tree_sitter_rust tree_sitter_typescript web_tree_sitter
dep_better_sqlite3_npm_name=		better-sqlite3
dep_better_sqlite3_version=		12.8.0
dep_node_llama_cpp_npm_name=		node-llama-cpp
dep_node_llama_cpp_version=		3.18.1
dep_sqlite_vec_npm_name=		sqlite-vec
dep_sqlite_vec_version=			0.1.9
dep_tree_sitter_go_npm_name=		tree-sitter-go
dep_tree_sitter_go_version=		0.23.4
dep_tree_sitter_javascript_npm_name=	tree-sitter-javascript
dep_tree_sitter_javascript_version=	0.23.1
dep_tree_sitter_python_npm_name=	tree-sitter-python
dep_tree_sitter_python_version=		0.23.4
dep_tree_sitter_rust_npm_name=		tree-sitter-rust
dep_tree_sitter_rust_version=		0.24.0
dep_tree_sitter_typescript_npm_name=	tree-sitter-typescript
dep_tree_sitter_typescript_version=	0.23.2
dep_web_tree_sitter_npm_name=		web-tree-sitter
dep_web_tree_sitter_version=		0.26.7

SQLITE_VEC_VERSION=	${dep_sqlite_vec_version}

.for dep in ${DEP_MODULES}
DISTFILES+=	${dep:S/_/-/g}-${dep_${dep}_version}${EXTRACT_SUFX}
.endfor
DISTFILES+=	sqlite-vec-src-${SQLITE_VEC_VERSION}${EXTRACT_SUFX}:sqlite_vec_src

DD=	${DISTDIR}/${DIST_SUBDIR}

do-fetch:
	@${MKDIR} ${DD}
	@if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} npm_config_force=true ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi
.for dep in ${DEP_MODULES}
	@if ! [ -f ${DD}/${dep:S/_/-/g}-${dep_${dep}_version}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_${dep}_npm_name} ${dep_${dep}_version} \
			${FILESDIR}/package-lock-${dep:S/_/-/g}.json \
			${DD}/${dep:S/_/-/g}-${dep_${dep}_version}${EXTRACT_SUFX}; \
	fi
.endfor
	@if ! [ -f ${DD}/sqlite-vec-src-${SQLITE_VEC_VERSION}${EXTRACT_SUFX} ]; then \
		${FETCH_CMD} -o ${DD}/sqlite-vec-src-${SQLITE_VEC_VERSION}${EXTRACT_SUFX} \
			https://github.com/asg017/sqlite-vec/archive/refs/tags/v${SQLITE_VEC_VERSION}.tar.gz; \
	fi

do-build:
	@${ECHO_MSG} "====> Building sqlite-vec for FreeBSD..."
	@${MKDIR} ${WRKDIR}/sqlite-vec-src-${SQLITE_VEC_VERSION} && \
		${TAR} -xf ${DD}/sqlite-vec-src-${SQLITE_VEC_VERSION}${EXTRACT_SUFX} -C ${WRKDIR}/sqlite-vec-src-${SQLITE_VEC_VERSION} --strip-components 1
	@cd ${WRKDIR}/sqlite-vec-src-${SQLITE_VEC_VERSION} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} loadable VERSION=${SQLITE_VEC_VERSION} CFLAGS="${CFLAGS} -I${LOCALBASE}/include -include sys/types.h"
	@${CP} ${WRKDIR}/sqlite-vec-src-${SQLITE_VEC_VERSION}/dist/vec0.so ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/sqlite-vec/
	@${ECHO_MSG} "====> Building better-sqlite3 for FreeBSD..."
	@cd ${WRKDIR}/better-sqlite3-${dep_better_sqlite3_version}/node_modules/${dep_better_sqlite3_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} && \
		${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/better-sqlite3/build/Release && \
		${CP} build/Release/better_sqlite3.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/better-sqlite3/build/Release/
	@${ECHO_MSG} "====> Building node-llama-cpp for FreeBSD..."
	@cd ${WRKDIR}/node-llama-cpp-${dep_node_llama_cpp_version}/node_modules/${dep_node_llama_cpp_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} 2>&1 || true
	@${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/node-llama-cpp/llama/localBuilds/freebsd-x64/Release 2>/dev/null || true
	@${CP} ${WRKDIR}/node-llama-cpp-${dep_node_llama_cpp_version}/node_modules/${dep_node_llama_cpp_npm_name}/llama/localBuilds/freebsd-x64/Release/*.so ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/node-llama-cpp/llama/localBuilds/freebsd-x64/Release/ 2>/dev/null || true
	@${ECHO_CMD} '{"version":"3.18.1","nodeAbi":99,"platform":"freebsd","arch":"x64"}' > ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/node-llama-cpp/llama/lastBuild.json
	@${ECHO_MSG} "====> Building tree-sitter modules for FreeBSD..."
.for dep in tree_sitter_go tree_sitter_javascript tree_sitter_python tree_sitter_rust tree_sitter_typescript web_tree_sitter
	@cd ${WRKDIR}/${dep:S/_/-/g}-${dep_${dep}_version}/node_modules/${dep_${dep}_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} && \
		${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/${dep_${dep}_npm_name}/build/Release && \
		${CP} build/Release/*.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/${dep_${dep}_npm_name}/build/Release/ 2>/dev/null || true
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	@cd ${WRKSRC}/node_modules/${PACKAGE_NAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/qmd
	@${ECHO_CMD} 'exec ${PREFIX}/bin/node ${PREFIX}/lib/node_modules/${PORTNAME}/dist/cli/qmd.js "$$@"' \
		>> ${STAGEDIR}${PREFIX}/bin/qmd
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/qmd
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/node-llama-cpp/llama/localBuilds -type d -exec ${CHMOD} 777 {} \; 2>/dev/null || true
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/node-llama-cpp/llama/localBuilds -type f -exec ${CHMOD} 666 {} \; 2>/dev/null || true
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME} -name prebuilds -type d -exec ${RM} -rf {} +
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME} \( -name "*.node" -or -name "*.so" \) | ${XARGS} ${STRIP_CMD}

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -type d -empty -delete
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
