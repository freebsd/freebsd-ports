PORTNAME=	opencc-cli
DISTVERSION=	1.3.1
CATEGORIES=	chinese
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Chinese Convert CLI - Node.js binding with command line interface
WWW=		https://github.com/BYVoid/OpenCC

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=	npm:www/npm

USES=		compiler:c++20-lang gmake nodejs:run python:build

WRKSRC=		${WRKDIR}/opencc-${DISTVERSION}

PACKAGE_NAME=	opencc

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

do-fetch:
	@${MKDIR} ${DD}
	@if ! [ -f ${DD}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching ${DISTNAME}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

do-build:
	@cd ${WRKSRC}/node_modules/${PACKAGE_NAME} && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} \
			node-gyp rebuild --nodedir=${LOCALBASE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	# remove prebuilt binaries for other platforms and their empty directories
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/prebuilds -name "*.node" -delete
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/prebuilds -type d -mindepth 1 -empty -delete
	# create directory for FreeBSD prebuilt binary and copy the built one
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64
	@${CP} ${WRKSRC}/node_modules/${PACKAGE_NAME}/build/Release/opencc.node \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64/
	# remove build artifacts, source code, and build tooling
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/build
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/src
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/deps
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/data
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/scripts
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/binding.gyp
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/*.gypi
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/*.orig
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/opencc.cc
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/opencc_config.h
	# remove all nested node_modules except node-gyp-build and .bin (the only runtime dependencies)
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules -mindepth 1 -maxdepth 1 \
		! -name node-gyp-build ! -name .bin -exec ${RM} -r {} +
	# remove broken symlinks from nested .bin (if it still exists)
	@if [ -d ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules/.bin ]; then \
		for f in ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node_modules/.bin/*; do \
			if [ -L "$$f" ] && ! [ -e "$$f" ]; then ${RM} "$$f"; fi; \
		done; \
	fi
	# remove unnecessary files
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "README.md" -delete
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "*.package-lock.json" -delete
	# fix shebang
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/cli.js
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/node/cli.js
	# create symlink in bin
	@${LN} -sf ../lib/node_modules/.bin/opencc ${STAGEDIR}${PREFIX}/bin/opencc
	# remove stray files
	@${RM} \
		${STAGEDIR}${LOCALBASE}/lib/package.json \
		${STAGEDIR}${LOCALBASE}/lib/package-lock.json

.include <bsd.port.mk>
