# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	2.6.0
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}
PKGNAMESUFFIX=	-kf5
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE personal finance manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt
LIB_DEPENDS=	libofx.so:finance/libofx \
		libqca-qt5.so:devel/qca-qt5

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		gettext grantlee:5 kde:5 pkgconfig shared-mime-info tar:xz
USE_KDE=	activities archive attica5 auth bookmarks codecs completion \
		config configwidgets coreaddons crash dbusaddons \
		designerplugin doctools ecm emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets \
		kdelibs4support kio newstuff notifications notifyconfig parts \
		runner service solid sonnet textwidgets unitconversion wallet \
		widgetsaddons windowsystem xmlgui
USE_QT5=	concurrent core dbus designer gui network printsupport qml \
		quick script sql svg webkit widgets xml \
		qmake_build buildtools_build

CONFLICTS_INSTALL=	${PORTNAME}-kde4-*

USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		SHLIB_SHVER=${PORTVERSION:R:R}

OPTIONS_SINGLE=		SQL
OPTIONS_SINGLE_SQL=	SQLITE SQLCIPHER
OPTIONS_SUB=		YES
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=		sqlite:3
SQLITE_CMAKE_ON=	-DSKG_CIPHER:BOOL=OFF
SQLCIPHER_DESC=		Use encrypted database
SQLCIPHER_LIB_DEPENDS=	libsqlcipher.so:databases/sqlcipher
SQLCIPHER_CMAKE_ON=	-DSKG_CIPHER:BOOL=ON
SQLCIPHER_PLIST_SUB+=	SQLCIPHER=""
SQLCIPHER_PLIST_SUB_OFF+=	SQLCIPHER="@comment "

post-patch:
.for i in skgbankgui skgbankmodeler skgbasegui skgbasemodeler skroogeakonadi
	${REINPLACE_CMD} -e 's|LIBRARY NAMELINK_SKIP||g' \
		${PATCH_WRKSRC}/${i}/CMakeLists.txt
.endfor

# Skrooge creates several empty directories due to how it calls CMake's
# install(DIRECTORY ...) function, so we need some code to remove them.
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share/skrooge/html \
		-type d -empty -delete

.include <bsd.port.mk>
