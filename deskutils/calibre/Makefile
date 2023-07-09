PORTNAME=	calibre
PORTVERSION=	6.22.0
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	http://download.calibre-ebook.com/${PORTVERSION}/ \
		https://curl.haxx.se/ca/:cacert
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		cacert.pem:cacert
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:C/:[^:]+$//:Ncacert.pem}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application
WWW=		https://calibre-ebook.com/

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libwmflite.so:graphics/libwmf \
		libchm.so:misc/chmlib \
		libicudata.so:devel/icu \
		libpodofo.so:graphics/podofo \
		libmtp.so:multimedia/libmtp \
		libfreetype.so:print/freetype2 \
		libhunspell-1.7.so:textproc/hunspell \
		libhyphen.so:textproc/hyphen \
		libstemmer.so:textproc/snowballstemmer \
		libxkbcommon.so:x11/libxkbcommon \
		libuchardet.so:textproc/uchardet
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:www/py-mechanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.4:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.3:www/py-html5-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>0:devel/py-pyicu@${PY_FLAVOR} \
		${LOCALBASE}/bin/cmake:devel/cmake-core \
		liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf \
		MathJax3>0:www/mathjax3
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.4:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:www/py-mechanize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.3:www/py-html5-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.8:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jeepney>=0.6:devel/py-jeepney@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		pdftohtml:graphics/poppler-utils \
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR} \
		liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf\
		MathJax3>0:www/mathjax3

USES=		desktop-file-utils gettext-runtime gl gnome localbase:ldflags \
		pkgconfig pyqt:6 python qt:6 shared-mime-info shebangfix \
		ssl tar:xz xorg
USE_RC_SUBR=	calibre
SUB_LIST+=	PYTHON_VERSION=${PYTHON_VERSION}
USE_PYQT=	pyqt6 pysip qtbuilder sip webengine
USE_QT=		base
USE_GL=		egl gl
USE_GNOME=	glib20
USE_XORG=	xrender xext x11

USE_GITHUB=	nodefault
GH_TUPLE=	kovidgoyal:calibre-translations:d911cab:translations \
		LibreOffice:dictionaries:8b6fc85:hypenation

SHEBANG_GLOB=	*.sh *.py *.recipe
python_OLD_CMD=	"/usr/bin/env  python" ${LOCALBASE}/bin/python3
MAKE_ENV+=	FC_INC_DIR="${LOCALBASE}/include/fontconfig" \
		FC_LIB_DIR="${LOCALBASE}/lib" \
		OVERRIDE_CFLAGS="${CFLAGS}" \
		OVERRIDE_LDFLAGS="${LDFLAGS}" \
		PODOFO_LIB_DIR="${LOCALBASE}/lib" \
		PODOFO_INC_DIR="${LOCALBASE}/include/podofo" \
		WITH_USB=yes \
		CALIBRE_CONFIG_DIRECTORY=${WRKDIR}/calibre-config \
		XDG_DATA_DIRS=${STAGEDIR}${PREFIX}/share \
		XDG_CONFIG_HOME=${WRKDIR}/xdg-config \
		XDG_UTILS_INSTALL_MODE=system \
		QMAKE=${QMAKE} \
		SIP_BIN=${SIP} \
		SIP_DIR=${PYQT_SIPDIR} \
		PYTHONDONTWRITEBYTECODE=true

post-extract:
	@${MV} ${WRKSRC_translations} ${WRKSRC}/src/translations
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/cacert.pem ${WRKSRC}/resources/mozilla-ca-certs.pem
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

.include <bsd.port.mk>
