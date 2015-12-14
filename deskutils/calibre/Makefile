# Created by: stas
# $FreeBSD$

PORTNAME=	calibre
PORTVERSION=	2.46.0
CATEGORIES=	deskutils python
MASTER_SITES=	http://download.calibre-ebook.com/${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application

LIB_DEPENDS=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpoppler-qt5.so:${PORTSDIR}/graphics/poppler-qt5 \
		libwmflite.so:${PORTSDIR}/graphics/libwmf \
		libchm.so:${PORTSDIR}/misc/chmlib \
		libicudata.so:${PORTSDIR}/devel/icu \
		libpodofo.so:${PORTSDIR}/graphics/podofo \
		libmtp.so:${PORTSDIR}/multimedia/libmtp
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt5-core>=0:${PORTSDIR}/devel/py-qt5-core \
		${PYTHON_PKGNAMEPREFIX}qt5-gui>=0:${PORTSDIR}/x11-toolkits/py-qt5-gui \
		${PYTHON_PKGNAMEPREFIX}qt5-network>=0:${PORTSDIR}/net/py-qt5-network \
		${PYTHON_PKGNAMEPREFIX}qt5-webkit>=0:${PORTSDIR}/www/py-qt5-webkit \
		${PYTHON_PKGNAMEPREFIX}qt5-widgets>=0:${PORTSDIR}/x11-toolkits/py-qt5-widgets \
		${PYTHON_PKGNAMEPREFIX}qt5-webkitwidgets>=0:${PORTSDIR}/www/py-qt5-webkitwidgets \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.0.0:${PORTSDIR}/sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.9:${PORTSDIR}/www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:${PORTSDIR}/www/py-mechanize \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt5-core>=0:${PORTSDIR}/devel/py-qt5-core \
		${PYTHON_PKGNAMEPREFIX}qt5-gui>=0:${PORTSDIR}/x11-toolkits/py-qt5-gui \
		${PYTHON_PKGNAMEPREFIX}qt5-network>=0:${PORTSDIR}/net/py-qt5-network \
		${PYTHON_PKGNAMEPREFIX}qt5-svg>=0:${PORTSDIR}/graphics/py-qt5-svg \
		${PYTHON_PKGNAMEPREFIX}qt5-webkit>=0:${PORTSDIR}/www/py-qt5-webkit \
		${PYTHON_PKGNAMEPREFIX}qt5-widgets>=0:${PORTSDIR}/x11-toolkits/py-qt5-widgets \
		${PYTHON_PKGNAMEPREFIX}qt5-webkitwidgets>=0:${PORTSDIR}/www/py-qt5-webkitwidgets \
		${PYTHON_PKGNAMEPREFIX}qt5-xmlpatterns>=0:${PORTSDIR}/textproc/py-qt5-xmlpatterns \
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
USE_QT5=	buildtools_build dbus qmake_build
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
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
		XDG_CONFIG_HOME=${WRKDIR}/xdg-config \
		XDG_UTILS_INSTALL_MODE=system \
		QMAKE=${QMAKE}

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC}/resources/content_server -name "*.orig" -delete

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
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install --prefix ${PREFIX} \
		--staging-root ${STAGEDIR}${PREFIX})
	@${RM} ${STAGEDIR}${PREFIX}/bin/calibre-uninstall
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/desktop-directories
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/calibre/calibre/plugins/*

.include <bsd.port.post.mk>
