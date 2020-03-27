# Created by: Sean Bruno
# $FreeBSD$

PORTNAME=	Cockatrice
PORTVERSION=	2.7.4
CATEGORIES=	games

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Virtual tabletop client and server for multiplayer card games

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lib gnome qt:5
USE_QT=		buildtools_build concurrent core network qmake_build websockets widgets gui
USE_GITHUB=	yes
GH_TAGNAME=	2020-03-20-Release-2.7.4

INSTALLS_ICONS=	yes
DATADIR=	${PREFIX}/share/${PORTNAME:tl}

OPTIONS_DEFINE=		COCKATRICE SERVATRICE MYSQL
OPTIONS_DEFAULT=	COCKATRICE
OPTIONS_SUB=		yes

COCKATRICE_DESC=	Build Cockatrice Client
SERVATRICE_DESC=	Build Cockatrice Server
MYSQL_DESC=		(Server Only) Add runtime dependencies on mysql-server

SERVATRICE_CMAKE_ON=	-DWITH_SERVER=ON
SERVATRICE_CMAKE_OFF=	-DWITH_SERVER=OFF
COCKATRICE_CMAKE_ON=	-DWITH_CLIENT=ON -DWITH_ORACLE=ON
COCKATRICE_CMAKE_OFF=	-DWITH_CLIENT=OFF -DWITH_ORACLE=OFF

COCKATRICE_USE=		qt=multimedia,printsupport,svg,linguisttools_build
SERVATRICE_USE=		qt=sql,sql-mysql
SERVATRICE_USE+=	RC_SUBR=servatrice

MYSQL_USES+=		mysql:server
MYSQL_SUB_LIST_OFF=	mysql=""
MYSQL_SUB_LIST=		mysql="mysql"

SERVATRICE_LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
