PORTNAME=	matreshka
DISTVERSION=	21.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	agh@riseup.net
COMMENT=	Ada framework for information systems development
WWW=		https://github.com/godunko/matreshka

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	segfault: raised STORAGE_ERROR : s-intman.adb:136 explicit raise

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:12,run gmake pkgconfig
USE_GCC=	yes:build
USE_GITHUB=	yes
GH_ACCOUNT=	godunko
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--gprdir="${PREFIX}/share/gpr"

MAKE_ENV+=	SMP_MFLAGS="-j${MAKE_JOBS_NUMBER}"

NO_MTREE=	yes

WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=			AMF
OPTIONS_DEFAULT=		AMF POSTGRES SQLITE
OPTIONS_GROUP=			DBSUPPORT
OPTIONS_GROUP_DBSUPPORT=	FIREBIRD MYSQL ORACLE POSTGRES SQLITE
OPTIONS_SUB=			yes

AMF_DESC=	Build Ada Modeling Framework
DBSUPPORT_DESC=	Database backend for generic SQL library
POSTGRES_DESC=	Postgres database support

AMF_CONFIGURE_ENABLE=		amf
FIREBIRD_USES=			firebird
FIREBIRD_CONFIGURE_ENABLE=	firebird
MYSQL_LIB_DEPENDS=		libunwind.so:devel/libunwind
MYSQL_USES=			mysql ssl
MYSQL_CONFIGURE_ENABLE=		mysql
ORACLE_CONFIGURE_ENABLE=	oracle
POSTGRES_USES=			pgsql
POSTGRES_CONFIGURE_ENABLE=	postgresql
SQLITE_USES=			sqlite
SQLITE_CONFIGURE_ENABLE=	sqlite3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
CONFIGURE_ARGS+=	--with-firebird-libdir=${LOCALBASE}/lib
.endif

pre-configure:
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} config)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
