# Created by: stas
# $FreeBSD$

PORTNAME=	calibre
PORTVERSION=	5.13.0
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	http://download.calibre-ebook.com/${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libwmflite.so:graphics/libwmf \
		libchm.so:misc/chmlib \
		libicudata.so:devel/icu \
		libpodofo.so:graphics/podofo \
		libmtp.so:multimedia/libmtp \
		libfreetype.so:print/freetype2 \
		libhunspell-1.7.so:textproc/hunspell \
		libhyphen.so:textproc/hyphen
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}css-parser>=1.0.4:www/py-css-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.3:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.3:www/py-html5-parser@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf
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
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5-parser>=0.4.3:www/py-html5-parser@${PY_FLAVOR} \
		${PY_PILLOW} \
		pdftohtml:graphics/poppler-utils \
		${PYTHON_PKGNAMEPREFIX}zeroconf>0:net/py-zeroconf

USES=		desktop-file-utils gettext-runtime gl gnome localbase:ldflags \
		pkgconfig pyqt:5 python:3.5+ qt:5 shared-mime-info shebangfix \
		ssl tar:xz xorg
USE_RC_SUBR=	calibre
SUB_LIST+=	PYTHON_VERSION=${PYTHON_VERSION}
USE_PYQT=	core gui network pysip qtbuilder sip svg webengine widgets xmlpatterns
USE_QT=		buildtools_build core dbus gui qmake_build widgets
USE_GL=		egl gl
USE_GNOME=	glib20
USE_XORG=	xrender xext x11

EXTRACT_BEFORE_ARGS=	-x -s '/^calibre/~-src/' -f
SHEBANG_GLOB=	*.sh *.py *.recipe
python_OLD_CMD=	"/usr/bin/env python2" "/usr/bin/env  python2" "/usr/bin/env  python" /bin/python2 \
		/usr/bin/python2 ${LOCALBASE}/bin/python3
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
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
		CALIBRE_PY3_PORT=1

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/env python{py_major_version}|#!${PYTHON_CMD}|" \
			-e "s|#!/usr/bin/env python2|#!${PYTHON_CMD}|" \
			-e "s|#!/usr/bin/env python|#!${PYTHON_CMD}|" \
		${WRKSRC}/setup/install.py \
		${WRKSRC}/src/calibre/gui2/dialogs/custom_recipes.py \
		${WRKSRC}/src/calibre/gui2/preferences/tweaks.py

do-build:
	@${MKDIR} ${WRKDIR}/calibre-config ${WRKDIR}/xdg-config
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

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

.include <bsd.port.mk>
