# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tarantool
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://tarantool.org/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${TR_REV}-src

MAINTAINER=	vg@FreeBSD.org
COMMENT=	High performance key/value storage server

LICENSE=	BSD

TR_REV=		248-g1f7eab2
MAKE_JOBS_UNSAFE=yes
USES=		cmake gettext:build gmake iconv perl5 compiler:c++11-lang
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
CMAKE_ARGS=	-DCMAKE_MAN_DIR=man \
		-DCMAKE_SYSCONF_DIR=${ETCDIR} \
		-DCMAKE_LOCALSTATE_DIR=${DATADIR}

OPTIONS_DEFINE=	CLIENT
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	MYSQL PGSQL
PLUGINS_DESC=	Plugins list
CLIENT_DESC=	Enable client
DEBUG_DESC=	Enable debug
MYSQL_DESC=	Install MySQL plugin
PGSQL_DESC=	Install PostgreSQL plugin

OPTIONS_DEFAULT=CLIENT

MAN1=		tarantool_box.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
CMAKE_ARGS+=	-DENABLE_CLIENT=true
PLIST_SUB+=	CLIENT=""
MAN1+=		tarantool.1
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_BUILD_TYPE=	RelWithDebugInfo
CMAKE_ARGS+=	-DENABLE_BACKTRACE=ON
.else
CMAKE_BUILD_TYPE=	Rel
CMAKE_ARGS+=	-DENABLE_BACKTRACE=OFF
.endif

.if ${PORT_OPTIONS:MMYSQL}
CMAKE_ARGS+=	-DWITH_MYSQL=ON
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	yes
.else
CMAKE_ARGS+=	-DWITH_MYSQL=OFF
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CMAKE_ARGS+=	-DWITH_POSTGRESQL=ON
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	yes
.else
CMAKE_ARGS+=	-DWITH_POSTGRESQL=OFF
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
