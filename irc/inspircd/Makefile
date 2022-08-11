PORTNAME=	inspircd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.13.0
CATEGORIES=	irc

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Modular C++ IRC daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

USES=		compiler:c++11-lang cpe gmake localbase:ldflags perl5
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
		--manual-dir=${MANPREFIX}/man/man1 \
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

OPTIONS_DEFINE=		GNUTLS LDAP MBEDTLS MYSQL OPENSSL PCRE PGSQL POSIX \
			SQLITE SSLREHASH
OPTIONS_DEFAULT=	OPENSSL POSIX
OPTIONS_SUB=		yes

GNUTLS_DESC=	Build m_ssl_gnutls module
LDAP_DESC=	Build m_ldap module
MBEDTLS_DESC=	Build m_ssl_mbedtls module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PCRE_DESC=	Build m_regex_pcre module
PGSQL_DESC=	Build m_pgsql module
POSIX_DESC=	Build m_regex_posix module
SQLITE_DESC=	Build m_sqlite3 module
SSLREHASH_DESC=	Build m_sslrehashsignal module

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_VARS=		EXTRAS+=m_ssl_gnutls.cpp

LDAP_USE=		OPENLDAP=yes
LDAP_VARS=		EXTRAS+=m_ldap.cpp
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_VARS=		EXTRAS+=m_ssl_mbedtls.cpp
MYSQL_USES=		mysql
MYSQL_VARS=		EXTRAS+=m_mysql.cpp
OPENSSL_USES=		pkgconfig ssl
OPENSSL_VARS=		EXTRAS+=m_ssl_openssl.cpp
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_VARS=		EXTRAS+=m_regex_pcre.cpp
PGSQL_USES=		pgsql
PGSQL_VARS=		EXTRAS+=m_pgsql.cpp
POSIX_VARS=		EXTRAS+=m_regex_posix.cpp
SQLITE_USES=		pkgconfig sqlite
SQLITE_VARS=		EXTRAS+=m_sqlite3.cpp
SSLREHASH_VARS+=	EXTRAS+=m_sslrehashsignal.cpp

_INSPIRCD_DBDIR?=	/var/db/${PORTNAME}
_INSPIRCD_LOGDIR?=	/var/log/${PORTNAME}
_INSPIRCD_RUNDIR?=	/var/run/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/inspircd.conf.example
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/modules.conf.example

pre-configure:
	@(cd ${WRKSRC}/src/modules && for m in ${EXTRAS}; do ${RLN} extra/$$m $$m; done)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_DBDIR}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_LOGDIR}
	@${MKDIR} ${STAGEDIR}${_INSPIRCD_RUNDIR}

.include <bsd.port.mk>
