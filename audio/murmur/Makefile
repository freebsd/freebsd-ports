# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	murmur
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	audio net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Murmur is the server component of Mumble

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:devel/boost-libs
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lang qmake pkgconfig python:build qt:5 ssl
USE_CXXSTD=	c++11
USE_QT=		buildtools_build core network sql xml

USE_GITHUB=	YES
GH_ACCOUNT=	mumble-voip
GH_PROJECT=	mumble

CONFIG=		no-client
QMAKE_ARGS=	"CONFIG+=${CONFIG}"
QMAKE_ENV+=	"MUMBLE_PYTHON=${PYTHON_CMD}"

USE_RC_SUBR=	murmur
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

OPTIONS_DEFINE=		BONJOUR DBUS DOCS ICE
OPTIONS_DEFAULT=	BONJOUR MYSQL SQLITE
OPTIONS_MULTI=		SQL
OPTIONS_MULTI_SQL=	MYSQL SQLITE

BONJOUR_DESC=		Bonjour Support
BONJOUR_VARS_OFF=	CONFIG+=no-bonjour
BONJOUR_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

DBUS_VARS_OFF=		CONFIG+=no-dbus
DBUS_USE=		QT=dbus

ICE_DESC=		Ice Support
ICE_VARS_OFF=		CONFIG+=no-ice
ICE_LIB_DEPENDS=	libIce.so:devel/ice

MYSQL_VARS_OFF=		CONFIG+=no-sql-mysql
MYSQL_USE=		QT=sql-mysql

SQLITE_VARS_OFF=	CONFIG+=no-sqlite3_run
SQLITE_USE=		QT=sql-sqlite3_run

USERS=		murmur
GROUPS=		murmur

.include <bsd.port.pre.mk>
# PCH is broken on GCC
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

post-patch:
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro

pre-install:
	${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|#host=.*|host=0.0.0.0|' ${WRKSRC}/scripts/murmur.ini

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${STAGEDIR}${PREFIX}/etc/murmur.ini.sample
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${CP} ${WRKSRC}/man/murmurd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGES INSTALL README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
