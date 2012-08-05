# New ports collection Makefile for:   inspircd
# Date created:        07 March 2011
# Whom:                Maxim Ignatenko <gelraen.ua@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	inspircd
PORTVERSION=	1.2.9
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/inspircd/inspircd/
DISTNAME=	InspIRCd-v${PORTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	A modular C++ IRC daemon

CONFLICTS=	inspircd-2.*

LATEST_LINK=	inspircd12

WRKSRC=	${WRKDIR}/inspircd
USE_BZIP2=	yes
USE_LDCONFIG=	${PREFIX}/lib/inspircd
USE_RC_SUBR=	inspircd
MAKE_JOBS_SAFE=	yes

USERS=	${INCPIRCD_USR}
GROUPS=	${INSPIRCD_GRP}

INSPIRCD_USR?=	ircd
INSPIRCD_UID?=	72
INSPIRCD_GRP?=	ircd
INSPIRCD_GID?=	72
INSPIRCD_RUN?=	/var/run/${PORTNAME}
INSPIRCD_LOG?=	/var/log/${PORTNAME}/ircd.log
SUB_LIST+=	\
		INSPIRCD_USR=${INSPIRCD_USR} \
		INSPIRCD_UID=${INSPIRCD_UID} \
		INSPIRCD_GRP=${INSPIRCD_GRP} \
		INSPIRCD_GID=${INSPIRCD_GID} \
		INSPIRCD_RUN=${INSPIRCD_RUN} \
		INSPIRCD_LOG=${INSPIRCD_LOG}
PLIST_SUB+=	INSPIRCD_GRP=${INSPIRCD_GRP}

# Configure script is written in perl
USE_PERL5_BUILD=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR}                   \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules            \
		--library-dir=${PREFIX}/lib/${PORTNAME}                   \
		--prefix=${DATADIR} --binary-dir=${PREFIX}/bin \
		--disable-interactive
MAKEFILE=	BSDmakefile

OPTIONS=	LDAPMODULES    "Build m_ldap{auth,oper} modules"          off \
		MYSQL       "Build m_mysql module"             off \
		PGSQL       "Build m_pgsql module"             off \
		SQLITE3     "Build m_sqlite3 module"           off \
		SQLMODULES  "Build m_sql{log,oper,utils,auth}" off \
		GNUTLS	    "Build m_ssl_gnutls module"        off \
		OPENSSL     "Build m_ssl_openssl module"       on \
		ZIPLINK     "Build m_ziplink module"           off \
		POSIX_RE    "Build m_regex_posix module"       on \
		PCRE        "Build m_regex_pcre module"        off \
		TRE         "Build m_regex_tre module"         off \
		IPV6        "Enable IPv6 support"              on

.include <bsd.port.options.mk>

.if defined(WITH_IPV6) && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6 --enable-remote-ipv6
.else
CONFIGURE_ARGS+=	--disable-remote-ipv6
.endif

.if defined(WITH_POSIX_RE) && !defined(WITHOUT_POSIX_RE)
PLIST_SUB+=	POSIX_RE=""
SYMLINK_FILES+=	m_regex_posix.cpp
.else
PLIST_SUB+=	POSIX_RE="@comment "
.endif

.if defined(WITH_PCRE) && !defined(WITHOUT_PCRE)
PLIST_SUB+=	PCRE=""
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
SYMLINK_FILES+=	m_regex_pcre.cpp
.else
PLIST_SUB+=	PCRE="@comment "
.endif

.if defined(WITH_TRE) && !defined(WITHOUT_TRE)
PLIST_SUB+=	TRE=""
LIB_DEPENDS+=	tre:${PORTSDIR}/textproc/libtre
CONFIGURE_ARGS+=	--tre-includes=${LOCALBASE}/include
SYMLINK_FILES+=	m_regex_tre.cpp
.else
PLIST_SUB+=	TRE="@comment "
.endif

.if defined(WITH_LDAPMODULES) && !defined(WITHOUT_LDAPMODULES)
USE_OPENLDAP=	yes
SYMLINK_FILES+=	m_ldapauth.cpp m_ldapoper.cpp
PLIST_SUB+=	LDAPMODULES=""
.else
PLIST_SUB+=	LDAPMODULES="@comment "
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
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-openssl
SYMLINK_FILES+=	m_ssl_openssl.cpp
PLIST_SUB+=	OPENSSL=""
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

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

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

post-configure:
#	${MV} ${WRKSRC}/BSDmakefile ${WRKSRC}/Makefile
	${TOUCH} ${WRKSRC}/.force-root-ok

post-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	@${CP} -rv ${WRKSRC}/include/* ${PREFIX}/include/${PORTNAME}/
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/locales
	@${CP} -rv ${WRKSRC}/locales/* ${PREFIX}/share/${PORTNAME}/locales/
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/modules/*.so
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/*.so
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.for FILE in censor conf filter helpop-full helpop motd quotes rules
	@if [ ! -f ${ETCDIR}/${PORTNAME}.${FILE} ] ; then	\
	    ${CP} -p ${ETCDIR}/${PORTNAME}.${FILE}.example	\
		${ETCDIR}/${PORTNAME}.${FILE};			\
	fi
.endfor

.include <bsd.port.mk>
