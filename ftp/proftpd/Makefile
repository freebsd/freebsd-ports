# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME?=	proftpd
PORTVERSION?=	1.3.4a
PORTREVISION?=	1
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
COMMENT?=	Highly configurable FTP daemon

LICENSE?=	GPLv2
LICENSE_FILE?=	${WRKSRC}/COPYING

.if defined(_PROFTPD_MODULE)
_BUILDING_PROFTPD_MODULE=	yes
DISTNAME=	proftpd-${PORTVERSION}
.endif

.if !defined(_BUILDING_PROFTPD_MODULE)
MAN1=	ftpcount.1 ftpmail.1 ftpasswd.1 ftpquota.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpscrub.8 ftpshut.8 ftpdctl.8

PORTDOCS=	*
.endif

MAKE_JOBS_UNSAFE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes

.if !defined(_BUILDING_PROFTPD_MODULE)
USE_RC_SUBR=	proftpd
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/proftpd:${PORTSDIR}/ftp/proftpd
.endif

LOCALSTATEDIR?=	/var/run

CONFIGURE_ARGS=--localstatedir=${LOCALSTATEDIR} \
		--libexecdir=${PREFIX}/libexec/proftpd \
		--with-pkgconfig=libdata/pkgconfig \
		--sysconfdir=${PREFIX}/etc \
		--enable-dso \
		--disable-sendfile

.if defined(_BUILDING_PROFTPD_MODULE)
CONFIGURE_ARGS+=	--with-shared=${_PROFTPD_MODULE}
INCLUDEDIRS:=${INCLUDEDIRS}:${WRKSRC}:${WRKSRC}/include
ALL_TARGET=	shared
BUILD_WRKSRC=	${WRKSRC}/modules
INSTALL_WRKSRC=	${WRKSRC}/modules
PLIST=		${WRKDIR}/PLIST
PLIST_FILES+=	libexec/proftpd/${_PROFTPD_MODULE}.a \
		libexec/proftpd/${_PROFTPD_MODULE}.la \
		libexec/proftpd/${_PROFTPD_MODULE}.so
PLIST_DIRSTRY+=	libexec/proftpd
.else
OPTIONS=	BAN "Include mod_ban (requires CTRLS)" off \
		COPY "Include mod_copy" on \
		CLAMAV "Include mod_clamav" off \
		CTRLS "Enable controls via ftpdctl" on \
		CTRLS_ADMIN "Include mod_ctrls_admin (requires CTRLS)" off \
		DEFLATE "Include mod_deflate" on \
		DYNMASQ "Include mod_dynmasq" off \
		EXEC "Include mod_exec" off \
		HTMLDOCS "Include HTML documentation" off \
		IFSESSION "Include mod_ifsession" on \
		IFVERSION "Include mod_ifversion" on \
		IPV6 "Support IPv6" on \
		LDAP "Include mod_ldap" off \
		LDAP_TLS "TLS for mod_ldap (requires LDAP, TLS)" off \
		MEMCACHE "Include mod_memcache" off \
		NLS "Use nls (builds mod_lang)" on \
		ODBC "Include mod_sql_odbc (requires SQL)" off \
		PCRE "Use pcre for regular expressions" on \
		QOS "Include mod_qos" off \
		QUOTATAB "Include mod_quotatab" on \
		QUOTATAB_FILE "Include mod_quotatab_file" on \
		QUOTATAB_LDAP "Include mod_quotatab_ldap (requires LDAP)" off \
		QUOTATAB_SQL "Include mod_quotatab_sql (requires SQL)" on \
		QUOTATAB_RADIUS "Include mod_quotatab_radius" off \
		SFTP "Include mod_sftp" on \
		SFTP_SQL "Include mod_sftp_sql (requires SFTP, SQL)" off \
		SFTP_PAM "Include mod_sftp_pam (requires SFTP)" off \
		SITE_MISC "Include mod_site_misc" off \
		SHAPER "Include mod_shaper (requires CTRLS)" off \
		SQL "Include mod_sql" on \
		SQL_PASSWD "Include mod_sql_passwd (requires SQL)" off \
		SQLITE "Include mod_sql_sqlite (requires SQL)" off \
		RADIUS "Include mod_radius" on \
		RATIO "Include mod_ratio" on \
		README "Include mod_readme" on \
		REWRITE "Include mod_rewrite" on \
		TLS "Include mod_tls" on \
		TLS_MEMCACHE "mod_tls_memcache (requires MEMCACHE)" off \
		TLS_SHMCACHE "TLS SHM session cache (requires TLS)" off \
		TDS "Include mod_sql_tds (requires SQL)" off \
		UNIQUE "Include mod_unique_id" off \
		WRAP "Include mod_wrap2" on \
		WRAP_FILE "Include mod_wrap2_file (requires WRAP)" off \
		WRAP_SQL "Include mod_wrap2_sql (requires SQL, WRAP)" off

