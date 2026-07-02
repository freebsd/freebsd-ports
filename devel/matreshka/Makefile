PORTNAME=	matreshka
DISTVERSIONPREFIX=	v
DISTVERSION=	21.0-18
DISTVERSIONSUFFIX=	-g464d78fe7
CATEGORIES=	devel

MAINTAINER=	ada@FreeBSD.org
COMMENT=	Ada framework for information systems development
WWW=		https://github.com/godunko/matreshka

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	segfault: raised STORAGE_ERROR : s-intman.adb:136 explicit raise

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:run gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	godunko
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--gprdir="${PREFIX}/share/gpr"

MAKE_ENV=	GNAT_OPTFLAGS="${_GPRBUILD_FLAGS}" \
		SMP_MFLAGS="-j${MAKE_JOBS_NUMBER}"

NO_MTREE=	yes

NO_SHLIB_REQUIRES_GLOB=	libgnat-${_ada_version}.so libgnarl-${_ada_version}.so

PLIST_SUB=	LIB_VERSION=${_ada_version} \
		SO_VERSION=${_MATRESHKA_SO_VERSION}

OPTIONS_DEFINE=			AMF
OPTIONS_DEFAULT=		AMF POSTGRES SQLITE
OPTIONS_GROUP=			DBSUPPORT
OPTIONS_GROUP_DBSUPPORT=	FIREBIRD MYSQL POSTGRES SQLITE
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
POSTGRES_USES=			pgsql
POSTGRES_CONFIGURE_ENABLE=	postgresql
SQLITE_USES=			sqlite
SQLITE_CONFIGURE_ENABLE=	sqlite3

_GPRBUILD_FLAGS=	-vh -vP2
_GPRINSTALL_FLAGS=	--no-manifest -v
_MATRESHKA_SO_VERSION=	${DISTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFIREBIRD}
CONFIGURE_ARGS+=	--with-firebird-libdir=${LOCALBASE}/lib
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	AMD64="" GENERIC="@comment "
.else
PLIST_SUB+=	AMD64="@comment " GENERIC=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%GPRBUILD_FLAGS%%|${_GPRBUILD_FLAGS}|' \
		${WRKSRC}/Makefile.build
	${REINPLACE_CMD} -e 's|%%GPRINSTALL_FLAGS%%|${_GPRINSTALL_FLAGS}|' \
		${WRKSRC}/Makefile.install
	${REINPLACE_CMD} -e 's|%%VERSION%%|${DISTVERSION}|' \
		${WRKSRC}/tools/configure/configure-version.adb
	${REINPLACE_CMD} -e 's|@VERSION@|${DISTVERSION}|' \
		-e 's|@RTL_VERSION_SUFFIX@|-${_ada_version}|' \
		${WRKSRC}/gnat/matreshka_config.gpr.in

pre-configure:
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${MAKE_CMD} config)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
