# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.12.4
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT?=	Qt 5 based distributed IRC client (client and monolithic binary)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource compiler:c++11-lib cpe execinfo pkgconfig tar:bzip2

CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

USE_QT5=	buildtools_build core network qmake_build
CMAKE_ARGS=	-DWITH_KDE=off \
		-DUSE_QT5=on

OPTIONS_DEFINE=		NLS
OPTIONS_MULTI=		MODULE DB
MODULE_DESC=		Quassel components
DB_DESC=		Database for Quassel core / monolithic
OPTIONS_MULTI_MODULE=	CLIENT CORE MONO
OPTIONS_MULTI_DB=	PGSQL SQLITE3
OPTIONS_DEFAULT=	CLIENT MONO SQLITE3
OPTIONS_SUB=		yes

CLIENT_DESC=		Quassel client (for use with core)
CLIENT_CMAKE_BOOL=	WANT_QTCLIENT
CLIENT_USE=		qt5=dbus,gui,phonon4,webkit,widgets
CLIENT_LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt5

CORE_DESC=		Quassel core server (for use with client)
CORE_CMAKE_BOOL=	WANT_CORE
CORE_USE=		qt5=script,sql
CORE_LIB_DEPENDS=	libqca-qt5.so:devel/qca-qt5
CORE_SUB_FILES=		pkg-message
CORE_VARS=		use_rc_subr=quasselcore \
			users=quasselcore \
			groups=quasselcore \
			plist=${NONEXISTENT} # allow core to override PLIST_FILES
CORE_PLIST_FILES=	bin/quasselcore

MONO_DESC=		Quassel standalone (monolithic binary: core+client combined)
MONO_CMAKE_BOOL=	WANT_MONO
MONO_USE=		qt5=script,sql
MONO_LIB_DEPENDS=	libqca-qt5.so:devel/qca-qt5

NLS_USE=		QT5=linguisttools_build

PGSQL_USE=		qt5=sql-pgsql

SQLITE3_USE=		qt5=sql-sqlite3_run

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' \
		${WRKSRC}/CMakeLists.txt

post-install-CLIENT-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselclient
post-install-CORE-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quasselcore
post-install-MONO-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quassel

.include <bsd.port.mk>