MODULES?=
LIBDIRS?=
INCLUDEDIRS?=

PLIST_SUB+=	LOCALSTATEDIR="${LOCALSTATEDIR}"

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.pre.mk>

.if !defined(_BUILDING_PROFTPD_MODULE)

# FreeBSD-SA-11:07.chroot
.if ${OSVERSION} < 800000
CHROOT_TEST !=	${GREP} __FreeBSD_libc_enter_restricted_mode \
	/usr/include/unistd.h > /dev/null || ${ECHO_CMD} error
. if ${CHROOT_TEST} == "error"
BROKEN=__FreeBSD_libc_enter_restricted_mode is not supported
. endif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-7-src-fsio.c
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-8-src-fsio.c
.endif

.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=	Does not compile on sparc64-9: storage size of 'utx' isn't known
.endif

.if !defined(WITHOUT_RATIO)
MODULES:=${MODULES}:mod_ratio
PLIST_SUB+=	MOD_RATIO=""
.else
PLIST_SUB+=	MOD_RATIO="@comment "
.endif

.if !defined(WITHOUT_README)
MODULES:=${MODULES}:mod_readme
PLIST_SUB+=	MOD_README=""
.else
PLIST_SUB+=	MOD_README="@comment "
.endif

.if !defined(WITHOUT_REWRITE)
MODULES:=${MODULES}:mod_rewrite
PLIST_SUB+=	MOD_REWRITE=""
.else
PLIST_SUB+=	MOD_REWRITE="@comment "
.endif

.if defined(WITH_WRAP_FILE)
AUTOSELECT_WRAP=	yes
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
MODULES:=${MODULES}:mod_wrap2_file
PLIST_SUB+=	MOD_WRAP_FILE=""
.else
PLIST_SUB+=	MOD_WRAP_FILE="@comment "
.endif

.if defined(WITH_WRAP_SQL)
AUTOSELECT_SQL=	yes
AUTOSELECT_WRAP=	yes
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
MODULES:=${MODULES}:mod_wrap2_sql
PLIST_SUB+=	MOD_WRAP_SQL=""
.else
PLIST_SUB+=	MOD_WRAP_SQL="@comment "
.endif

.if defined(WITH_BAN)
AUTOSELECT_CTRLS=	yes
MODULES:=${MODULES}:mod_ban
PLIST_SUB+=	MOD_BAN=""
.else
PLIST_SUB+=	MOD_BAN="@comment "
.endif

.if !defined(WITHOUT_COPY)
MODULES:=${MODULES}:mod_copy
PLIST_SUB+=	MOD_COPY=""
.else
PLIST_SUB+=	MOD_COPY="@comment "
.endif

.if defined(WITH_CTRLS_ADMIN)
AUTOSELECT_CTRLS=	yes
MODULES:=${MODULES}:mod_ctrls_admin
PLIST_SUB+=	MOD_CTRLS_ADMIN=""
.else
PLIST_SUB+=	MOD_CTRLS_ADMIN="@comment "
.endif

.if !defined(WITHOUT_DEFLATE)
MODULES:=${MODULES}:mod_deflate
PLIST_SUB+=	MOD_DEFLATE=""
.else
PLIST_SUB+=	MOD_DEFLATE="@comment "
.endif

