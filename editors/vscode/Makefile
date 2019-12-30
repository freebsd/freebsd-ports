# $FreeBSD$

PORTNAME=	vscode
DISTVERSION=	1.41.0
CATEGORIES=	editors
MASTER_SITES=	https://atom.io/download/electron/v${ELECTRON_VER}/:electron_headers \
		https://github.com/electron/electron/releases/download/v${ELECTRON_VER}/:electron_linux \
		https://nodejs.org/dist/v${NODE_VER}/:node_headers \
		https://registry.yarnpkg.com/vscode-ripgrep/-/:vscode_ripgrep \
		https://github.com/tagattie/FreeBSD-VSCode/releases/download/${DISTVERSION}/:yarn_cache
DISTFILES=	node-v${ELECTRON_VER}-headers${EXTRACT_SUFX}:electron_headers \
		electron-v${ELECTRON_VER}-linux-x64.zip:electron_linux \
		ffmpeg-v${ELECTRON_VER}-linux-x64.zip:electron_linux \
		node-v${NODE_VER}-headers${EXTRACT_SUFX}:node_headers \
		vscode-ripgrep-${VSCODE_RIPGREP_VER}.tgz:vscode_ripgrep
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Visual Studio Code - Open Source ("Code - OSS")

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	electron:devel/electron6 \
		rg:textproc/ripgrep \
		npm:www/npm-node10 \
		yarn:www/yarn-node10
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libsnappy.so:archivers/snappy \
		libasound.so:audio/alsa-lib \
		libFLAC.so:audio/flac \
		libopus.so:audio/opus \
		libdbus-1.so:devel/dbus \
		libinotify.so:devel/libinotify \
		libnotify.so:devel/libnotify \
		libpci.so:devel/libpci \
		libnspr4.so:devel/nspr \
		libpcre2-8.so:devel/pcre2 \
		libre2.so:devel/re2 \
		libdrm.so:graphics/libdrm \
		libwebp.so:graphics/webp \
		libavcodec.so:multimedia/ffmpeg \
		libvpx.so:multimedia/libvpx \
		libopenh264.so:multimedia/openh264 \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsecret-1.so:security/libsecret \
		libnss3.so:security/nss \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins \
		xdg-open:devel/xdg-utils \
		bash:shells/bash
TEST_DEPENDS=	electron:devel/electron6 \
		bash:shells/bash

USES=		desktop-file-utils gl gmake gnome jpeg pkgconfig \
		python:2.7,build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft

SOURCE_COMMIT_HASH=	9579eda04fdb3a9bba2750f15193e5fafe16b959

BINARY_ALIAS=	python=${PYTHON_CMD}

USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xtst
USE_GL=		gl glesv2
USE_GNOME=	atk cairo pango gdkpixbuf2 gtk30 libxml2 libxslt

USE_LDCONFIG=	${DATADIR}

ELECTRON_VER=	6.1.6	# keep in sync with devel/electron6
NODE_VER=	12.4.0
VSCODE_RIPGREP_VER=	1.5.7

SHEBANG_FILES=	extensions/vscode-test-resolver/scripts/terminateProcess.sh \
		resources/linux/bin/code.sh \
		scripts/test.sh

DATADIR=	${PREFIX}/share/code-oss
TMPDIR=		${WRKDIR}

MAKE_ENV+=	BUILD_SOURCEVERSION=${SOURCE_COMMIT_HASH} \
		PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=1 \
		XDG_CACHE_HOME=${WRKDIR}/.cache

OPTIONS_DEFINE=	POUDRIERE
POUDRIERE_DESC=	Support build with poudriere (KEEP THIS ON)
OPTIONS_DEFAULT=	POUDRIERE

POUDRIERE_DISTFILES=	yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache \
			vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache
POUDRIERE_EXTRACT_ONLY=	yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} \
			vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX}
POUDRIERE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-build_gulpfile.extensions.js

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The limit imposed by poudriere(8) for the maximum number of files allowed to be"
	@${ECHO_MSG} "opened by a jail (default 1024) is exceeded during the build of ${PORTNAME}."
	@${ECHO_MSG} "To successfully build ${PORTNAME} with poudriere(8), you must add the following"
	@${ECHO_MSG} "line to poudriere.conf:"
	@${ECHO_MSG} "MAX_FILES_${PORTNAME}=4096"
	@${ECHO_MSG} ""

post-extract:
	${MKDIR} ${WRKDIR}/vscode-ripgrep
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/vscode-ripgrep-${VSCODE_RIPGREP_VER}.tgz \
		--strip-components 1 -C ${WRKDIR}/vscode-ripgrep
	# setup electron headers for node-gyp
	${MKDIR} ${WRKDIR}/.cache/node-gyp/${ELECTRON_VER}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/node-v${ELECTRON_VER}-headers${EXTRACT_SUFX} \
		--strip-components 1 -C ${WRKDIR}/.cache/node-gyp/${ELECTRON_VER}
	${ECHO} 9 > ${WRKDIR}/.cache/node-gyp/${ELECTRON_VER}/installVersion
	# setup node headers for node-gyp
	${MKDIR} ${WRKDIR}/.cache/node-gyp/${NODE_VER}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/node-v${NODE_VER}-headers${EXTRACT_SUFX} \
		--strip-components 1 -C ${WRKDIR}/.cache/node-gyp/${NODE_VER}
	${ECHO} 9 > ${WRKDIR}/.cache/node-gyp/${NODE_VER}/installVersion
	# setup download cache for gulp-atom-electron
	${MKDIR} ${WRKDIR}/gulp-electron-cache/atom/electron
	${CP} ${DISTDIR}/${DIST_SUBDIR}/electron-v${ELECTRON_VER}-linux-x64.zip \
		${WRKDIR}/gulp-electron-cache/atom/electron
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ffmpeg-v${ELECTRON_VER}-linux-x64.zip \
		${WRKDIR}/gulp-electron-cache/atom/electron
	# setup electron download cache for UI smoke tests
	# ${MKDIR} ${WRKDIR}/.cache/electron
	# ${SED} -e 's/freebsd${OSREL:R}/freebsd/' ${DISTDIR}/${DIST_SUBDIR}/SHASUMS256.txt > \
	# 	${WRKDIR}/.cache/electron/SHASUMS256.txt-${ELECTRON_VER}
	# ${CP} ${DISTDIR}/${DIST_SUBDIR}/electron-v${ELECTRON_VER}-freebsd${OSREL:R}-x64.zip \
	# 	${WRKDIR}/.cache/electron/electron-v${ELECTRON_VER}-freebsd-x64.zip

