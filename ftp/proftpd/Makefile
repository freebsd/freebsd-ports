# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
PORTVERSION=	1.3.3
PORTREVISION=	3
CATEGORIES?=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.fastorama.com/mirrors/ftp.proftpd.org/distrib/source/ \
		ftp://ftp.dataguard.no/ftp/pub/proftpd/distrib/source/ \
		ftp://spirit.bentel.sk/mirrors/Proftpd/distrib/source/ \
		ftp://proftpd.networkedsystems.co.uk/distrib/source/ \
		http://mirrors.ibiblio.org/pub/mirrors/proftpd/distrib/source/ \
		http://www.mirrorservice.org/sites/ftp.proftpd.org/distrib/source/ \
		http://labratsoftware.com/mod_sql_tds/:sql_tds \
		https://secure.thrallingpenguin.com/redmine/attachments/download/1/:clam \
		LOCAL/beech:sql_tds
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	Highly configurable ftp daemon

MAN1=	ftpcount.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpscrub.8 ftpshut.8 ftpdctl.8

MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	*

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes

CONFLICTS=	proftpd-devel-1.[0-9].*

USE_RC_SUBR=	proftpd

LOCALSTATEDIR?=	/var/run

CONFIGURE_ARGS=	--localstatedir=${LOCALSTATEDIR} \
		--with-pkgconfig=libdata/pkgconfig \
		--sysconfdir=${PREFIX}/etc \
		--disable-sendfile

OPTIONS=	BAN "Include mod_ban (Requires CTRLS)" off \
		CLAMAV "Include mod_clamav" off \
		CTRLS "Include controls" off \
		EXEC "Include mod_exec" off \
		HTMLDOCS "Include HTML documentation" off \
		IFSESSION "Include mod_ifsession" on \
		IPV6 "Use IPv6" on \
		LDAP "Use LDAP" off \
		LDAP_TLS "Use LDAP TLS (Requires LDAP, OPENSSL)" off

# Set the MYSQL option based upon the setting from the
# slave port (ftp/proftpd-mysql).
.if defined(WITH_MYSQL)
OPTIONS+=	MYSQL "MySQL auth" on
.else
OPTIONS+=	MYSQL "MySQL auth" off
.endif

OPTIONS+=	NLS "Use nls (builds mod_lang)" on \
		ODBC "ODBC" off \
		OPENSSL "Include mod_tls" on \
		PGSQL "Postgres auth" off \
		QUOTA "Include mod_quota" off \
		QUOTATAB_RADIUS "include mod_quotatab_radius" off \
		SHAPER "Shaper module" off \
		SQLITE "SQLite auth" off \
		RADIUS "Include mod_radius" on \
		RATIO "Include mod_ratio" on \
		README "Include mod_readme" on \
		REWRITE "Include mod_rewrite" on \
		TLS_SHMCACHE "TLS SHM session cache (requires OPENSSL)" off \
		TDS "Include mod_sql_tds" off \
		SFTP "Include mod_sftp" off\
		SFTP_SQL "Include mod_sftp_sql" off \
		SFTP_PAM "Include mod_sftp_pam" off \
		SITE_MISC "Include mod_site_misc" off \
		SQL_PASSWD "Include mod_sql_passwd" off \
		UNIQUE "Include mod_unique_id" off \
		WRAP "Include mod_wrap2" on \
		WRAP_FILE "Include mod_wrap2_file (requires WRAP)" off \
		WRAP_SQL "Include mod_wrap2_sql (requires WRAP)" off

MODULES?=
LIBDIRS?=
INCLUDEDIRS?=

PLIST_SUB+=	LOCALSTATEDIR="${LOCALSTATEDIR}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_RATIO)
MODULES:=${MODULES}:mod_ratio
.endif

.if !defined(WITHOUT_README)
MODULES:=${MODULES}:mod_readme
.endif

.if !defined(WITHOUT_REWRITE)
MODULES:=${MODULES}:mod_rewrite
.endif

.if !defined(WITHOUT_WRAP)
MODULES:=${MODULES}:mod_wrap2
INCLUDEDIRS:=${INCLUDEDIRS}:${WORKDIR}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	WRAP=""
.else
PLIST_SUB+=	WRAP="@comment "
.endif

.if ( defined(WITH_WRAP_FILE) || defined(WITH_WRAP_SQL) ) && defined(WITHOUT_WRAP)
IGNORE=	options WRAP_FILE and WRAP_FILE_SQL require WRAP
.endif