.if defined(WITH_DYNMASQ)
MODULES:=${MODULES}:mod_dynmasq
PLIST_SUB+=	MOD_DYNMASQ=""
.else
PLIST_SUB+=	MOD_DYNMASQ="@comment "
.endif

.if defined(WITH_EXEC)
MODULES:=${MODULES}:mod_exec
PLIST_SUB+=	MOD_EXEC=""
.else
PLIST_SUB+=	MOD_EXEC="@comment "
.endif

.if !defined(WITHOUT_IFSESSION)
MODULES:=${MODULES}:mod_ifsession
PLIST_SUB+=     MOD_IFSESSION=""
.else
PLIST_SUB+=     MOD_IFSESSION="@comment "
.endif

.if !defined(WITHOUT_IFVERSION)
MODULES:=${MODULES}:mod_ifversion
PLIST_SUB+=	MOD_IFVERSION=""
.else
PLIST_SUB+=	MOD_IFVERSION="@comment "
.endif

.if defined(WITH_TLS_MEMCACHE)
AUTOSELECT_MEMCACHE=	yes
AUTOSELECT_TLS=		yes
MODULES:=${MODULES}:mod_tls_memcache
PLIST_SUB+=	MOD_TLS_MEMCACHE=""
.else
PLIST_SUB+=	MOD_TLS_MEMCACHE="@comment "
.endif

.if !defined(WITHOUT_RADIUS)
MODULES:=${MODULES}:mod_radius
PLIST_SUB+=	MOD_RADIUS=""
.else
PLIST_SUB+=	MOD_RADIUS="@comment "
.endif

.if defined(WITH_QOS)
MODULES:=${MODULES}:mod_qos
PLIST_SUB+=	MOD_QOS=""
.else
PLIST_SUB+=	MOD_QOS="@comment "
.endif

.if !defined(WITHOUT_QUOTATAB_FILE)
AUTOSELECT_QUOTATAB=	yes
MODULES:=${MODULES}:mod_quotatab_file
PLIST_SUB+=	MOD_QUOTATAB_FILE=""
.else
PLIST_SUB+=	MOD_QUOTATAB_FILE="@comment "
.endif

.if defined(WITH_QUOTATAB_LDAP)
AUTOSELECT_QUOTATAB=	yes
AUTOSELECT_LDAP=	yes
MODULES:=${MODULES}:mod_quotatab_ldap
PLIST_SUB+=	MOD_QUOTATAB_LDAP=""
.else
PLIST_SUB+=	MOD_QUOTATAB_LDAP="@comment "
.endif

.if defined(WITH_QUOTATAB_RADIUS)
AUTOSELECT_QUOTATAB=	yes
MODULES:=${MODULES}:mod_quotatab_radius
PLIST_SUB+=	MOD_QUOTATAB_RADIUS=""
.else
PLIST_SUB+=	MOD_QUOTATAB_RADIUS="@comment "
.endif

.if !defined(WITHOUT_QUOTATAB_SQL)
AUTOSELECT_QUOTATAB=	yes
AUTOSELECT_SQL=	yes
MODULES:=${MODULES}:mod_quotatab_sql
PLIST_SUB+=	MOD_QUOTATAB_SQL=""
.else
PLIST_SUB+=	MOD_QUOTATAB_SQL="@comment "
.endif

.if defined(WITH_SHAPER)
AUTOSELECT_CTRLS=	yes
MODULES:=${MODULES}:mod_shaper
PLIST_SUB+=	MOD_SHAPER=""
.else
PLIST_SUB+=	MOD_SHAPER="@comment "
.endif

.if defined(WITH_SITE_MISC)
MODULES:=${MODULES}:mod_site_misc
PLIST_SUB+=	MOD_SITE_MISC=""
.else
PLIST_SUB+=	MOD_SITE_MISC="@comment "
.endif

.if defined(WITH_UNIQUE)
MODULES:=${MODULES}:mod_unique_id
PLIST_SUB+=	MOD_UNIQUE=""
.else
PLIST_SUB+=	MOD_UNIQUE="@comment "
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

