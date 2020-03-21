# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quassel
PORTVERSION=	0.13.1
PORTREVISION=	2
CATEGORIES=	irc

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT?=	Qt 5 based distributed IRC client (client and monolithic binary)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lib cpe pkgconfig qt:5 tar:bzip2
USE_GITHUB=	yes
USE_QT=		buildtools_build core network qmake_build

CMAKE_ARGS=	-DWITH_KDE=off \
		-DUSE_QT5=on
CPE_VENDOR=	quassel-irc
CPE_PRODUCT=	quassel_irc

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
CLIENT_USE=		qt=dbus,gui,phonon4,webkit,widgets openldap=yes
CLIENT_LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt \
			libsnore-qt5.so:devel/snorenotify

CORE_DESC=		Quassel core server (for use with client)
CORE_CMAKE_BOOL=	WANT_CORE
CORE_USE=		qt=script,sql
CORE_USES=		qca
CORE_SUB_FILES=		pkg-message
CORE_VARS=		use_rc_subr=quasselcore \
			users=quasselcore \
			groups=quasselcore \
			plist=${NONEXISTENT} # allow core to override PLIST_FILES
CORE_PLIST_FILES=	bin/quasselcore

MONO_DESC=		Quassel standalone (monolithic binary: core+client combined)
MONO_CMAKE_BOOL=	WANT_MONO
MONO_USE=		qt=script,sql
MONO_USES=		qca

NLS_USE=		QT=linguisttools_build

PGSQL_USE=		qt=sql-pgsql

SQLITE3_USE=		qt=sql-sqlite3_run

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
