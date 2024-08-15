PORTNAME=	mumble-server
DISTVERSION=	1.5.634
PORTREVISION=	3
CATEGORIES=	audio net
MASTER_SITES=	https://github.com/${PORTNAME:S/-server//}-voip/${PORTNAME:S/-server//}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME:S/-server//}-${DISTVERSION}

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
USE_RC_SUBR=	mumble_server

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	server
CMAKE_OFF=	client

CXXFLAGS+=	-Wno-deprecated-declarations

EXTRA_PATCHES+=	${.CURDIR}/../mumble/files/patch-src_MumbleProtocol.cpp
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

USERS=		mumble-server
GROUPS=		mumble-server

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
	${SED} -i '' -e 's|database=.*|database=/var/db/mumble-server/mumble-server.sqlite| ; \
			s|;pidfile=.*|pidfile=/var/run/mumble-server/mumble-server.pid| ; \
			s|;logfile=.*|logfile=/var/log/mumble-server/mumble-server.log| ; \
			s|;host=.*|host=0.0.0.0|' \
		${STAGEDIR}${PREFIX}/etc/mumble/mumble-server.ini
	${MV}   ${STAGEDIR}${PREFIX}/etc/mumble/mumble-server.ini \
		${STAGEDIR}${PREFIX}/etc/mumble/mumble-server.ini.sample
.for f in bin/mumble-server-user-wrapper share/man/man1/mumble-server-user-wrapper.1
	${RM} ${STAGEDIR}${PREFIX}/${f}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.md SECURITY.md docs/additional-readmes/README.static.linux
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
