# Created by: Craig Edwards <brain@mail1.chatspike.net>
# $FreeBSD$

PORTNAME=	inspircd
PORTVERSION=	2.0.25
DISTVERSIONPREFIX=	v
CATEGORIES=	irc

MAINTAINER=	dg@syrec.org
COMMENT=	Modular C++ IRC daemon

LICENSE=	GPLv2

CONFLICTS=	inspircd-1.*

USE_GITHUB=	yes
GH_ACCOUNT=	inspircd

USE_RC_SUBR=	${PORTNAME}
MAKEFILE=	BSDmakefile

USERS=	ircd
GROUPS=	ircd
INSPIRCD_UID=	72

INSPIRCD_RUN?=	/var/run/${PORTNAME}
INSPIRCD_LOG?=	/var/log/${PORTNAME}/ircd.log
SUB_LIST+=	PORTNAME=${PORTNAME} \
		INSPIRCD_LOG=${INSPIRCD_LOG} \
		INSPIRCD_RUN=${INSPIRCD_RUN} \
		USERS=${USERS} \
		GROUPS=${GROUPS}

# Configure script is written in perl
USES=		cpe perl5
USE_PERL5=	build

CPE_VENDOR=	inspire_ircd
CPE_PRODUCT=	inspircd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR} \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules \
		--prefix=${PREFIX}/lib/${PORTNAME} \
		--binary-dir=${PREFIX}/bin --library-dir=${PREFIX}/lib/${PORTNAME} \
		--log-dir=${INSPIRCD_LOG} --data-dir=/var/db/inspircd \
		--enable-kqueue --disable-interactive \
		--uid=${INSPIRCD_UID}

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE LDAPAUTH LDAPOPER GNUTLS OPENSSL PCRE POSIX GEOIP
OPTIONS_DEFAULT=	OPENSSL POSIX

GNUTLS_DESC=	Build m_ssl_gnutls module
LDAPAUTH_DESC=	Build m_ldapauth module
LDAPOPER_DESC=	Build m_ldapoper module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PGSQL_DESC=	Build m_pgsql module
SQLITE_DESC=	Build m_sqlite3 module
PCRE_DESC=	Build m_regex_pcre module
POSIX_DESC=	Build m_regex_posix module
GEOIP_DESC=	Build m_geoip module

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAPAUTH}
USE_OPENLDAP=	yes
EXTRAS:=${EXTRAS},m_ldapauth.cpp
PLIST_SUB+=	LDAPAUTH=""
.else
PLIST_SUB+=	LDAPAUTH="@comment "
.endif

.if ${PORT_OPTIONS:MLDAPOPER}
USE_OPENLDAP=	yes
EXTRAS:=${EXTRAS},m_ldapoper.cpp
PLIST_SUB+=	LDAPOPER=""
.else
PLIST_SUB+=	LDAPOPER="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
EXTRAS:=${EXTRAS},m_mysql.cpp
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
EXTRAS:=${EXTRAS},m_pgsql.cpp
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=	pkgconfig sqlite
EXTRAS:=${EXTRAS},m_sqlite3.cpp
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
USES+=	pkgconfig
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
EXTRAS:=${EXTRAS},m_ssl_gnutls.cpp
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=	ssl pkgconfig
CONFIGURE_ARGS+=	--enable-openssl
EXTRAS:=${EXTRAS},m_ssl_openssl.cpp
PLIST_SUB+=	OPENSSL=""
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
EXTRAS:=${EXTRAS},m_regex_pcre.cpp
PLIST_SUB+=	PCRE=""
.else
PLIST_SUB+=	PCRE="@comment "
.endif

.if ${PORT_OPTIONS:MPOSIX}
EXTRAS:=${EXTRAS},m_regex_posix.cpp
PLIST_SUB+=	POSIX=""
.else
PLIST_SUB+=	POSIX="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
EXTRAS:=${EXTRAS},m_geoip.cpp
PLIST_SUB+=	GEOIP=""
.else
PLIST_SUB+=	GEOIP="@comment "
.endif

pre-configure:
	@if [ ${EXTRAS} ]; then \
		cd ${WRKSRC} && ${CONFIGURE_CMD} --enable-extras=${EXTRAS} ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|DATA_PATH "/inspircd.pid"|"/var/run/inspircd/inspircd.pid"|' ${WRKSRC}/src/inspircd.cpp
	@${REINPLACE_CMD} -e 's|conf/examples|examples|g' ${WRKSRC}/docs/conf/inspircd.conf.example

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