.if defined(WITH_WRAP_FILE)
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
MODULES:=${MODULES}:mod_wrap2_file
.endif

.if defined(WITH_WRAP_SQL)
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
MODULES:=${MODULES}:mod_wrap2_sql
.endif

.if defined(WITH_EXEC)
MODULES:=${MODULES}:mod_exec
.endif

.if defined(WITH_RADIUS)
MODULES:=${MODULES}:mod_radius
.endif

.if defined(WITH_SHAPER)
MODULES:=${MODULES}:mod_shaper
.endif

.if defined(WITH_SITE_MISC)
MODULES:=${MODULES}:mod_site_misc
.endif

.if defined(WITH_QUOTATAB_RADIUS)
MODULES:=${MODULES}:mod_quotatab_radius
.endif

.if defined(WITH_BAN)
.if !defined(WITH_CTRLS)
IGNORE=	option BAN requires CTRLS
.endif
MODULES:=${MODULES}:mod_ban
.endif

.if defined(WITH_UNIQUE)
MODULES:=${MODULES}:mod_unique_id
.endif

.if defined(WITH_SETPASSENT)
CONFIGURE_ARGS+=	--enable-force-setpassent
.endif

.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--disable-auth-pam
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !defined(WITHOUT_NLS)
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=yes
PROFTPD_LIBS+=	-lintl -L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_rewrite:mod_wrap2:mod_ifsession:mod_lang

INCLUDEDIRS?=
LIBDIRS?=

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
MODULES:=${MODULES}:mod_ldap
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

# LDAP_TLS and TLS_SHMCACHE require OPENSSL
.if ( defined(WITH_LDAP_TLS) || defined(WITH_TLS_SHMCACHE) ) && !defined(WITH_OPENSSL)
IGNORE=	options LDAP_TLS and TLS_SHMCACHE require OPENSSL
.endif

# MYSQL, PGSQL, SQLITE, ODBC, TDS, SFTP_SQL and SQL_PASSWD require mod_sql
.if defined(WITH_MYSQL) || defined(WITH_PGSQL) || \
defined(WITH_SQLITE) || defined(WITH_ODBC) || defined(WITH_TDS) \
|| defined(WITH_SFTP_SQL) || defined (WITH_SQL_PASSWD)
MODULES:=${MODULES}:mod_sql
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MODULES:=${MODULES}:mod_sql_mysql
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include:${LOCALBASE}/include/mysql:${WRKSRC}/contrib
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib/mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MODULES:=${MODULES}:mod_sql_postgres
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=     yes
MODULES:=${MODULES}:mod_sql_sqlite
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS=    iodbc.3:${PORTSDIR}/databases/libiodbc
MODULES:=${MODULES}:mod_sql_odbc
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
CONFIGURE_ARGS+=LIBS=-liodbc LD_LIBRARY_PATH=${LOCALBASE}/lib LDFLAGS=-L${LOCALBASE}/lib
.endif

.if defined(WITH_TDS)
DISTFILES+=	mod_sql_tds-4.11.tar.bz2:sql_tds
EXTRACT_ONLY+=	mod_sql_tds-4.11.tar.bz2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-contrib-mod_sql_tds.c
MODULES:=${MODULES}:mod_sql_tds
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
.endif

.if defined(WITH_SQL_PASSWD)
MODULES:=${MODULES}:mod_sql_passwd
.endif

.if ${MODULES:M*mod_sql*}
PLIST_SUB+=	SQL=""
.else
PLIST_SUB+=	SQL="@comment "
.endif

.if defined(WITH_TLS_SHMCACHE)
MODULES:=${MODULES}:mod_tls_shmcache
.endif

.if defined(WITH_OPENSSL)
.include <${PORTSDIR}/Mk/bsd.openssl.mk>
CFLAGS+=	-DHAVE_OPENSSL -I${OPENSSLINC}
PROFTPD_LIBS+=	-lssl -lcrypto -L${OPENSSLLIB}
MODULES:=${MODULES}:mod_tls
PLIST_SUB+=	TLS=""
.else
PLIST_SUB+=	TLS="@comment "
.endif

.if defined(WITH_CTRLS)
CONFIGURE_ARGS+=	--enable-ctrls
.if !defined(WITHOUT_CTRLS_ADMIN)
MODULES:=${MODULES}:mod_ctrls_admin
.endif
PLIST_SUB+=	CTRLS_ADMIN=""
.else
PLIST_SUB+=	CTRLS_ADMIN="@comment "
.endif

