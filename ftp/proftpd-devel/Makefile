# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
DISTVERSION=	1.3.1rc3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.fastorama.com/mirrors/ftp.proftpd.org/distrib/source/ \
		ftp://ftp.dataguard.no/ftp/pub/proftpd/distrib/source/ \
		ftp://spirit.bentel.sk/mirrors/Proftpd/distrib/source/ \
		ftp://proftpd.networkedsystems.co.uk/distrib/source/ \
		http://mirrors.ibiblio.org/pub/mirrors/proftpd/distrib/source/ \
		http://www.mirrorservice.org/sites/ftp.proftpd.org/distrib/source/

MAINTAINER?=	beech@FreeBSD.org
COMMENT?=	Highly configurable ftp daemon

MAN1=	ftpcount.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8 ftpdctl.8

PORTDOCSdoc=	Configuration.html faq.html
PORTDOCScontrib=mod_ifsession.html mod_radius.html mod_rewrite.html \
		mod_tls.html mod_wrap2.html mod_wrap2_file.html mod_wrap2_sql.html \
		mod_ban.html mod_quotatab_radius.html ftpasswd.html
PORTDOCS=	${PORTDOCSdoc} ${PORTDOCScontrib}

PORTEXAMPLES=	ASCII.html CreateHome.html Filters.html SQL.html Umask.html \
		AuthFiles.html DNS.html Globbing.html SSH.html Upgrade.html \
		Authentication.html DSO.html Limit.html Scoreboard.html Vhost.html \
		BCP.html Debugging.html ListOptions.html ServerType.html \
		VirtualUsers.html Chroot.html Directory.html Logging.html Stopping.html \
		index.html Classes.html DisplayFiles.html NAT.html TLS.html ConfigFile.html \
		FTP.html Quotas.html Timestamps.html Controls.html \
		FXP.html Regex.html Tracing.html

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes

USE_RC_SUBR=	proftpd.sh

CONFIGURE_ARGS=	--localstatedir=/var/run \
		--sysconfdir=${PREFIX}/etc \
		--enable-builtin-getnameinfo \
		--disable-sendfile

OPTIONS=	IPV6 "Use IPv6" off \
		LDAP "Use LDAP" off \
		LDAP_TLS "Use LDAP TLS (Requires LDAP)" off\
		MYSQL "Use MySQL" off \
		PGSQL "Use Postgres" off \
		OPENSSL "Include mod_tls" off \
		QUOTA "Include mod_quota" off \
		IFSESSION "Include mod_ifsession" on \
		README "Include mod_readme" on \
		RATIO "Include mod_ratio" on \
		CTRLS "include controls" off \
		REWRITE "Include mod_rewrite" on \
		WRAP "Include mod_wrap2" on \
		WRAP_FILE "include mod_wrap2_file" off \
		WRAP_SQL "include mod_wrap2_sql" off \
		RADIUS "Include mod_radius" off \
		QUOTATAB_RADIUS "include mod_quotatab_radius" off \
		BAN "include mod_ban (Requires CTRLS)" off \
		NLS "Use nls (builds mod_lang)" off \
		CYRFIX "Use patch for fix cyrillic encoding" off \
		CODECONV "Use charset conversion (mod_codeconv)" off

MODULES?=
LIBDIRS?=
INCLUDEDIRS?=

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
PLIST_FILES+=	include/proftpd/mod_wrap2.h
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

.if defined(WITH_RADIUS)
MODULES:=${MODULES}:mod_radius
.endif

.if defined(WITH_QUOTATAB_RADIUS)
MODULES:=${MODULES}:mod_quotatab_radius
.endif

.if defined(WITH_BAN)
MODULES:=${MODULES}:mod_ban
.endif

.if defined(WITH_SETPASSENT)
CONFIGURE_ARGS+=	--enable-force-setpassent
.endif

.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--disable-auth-pam
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_NLS)
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=yes
PROFTPD_LIBS+=	-lintl -L${LOCALBASE}/lib
.endif

.if defined (WITH_CYRFIX)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-cyrillic-fix-netio.c
.endif

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_rewrite:mod_wrap2:mod_ifsession

INCLUDEDIRS?=
LIBDIRS?=

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
MODULES:=${MODULES}:mod_ldap
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MODULES:=${MODULES}:mod_sql_mysql
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include:${LOCALBASE}/include/mysql
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MODULES:=${MODULES}:mod_sql_postgres
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if ${MODULES:M*mod_sql_*}
MODULES:=mod_sql${MODULES}
.endif

.if defined(WITH_OPENSSL)
CFLAGS+=	-DHAVE_OPENSSL
.include <${PORTSDIR}/Mk/bsd.openssl.mk>
PROFTPD_LIBS+=	-lssl -lcrypto -L${LOCALBASE}/lib
MODULES:=${MODULES}:mod_tls
.if defined(WITH_LDAP_TLS)
EXTRA_PATCHES+=	${FILESDIR}/extra_patch-ldap-tls-mod_ldap.c
.endif
.endif

.if defined(WITH_CTRLS)
CONFIGURE_ARGS+=	--enable-ctrls
PLIST_FILES+=	sbin/ftpdctl
.if !defined(WITHOUT_CTRLS_ADMIN)
MODULES:=${MODULES}:mod_ctrls_admin
.endif
.endif

.if defined(WITH_QUOTA)
MODULES:=${MODULES}:mod_quotatab:mod_quotatab_file
.if defined(WITH_LDAP)
MODULES:=${MODULES}:mod_quotatab_ldap
.endif
.if defined(WITH_PGSQL) || defined(WITH_MYSQL)
MODULES:=${MODULES}:mod_quotatab_sql
.endif
.endif

.if defined(WITH_CODECONV)
USE_ICONV=	YES
MODULES:=${MODULES}:mod_codeconv
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
PROFTPD_LIBS+=	-liconv -L${LOCALBASE}/lib
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mod-codeconv
.endif

# mod_ifsession should be the last item in the modules list
.if !defined(WITHOUT_IFSESSION)
MODULES:=${MODULES}:mod_ifsession
.endif

# Keep this here below, in case similar constructs need to be made
CONFIGURE_ENV+=	"LIBS=${PROFTPD_LIBS}"

.if !empty(MODULES)
CONFIGURE_ARGS+=	--with-modules=${MODULES}
.endif

.if !empty(INCLUDEDIRS)
CONFIGURE_ARGS+=	--with-includes=${INCLUDEDIRS}
.endif

.if !empty(LIBDIRS)
CONFIGURE_ARGS+=	--with-libraries=${LIBDIRS}
.endif

MODULES!=${ECHO} ${MODULES} | ${SED} -e 's,^:,,' -e 's,:$$,,'

post-patch:
.if defined(WITH_NLS)
	@${REINPLACE_CMD} -e 's|-lsupp|-lsupp -lintl|g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|proftpd\.conf|proftpd.conf.sample|g' ${WRKSRC}/Makefile.in

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

post-configure:
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

post-install:
	@cd  ${PREFIX}/etc/ && ${CP} -n proftpd.conf.sample proftpd.conf
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCSdoc} ${DOCSDIR}/
	@cd ${WRKSRC}/doc/contrib && ${INSTALL_DATA} ${PORTDOCScontrib} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/doc/howto/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif
.if !defined(WITHOUT_PAM)
	@${CAT} ${PKGMESSAGE}
.endif
.if defined(WITH_CTRLS)
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpdctl ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/src/ftpdctl.8 ${MAN8PREFIX}/man/man8/
.endif

.include <bsd.port.post.mk>
