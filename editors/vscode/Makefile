PORTNAME=	vscode
DISTVERSION=	1.101.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/tagattie/FreeBSD-VSCode/releases/download/${DISTVERSION}/:node_modules
DISTFILES=	vscode-node-modules-${DISTVERSION}${EXTRACT_SUFX}:node_modules \
		vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX}:node_modules
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Visual Studio Code - Open Source ("Code - OSS")
WWW=		https://code.visualstudio.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

EXTRACT_DEPENDS=jq:textproc/jq \
		node${NODEJS_VERSION}>0:www/node${NODEJS_VERSION}
BUILD_DEPENDS=	zip:archivers/zip \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		jq:textproc/jq \
		rg:textproc/ripgrep \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libsndio.so:audio/sndio \
		libdbus-1.so:devel/dbus \
		libicuuc.so:devel/icu \
		libepoll-shim.so:devel/libepoll-shim \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
		libnotify.so:devel/libnotify \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libpcre2-8.so:devel/pcre2 \
		libre2.so:devel/re2 \
		liblcms2.so:graphics/lcms2 \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libdav1d.so:multimedia/dav1d \
		libvpx.so:multimedia/libvpx \
		libopenh264.so:multimedia/openh264 \
		libpipewire-0.3.so:multimedia/pipewire \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		bash:shells/bash
TEST_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		bash:shells/bash

USES=		desktop-file-utils gl gmake gnome gssapi:mit iconv:wchar_t \
		jpeg localbase:ldflags nodejs:22,build pkgconfig python:build \
		shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft

SOURCE_COMMIT_HASH=	2901c5ac6db8a986a5666c3af51ff804d05af0d4

BINARY_ALIAS=	python=${PYTHON_CMD}

USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xtst
USE_GL=		gbm gl glesv2
USE_GNOME=	atk cairo pango gdkpixbuf gtk30 libxml2 libxslt

SHEBANG_REGEX=	./(extensions|node_modules|resources|scripts|src)/.*\.sh$$
PATHFIX_FILES=	src/vs/workbench/contrib/debug/node/terminals.ts

DATADIR=	${PREFIX}/share/code-oss
TMPDIR=		${WRKDIR}
BUNDLE_LIBS=	yes

MAKE_ENV+=	BUILD_SOURCEVERSION=${SOURCE_COMMIT_HASH}
# Don't download electron binary distribution on electron node_modules installation
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
# Don't download browser binaries on playwright node_modules installation
MAKE_ENV+=	PLAYWRIGHT_BROWSERS_PATH=${WRKDIR}/pw-browsers \
		PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1
# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1
TEST_ENV=	${MAKE_ENV:C/TMPDIR=.*//}

NODEJS_DIR=	${.CURDIR:H:H}/www/node22
.include "${NODEJS_DIR}/Makefile.version"
ELECTRON_DIR=	${.CURDIR:H:H}/devel/electron35
.include "${ELECTRON_DIR}/Makefile.version"

ELECTRON_DOWNLOAD_URL=	https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	/sbin/sha256 -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The limit imposed by poudriere(8) for the maximum number of files allowed to be"
	@${ECHO_MSG} "opened by a jail (default 1024) is exceeded during the build of ${PORTNAME}."
	@${ECHO_MSG} "To successfully build ${PORTNAME} with poudriere(8), you must add the following"
	@${ECHO_MSG} "line to poudriere.conf:"
	@${ECHO_MSG} "MAX_FILES_${PORTNAME}=8192"
	@${ECHO_MSG} ""

post-extract:
	@${CP} ${WRKSRC}/build/.moduleignore.linux \
		${WRKSRC}/build/.moduleignore.freebsd
	@${ECHO_MSG} "===>  Installing node modules in ${WRKSRC}"
	@${TAR} -xzf ${WRKDIR}/vscode-.-node-modules${EXTRACT_SUFX} -C ${WRKSRC}
	@for dir in `node -p "JSON.stringify(require('${WRKSRC}/build/npm/dirs').dirs)" | jq -r '.[]'`; do \
		if [ -f ${WRKDIR}/vscode-`echo $${dir} | tr _ __ | tr / _`-node-modules${EXTRACT_SUFX} ]; then \
			${ECHO_MSG} "===>  Installing node modules in ${WRKSRC}/$${dir}"; \
			${TAR} -xzf ${WRKDIR}/vscode-`echo $${dir} | tr _ __ | tr / _`-node-modules${EXTRACT_SUFX} -C ${WRKSRC}/$${dir}; \
		fi; \
	done

post-patch:
	@${REINPLACE_CMD} -E 's|^(target=").*(")$$|\1${ELECTRON_VER}\2|' \
		${WRKSRC}/.npmrc
	@${REINPLACE_CMD} -E 's|^(target=").*(")$$|\1${NODEJS_PORTVERSION}\2|' \
		${WRKSRC}/remote/.npmrc
	@(cd ${WRKSRC} && \
		${FIND} -E . -type f -iregex '${SHEBANG_REGEX}' \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
	@(cd ${WRKSRC} && \
		${FIND} ${PATHFIX_FILES} -type f \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
	@${REINPLACE_CMD} -e 's/@@NAME_LONG@@/Code - OSS/; \
			s/@@NAME_SHORT@@/Code - OSS/; \
			s/@@PRODNAME@@/Code - OSS/; \
			s/@@NAME@@/code-oss/g; \
			s|@@EXEC@@|${PREFIX}/bin/code-oss|; \
			s/@@ICON@@/com.visualstudio.code.oss/; \
			s/@@URLPROTOCOL@@/code-oss/; \
			s/@@LICENSE@@/MIT/; \
			s/@@APPNAME@@/code-oss/g; \
			s|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/resources/completions/bash/code \
		${WRKSRC}/resources/completions/zsh/_code \
		${WRKSRC}/resources/linux/bin/code.sh \
		${WRKSRC}/resources/linux/code.appdata.xml \
		${WRKSRC}/resources/linux/code.desktop \
		${WRKSRC}/resources/linux/code-url-handler.desktop
	@(cd ${WRKDIR}/builtInExtensions && \
		${FIND} . -type f -name '*.sh' \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" \
					-e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' {} ';')

pre-build:
# rebuild native node modules in top directory
	@for subdir in `${FIND} ${WRKSRC}/node_modules -type f -name binding.gyp -exec ${DIRNAME} {} ';'`; do \
		${ECHO_MSG} "===>   Rebuilding native modules in $${subdir}"; \
		cd $${subdir} && \
		${SETENV} ${MAKE_ENV} \
			npm_config_runtime=electron \
			npm_config_target=${ELECTRON_VER} \
			npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers \
			node-gyp --userconfig=${WRKSRC}/.npmrc rebuild; \
	done
# rebuild native node modules in subdirectories
	@for dir in `node -p "JSON.stringify(require('${WRKSRC}/build/npm/dirs').dirs)" | jq -r '.[]'`; do \
		for subdir in `${FIND} ${WRKSRC}/$${dir}/node_modules -type f -name binding.gyp -exec ${DIRNAME} {} ';' 2> /dev/null`; do \
			${ECHO_MSG} "===>   Rebuilding native modules in $${subdir}"; \
			if [ "`${ECHO_CMD} $${subdir} | ${GREP} /build/`" ]; then \
				cd $${subdir} && \
				${SETENV} ${MAKE_ENV} \
					npm_config_runtime=node \
					npm_config_target=${NODEJS_PORTVERSION} \
					npm_config_nodedir=${LOCALBASE} \
					node-gyp --userconfig=${WRKSRC}/build/.npmrc rebuild; \
			elif [ "`${ECHO_CMD} $${subdir} | ${GREP} /remote/`" ]; then \
				cd $${subdir} && \
				${SETENV} ${MAKE_ENV} \
					npm_config_runtime=node \
					npm_config_target=${NODEJS_PORTVERSION} \
					npm_config_nodedir=${LOCALBASE} \
					node-gyp --userconfig=${WRKSRC}/remote/.npmrc rebuild; \
			else \
				cd $${subdir} && \
				${SETENV} ${MAKE_ENV} \
					npm_config_runtime=electron \
					npm_config_target=${ELECTRON_VER} \
					npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers \
					node-gyp --userconfig=${WRKSRC}/.npmrc rebuild; \
			fi; \
		done; \
	done
# copy rg binary file to @vscode/ripgrep node module directory
	@${MKDIR} ${WRKSRC}/node_modules/@vscode/ripgrep/bin
	@${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/node_modules/@vscode/ripgrep/bin
	@${MKDIR} ${WRKSRC}/build/node_modules/@vscode/ripgrep/bin
	@${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/build/node_modules/@vscode/ripgrep/bin
	@${MKDIR} ${WRKSRC}/remote/node_modules/@vscode/ripgrep/bin
	@${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/remote/node_modules/@vscode/ripgrep/bin

do-build:
# setup download cache for gulp-atom-electron
	@${MKDIR} ${WRKDIR}/.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH}
	@cd ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} && \
		zip -q -r ${WRKDIR}/.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH}/electron-v${ELECTRON_VER}-linux-${ELECTRON_ARCH}.zip .
	@cd ${WRKDIR}/.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH} && \
		${SHA256} -r *-v${ELECTRON_VER}-linux-*.zip | \
		${SED} -e 's/ / */' > SHASUMS256.txt
# add newline character at the end of the file if not already
	@${AWK} '1' ${WRKSRC}/build/checksums/electron.txt > \
		${WRKSRC}/build/checksums/electron.txt.new
	@${MV} -f ${WRKSRC}/build/checksums/electron.txt.new \
		${WRKSRC}/build/checksums/electron.txt
	@cd ${WRKDIR}/.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH} && \
		${SHA256} -r *-v${ELECTRON_VER}-linux-*.zip | \
		${SED} -e 's/ / */' >> ${WRKSRC}/build/checksums/electron.txt
# remove backup files so that they are not included in the package
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' -o -name '*~' \) -delete
# build and package vscode
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npx tsc -p build/tsconfig.build.json
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npm_config_runtime=electron \
		npm_config_target=${ELECTRON_VER} \
		npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers \
		npm --userconfig=${WRKSRC}/.npmrc run gulp vscode-linux-${ELECTRON_ARCH}-min
# move marketplace extensions
	@${MV} ${WRKDIR}/builtInExtensions/* ${WRKDIR}/VSCode-linux-${ELECTRON_ARCH}/resources/app/extensions

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/resources/completions/bash/code \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/code-oss
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/resources/completions/zsh/_code \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_code-oss
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata/code-oss.appdata.xml
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
.for f in code.desktop code-url-handler.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/linux/${f} \
		${STAGEDIR}${PREFIX}/share/applications/${f:S/code/code-oss/}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/com.visualstudio.code.oss.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -cf - -C ${WRKDIR}/VSCode-linux-${ELECTRON_ARCH} . | \
		${TAR} -xf - -C ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR}/resources/app -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}
.for f in chromedriver mksnapshot v8_context_snapshot_generator
	@${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	@${RM} -r ${STAGEDIR}${DATADIR}/gen
	@${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	@${RM} -r ${STAGEDIR}${DATADIR}/resources/completions
	${RLN} ${STAGEDIR}${DATADIR}/bin/code-oss ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

pre-test:
# setup electron dependency for unit tests
	@${MKDIR} ${WRKSRC}/.build/electron
	@${TAR} -cf - -C ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} . | \
		${TAR} -xf - -C ${WRKSRC}/.build/electron
	@cd ${WRKSRC}/.build/electron && ${MV} -f electron code-oss

do-test:
# Note: Xvfb or something similar is necessary for headless testing
# unit tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./scripts/test.sh --build || ${TRUE}
# UI smoke tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} npm run smoketest

build-remote-extension-host: configure pre-build
# setup download cache for node
	@${MKDIR} ${WRKSRC}/.build/node/v${NODEJS_PORTVERSION}/linux-${ELECTRON_ARCH}
	@${CP} ${LOCALBASE}/bin/node ${WRKSRC}/.build/node/v${NODEJS_PORTVERSION}/linux-${ELECTRON_ARCH}
# build vscode remote extension host
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npm_config_runtime=node \
		npm_config_target=${NODEJS_PORTVERSION} \
		npm_config_nodedir=${LOCALBASE} \
		npm --userconfig=${WRKSRC}/remote/.npmrc run gulp vscode-reh-linux-${ELECTRON_ARCH}-min
	@${MKDIR} ${WRKDIR}/vscode-reh/bin/${SOURCE_COMMIT_HASH}
	${TAR} -cf - -C ${WRKDIR}/vscode-reh-linux-${ELECTRON_ARCH} . | \
		${TAR} -xf - -C ${WRKDIR}/vscode-reh/bin/${SOURCE_COMMIT_HASH}
	@${FIND} ${WRKDIR}/vscode-reh -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}
	${TAR} -czf ${WRKDIR}/vscode-reh-${DISTVERSION}-${OPSYS:tl}${OSREL:R}-${ARCH}.tar.gz -C ${WRKDIR}/vscode-reh .
	# cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run gulp vscode-reh-web-linux-${ELECTRON_ARCH}-min

### targets for port maintainer(s)
make-node-modules-archive: extract
	@${ECHO_MSG} "===>  Fetching and installing node modules in ${WRKSRC}"
	@cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} npm install --ignore-scripts --no-progress --no-audit --no-fund && \
	${TAR} -czf ${WRKDIR}/vscode-.-node-modules${EXTRACT_SUFX} node_modules
	@for dir in `node -p "JSON.stringify(require('${WRKSRC}/build/npm/dirs').dirs)" | jq -r '.[]'`; do \
		cd ${WRKSRC}/$${dir} && \
		${ECHO_MSG} "===>  Fetching and installing node modules in ${WRKSRC}/$${dir}" && \
		${SETENV} ${MAKE_ENV} npm install --ignore-scripts --no-progress --no-audit --no-fund && \
		if [ -d node_modules ]; then \
			${TAR} -czf ${WRKDIR}/vscode-`echo $${dir} | tr _ __ | tr / _`-node-modules${EXTRACT_SUFX} node_modules; \
		fi; \
	done
	@cd ${WRKDIR} && \
	${TAR} -czf vscode-node-modules-${DISTVERSION}${EXTRACT_SUFX} vscode-*-node-modules.tar.gz

make-marketplace-exts-archive: extract
	@${RM} -r ${WRKSRC}/.build/builtInExtensions
	@cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} npm run download-builtin-extensions
	@${TAR} -czf ${WRKDIR}/vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX} -C ${WRKSRC}/.build builtInExtensions

.include <bsd.port.mk>