# LDAP, PGSQL and MYSQL options due nothing (in this case)
# without QUOTA support.
.if defined(WITH_QUOTA)
MODULES:=${MODULES}:mod_quotatab:mod_quotatab_file
PLIST_SUB+=	QUOTA=""
.if defined(WITH_LDAP)
MODULES:=${MODULES}:mod_quotatab_ldap
.endif
.if defined(WITH_PGSQL) || defined(WITH_MYSQL)
MODULES:=${MODULES}:mod_quotatab_sql
.endif
.else
PLIST_SUB+=	QUOTA="@comment "
.endif

.if defined(WITH_CLAMAV)
DISTFILES+=	mod_clamav-0.11rc.tar.gz:clam
EXTRACT_ONLY+=	mod_clamav-0.11rc.tar.gz
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_mod_xfer.c
USE_CLAMAV=	yes
MODULES:=${MODULES}:mod_clamav
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	CLAMAV=""
.else
PLIST_SUB+=	CLAMAV="@comment "
.endif

.if defined(WITH_SFTP)
MODULES:=${MODULES}:mod_sftp
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     SFTP=""
.else
PLIST_SUB+=     SFTP="@comment "
.endif

.if defined(WITH_SFTP_SQL)
MODULES:=${MODULES}:mod_sftp_sql
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     SFTP_SQL=""
.else
PLIST_SUB+=     SFTP_SQL="@comment "
.endif

.if defined(WITH_SFTP_PAM)
MODULES:=${MODULES}:mod_sftp_pam
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     SFTP_PAM=""
.else
PLIST_SUB+=     SFTP_PAM="@comment "
.endif

# mod_ifsession should be the last item in the modules list
.if !defined(WITHOUT_IFSESSION)
MODULES:=${MODULES}:mod_ifsession
.endif

# Keep this here below, in case similar constructs need to be made
CONFIGURE_ENV+=	"LIBS=${PROFTPD_LIBS}"

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES:C/^://g}
.endif

.if !empty(INCLUDEDIRS)
CONFIGURE_ARGS+=	--with-includes=${INCLUDEDIRS}
.endif

.if !empty(LIBDIRS)
CONFIGURE_ARGS+=	--with-libraries=${LIBDIRS}
.endif

post-extract:
.if defined(WITH_CLAMAV)
	(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mod_clamav-0.11rc.tar.gz ${EXTRACT_AFTER_ARGS})
	@${CP} ${WRKDIR}/mod_clamav-0.11rc/mod_clamav.* ${WRKSRC}/contrib
.endif
.if defined(WITH_TDS)
	 @${MV} ${WRKDIR}/mod_sql_tds.c ${WRKSRC}/contrib/
.endif

post-patch:
.if defined(WITH_NLS)
	@${REINPLACE_CMD} -e 's|-lsupp|-lsupp -lintl|g' ${WRKSRC}/Makefile.in
.endif
.if defined(WITH_LDAP_TLS)
	@${REINPLACE_CMD} -e 's:/\* #define USE_LDAP_TLS \*/:#define USE_LDAP_TLS:' \
		${WRKSRC}/contrib/mod_ldap.c
.endif
	@${REINPLACE_CMD} -e 's|proftpd\.conf|proftpd.conf.sample|g' ${WRKSRC}/Makefile.in

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES:C/^://g}"

post-configure:
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

post-install:
	@cd  ${PREFIX}/etc/ && ${CP} -n proftpd.conf.sample proftpd.conf
	@${MKDIR} ${LOCALSTATEDIR}/proftpd
.if defined(WITH_SFTP)
	@cd  ${PREFIX}/etc/proftpd && ${CP} -n dhparams.pem.sample dhparams.pem
	@cd  ${PREFIX}/etc/proftpd && ${CP} -n blacklist.dat.sample blacklist.dat
.endif
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${CP} README* RELEASE_NOTES ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} license.txt ${DOCSDIR}
. if defined(WITH_HTMLDOCS)
	@${INSTALL} -d ${DOCSDIR}/html
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} Configuration.html faq.html ${DOCSDIR}/html
	@${CP} -RP ${WRKSRC}/doc/contrib ${DOCSDIR}/html/contrib
	@${CP} -RP ${WRKSRC}/doc/modules ${DOCSDIR}/html/modules
	@${CP} -RP ${WRKSRC}/doc/howto ${DOCSDIR}/html/howto
. endif
.endif
.if defined(WITH_CTRLS)
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpdctl ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/src/ftpdctl.8 ${MAN8PREFIX}/man/man8/
.endif

.include <bsd.port.post.mk>
