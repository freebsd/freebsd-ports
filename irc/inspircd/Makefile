# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/inspircd/inspircd/
DISTNAME=	InspIRCd-${PORTVERSION}

MAINTAINER=	feld@feld.me
COMMENT=	A modular C++ IRC daemon

CONFLICTS=	inspircd-1.*

USE_BZIP2=	yes
USE_RC_SUBR=	${PORTNAME}
MAKEFILE=	BSDmakefile

USERS=		${INSPIRCD_USR}
GROUPS=		${INSPIRCD_GRP}

INSPIRCD_USR?=	ircd
INSPIRCD_UID?=	72
INSPIRCD_GRP?=	ircd
INSPIRCD_GID?=	72
INSPIRCD_RUN?=	/var/run/${PORTNAME}
INSPIRCD_LOG?=	/var/log/${PORTNAME}/ircd.log
SUB_LIST+=	PORTNAME=${PORTNAME}         \
		INSPIRCD_USR=${INSPIRCD_USR} \
		INSPIRCD_GRP=${INSPIRCD_GRP} \
		INSPIRCD_LOG=${INSPIRCD_LOG} \
		INSPIRCD_RUN=${INSPIRCD_RUN}
PLIST_SUB+=	INSPIRCD_GRP=${INSPIRCD_GRP}
SUB_FILES+=	pkg-deinstall

# Configure script is written in perl
USE_PERL5_BUILD=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR} \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules            \
		--library-dir=${PREFIX}/lib/${PORTNAME}                   \
		--prefix=${PREFIX}/lib/${PORTNAME} --binary-dir=${PREFIX}/bin \
		--enable-kqueue --enable-ipv6 --disable-interactive \
		--uid=${INSPIRCD_UID}

PORTDOCS=	docs/* extras/*

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE LDAP GNUTLS OPENSSL

GNUTLS_DESC=	Build m_ssl_gnutls module
LDAP_DESC=	Build m_ldapauth module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PGSQL_DESC=	Build m_pgsql module
SQLITE_DESC=	Build m_sqlite3 module

.include <bsd.port.options.mk>

post-extract:
	@(cd ${WRKDIR} && ${MV} ${PORTNAME} ${DISTNAME})

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
EXTRAS:=${EXTRAS},m_ldapauth.cpp
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
EXTRAS:=${EXTRAS},m_mysql.cpp
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
EXTRAS:=${EXTRAS},m_pgsql.cpp
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
EXTRAS:=${EXTRAS},m_sqlite3.cpp
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--enable-gnutls
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=yes
CONFIGURE_ARGS+=	--enable-openssl
PLIST_SUB+=	OPENSSL=""
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

CONFIGURE_ARGS+=	--enable-extras=${EXTRAS}

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.for FILE in inspircd.censor inspircd.conf inspircd.filter inspircd.helpop-full \
	inspircd.helpop inspircd.motd inspircd.quotes inspircd.rules links.conf modules.conf opers.conf
	@if ${TEST} -f ${ETCDIR}/${FILE} &&              \
	    ${TEST} ! -f ${ETCDIR}/${FILE}.example ; then \
		${CP} -p ${ETCDIR}/${FILE}.example       \
			${ETCDIR}/${FILE};               \
	fi
.endfor

.include <bsd.port.mk>
