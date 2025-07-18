PORTNAME=	calibre
PORTVERSION=	8.7.0
CATEGORIES=	deskutils python
MASTER_SITES=	https://download.calibre-ebook.com/${PORTVERSION}/:DEFAULT \
		https://raw.githubusercontent.com/rhasspy/piper/${PIPER_VOICES_HASH}/:piper
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT VOICES.md:piper
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:C/:.*//:S/VOICES.md//1}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application
WWW=		https://calibre-ebook.com/

LICENSE=	GPLv3

EXTRACT_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=		${LOCALBASE}/bin/cmake:devel/cmake-core \
			${NONEXISTENT}:misc/iso-codes:extract \
			${PY_SETUPTOOLS} \
			${PYTHON_PKGNAMEPREFIX}apsw>=3.43.0.0:databases/py-apsw@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.2:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.10:www/py-css-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.12:www/py-html5-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=4.9.3:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mechanize>=0.4.8:www/py-mechanize@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xxhash>3.3.0:devel/py-xxhash@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
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
RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}apsw>=3.43.0.0:databases/py-apsw@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.2:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.10:www/py-css-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dnspython>=2.4.2:dns/py-dnspython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.10:textproc/py-feedparser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.12:www/py-html5-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}jeepney>=0.8.0:devel/py-jeepney@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=4.9.3:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>=3.4.4:textproc/py-markdown@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mechanize>=0.4.8:www/py-mechanize@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.7:devel/py-msgpack@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}netifaces>=0.11.0:net/py-netifaces@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.19.0:security/py-pycryptodome@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xxhash>=3.3.0:devel/py-xxhash@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
			liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf \
			MathJax3>0:www/mathjax3 \
			pdftohtml:graphics/poppler-utils \
			xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext-runtime:build gl localbase:ldflags \
		pkgconfig pyqt:6 python:3.11+ qt:6 shared-mime-info shebangfix sqlite ssl \
		tar:xz xorg
USE_GITHUB=	nodefault
GH_TUPLE=	kovidgoyal:calibre-translations:8abf932:translations \
		LibreOffice:dictionaries:537912c:hypenation
PIPER_VOICES_HASH=	4147f9629e88d3c1d4915a127f2d843f98347303
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

.include <bsd.port.pre.mk>

ISOCODESWRKSRC!=	${BSDMAKE} -C ${.CURDIR}/../../misc/iso-codes -V WRKSRC

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
		--path-to-isocodes=${ISOCODESWRKSRC} --isocodes-extracted \
		--path-to-piper_voices=${DISTDIR}/${DIST_SUBDIR}/VOICES.md \
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

update-recent-uas: patch
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} recent_uas)
	${CP} ${BUILD_WRKSRC}/resources/user-agent-data.json ${FILESDIR}

.include <bsd.port.post.mk>
