PORTNAME=	calibre
PORTVERSION=	8.16.2
PORTREVISION=	6
CATEGORIES=	deskutils python
MASTER_SITES=	https://download.calibre-ebook.com/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	https://github.com/kovidgoyal/calibre/commit/
PATCHFILES=	49af1f0904e00351ffbf9ad430a37bfe66226bae.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application
WWW=		https://calibre-ebook.com/

LICENSE=	GPLv3

EXTRACT_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=		${LOCALBASE}/bin/cmake:devel/cmake-core \
			${NONEXISTENT}:misc/iso-codes:extract \
			${PY_SETUPTOOLS} \
			${PYTHON_PKGNAMEPREFIX}apsw>=3.50.4.0:databases/py-apsw@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12.2:www/py-beautifulsoup4@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.10:www/py-css-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.12:www/py-html5-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=6.0.1:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mechanize>=0.4.8:www/py-mechanize@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.7:devel/py-msgpack@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}regex>=2023.8.8:textproc/py-regex@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xxhash>3.3.0:devel/py-xxhash@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zeroconf>0.115.0:net/py-zeroconf@${PY_FLAVOR} \
			liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf \
			MathJax3>0:www/mathjax3
LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg \
			libfreetype.so:print/freetype2 \
			libhunspell-1.7.so:textproc/hunspell \
			libhyphen.so:textproc/hyphen \
			libicudata.so:devel/icu \
			libmtp.so:multimedia/libmtp \
			libpodofo.so:graphics/podofo \
			libstemmer.so:textproc/snowballstemmer \
			libuchardet.so:textproc/uchardet \
			libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}apsw>=3.50.4.0:databases/py-apsw@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12.2:www/py-beautifulsoup4@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}chardet>=5.2.0:textproc/py-chardet@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.10:www/py-css-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dnspython>=2.6.1:dns/py-dnspython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.10:textproc/py-feedparser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fonttools>=4.42.1:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html2text>=2024.2.26:textproc/py-html2text@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.12:www/py-html5-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jeepney>=0.8.0:devel/py-jeepney@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=6.0.1:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>=3.4.4:textproc/py-markdown@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mechanize>=0.4.8:www/py-mechanize@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.7:devel/py-msgpack@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}netifaces>=0.11.0:net/py-netifaces@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}psutil>=5.9.5:sysutils/py-psutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}py7zr>=0.20.6:archivers/py-py7zr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.19.1:security/py-pycryptodome@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyzstd>=0.15.9:archivers/py-pyzstd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}regex>=2023.8.8:textproc/py-regex@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tzdata>=2023.3:devel/py-tzdata@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tzlocal>=5.0.1:devel/py-tzlocal@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xxhash>=3.3.0:devel/py-xxhash@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zeroconf>0.115.0:net/py-zeroconf@${PY_FLAVOR} \
			liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf \
			MathJax3>0:www/mathjax3 \
			cwebp:graphics/webp \
			jpegtran:graphics/jpeg-turbo \
			optipng:graphics/optipng \
			pdftohtml:graphics/poppler-utils \
			xdg-open:devel/xdg-utils

USES=		cpe desktop-file-utils gettext-runtime:build gl \
		localbase:ldflags pkgconfig pyqt:6 python:3.11+ qt:6 \
		shared-mime-info shebangfix sqlite ssl tar:xz xorg
CPE_VENDOR=	calibre-ebook
USE_GITHUB=	nodefault
GH_TUPLE=	kovidgoyal:calibre-translations:94d8062:translations \
		LibreOffice:dictionaries:fe49c66:hypenation
USE_GL=		opengl
USE_PYQT=	pyqt6 pysip webengine qtbuilder:build sip:build
USE_QT=		base
USE_RC_SUBR=	calibre
USE_XORG=	x11 xext xrender

SHEBANG_GLOB=	*.py *.recipe *.sh
python_OLD_CMD=	"/usr/bin/env  python" ${LOCALBASE}/bin/python3
MAKE_ENV=	CALIBRE_CONFIG_DIRECTORY=${WRKDIR}/calibre-config \
		FC_INC_DIR="${LOCALBASE}/include/fontconfig" \
		FC_LIB_DIR="${LOCALBASE}/lib" \
		OVERRIDE_CFLAGS="${CFLAGS}" \
		OVERRIDE_LDFLAGS="${LDFLAGS}" \
		PODOFO_INC_DIR="${LOCALBASE}/include/podofo" \
		PODOFO_LIB_DIR="${LOCALBASE}/lib" \
		PYTHONDONTWRITEBYTECODE=true \
		QMAKE=${QMAKE} \
		SIP_BIN=${SIP} \
		SIP_DIR=${PYQT_SIPDIR} \
		WITH_USB=yes \
		XDG_CONFIG_HOME=${WRKDIR}/xdg-config \
		XDG_DATA_DIRS=${STAGEDIR}${PREFIX}/share \
		XDG_UTILS_INSTALL_MODE=system
