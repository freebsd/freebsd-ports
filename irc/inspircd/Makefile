# Created by: Craig Edwards <brain@mail1.chatspike.net>
# $FreeBSD$

PORTNAME=	inspircd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.0
CATEGORIES=	irc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Modular C++ IRC daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.txt

# Configure script is written in perl
USES=		compiler:c++11-lang cpe gmake localbase:ldflags perl5
USE_GITHUB=	yes
USE_PERL5=	build

CPE_VENDOR=	inspire_ircd
CPE_PRODUCT=	inspircd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--binary-dir=${PREFIX}/bin \
		--config-dir=${ETCDIR} \
		--data-dir=${INSPIRCD_DBDIR} \
		--log-dir=${INSPIRCD_LOGDIR} \
		--manual-dir=${MANPREFIX}/man/man1 \
		--module-dir=${PREFIX}/libexec/${PORTNAME}/modules \
		--prefix=${PREFIX}/libexec/${PORTNAME} \
		--distribution-label=${OPSYS}-${PORTVERSION} \
		--uid=0 --gid=0 \
		--disable-auto-extras

USE_RC_SUBR=	${PORTNAME}
MAKEFILE=	GNUmakefile

USERS=		ircd
GROUPS=		ircd
INSPIRCD_UID=	72
INSPIRCD_GID=	72

INSPIRCD_DBDIR?=	/var/db/${PORTNAME}
INSPIRCD_LOGDIR?=	/var/log/${PORTNAME}
INSPIRCD_RUNDIR?=	/var/run/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	INSPIRCD_DBDIR=${INSPIRCD_DBDIR} \
		INSPIRCD_GROUP=${GROUPS} \
		INSPIRCD_LOGDIR=${INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS} \
		PORTNAME=${PORTNAME}
PLIST_SUB=	INSPIRCD_DBDIR=${INSPIRCD_DBDIR} \
		INSPIRCD_GROUP=${GROUPS} \
		INSPIRCD_LOGDIR=${INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS}

OPTIONS_DEFINE=		GNUTLS IPV6 LDAP MBEDTLS MYSQL OPENSSL PCRE PGSQL POSIX SQLITE SSLREHASH
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

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_USES=			pkgconfig
GNUTLS_VARS=			EXTRAS+=m_ssl_gnutls.cpp

LDAP_USE=	OPENLDAP=yes
LDAP_VARS=	EXTRAS+=m_ldap.cpp

MBEDTLS_LIB_DEPENDS=		libmbedtls.so:security/mbedtls
MBEDTLS_VARS=			EXTRAS+=m_ssl_mbedtls.cpp

MYSQL_USES=	mysql
MYSQL_VARS=	EXTRAS+=m_mysql.cpp

OPENSSL_USES=			pkgconfig ssl
OPENSSL_VARS=			EXTRAS+=m_ssl_openssl.cpp

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_VARS=		EXTRAS+=m_regex_pcre.cpp

PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRAS+=m_pgsql.cpp

POSIX_VARS=	EXTRAS+=m_regex_posix.cpp

SQLITE_USES=	pkgconfig sqlite
SQLITE_VARS=	EXTRAS+=m_sqlite3.cpp

SSLREHASH_VARS+=	EXTRAS+=m_sslrehashsignal.cpp

pre-configure:
	@(cd ${WRKSRC}/src/modules && for m in ${EXTRAS}; do ${RLN} extra/$$m $$m; done)

post-patch:
	@${REINPLACE_CMD} -e 's|%%INSPIRCD_USER%%|${USERS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%INSPIRCD_UID%%|${INSPIRCD_UID}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%INSPIRCD_GROUP%%|${GROUPS}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%INSPIRCD_GID%%|${INSPIRCD_GID}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|DATA_PATH "/inspircd.pid"|"${INSPIRCD_RUNDIR}/inspircd.pid"|' ${WRKSRC}/src/inspircd.cpp
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/inspircd.conf.example
	@${REINPLACE_CMD} -e 's|examples/||g' -e 's|\.example||g' ${WRKSRC}/docs/conf/modules.conf.example
	@${RM} ${WRKSRC}/make/template/main.mk.orig

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_DBDIR}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_LOGDIR}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_RUNDIR}

.include <bsd.port.mk>