.if !defined(WITHOUT_PCRE)
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
LIB_DEPENDS+=		pcre.1:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if defined(WITH_LDAP)
. if defined(WITH_LDAP_TLS)
AUTOSELECT_TLS=	yes
. endif
USE_OPENLDAP=	yes
MODULES:=${MODULES}:mod_ldap
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	MOD_LDAP=""
.else
PLIST_SUB+=	MOD_LDAP="@comment "
.endif

.if defined(WITH_SQLITE)
AUTOSELECT_SQL=	yes
USE_SQLITE=     yes
MODULES:=${MODULES}:mod_sql_sqlite
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	MOD_SQL_SQLITE=""
.else
PLIST_SUB+=	MOD_SQL_SQLITE="@comment "
.endif

.if defined(WITH_ODBC)
AUTOSELECT_SQL=	yes
LIB_DEPENDS=    iodbc.3:${PORTSDIR}/databases/libiodbc
MODULES:=${MODULES}:mod_sql_odbc
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
CONFIGURE_ARGS+=LIBS=-liodbc LD_LIBRARY_PATH=${LOCALBASE}/lib LDFLAGS=-L${LOCALBASE}/lib
PLIST_SUB+=	MOD_ODBC=""
.else
PLIST_SUB+=	MOD_ODBC="@comment "
.endif

.if defined(WITH_TDS) || make(makesum) || defined(FETCH_ALL)
AUTOSELECT_SQL=	yes
DISTFILES+=	mod_sql_tds-4.13.tar.bz2:sql_tds
EXTRACT_ONLY+=	mod_sql_tds-4.13.tar.bz2
MODULES:=${MODULES}:mod_sql_tds
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
PLIST_SUB+=	MOD_SQL_TDS=""
.else
PLIST_SUB+=	MOD_SQL_TDS="@comment "
.endif

.if defined(WITH_SQL_PASSWD)
AUTOSELECT_SQL=	yes
MODULES:=${MODULES}:mod_sql_passwd
PLIST_SUB+=	MOD_SQL_PASSWD=""
.else
PLIST_SUB+=	MOD_SQL_PASSWD="@comment "
.endif

.if defined(WITH_TLS_SHMCACHE)
AUTOSELECT_TLS=	yes
MODULES:=${MODULES}:mod_tls_shmcache
PLIST_SUB+=	MOD_TLS_SHMCACHE=""
.else
PLIST_SUB+=	MOD_TLS_SHMCACHE="@comment "
.endif

.if defined(WITH_CLAMAV) || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	mod_clamav-0.11rc.tar.gz:clam
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_mod_xfer.c
USE_CLAMAV=	yes
MODULES:=${MODULES}:mod_clamav
LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	MOD_CLAMAV=""
.else
PLIST_SUB+=	MOD_CLAMAV="@comment "
.endif

.if defined(WITH_SFTP_SQL)
AUTOSELECT_SFTP=	yes
AUTOSELECT_SQL=		yes
MODULES:=${MODULES}:mod_sftp_sql
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     MOD_SFTP_SQL=""
.else
PLIST_SUB+=     MOD_SFTP_SQL="@comment "
.endif

.if defined(WITH_SFTP_PAM)
AUTOSELECT_SFTP=	yes
MODULES:=${MODULES}:mod_sftp_pam
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     MOD_SFTP_PAM=""
.else
PLIST_SUB+=     MOD_SFTP_PAM="@comment "
.endif

# Handle autoselectable configuration at the end
.if !defined(WITHOUT_CTRLS) || defined(AUTOSELECT_CTRLS)
CONFIGURE_ARGS+=	--enable-ctrls
PLIST_SUB+=	CTRLS=""
.else
CONFIGURE_ARGS+=	--disable-ctrls
PLIST_SUB+=	CTRLS="@comment "
.endif

.if defined(WITH_MEMCACHE) || defined(AUTOSELECT_MEMCACHE)
LIB_DEPENDS+=		memcached.8:${PORTSDIR}/databases/libmemcached
CONFIGURE_ARGS+=	--enable-memcache
PLIST_SUB+=	MOD_MEMCACHE=""
.else
CONFIGURE_ARGS+=	--disable-memcache
PLIST_SUB+=	MOD_MEMCACHE="@comment "
.endif

