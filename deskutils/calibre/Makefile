# Created by: stas
# $FreeBSD$

PORTNAME=	calibre
PORTVERSION=	1.48.0
PORTREVISION=	6
CATEGORIES=	deskutils python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application

LIB_DEPENDS=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4 \
		libwmflite.so:${PORTSDIR}/graphics/libwmf \
		libchm.so:${PORTSDIR}/misc/chmlib \
		libicudata.so:${PORTSDIR}/devel/icu \
		libpodofo.so:${PORTSDIR}/graphics/podofo
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${NONEXISTENT}:${PORTSDIR}/x11-toolkits/qt4-gui:patch
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.9:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:${PORTSDIR}/www/py-mechanize \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=0:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=0:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}qt4-xml>=0:${PORTSDIR}/textproc/py-qt4-xml \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0:${PORTSDIR}/www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:${PORTSDIR}/databases/py-apsw \
		pdftohtml:${PORTSDIR}/graphics/poppler-utils

USE_RC_SUBR=	calibre
EXTRACT_BEFORE_ARGS=	-x -s '/^calibre/~-src/' -f

USES=		desktop-file-utils pkgconfig python:2 shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	src/calibre/ebooks/metadata/odt.py \
		src/calibre/utils/*.py \
		src/odf/*.py
USE_QT4=	dbus qmake_build moc_build
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-src
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	FC_INC_DIR="${LOCALBASE}/include/fontconfig" \
		FC_LIB_DIR="${LOCALBASE}/lib" \
		OVERRIDE_CFLAGS="${CFLAGS}" \
		OVERRIDE_LDFLAGS="${LDFLAGS}" \
		PODOFO_LIB_DIR="${LOCALBASE}/lib" \
		PODOFO_INC_DIR="${LOCALBASE}/include/podofo" \
		WITH_USB=yes \
		CALIBRE_CONFIG_DIRECTORY=${WRKDIR}/calibre-config \
		XDG_DATA_DIRS=${STAGEDIR}${PREFIX}/share \
		XDG_CONFIG_HOME=${WRKDIR}/xdg-config

.include <bsd.port.pre.mk>

QTGUI_WRKSRC!=	cd ${PORTSDIR}/x11-toolkits/qt4-gui && ${MAKE} -V WRKSRC

post-patch:
	@${FIND} ${WRKSRC}/resources/content_server -name "*.orig" -delete
	@${REINPLACE_CMD} -e "/^qt_private_inc =/s|\[]|[ '${QTGUI_WRKSRC}/include/QtGui', '${QTGUI_WRKSRC}/include/QtCore' ]|" \
		${WRKSRC}/setup/build_environment.py

do-build:
	@${MKDIR} ${WRKDIR}/calibre-config ${WRKDIR}/xdg-config
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
.for dir in bash-completion gnome/apps mime/packages \
	icons/hicolor/128x128 zsh/site-functions
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${dir}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install --prefix ${PREFIX} \
		--staging-root ${STAGEDIR}${PREFIX})
	@${RM} ${STAGEDIR}${PREFIX}/bin/calibre-uninstall
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/calibre/calibre/plugins/*

.include <bsd.port.post.mk>