SUB_LIST=	PYTHON_VERSION=${PYTHON_VERSION}

ISOCODESWRKSRC_CMD=	${BSDMAKE} -C ${.CURDIR}/../../misc/iso-codes -V WRKSRC

post-extract:
	@${CP} ${FILESDIR}/user-agent-data.json ${WRKSRC}/resources

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/env python{py_major_version}|#!${PYTHON_CMD}|" \
			-e "s|#!/usr/bin/env python|#!${PYTHON_CMD}|" \
		${WRKSRC}/setup/install.py \
		${WRKSRC}/src/calibre/gui2/dialogs/custom_recipes.py \
		${WRKSRC}/src/calibre/gui2/preferences/tweaks.py

do-configure:
	# do nothing

do-build:
	@${MKDIR} ${WRKDIR}/calibre-config ${WRKDIR}/xdg-config
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} bootstrap \
		--system-liberation_fonts \
		--path-to-liberation_fonts=${LOCALBASE}/share/fonts/Liberation \
		--system-mathjax \
		--path-to-mathjax=${LOCALBASE}/www/MathJax3 \
		--path-to-hyphenation=${WRKSRC_hypenation} \
		--path-to-translations=${WRKSRC_translations} \
		--path-to-cacerts=${LOCALBASE}/share/certs/ca-root-nss.crt \
		--path-to-isocodes=$$(${ISOCODESWRKSRC_CMD}) --isocodes-extracted \
	)
	@${RMDIR} ${LOCALBASE}/libexec/qt6/locales 2>/dev/null || ${TRUE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages \
		${STAGEDIR}${PREFIX}/share/icons/hicolor \
		${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/desktop-directories \
		${STAGEDIR}${PREFIX}/share/mime/packages
	# Create this file to avoid what looks like a bug in xdg-desktop-menu
	@${TOUCH} ${STAGEDIR}${PREFIX}/share/applications/defaults.list
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install --prefix ${PREFIX} \
		--staging-root ${STAGEDIR}${PREFIX})
	@${RM} ${STAGEDIR}${PREFIX}/bin/calibre-uninstall \
		${STAGEDIR}${PREFIX}/share/applications/defaults.list
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/desktop-directories
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/calibre/calibre/plugins/*

# calibre-debug --test-build has no way to deselect individual tests, so the
# tests covering functionality this port intentionally does not ship are
# renamed out of the way in pre-test.  Each entry here is a feature the port
# cannot currently support:
#
#   7z		needs py7zr>=1.0.0 for the extractall(factory=...) API,
#		archivers/py-py7zr is still at 0.22.0
#   piper	the bundled piper TTS extension is not built
#   plugins	imports calibre_extensions.piper, so it fails for the same reason
#   pychm	no port for pychm
#   pykakasi	no port for pykakasi
#   qt		calls JxrDecApp, a bundled JPEG-XR tool that is not built
#   sqlite	databases/py-sqlite3 lacks enable_load_extension()
#   unrar	no port for unrardll
#
TEST_IGNORE?=	7z piper plugins pychm pykakasi qt sqlite unrar

_TEST_BUILD_PY=	${STAGEDIR}${PREFIX}/lib/calibre/calibre/test_build.py

pre-test:
	@${REINPLACE_CMD} -E -e 's,^    def (test_(${TEST_IGNORE:ts|}))\(self\):,    def _skipped_\1(self):,' \
		${_TEST_BUILD_PY}
.for _t in ${TEST_IGNORE}
	@${GREP} -q "^    def _skipped_test_${_t}(self):" ${_TEST_BUILD_PY} || \
		(${ECHO_MSG} "=> TEST_IGNORE: no test_${_t} in test_build.py, drop it from TEST_IGNORE"; ${FALSE})
.endfor

do-test:
	@(cd ${WRKDIR}; ${SETENV} \
		CALIBRE_CONFIG_DIRECTORY=${WRKDIR}/calibre-config \
		CALIBRE_EXECUTABLES_PATH=${STAGEDIR}${PREFIX}/bin \
		CALIBRE_EXTENSIONS_PATH=${STAGEDIR}${PREFIX}/lib/calibre/calibre/plugins \
		CALIBRE_PYTHON_PATH=${STAGEDIR}${PREFIX}/lib/calibre \
		CALIBRE_RESOURCES_PATH=${STAGEDIR}${PREFIX}/share/calibre \
		${STAGEDIR}${PREFIX}/bin/calibre-debug --test-build)

post-test:
	@${MV} ${_TEST_BUILD_PY}.bak ${_TEST_BUILD_PY}

update-recent-uas: patch
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} recent_uas)
	${CP} ${BUILD_WRKSRC}/resources/user-agent-data.json ${FILESDIR}

.include <bsd.port.mk>
