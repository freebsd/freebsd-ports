# $FreeBSD$

PORTNAME=	powerdns
PORTVERSION=	3.3
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES=	dns ipv6
PKGNAMESUFFIX=	-devel
DISTNAME=	auth-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	tremere@cainites.net
COMMENT=	Advanced DNS server with multiple backends including SQL

LICENSE=	GPLv2

BUILD_DEPENDS=	ragel:${PORTSDIR}/devel/ragel \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libboost_serialization.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	YES
GH_ACCOUNT=	PowerDNS
GH_PROJECT=	pdns
GH_TAGNAME=	auth-3.3
GH_COMMIT=	b8fe1df

USE_LUA=	5.1
LUA_COMPS=	lua

CONFLICTS=	powerdns-[2-3].[0-9]*

NO_LATEST_LINK=	YES

USES=		bison gmake pkgconfig
USE_SUBMAKE=	YES
USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-modules="" \
		--with-dynmodules="pipe ${MODULES}" \
		--sysconfdir="${PREFIX}/etc/pdns" \
		--with-boost="${LOCALBASE}"
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		POWERDNS_OPTIONS="${POWERDNS_OPTIONS}"

SUB_FILES=	pkg-message

USE_RC_SUBR+=	pdns-devel

OPTIONS_DEFINE=	GEO MYSQL MYSQL_LOCAL OPENDBX OPENLDAP OPENLDAP_LOCAL \
		PGSQL PGSQL_LOCAL POLARSSL SQLITE3 TOOLS
OPTIONS_MULTI=	DNSSEC
OPTIONS_MULTI_DNSSEC=	BOTAN110 CRYPTOPP

BACKENDS_DESC=		Choose backend(s)
PGSQL_DESC=		PostgreSQL backend
PGSQL_LOCAL_DESC=	RUN_DEPEND on PostgreSQL server
MYSQL_DESC=		MySQL backend
MYSQL_LOCAL_DESC=	RUN_DEPEND on MySQL server
OPENDBX_DESC=		OpenDBX backend
OPENLDAP_DESC=		OpenLDAP backend
OPENLDAP_LOCAL_DESC=	RUN_DEPEND on OpenLDAP server
SQLITE3_DESC=		SQLite 3 backend
GEO_DESC=		Geo backend
DNSSEC_DESC=		Enable extra DNSSEC options
BOTAN110_DESC=		Faster signing + ECDSA & GOST algorithms
CRYPTOPP_DESC=		ECDSA algorithms
POLARSSL_DESC=		Use embedded PolarSSL
TOOLS_DESC=		Build extra tools

OPTIONS_DEFAULT=	PGSQL DNSSEC BOTAN110 POLARSSL

OPTIONS_SUB=	yes

TOOLS_CONFIGURE_ENABLE=	tools

PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
PGSQL_USE=		PGSQL=YES
PGSQL_LOCAL_USE=	PGSQL=server

MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USE=		MYSQL=YES
MYSQL_LOCAL_USE=	MYSQL=server

OPENLDAP_CXXFLAGS=	-DLDAP_DEPRECATED=1
OPENLDAP_USE=		OPENLDAP=YES
OPENLDAP_LOCAL_RUN_DEPENDS=	openldap-server>=0:${PORTSDIR}/net/openldap24-server

SQLITE3_USE=	SQLITE=3

OPENDBX_LIB_DEPENDS=	libopendbx.so:${PORTSDIR}/databases/opendbx

BOTAN110_CONFIGURE_ENABLE=	botan1.10
BOTAN110_LIB_DEPENDS=		libbotan-1.10.so:${PORTSDIR}/security/botan110

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGEO}
MODULES+=	"geo"
.endif

.if ${PORT_OPTIONS:MPGSQL}
MODULES+=	"gpgsql"
.endif

.if ${PORT_OPTIONS:MMYSQL}
MODULES+=	"gmysql"
.endif

