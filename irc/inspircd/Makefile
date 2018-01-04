# Created by: Craig Edwards <brain@mail1.chatspike.net>
# $FreeBSD$

PORTNAME=	inspircd
PORTVERSION=	2.0.25
DISTVERSIONPREFIX=	v
CATEGORIES=	irc

MAINTAINER=	dg@syrec.org
COMMENT=	Modular C++ IRC daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

# Configure script is written in perl
USES=		cpe perl5
USE_PERL5=	build
CPE_VENDOR=	inspire_ircd
CPE_PRODUCT=	inspircd
USE_GITHUB=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} \
		--config-dir=${ETCDIR} \
		--prefix=${PREFIX}/libexec/${PORTNAME} \
		--binary-dir=${PREFIX}/bin \
		--module-dir=${PREFIX}/libexec/${PORTNAME}/modules \
		--log-dir=${INSPIRCD_LOGDIR} \
		--data-dir=${INSPIRCD_DBDIR} \
		--uid=${INSPIRCD_UID} \
		--enable-kqueue \
		--disable-interactive

USE_RC_SUBR=	${PORTNAME}
MAKEFILE=	BSDmakefile

USERS=		ircd
GROUPS=		ircd
INSPIRCD_UID=	72

INSPIRCD_DBDIR?=	/var/db/${PORTNAME}
INSPIRCD_LOGDIR?=	/var/log/${PORTNAME}
INSPIRCD_RUNDIR?=	/var/run/${PORTNAME}

SUB_FILES=	pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		INSPIRCD_DBDIR=${INSPIRCD_DBDIR} \
		INSPIRCD_LOGDIR=${INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS} \
		INSPIRCD_GROUP=${GROUPS}
PLIST_SUB=	INSPIRCD_DBDIR=${INSPIRCD_DBDIR} \
		INSPIRCD_LOGDIR=${INSPIRCD_LOGDIR} \
		INSPIRCD_RUNDIR=${INSPIRCD_RUNDIR} \
		INSPIRCD_USER=${USERS} \
		INSPIRCD_GROUP=${GROUPS}

CONFLICTS=	inspircd-1.*

OPTIONS_DEFINE=	GEOIP GNUTLS IPV6 LDAPAUTH LDAPOPER MYSQL OPENSSL PCRE PGSQL POSIX SQLITE
OPTIONS_DEFAULT=OPENSSL POSIX
OPTIONS_SUB=	yes

GEOIP_DESC=	Build m_geoip module
GNUTLS_DESC=	Build m_ssl_gnutls module
LDAPAUTH_DESC=	Build m_ldapauth module
LDAPOPER_DESC=	Build m_ldapoper module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PCRE_DESC=	Build m_regex_pcre module
PGSQL_DESC=	Build m_pgsql module
POSIX_DESC=	Build m_regex_posix module
SQLITE_DESC=	Build m_sqlite3 module

GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
GEOIP_VARS=		extras+=m_geoip.cpp

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFGURE_ENABLE=	gnutls
GNUTLS_VARS=		extras+=m_ssl_gnutls.cpp

IPV6_CONFIGURE_ENABLE=	ipv6

LDAPAUTH_USE=		openldap=yes
LDAPAUTH_VARS=		extras+=m_ldapauth.cpp

LDAPOPER_USE=		openldap=yes
LDAPOPER_VARS=		extras+=m_ldapoper.cpp

MYSQL_USES=		mysql
MYSQL_VARS=		extras+=m_mysql.cpp

OPENSSL_USES=		pkgconfig ssl
OPENSSL_CONFIGURE_ENABLE=	openssl
OPENSSL_VARS=		extras+=m_ssl_openssl.cpp

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_VARS=		extras+=m_regex_pcre.cpp

PGSQL_USES=		pgsql
PGSQL_VARS=		extras+=m_pgsql.cpp

POSIX_VARS=		extras+=m_regex_posix.cpp

SQLITE_USES=		pkgconfig sqlite
SQLITE_VARS=		extras+=m_sqlite3.cpp

pre-configure:
	@(cd ${WRKSRC}/src/modules && for m in ${EXTRAS}; do ${RLN} extra/$$m $$m; done)

post-patch:
	@${REINPLACE_CMD} -e 's|DATA_PATH "/inspircd.pid"|"${INSPIRCD_RUNDIR}/inspircd.pid"|' ${WRKSRC}/src/inspircd.cpp
	@${REINPLACE_CMD} -e 's|conf/examples|examples|g' ${WRKSRC}/docs/conf/inspircd.conf.example

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_DBDIR}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_LOGDIR}
	@${MKDIR} ${STAGEDIR}${INSPIRCD_RUNDIR}

.include <bsd.port.mk>
