PORTNAME=	inspircd
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.0
CATEGORIES=	irc

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Modular C++ IRC daemon
WWW=		https://www.inspircd.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USES=		compiler:c++11-lang cpe gmake localbase:ldflags perl5 pkgconfig
USE_GITHUB=	yes
USE_PERL5=	build
USE_RC_SUBR=	${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--binary-dir=${PREFIX}/bin \
		--config-dir=${ETCDIR} \
		--data-dir=${_INSPIRCD_DBDIR} \
		--disable-auto-extras \
		--distribution-label=${OPSYS}-${PORTVERSION} \
		--gid=nobody \
		--log-dir=${_INSPIRCD_LOGDIR} \
		--manual-dir=${PREFIX}/share/man/man1 \
		--module-dir=${PREFIX}/libexec/${PORTNAME}/modules \
		--prefix=${PREFIX}/libexec/${PORTNAME} \
		--runtime-dir=${_INSPIRCD_RUNDIR} \
		--uid=nobody

MAKEFILE=	GNUmakefile

SUB_FILES=	pkg-message
SUB_LIST=	INSPIRCD_DBDIR=${_INSPIRCD_DBDIR} \
		INSPIRCD_GROUP=${GROUPS} \
		INSPIRCD_LOGDIR=${_INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${_INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS} \
		PORTNAME=${PORTNAME}

USERS=		ircd
GROUPS=		ircd

PLIST_SUB=	INSPIRCD_DBDIR=${_INSPIRCD_DBDIR} \
		INSPIRCD_GROUP=${GROUPS} \
		INSPIRCD_LOGDIR=${_INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${_INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS}

OPTIONS_DEFINE=		ARGON GNUTLS JSON LDAP MAXMIND MBEDTLS MYSQL OPENSSL \
			PCRE2 PGSQL POSIX RE2 SQLITE SSLREHASH SYSLOG
OPTIONS_DEFAULT=	OPENSSL POSIX
OPTIONS_SUB=		yes

ARGON_DESC=	Build m_argon2 module
GNUTLS_DESC=	Build m_ssl_gnutls module
JSON_DESC=	Build m_log_json module
LDAP_DESC=	Build m_ldap module
MAXMIND_DESC=	Build m_geo_maxmind module
MBEDTLS_DESC=	Build m_ssl_mbedtls module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PCRE2_DESC=	Build m_regex_pcre2 module
PGSQL_DESC=	Build m_pgsql module
POSIX_DESC=	Build m_regex_posix module
RE2_DESC=	Build m_regex_re2 module
SQLITE_DESC=	Build m_sqlite3 module
SSLREHASH_DESC=	Build m_sslrehashsignal module
SYSLOG_DESC=	Build m_log_syslog module

ARGON_LIB_DEPENDS=	libargon2.so:security/libargon2
ARGON_VARS=		EXTRAS+=m_argon2.cpp
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_VARS=		EXTRAS+=m_ssl_gnutls.cpp
JSON_BUILD_DEPENDS=	rapidjson>0:devel/rapidjson
JSON_VARS=		EXTRAS+=m_log_json.cpp
LDAP_USES=		ldap
LDAP_VARS=		EXTRAS+=m_ldap.cpp
MAXMIND_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
MAXMIND_VARS=		EXTRAS+=m_geo_maxmind.cpp
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls2
MBEDTLS_VARS=		EXTRAS+=m_ssl_mbedtls.cpp
MYSQL_USES=		mysql
MYSQL_VARS=		EXTRAS+=m_mysql.cpp
OPENSSL_USES=		ssl
OPENSSL_VARS=		EXTRAS+=m_ssl_openssl.cpp
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_VARS=		EXTRAS+=m_regex_pcre2.cpp
PGSQL_USES=		pgsql
PGSQL_VARS=		EXTRAS+=m_pgsql.cpp
POSIX_VARS=		EXTRAS+=m_regex_posix.cpp
RE2_LIB_DEPENDS=	libre2.so:devel/re2
RE2_VARS=		EXTRAS+=m_regex_re2.cpp
SQLITE_USES=		sqlite
SQLITE_VARS=		EXTRAS+=m_sqlite3.cpp
SSLREHASH_VARS=		EXTRAS+=m_sslrehashsignal.cpp
SYSLOG_VARS=		EXTRAS+=m_log_syslog.cpp

_INSPIRCD_DBDIR?=	/var/db/${PORTNAME}
_INSPIRCD_LOGDIR?=	/var/log/${PORTNAME}
_INSPIRCD_RUNDIR?=	/var/run/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/inspircd.example.conf
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/modules.example.conf

pre-configure:
	@(cd ${WRKSRC}/src/modules && for m in ${EXTRAS}; do ${RLN} extra/$$m $$m; done)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_DBDIR}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_LOGDIR}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_RUNDIR}

.include <bsd.port.mk>