post-patch:
	# force use of electron version matching port one
	${REINPLACE_CMD} -E 's|^(target ").*(")$$|\1${ELECTRON_VER}\2|' \
		${WRKSRC}/.yarnrc
	# setup yarnrc for offline node_modules installation
	${SED} -e 's|$${WRKDIR}|${WRKDIR}|' \
		${FILESDIR}/yarnrc-offline-mirror >> ${WRKSRC}/.yarnrc
	${REINPLACE_CMD} -e 's/@@NAME_LONG@@/Code - OSS/; \
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

pre-build:
	cd ${LOCALBASE}/share && \
		${TAR} -cf - electron | ${TAR} -xf - -C ${WRKDIR}
	${CP} ${FILESDIR}/package.json-build ${WRKSRC}/package.json
	${CP} ${FILESDIR}/package.json-remote-build ${WRKSRC}/remote/package.json

pre-build-POUDRIERE-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn --frozen-lockfile --offline # --no-progress

pre-build-POUDRIERE-off:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn --frozen-lockfile # --no-progress

do-build:
	${MKDIR} ${WRKDIR}/vscode-ripgrep/bin
	${CP} ${LOCALBASE}/bin/rg ${WRKDIR}/vscode-ripgrep/bin
	cd ${WRKDIR} && \
		${TAR} -cf - vscode-ripgrep | ${TAR} -xf - -C ${WRKSRC}/node_modules
	cd ${WRKDIR} && \
		${TAR} -cf - vscode-ripgrep | ${TAR} -xf - -C ${WRKSRC}/remote/node_modules
	${CP} ${FILESDIR}/package.json-package ${WRKSRC}/package.json
	${CP} ${FILESDIR}/package.json-remote-package ${WRKSRC}/remote/package.json
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-linux-x64-min
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-reh-linux-x64-min
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-reh-web-linux-x64-min

post-build-POUDRIERE-on:
	${MV} ${WRKDIR}/builtInExtensions/* ${WRKDIR}/VSCode-linux-x64/resources/app/extensions

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/resources/completions/bash/code \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/code-oss
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/resources/completions/zsh/_code \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_code-oss
	${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata/code-oss.appdata.xml
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
.for f in code.desktop code-url-handler.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/linux/${f} \
		${STAGEDIR}${PREFIX}/share/applications/${f:S/code/code-oss/}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/com.visualstudio.code.oss.png
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/electron/electron \
		${STAGEDIR}${DATADIR}/code-oss
.for f in libEGL.so libGLESv2.so
	${INSTALL_LIB} ${WRKDIR}/electron/${f} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/swiftshader
.for f in libEGL.so libGLESv2.so
	${INSTALL_LIB} ${WRKDIR}/electron/swiftshader/${f} \
		${STAGEDIR}${DATADIR}/swiftshader
.endfor
.for f in chrome_100_percent.pak chrome_200_percent.pak icudtl.dat natives_blob.bin resources.pak snapshot_blob.bin v8_context_snapshot.bin
	${INSTALL_DATA} ${WRKDIR}/electron/${f} ${STAGEDIR}${DATADIR}
.endfor
.for d in locales resources
	cd ${WRKDIR}/electron/${d} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/${d} "! -name default_app.asar"
.endfor
	cd ${WRKDIR}/VSCode-linux-x64/bin && \
		${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/bin
	cd ${WRKDIR}/VSCode-linux-x64/resources/app && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/resources/app
	cd ${STAGEDIR}${DATADIR}/resources/app/node_modules.asar.unpacked && \
		${FIND} . -type f -exec ${STRIP_CMD} {} ';' \
				-exec ${CHMOD} ${BINMODE} {} ';'
	${RLN} ${STAGEDIR}${DATADIR}/bin/code-oss ${STAGEDIR}${PREFIX}/bin

pre-test:
	# setup electron dependency for unit tests
	${MKDIR} ${WRKSRC}/.build
	cd ${LOCALBASE}/share && \
		${TAR} -cf - electron | ${TAR} -xf - -C ${WRKSRC}/.build
	cd ${WRKSRC}/.build/electron && ${MV} -f electron code-oss

do-test:
	# Note: Xvfb or something similar is necessary for headless testing
	# unit tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./scripts/test.sh || ${TRUE}
	# UI smoke tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} yarn smoketest

### targets for port maintainer(s)
make-yarn-cache:
	# do "make build" before executing this target
	cd ${WRKDIR} && ${TAR} -czf \
		yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} yarn-offline-cache

make-marketplace-exts:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} yarn download-builtin-extensions && \
	cd ${WRKSRC}/.build && ${TAR} -czf \
		vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX} builtInExtensions && \
		${MV} vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX} ${WRKDIR}

.include <bsd.port.mk>
