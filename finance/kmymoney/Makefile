PORTNAME=	kmymoney
PORTVERSION=	5.2.2
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE personal finance manager
WWW=		https://kmymoney.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libalkimia6.so:finance/alkimia \
		libKChart6.so:graphics/kdiagram-qt6 \
		libmpir.so:math/mpir \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gettext-runtime:build gettext-tools kde:6 \
		pkgconfig qt:6 shared-mime-info shebangfix tar:xz
USE_KDE=	activities archive codecs colorscheme completion config \
		configwidgets coreaddons crash i18n \
		itemmodels itemviews jobwidgets kcmutils \
		kio notifications textwidgets service sonnet \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_LDCONFIG=	yes
USE_QT=		base

CMAKE_ON=	BUILD_WITH_QT6

PLIST_SUB=	KMM_VERSION=${PORTVERSION}

OPTIONS_DEFINE=		ADDRESSBOOK GNUPG HOLIDAYS
OPTIONS_DEFAULT=	ADDRESSBOOK CALENDAR GNUPG HOLIDAYS KBANKING OFX
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	CALENDAR KBANKING OFX SQLCIPHER WOOB

OPTIONS_SUB=		yes

ADDRESSBOOK_DESC=	KDE PIM address book support
ADDRESSBOOK_USE=	KDE=akonadi,contacts,identitymanagement
ADDRESSBOOK_CMAKE_BOOL=	ENABLE_ADDRESSBOOK

CALENDAR_DESC=		iCalendar exporter
CALENDAR_LIB_DEPENDS=	libical.so:devel/libical
CALENDAR_CMAKE_BOOL=	ENABLE_LIBICAL

GNUPG_LIB_DEPENDS=	libgpgmepp.so:security/gpgmepp \
			libqgpgmeqt6.so:security/qgpgme@qt6
GNUPG_CMAKE_BOOL=	ENABLE_GPG

HOLIDAYS_DESC=		Fetch holidays from KDE PIM system
HOLIDAYS_USE=		KDE=holidays
HOLIDAYS_CMAKE_BOOL=	ENABLE_HOLIDAYS

KBANKING_DESC=		Online banking via KBanking (AqBanking)
KBANKING_LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
			libgwengui-qt6.so:devel/gwenhywfar-qt6 \
			libaqbanking.so:finance/aqbanking
KBANKING_USE=		QT=declarative:run
KBANKING_CMAKE_BOOL=	ENABLE_KBANKING

OFX_DESC=		OFX (Open Financial Exchange) importer
OFX_LIB_DEPENDS=	libofx.so:finance/libofx
OFX_CMAKE_BOOL=		ENABLE_LIBOFX

SQLCIPHER_DESC=		KMyMoney database encryption
SQLCIPHER_LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher
SQLCIPHER_CMAKE_BOOL=	ENABLE_SQLCIPHER

WOOB_DESC=		Online banking via Web Outside Of Browsers
WOOB_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}woob>0:www/py-woob@${PY_FLAVOR}
WOOB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}woob>0:www/py-woob@${PY_FLAVOR}
WOOB_USES=		python
WOOB_CMAKE_BOOL=	ENABLE_WOOB

.include <bsd.port.mk>
