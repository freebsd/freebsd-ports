# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/InspIRCd-2.0/${PORTVERSION}
DISTNAME=	InspIRCd-${PORTVERSION}

MAINTAINER=	brain@inspircd.org
COMMENT=	A modular C++ IRC daemon

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

OPTIONS=	LDAPAUTH    "Build m_ldapauth module"          off \
		MYSQL       "Build m_mysql module"             off \
		PGSQL       "Build m_pgsql module"             off \
		SQLITE3     "Build m_sqlite3 module"           off \
		GNUTLS	    "Build m_ssl_gnutls module"        off \
		OPENSSL     "Build m_ssl_openssl module"       off

.include <bsd.port.pre.mk>

post-extract:
	@(cd ${WRKDIR} && ${MV} ${PORTNAME} ${DISTNAME})

.if defined(WITH_LDAPAUTH) && !defined(WITHOUT_LDAPAUTH)
USE_OPENLDAP=	yes
EXTRAS:=${EXTRAS},m_ldapauth.cpp
PLIST_SUB+=	LDAPAUTH=""
.else
PLIST_SUB+=	LDAPAUTH="@comment "
.endif

.if defined(WITH_MYSQL) && !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
EXTRAS:=${EXTRAS},m_mysql.cpp
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
EXTRAS:=${EXTRAS},m_pgsql.cpp
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE3) && !defined(WITHOUT_SQLITE3)
USE_SQLITE=	3
EXTRAS:=${EXTRAS},m_sqlite3.cpp
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(WITH_GNUTLS) && !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if defined(WITH_OPENSSL) && !defined(WITHOUT_OPENSSL)
.include <bsd.openssl.mk>
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

.include <bsd.port.post.mk>