.if ${PORT_OPTIONS:MPGSQL_LOCAL}
SUB_LIST+=	PGSQL_REQ=postgresql
.else
SUB_LIST+=	PGSQL_REQ=
.endif

.if ${PORT_OPTIONS:MMYSQL_LOCAL}
SUB_LIST+=	MYSQL_REQ=mysql
.else
SUB_LIST+=	MYSQL_REQ=
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
MODULES+=	"ldap"
.endif

.if ${PORT_OPTIONS:MOPENLDAP_LOCAL}
SUB_LIST+=	SLAPD_REQ=slapd
.else
SUB_LIST+=	SLAPD_REQ=
.endif

.if ${PORT_OPTIONS:MSQLITE3}
MODULES+=	"gsqlite3"
.endif

.if ${PORT_OPTIONS:MOPENDBX}
MODULES+=	"opendbx"
.endif

.if ${PORT_OPTIONS:MPOLARSSL}
CONFIGURE_ARGS+=	--without-system-polarssl
.else
LIB_DEPENDS+=		libpolarssl.so:${PORTSDIR}/security/polarssl
.endif

.if ${PORT_OPTIONS:MCRYPTOPP}
.	if exists(${LOCALBASE}/lib/libcryptopp.so)
LIB_DEPENDS+=		libcryptopp.so:${PORTSDIR}/security/cryptopp
.	else
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
.	endif
CONFIGURE_ARGS+=	--enable-cryptopp
.endif

pre-patch:
	${ECHO_CMD} ${BARBA}
	@${REINPLACE_CMD} -e "s;/bin/bash;/usr/bin/env bash;" \
		-e "s;ssed -r;sed -E -e;g" \
		-e "s;-i;-i \.bak;g" \
		${WRKSRC}/build-scripts/set-version-auth
	@${REINPLACE_CMD} -e 's;\$$(LIBCURL_LIBS) \$$(MYSQL_lib);;g' \
		-e 's;\$$(LIBCURL_CFLAGS);;g' \
		${WRKSRC}/pdns/Makefile.am
.if ${PORT_OPTIONS:MBOTAN110}
	@${REINPLACE_CMD} -e 's;\$$(BOOST_CPPFLAGS);;g' \
		-e 's;-lgmp -lrt;;g' \
		${WRKSRC}/pdns/Makefile.am
	@${REINPLACE_CMD} -E -e 's;(\$$\(BOTAN110_CFLAGS\));\1 \$$\(BOOST_CPPFLAGS\);' \
		${WRKSRC}/pdns/Makefile.am
.endif
.if ${PORT_OPTIONS:MOPENLDAP}
	@${REINPLACE_CMD} -e 's;la_LDFLAGS =;la_LDFLAGS = -L${LOCALBASE}/lib ;' \
		${WRKSRC}/modules/ldapbackend/Makefile.am
.endif
.if ${PORT_OPTIONS:MPGSQL}
	@${REINPLACE_CMD} -E -e 's;(PGSQL_inc_check="\$$withval/include/pgsql)";\1 \$$withval/include";' \
		${WRKSRC}/configure.ac
.endif

pre-configure:
	@(cd ${WRKSRC} && ${WRKSRC}/build-scripts/set-version-auth git-${GH_TAGNAME} 0.0.${GH_TAGNAME} 0.0.${GH_TAGNAME} && ${WRKSRC}/bootstrap)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in pdns.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${STAGEDIR}${EXAMPLESDIR}/
.endfor
.for j in libgpgsqlbackend.so libgmysqlbackend.so libgsqlite3backend.so \
	libldapbackend.so libopendbxbackend.so libgeobackend.so \
	libpipebackend.so
	@if ([ -f ${STAGEDIR}${PREFIX}/lib/$j ] && [ ! -f ${STAGEDIR}${PREFIX}/lib/$j.0 ]); then \
		${LN} -sf ${PREFIX}/lib/$j ${STAGEDIR}${PREFIX}/lib/$j.0; \
	fi
.endfor

.include <bsd.port.post.mk>