.if !defined(WITHOUT_QUOTATAB) || defined(AUTOSELECT_QUOTATAB)
MODULES:=${MODULES}:mod_quotatab
PLIST_SUB+=	MOD_QUOTATAB=""
.else
PLIST_SUB+=	MOD_QUOTATAB="@comment "
.endif

.if !defined(WITHOUT_SFTP) || defined(AUTOSELECT_SFTP)
MODULES:=${MODULES}:mod_sftp
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=     MOD_SFTP=""
.else
PLIST_SUB+=     MOD_SFTP="@comment "
.endif

.if !defined(WITHOUT_SQL) || defined(AUTOSELECT_SQL)
MODULES:=${MODULES}:mod_sql
PLIST_SUB+=	MOD_SQL=""
.else
PLIST_SUB+=	MOD_SQL="@comment "
.endif

.if defined(WITH_OPENSSL) || !defined(WITHOUT_TLS) || defined(AUTOSELECT_TLS)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CFLAGS+=	-DHAVE_OPENSSL -I${OPENSSLINC}
PROFTPD_LIBS+=	-lssl -lcrypto -L${OPENSSLLIB}
MODULES:=${MODULES}:mod_tls
PLIST_SUB+=	MOD_TLS=""
.else
PLIST_SUB+=	MOD_TLS="@comment "
.endif

.if !defined(WITHOUT_WRAP) || defined(AUTOSELECT_WRAP)
MODULES:=${MODULES}:mod_wrap2
INCLUDEDIRS:=${INCLUDEDIRS}:${WORKDIR}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
PLIST_SUB+=	MOD_WRAP=""
.else
PLIST_SUB+=	MOD_WRAP="@comment "
.endif

# Keep this here below, in case similar constructs need to be made
CONFIGURE_ENV+=	"LIBS=${PROFTPD_LIBS}"

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-shared=${MODULES:C/^://g}
PLIST_SUB+=	MODULES=""
.else
PLIST_SUB+=	MODULES="@comment "
.endif

# Create list of autoselected modules
.if defined(WITHOUT_CTRLS) && defined(AUTOSELECT_CTRLS)
AUTOSELECT_MODULES+=	mod_ctrls
.endif
.if !defined(WITH_MEMCACHE) && defined(AUTOSELECT_MEMCACHE)
AUTOSELECT_MODULES+=	mod_memcache
.endif
.if defined(WITHOUT_QUOTATAB) && defined(AUTOSELECT_QUOTATAB)
AUTOSELECT_MODULES+=	mod_quotatab
.endif
.if defined(WITHOUT_SFTP) && defined(AUTOSELECT_SFTP)
AUTOSELECT_MODULES+=	mod_sftp
.endif
.if defined(WITHOUT_SQL) && defined(AUTOSELECT_SQL)
AUTOSELECT_MODULES+=	mod_sql
.endif
.if defined(WITHOUT_TLS) && defined(AUTOSELECT_TLS)
AUTOSELECT_MODULES+=	mod_tls
.endif
.if defined(WITHOUT_WRAP) && defined(AUTOSELECT_WRAP)
AUTOSELECT_MODULES+=	mod_wrap
.endif

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.if !empty(INCLUDEDIRS)
CONFIGURE_ARGS+=	--with-includes=${INCLUDEDIRS}
.endif

.if !empty(LIBDIRS)
CONFIGURE_ARGS+=	--with-libraries=${LIBDIRS}
.endif

.if !defined(BUILDING_PROFTPD_MODULE)
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
.if defined(AUTOSELECT_MODULES)
	@${ECHO_MSG} "*** NOTICE ***"
	@${ECHO_MSG} "The following modules are required by the current\
	configuration and have been automatically added to the build:"
	@${ECHO_MSG} ${AUTOSELECT_MODULES}
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} "==> Configuring with following modules:"
	@${ECHO_MSG} "${MODULES:C/^://g}"

post-configure:
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.if defined(_BUILDING_PROFTPD_MODULE)
pre-build:
	@cd ${WRKSRC} && ${MAKE} include/buildstamp.h
.else
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
.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.post.mk>
