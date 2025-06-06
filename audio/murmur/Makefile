PORTNAME=	murmur
DISTVERSION=	1.3.4
PORTREVISION=	11
CATEGORIES=	audio net

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Server component of Mumble
WWW=		https://www.mumble.info/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:devel/boost-libs
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		compiler:c++11-lang qmake pkgconfig python:build qt:5 ssl
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated CRYPTO_MEM_CHECK_ON
USE_CXXSTD=	c++11
USE_GITHUB=	YES
GH_ACCOUNT=	mumble-voip
GH_PROJECT=	mumble
USE_QT=		buildtools:build core network sql xml
USE_RC_SUBR=	murmur

CONFIG=		no-client
QMAKE_ARGS=	"CONFIG+=${CONFIG}"
QMAKE_ENV+=	"MUMBLE_PYTHON=${PYTHON_CMD}"

PORTSCOUT=	limit:^1\.3\.
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

USERS=		murmur
GROUPS=		murmur

OPTIONS_DEFINE=		BONJOUR DBUS DOCS ICE
OPTIONS_DEFAULT=	BONJOUR MYSQL SQLITE
OPTIONS_MULTI=		SQL
OPTIONS_MULTI_SQL=	MYSQL SQLITE

BONJOUR_DESC=		Bonjour Support
ICE_DESC=		Ice Support

BONJOUR_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
BONJOUR_VARS_OFF=	CONFIG+=no-bonjour

DBUS_USE=		QT=dbus
DBUS_VARS_OFF=		CONFIG+=no-dbus

ICE_LIB_DEPENDS=	libIce.so:devel/ice37
ICE_VARS_OFF=		CONFIG+=no-ice

MYSQL_USE=		QT=sql-mysql
MYSQL_VARS_OFF=		CONFIG+=no-sql-mysql

SQLITE_USE=		QT=sql-sqlite3:run
SQLITE_VARS_OFF=	CONFIG+=no-sqlite3_run

.include <bsd.port.pre.mk>
# PCH is broken on GCC
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIG+=	no-pch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|--no-add-needed|--no-copy-dt-needed-entries|' ${WRKSRC}/qmake/compiler.pri
	@${ECHO_CMD} 'QMAKE_LFLAGS += -fstack-protector' >> ${WRKSRC}/src/murmur/murmur.pro

pre-install:
	${SED} -i '' -e 's|database=.*|database=/var/db/murmur/murmur.sqlite|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|;pidfile=.*|pidfile=/var/run/murmur/murmur.pid|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|;logfile=.*|logfile=/var/log/murmur/murmur.log|' ${WRKSRC}/scripts/murmur.ini
	${SED} -i '' -e 's|;host=.*|host=0.0.0.0|' ${WRKSRC}/scripts/murmur.ini

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scripts/murmur.ini ${STAGEDIR}${PREFIX}/etc/murmur.ini.sample
	${CP} ${WRKSRC}/man/murmurd.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGES INSTALL README README.Linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}/var/db/murmur
	${MKDIR} ${STAGEDIR}/var/log/murmur
	${MKDIR} ${STAGEDIR}/var/run/murmur

.include <bsd.port.post.mk>
