# Created by: Maxim Ignatenko <gelraen.ua@gmail.com>
# $FreeBSD$

PORTNAME=	inspircd
PORTVERSION=	1.2.9
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/inspircd/inspircd/
PKGNAMESUFFIX=	12
DISTNAME=	InspIRCd-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modular C++ IRC daemon

CONFLICTS=	inspircd-2.*
EXPIRATION_DATE=2013-12-01
DEPRECATED=	No upstream support; known vulnerable. Please use irc/inspircd

LATEST_LINK=	inspircd12

USES=		shebangfix perl5
USE_BZIP2=	yes
USE_LDCONFIG=	${PREFIX}/lib/inspircd
USE_RC_SUBR=	inspircd
SHEBANG_FILES=	configure modulemanager make/run-cc.pl

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
USE_PERL5=	build

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cc=${CXX} --config-dir=${ETCDIR}                   \
		--module-dir=${PREFIX}/lib/${PORTNAME}/modules            \
		--library-dir=${PREFIX}/lib/${PORTNAME}                   \
		--prefix=${DATADIR} --binary-dir=${PREFIX}/bin \
		--disable-interactive
MAKEFILE=	BSDmakefile

OPTIONS_DEFINE=	LDAPMODULES MYSQL PGSQL SQLITE3 SQLMODULES GNUTLS OPENSSL \
		ZIPLINK POSIX_RE PCRE TRE IPV6
OPTIONS_DEFAULT=	OPENSSL POSIX_RE
LDAPMODULES_DESC=	Build m_ldap{auth,oper} modules
SQLMODULES_DESC=	Build m_sql{log,oper,utils,auth}
ZIPLINK_DESC=		Build m_ziplink module
POSIX_RE_DESC=		Build m_regex_posix module
PCRE_DESC=		Build m_regex_pcre module
TRE_DESC=		Build m_regex_tre module

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6 --enable-remote-ipv6
.else
CONFIGURE_ARGS+=	--disable-remote-ipv6
.endif

.if ${PORT_OPTIONS:MPOSIX_RE}
PLIST_SUB+=	POSIX_RE=""
SYMLINK_FILES+=	m_regex_posix.cpp
.else
PLIST_SUB+=	POSIX_RE="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
PLIST_SUB+=	PCRE=""
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
SYMLINK_FILES+=	m_regex_pcre.cpp
.else
PLIST_SUB+=	PCRE="@comment "
.endif

.if ${PORT_OPTIONS:MTRE}
PLIST_SUB+=	TRE=""
LIB_DEPENDS+=	tre:${PORTSDIR}/textproc/libtre
CONFIGURE_ARGS+=	--tre-includes=${LOCALBASE}/include
SYMLINK_FILES+=	m_regex_tre.cpp
.else
PLIST_SUB+=	TRE="@comment "
.endif

.if ${PORT_OPTIONS:MLDAPMODULES}
USE_OPENLDAP=	yes
SYMLINK_FILES+=	m_ldapauth.cpp m_ldapoper.cpp
PLIST_SUB+=	LDAPMODULES=""
.else
PLIST_SUB+=	LDAPMODULES="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
SYMLINK_FILES+=	m_mysql.cpp m_sqlv2.h
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
SYMLINK_FILES+=	m_pgsql.cpp m_sqlv2.h
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
SYMLINK_FILES+=	m_sqlite3.cpp m_sqlv2.h
PLIST_SUB+=	SQLITE3=""
.else
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MSQLMODULES}
.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MSQLITE3}
BROKEN=		Please enable at least one of MYSQL, PGSQL or SQLITE3 required by SQLMODULES
.endif
SYMLINK_FILES+=	m_sqlauth.cpp m_sqllog.cpp m_sqloper.cpp m_sqlutils.cpp \
		m_sqlutils.h
PLIST_SUB+=	SQLMODULES=""
.else
PLIST_SUB+=	SQLMODULES="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-gnutls
SYMLINK_FILES+=	m_ssl_gnutls.cpp
PLIST_SUB+=	GNUTLS=""
.else
PLIST_SUB+=	GNUTLS="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-openssl
SYMLINK_FILES+=	m_ssl_openssl.cpp
PLIST_SUB+=	OPENSSL=""
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MSSLMODULES}
.if ! ${PORT_OPTIONS:MGNUTLS} && ! ${PORT_OPTIONS:MOPENSSL}
BROKEN=		Please enable at least one of GNUTLS or OPENSSL required by SSLMODULES
.endif
SYMLINK_FILES+=	m_ssl_oper_cert.cpp m_sslinfo.cpp
PLIST_SUB+=	SSLMODULES=""
.else
PLIST_SUB+=	SSLMODULES="@comment "
.endif

.if ${PORT_OPTIONS:MZIPLINK}
SYMLINK_FILES+=	m_ziplink.cpp
PLIST_SUB+=	ZIPLINK=""
.else
PLIST_SUB+=	ZIPLINK="@comment "
.endif

CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

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
