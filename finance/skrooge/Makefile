PORTNAME=	skrooge
DISTVERSION=	26.8.0
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal finance manager
WWW=		https://skrooge.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libofx.so:finance/libofx \
		libsqlcipher.so:databases/sqlcipher
RUN_DEPENDS=	${LOCALBASE}/bin/aqbanking-cli:finance/aqbanking \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12.2:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}woob>=3.6:www/py-woob@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang desktop-file-utils gettext \
		gl kde:6 pkgconfig python qt:6 shared-mime-info \
		shebangfix tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	activities archive attica auth bookmarks codecs colorscheme \
		completion config configwidgets coreaddons dbusaddons \
		guiaddons i18n iconthemes itemviews jobwidgets \
		kio newstuff notifications notifyconfig package parts \
		runner service solid sonnet statusnotifieritem texttemplate \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_LDCONFIG=	yes
USE_QT=		5compat base declarative positioning svg \
		webchannel \
		tools:build
USE_XORG=	x11

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE

WEBENGINE_DESC=		Render reports and dashboards with QtWebEngine
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL=	SKG_WEBENGINE

SHEBANG_FILES=	plugins/import/skrooge_import_backend/skrooge-sabb.py \
		plugins/import/skrooge_import_backend/skrooge-woob.py \
		skgbankmodeler/skrooge-boursorama.py \
		skgbankmodeler/skrooge-coinmarketcap.py \
		skgbankmodeler/skrooge-cryptocompare.py \
		skgbankmodeler/skrooge-exchangerates.py \
		skgbankmodeler/skrooge-exchangerates_apilayer.py

PLIST_SUB=	SHLIB_VER="${PORTVERSION}"

# Skrooge creates several empty directories due to how it calls CMake's
# install(DIRECTORY ...) function, so we need some code to remove them.
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share/skrooge/html \
		-type d -empty -delete

.include <bsd.port.mk>
