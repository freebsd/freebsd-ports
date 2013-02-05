# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	2.0.9
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/inspircd/inspircd/
DISTNAME=	InspIRCd-${PORTVERSION}

MAINTAINER=	feld@feld.me
COMMENT=	A modular C++ IRC daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

CONFLICTS=	inspircd-1.*

USE_BZIP2=	yes
USE_RC_SUBR=	${PORTNAME}
MAKEFILE=	BSDmakefile

USERS=	ircd
GROUPS=	ircd
INSPIRCD_UID=	72

INSPIRCD_RUN?=	/var/run/${PORTNAME}
INSPIRCD_LOG?=	/var/log/${PORTNAME}/ircd.log
SUB_LIST+=	PORTNAME=${PORTNAME} \
		INSPIRCD_LOG=${INSPIRCD_LOG} \
		INSPIRCD_RUN=${INSPIRCD_RUN}

# Configure script is written in perl
USE_PERL5_BUILD=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR} \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules \
		--prefix=${PREFIX}/lib/${PORTNAME} --binary-dir=${PREFIX}/bin \
		--enable-kqueue --disable-interactive \
		--uid=${INSPIRCD_UID}

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE LDAPAUTH LDAPOPER GNUTLS OPENSSL PCRE POSIX
OPTIONS_DEFAULT=	POSIX

GNUTLS_DESC=	Build m_ssl_gnutls module
LDAPAUTH_DESC=	Build m_ldapauth module
LDAPOPER_DESC=	Build m_ldapoper module
MYSQL_DESC=	Build m_mysql module
OPENSSL_DESC=	Build m_ssl_openssl module
PGSQL_DESC=	Build m_pgsql module
SQLITE_DESC=	Build m_sqlite3 module
PCRE_DESC=	Build m_regex_pcre module
POSIX_DESC=	Build m_regex_posix module

.include <bsd.port.options.mk>

post-extract:
	@(cd ${WRKDIR} && ${MV} ${PORTNAME} ${DISTNAME})

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
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--enable-gnutls
EXTRAS:=${EXTRAS},m_ssl_gnutls.cpp
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=yes
CONFIGURE_ARGS+=	--enable-openssl
EXTRAS:=${EXTRAS},m_ssl_openssl.cpp
PLIST_SUB+=	OPENSSL=""
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
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

pre-configure:
	@if [ ${EXTRAS} ]; then \
		cd ${WRKSRC} && ./${CONFIGURE_SCRIPT} --enable-extras=${EXTRAS} ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|DATA_PATH "/inspircd.pid"|"/var/run/inspircd/inspircd.pid"|' ${WRKSRC}/src/inspircd.cpp

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.for FILE in inspircd.censor inspircd.conf inspircd.filter inspircd.helpop-full \
	inspircd.helpop inspircd.motd inspircd.quotes inspircd.rules links.conf modules.conf opers.conf
	@if ${TEST} -f ${ETCDIR}/${FILE} && \
		${TEST} ! -f ${ETCDIR}/examples/${FILE}.example ; then \
			${CP} -p ${ETCDIR}/examples/${FILE}.example \
			${ETCDIR}/${FILE}; \
	fi
.endfor

.include <bsd.port.mk>
