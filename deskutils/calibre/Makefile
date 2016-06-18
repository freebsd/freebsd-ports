# Created by: stas
# $FreeBSD$

PORTNAME=	calibre
PORTVERSION=	2.59.0
CATEGORIES=	deskutils python
MASTER_SITES=	http://download.calibre-ebook.com/${PORTVERSION}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ebook management application

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick \
		libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libwmflite.so:graphics/libwmf \
		libchm.so:misc/chmlib \
		libicudata.so:devel/icu \
		libpodofo.so:graphics/podofo \
		libmtp.so:multimedia/libmtp
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt5-core>=0:devel/py-qt5-core \
		${PYTHON_PKGNAMEPREFIX}qt5-gui>=0:x11-toolkits/py-qt5-gui \
		${PYTHON_PKGNAMEPREFIX}qt5-network>=0:net/py-qt5-network \
		${PYTHON_PKGNAMEPREFIX}qt5-webkit>=0:www/py-qt5-webkit \
		${PYTHON_PKGNAMEPREFIX}qt5-widgets>=0:x11-toolkits/py-qt5-widgets \
		${PYTHON_PKGNAMEPREFIX}qt5-webkitwidgets>=0:www/py-qt5-webkitwidgets \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.9:www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:databases/py-apsw
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.9:www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0:www/py-mechanize \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt5-core>=0:devel/py-qt5-core \
		${PYTHON_PKGNAMEPREFIX}qt5-gui>=0:x11-toolkits/py-qt5-gui \
		${PYTHON_PKGNAMEPREFIX}qt5-network>=0:net/py-qt5-network \
		${PYTHON_PKGNAMEPREFIX}qt5-svg>=0:graphics/py-qt5-svg \
		${PYTHON_PKGNAMEPREFIX}qt5-webkit>=0:www/py-qt5-webkit \
		${PYTHON_PKGNAMEPREFIX}qt5-widgets>=0:x11-toolkits/py-qt5-widgets \
		${PYTHON_PKGNAMEPREFIX}qt5-webkitwidgets>=0:www/py-qt5-webkitwidgets \
		${PYTHON_PKGNAMEPREFIX}qt5-xmlpatterns>=0:textproc/py-qt5-xmlpatterns \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}cssselect>=0:www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}apsw>=0:databases/py-apsw \
		pdftohtml:graphics/poppler-utils

USE_RC_SUBR=	calibre
EXTRACT_BEFORE_ARGS=	-x -s '/^calibre/~-src/' -f

USES=		desktop-file-utils pkgconfig python:2 shared-mime-info shebangfix tar:xz
SHEBANG_FILES=	resources/calibre-portable.sh \
		src/calibre/ebooks/metadata/odt.py \
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
	# Create this file to avoid what looks like a bug in xdg-desktop-menu
	@${TOUCH} ${STAGEDIR}${PREFIX}/share/applications/defaults.list
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} install --prefix ${PREFIX} \
		--staging-root ${STAGEDIR}${PREFIX})
	@${RM} ${STAGEDIR}${PREFIX}/bin/calibre-uninstall \
		${STAGEDIR}${PREFIX}/share/applications/defaults.list
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/desktop-directories
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/calibre/calibre/plugins/*

.include <bsd.port.post.mk>
