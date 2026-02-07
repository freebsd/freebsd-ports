PORTNAME=	skrooge
DISTVERSION=	2.33.0
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}
DIST_SUBDIR=	KDE/${PORTNAME}

PATCH_SITES=	https://invent.kde.org/office/skrooge/-/commit/
PATCHFILES+=	5758d908b5918401a0e75b17b1d23253fb12272a.patch:-p1
PATCHFILES+=	7e50a40c90147698de7a1848e62566548646ec77.patch:-p1
PATCHFILES+=	07c3967161169c32b98c21a0bbca6722618c63de.patch:-p1
PATCHFILES+=	0f70ff87a5a087d149f6c3edf0d64145d3308f22.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal finance manager
WWW=		https://skrooge.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libofx.so:finance/libofx \
		libsqlcipher.so:databases/sqlcipher
RUN_DEPENDS=	${LOCALBASE}/bin/aqbanking-cli:finance/aqbanking \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.2:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}woob>=3.6:www/py-woob@${PY_FLAVOR}

USES=		cmake compiler:c++11-lib desktop-file-utils gettext grantlee:5 \
		kde:5 pkgconfig python qt:5 shared-mime-info \
		shebangfix tar:xz xorg
USE_KDE=	archive attica auth bookmarks codecs completion \
		config configwidgets coreaddons dbusaddons emoticons \
		guiaddons i18n iconthemes init itemviews jobwidgets \
		kio newstuff notifications notifyconfig package parts \
		plasma-framework runner service solid sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
# designerplugin is weird: it's defined as a _run dependency, but
# skrooge checks for it at build-time.
USE_KDE+=	designerplugin:build designerplugin:run
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus declarative designer gui location \
		network printsupport quickcontrols2 script sql svg \
		webchannel webengine widgets xml xmlpatterns \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

SHEBANG_FILES=	plugins/import/skrooge_import_backend/skrooge-sabb.py \
		plugins/import/skrooge_import_backend/skrooge-woob.py \
		skgbankmodeler/skrooge-boursorama.py \
		skgbankmodeler/skrooge-coinmarketcap.py \
		skgbankmodeler/skrooge-cryptocompare.py \
		skgbankmodeler/skrooge-exchangerates.py \
		skgbankmodeler/skrooge-exchangerates_apilayer.py

# This is temporarily needed to run the fix-shebang target after the patches
# are applied and should be removed in the next version.
TARGET_ORDER_OVERRIDE=	750:fix-shebang

PLIST_SUB=	SHLIB_VER="${PORTVERSION}"

# Skrooge creates several empty directories due to how it calls CMake's
# install(DIRECTORY ...) function, so we need some code to remove them.
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share/skrooge/html \
		-type d -empty -delete

.include <bsd.port.mk>
