PORTNAME=	mumble
DISTVERSION=	1.5.857
CATEGORIES=	audio net
MASTER_SITES=	https://github.com/${PORTNAME}-voip/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-server

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Server component of Mumble
WWW=		https://www.mumble.info/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++17-lang pkgconfig python:build qt:5 ssl
USE_CXXSTD=	c++17
USE_QT=		buildtools:build core dbus network qmake:build sql xml
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX:S|-|_|}

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	server
CMAKE_OFF=	client

CXXFLAGS+=	-Wno-deprecated-declarations

SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

USERS=		${PORTNAME}${PKGNAMESUFFIX}
GROUPS=		${USERS}

PLIST_SUB=	GROUPS=${GROUPS}
PORTDOCS=	README.md README.static.linux SECURITY.md

OPTIONS_DEFINE=		AVAHI DOCS ICE LTO
OPTIONS_DEFAULT=	AVAHI LTO MYSQL SQLITE
OPTIONS_MULTI=		SQL
OPTIONS_MULTI_SQL=	MYSQL PGSQL SQLITE

ICE_DESC=		Ice Support

AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_CMAKE_BOOL=	zeroconf

ICE_LIB_DEPENDS=	libIce.so:devel/ice37
ICE_CMAKE_BOOL=		ice

LTO_CMAKE_BOOL=		lto

MYSQL_USE=		QT=sql-mysql:run
PGSQL_USE=		QT=sql-pgsql:run
SQLITE_USE=		QT=sql-sqlite3:run

.include <bsd.port.pre.mk>

post-install:
	${REINPLACE_CMD} -e '\
			s|database=.*|database=/var/db/mumble-server/mumble-server.sqlite| ; \
			s|;pidfile=.*|pidfile=/var/run/mumble-server/mumble-server.pid| ; \
			s|;logfile=.*|logfile=/var/log/mumble-server/mumble-server.log| ; \
			s|;host=.*|host=0.0.0.0|' \
		${STAGEDIR}${ETCDIR}/mumble-server.ini
	${MV}   ${STAGEDIR}${ETCDIR}/mumble-server.ini \
		${STAGEDIR}${ETCDIR}/mumble-server.ini.sample
	${RM}   ${STAGEDIR}${PREFIX}/bin/mumble-server-user-wrapper \
		${STAGEDIR}${PREFIX}/share/man/man1/mumble-server-user-wrapper.1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${WRKSRC}/docs/additional-readmes/README.static.linux ${WRKSRC}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
