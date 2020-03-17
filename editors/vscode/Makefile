# $FreeBSD$

PORTNAME=	vscode
DISTVERSION=	1.43.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://nodejs.org/dist/v${NODE_VER}/:node_headers \
		https://github.com/tagattie/FreeBSD-VSCode/releases/download/${DISTVERSION}/:yarn_cache
DISTFILES=	node-v${NODE_VER}-headers${EXTRACT_SUFX}:node_headers \
		yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache \
		vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX}:yarn_cache
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	tagattie@yandex.com
COMMENT=	Visual Studio Code - Open Source ("Code - OSS")

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	zip:archivers/zip \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		rg:textproc/ripgrep \
		npm:www/npm-node10 \
		yarn:www/yarn-node10
LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libatspi.so:accessibility/at-spi2-core \
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
		liblcms2.so:graphics/lcms2 \
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
TEST_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		bash:shells/bash

USES=		desktop-file-utils gl gmake gnome jpeg pkgconfig \
		python:2.7,build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft

SOURCE_COMMIT_HASH=	78a4c91400152c0f27ba4d363eb56d2835f9903a

BINARY_ALIAS=	python=${PYTHON_CMD}

USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xkbfile \
		xrandr xrender xscrnsaver xtst
USE_GL=		gl glesv2
USE_GNOME=	atk cairo pango gdkpixbuf2 gtk30 libxml2 libxslt

USE_LDCONFIG=	${DATADIR}

# See ${WRKSRC}/remote/.yarnrc for NODE_VER
NODE_VER=	12.4.0

SHEBANG_REGEX=	./(extensions|resources|scripts|src)/.*\.sh$$
PATHFIX_FILES=	src/vs/workbench/contrib/debug/node/terminals.ts

DATADIR=	${PREFIX}/share/code-oss
TMPDIR=		${WRKDIR}

MAKE_ENV+=	BUILD_SOURCEVERSION=${SOURCE_COMMIT_HASH} \
		ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=1 \
		XDG_CACHE_HOME=${WRKDIR}/.cache

ELECTRON_DIR=	${.CURDIR}/../../devel/electron7
.include	"${ELECTRON_DIR}/Makefile.version"

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The limit imposed by poudriere(8) for the maximum number of files allowed to be"
	@${ECHO_MSG} "opened by a jail (default 1024) is exceeded during the build of ${PORTNAME}."
	@${ECHO_MSG} "To successfully build ${PORTNAME} with poudriere(8), you must add the following"
	@${ECHO_MSG} "line to poudriere.conf:"
	@${ECHO_MSG} "MAX_FILES_${PORTNAME}=4096"
	@${ECHO_MSG} ""

post-patch:
	# force use of electron version matching port one
	${REINPLACE_CMD} -E 's|^(target ").*(")$$|\1${ELECTRON_VER}\2|' \
		${WRKSRC}/.yarnrc
	# setup yarnrc for using local node headers
	${ECHO_CMD} 'nodedir "${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers"' >> \
		${WRKSRC}/.yarnrc
	${ECHO_CMD} 'nodedir "${WRKDIR}/node-v${NODE_VER}"' >> \
		${WRKSRC}/remote/.yarnrc
	# setup yarnrc for offline node_modules installation
	${ECHO_CMD} 'yarn-offline-mirror "../yarn-offline-cache"' >> \
		${WRKSRC}/.yarnrc
	(cd ${WRKSRC} && \
		${FIND} -E . -type f -iregex '${SHEBANG_REGEX}' \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
	(cd ${WRKSRC} && \
		${FIND} ${PATHFIX_FILES} -type f \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
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
	(cd ${WRKDIR}/builtInExtensions && \
		${FIND} . -type f -name '*.sh' \
			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" \
					-e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' {} ';')

pre-build:
	# # install node_modules without executing post-installation scripts
	# cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	# 	yarn --frozen-lockfile --ignore-scripts --offline
	# # copy rg binary files to vscode-ripgrep module directory
	# ${MKDIR} ${WRKSRC}/node_modules/vscode-ripgrep/bin
	# ${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/node_modules/vscode-ripgrep/bin
	# ${MKDIR} ${WRKSRC}/remote/node_modules/vscode-ripgrep/bin
	# ${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/remote/node_modules/vscode-ripgrep/bin
	# install node_modules
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn --frozen-lockfile --offline
	# copy rg binary files to vscode-ripgrep module directory
	${MKDIR} ${WRKSRC}/node_modules/vscode-ripgrep/bin
	${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/node_modules/vscode-ripgrep/bin
	${MKDIR} ${WRKSRC}/remote/node_modules/vscode-ripgrep/bin
	${CP} ${LOCALBASE}/bin/rg ${WRKSRC}/remote/node_modules/vscode-ripgrep/bin

do-build:
	# setup download cache for gulp-atom-electron
	${MKDIR} ${WRKDIR}/gulp-electron-cache/atom/electron
	cd ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} && \
		zip -q -r ${WRKDIR}/gulp-electron-cache/atom/electron/electron-v${ELECTRON_VER}-linux-x64.zip .
	cd ${WRKDIR}/gulp-electron-cache/atom/electron && \
		${SHA256} -r *-v${ELECTRON_VER}-linux-*.zip | \
		${SED} -e 's/ / */' > SHASUMS256.txt-${ELECTRON_VER}
	# build and package vscode
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-linux-x64-min
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-reh-linux-x64-min
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn gulp vscode-reh-web-linux-x64-min
	# copy marketplace extensions
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
	cd ${WRKDIR}/VSCode-linux-x64 && \
		${TAR} -cf - . | ${TAR} -xf - -C ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR}/resources/app/node_modules.asar.unpacked && \
		${FIND} . -type f -exec ${STRIP_CMD} {} ';'
.for f in chromedriver mksnapshot v8_context_snapshot_generator
	${RM} ${STAGEDIR}${DATADIR}/${f}
.endfor
	${RM} -r ${STAGEDIR}${DATADIR}/node_headers
	${RM} -r ${STAGEDIR}${DATADIR}/resources/completions
	${RLN} ${STAGEDIR}${DATADIR}/bin/code-oss ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

pre-test:
	# setup electron dependency for unit tests
	${MKDIR} ${WRKSRC}/.build/electron
	cd ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} && \
		${TAR} -cf - . | ${TAR} -xf - -C ${WRKSRC}/.build/electron
	cd ${WRKSRC}/.build/electron && ${MV} -f electron code-oss

do-test:
	# Note: Xvfb or something similar is necessary for headless testing
	# unit tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./scripts/test.sh || ${TRUE}
	# UI smoke tests
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} yarn smoketest

### targets for port maintainer(s)
make-yarn-cache:
	# do "make configure" before executing this target
	${RM} -r ${WRKDIR}/yarn-offline-cache
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn --frozen-lockfile --ignore-scripts
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn postinstall --frozen-lockfile
	cd ${WRKDIR} && ${TAR} -czf \
		yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} yarn-offline-cache

make-marketplace-exts:
	${RM} -r ${WRKSRC}/.build/builtInExtensions
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn download-builtin-extensions && \
	cd ${WRKSRC}/.build && ${TAR} -czf \
		${WRKDIR}/vscode-marketplace-exts-${DISTVERSION}${EXTRACT_SUFX} builtInExtensions

.include <bsd.port.mk>
