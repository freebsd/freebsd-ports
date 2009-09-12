# New ports collection makefile for:   inspircd
# Date created:        25 August 2006
# Whom:                brain
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	1.1.20
CATEGORIES=	irc
MASTER_SITES=	http://www.inspircd.org/downloads/ \
		http://www.chatspike.net/downloads/
DISTNAME=	InspIRCd-${PORTVERSION}

MAINTAINER=	brain@inspircd.org
COMMENT=	A modular C++ IRC daemon

WRKSRC=	${WRKDIR}/inspircd
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	${PREFIX}/lib/inspircd
USE_RC_SUBR=	inspircd.sh

INSPIRCD_USR?=	ircd
INSPIRCD_UID?=	72
INSPIRCD_GRP?=	ircd
INSPIRCD_GID?=	72
INSPIRCD_RUN?=	/var/run/${PORTNAME}
INSPIRCD_LOG?=	/var/log/${PORTNAME}/ircd.log
SUB_LIST+=	PORTNAME=${PORTNAME}         \
		INSPIRCD_USR=${INSPIRCD_USR} \
		INSPIRCD_UID=${INSPIRCD_UID} \
		INSPIRCD_GRP=${INSPIRCD_GRP} \
		INSPIRCD_GID=${INSPIRCD_GID} \
		INSPIRCD_RUN=${INSPIRCD_RUN} \
		INSPIRCD_LOG=${INSPIRCD_LOG}
PLIST_SUB+=	INSPIRCD_GRP=${INSPIRCD_GRP}
SUB_FILES+=	pkg-install pkg-deinstall

USE_OPENSSL=	yes
OPENSSL_PORT?=	security/openssl

# Configure script is written in perl
USE_PERL5_BUILD=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR}                   \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules            \
		--library-dir=${PREFIX}/lib/${PORTNAME}                   \
		--prefix=${PREFIX}/${PORTNAME} --binary-dir=${PREFIX}/bin \
		--enable-ipv6 --enable-remote-ipv6 --disable-interactive

OPTIONS=	FILTER_PCRE "Build m_filter_pcre module"       off \
		LDAPAUTH    "Build m_ldapauth module"          off \
		MYSQL       "Build m_mysql module"             off \
		PGSQL       "Build m_pgsql module"             off \
		SQLITE3     "Build m_sqlite3 module"           off \
		SQLMODULES  "Build m_sql{log,oper,utils,auth}" off \
		GNUTLS	    "Build m_ssl_gnutls module"        off \
		OPENSSL     "Build m_ssl_openssl module"       off \
		SSLMODULES  "Build m_ssl_{info,oper_cert}"     off \
		ZIPLINK     "Build m_ziplink module"           off

.include <bsd.port.pre.mk>

.if defined(WITH_FILTER_PCRE) && !defined(WITHOUT_FILTER_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
SYMLINK_FILES+=	m_filter_pcre.cpp
PLIST_SUB+=	FILTER_PCRE=""
.else
PLIST_SUB+=	FILTER_PCRE="@comment "
.endif

.if defined(WITH_LDAPAUTH) && !defined(WITHOUT_LDAPAUTH)
USE_OPENLDAP=	yes
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__modules__extra__m_ldapauth.cpp
SYMLINK_FILES+=	m_ldapauth.cpp
PLIST_SUB+=	LDAPAUTH=""
.else
PLIST_SUB+=	LDAPAUTH="@comment "
.endif

.if defined(WITH_MYSQL) && !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
SYMLINK_FILES+=	m_mysql.cpp m_sqlv2.h
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
SYMLINK_FILES+=	m_pgsql.cpp m_sqlv2.h
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE3) && !defined(WITHOUT_SQLITE3)
USE_SQLITE=	3
SYMLINK_FILES+=	m_sqlite3.cpp m_sqlv2.h
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(WITH_SQLMODULES) && !defined(WITHOUT_SQLMODULES)
.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE3)
BROKEN=		Please enable at least one of MYSQL, PGSQL or SQLITE3 required by SQLMODULES
.endif
SYMLINK_FILES+=	m_sqlauth.cpp m_sqllog.cpp m_sqloper.cpp m_sqlutils.cpp \
		m_sqlutils.h
PLIST_SUB+=	SQLMODULES=""
.else
PLIST_SUB+=	SQLMODULES="@comment "
.endif

.if defined(WITH_GNUTLS) && !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
SYMLINK_FILES+=	m_ssl_gnutls.cpp
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if defined(WITH_OPENSSL) && !defined(WITHOUT_OPENSSL)
# I'd like to say USE_OPENSSL=yes here but that's not allowed.
# Failing that maybe?: .include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-openssl
SYMLINK_FILES+=	m_ssl_openssl.cpp
PLIST_SUB+=	OPENSSL=""

# The configure script tries to run 'pkg-config --libs openssl' in
# order to work out how to link against openssl.  This works fine if
# OpenSSL is installed as a port, but not if the base system version
# is being used.
.if defined(WITH_OPENSSL_BASE)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__modules__extra__m_ssl_openssl.cpp
.endif

.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if defined(WITH_SSLMODULES) && !defined(WITHOUT_SSLMODULES)
.if !defined(WITH_GNUTLS) && !defined(WITH_OPENSSL)
BROKEN=		Please enable at least one of GNUTLS or OPENSSL required by SSLMODULES
.endif
SYMLINK_FILES+=	m_ssl_oper_cert.cpp m_sslinfo.cpp
PLIST_SUB+=	SSLMODULES=""
.else
PLIST_SUB+=	SSLMODULES="@comment "
.endif

.if defined(WITH_ZIPLINK) && !defined(WITHOUT_ZIPLINK)
SYMLINK_FILES+=	m_ziplink.cpp
PLIST_SUB+=	ZIPLINK=""
.else
PLIST_SUB+=	ZIPLINK="@comment "
.endif

CXXFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e '/INSTMODE/s|700|755|;/install -d.*BINPATH/d'\
	  -e 's,FLAGS = @FLAGS@,FLAGS = ${CXXFLAGS} @FLAGS@,' \
	  ${WRKSRC}/.Makefile.inc

.for f in ${SYMLINK_FILES}
pre-configure::
	cd ${WRKSRC}/src/modules && \
	  ${TEST} -L ${f}        || \
	  ${LN} -s extra/${f} ${f}
.endfor

pre-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/*.so
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.for FILE in censor conf filter helpop-full helpop motd quotes rules
	@if ${TEST} -f ${ETCDIR}/${PORTNAME}.${FILE} &&              \
	    ${TEST} ! -f ${ETCDIR}/${PORTNAME}.${FILE}.example ; then \
		${CP} -p ${ETCDIR}/${PORTNAME}.${FILE}.example       \
			${ETCDIR}/${PORTNAME}.${FILE};               \
	fi
.endfor

.include <bsd.port.post.mk>
