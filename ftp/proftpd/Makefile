# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
DISTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.fastorama.com/mirrors/ftp.proftpd.org/distrib/source/ \
		ftp://ftp.dataguard.no/ftp/pub/proftpd/distrib/source/ \
		ftp://spirit.bentel.sk/mirrors/Proftpd/distrib/source/ \
		ftp://proftpd.networkedsystems.co.uk/distrib/source/ \
		ftp://ftp.ethereal.com/mirrors/ftp.proftpd.org/distrib/source/ \
		ftp://mirror.cybercomm.nl/pub/proftpd/distrib/source/

MAINTAINER?=	beech@mangohealth.org
COMMENT?=	Highly configurable ftp daemon

MAN1=	ftpcount.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8 ftpdctl.8

PORTDOCSdoc=	Configuration.html faq.html
PORTDOCScontrib=mod_ifsession.html mod_radius.html mod_rewrite.html \
		mod_tls.html mod_wrap.html ftpasswd.html
PORTDOCS=	${PORTDOCSdoc} ${PORTDOCScontrib}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

USE_RC_SUBR=	proftpd.sh

CONFIGURE_ARGS=	--localstatedir=/var/run \
		--sysconfdir=${EXAMPLESDIR}/etc \
		--disable-sendfile

OPTIONS=	IPV6 "Use IPv6" off \
		LDAP "Use LDAP" off \
		LDAP_TLS "Use LDAP TLS (Requires LDAP)" off\
		MYSQL "Use MySQL" off \
		POSTGRESQL "Use Postgres" off \
		OPENSSL "Include mod_tls" off \
		QUOTA "Include mod_quota" off \
		IFSESSION "Include mod_ifsession" on \
		README "Include mod_readme" on \
		RATIO "Include mod_ratio" on \
		REWRITE "Include mod_rewrite" on \
		WRAP "Include mod_wrap" on \
		RADIUS "Include mod_radius" off

MODULES?=

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
.if exists (${LOCALBASE}/include/getopt.h)
BROKEN=	Does not build when libgnugetopt is installed
.endif
.endif

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
MODULES:=${MODULES}:mod_wrap
.endif

.if defined(WITH_RADIUS)
MODULES:=${MODULES}:mod_radius
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

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_rewrite:mod_wrap:mod_ifsession

INCLUDEDIRS=
LIBDIRS=

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
MODULES:=${MODULES}:mod_ldap
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MODULES:=${MODULES}:mod_sql:mod_sql_mysql
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib/mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
MODULES:=${MODULES}:mod_sql:mod_sql_postgres
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include
LIBDIRS:=${LIBDIRS}:${LOCALBASE}/lib
.endif

.if defined(WITH_OPENSSL)
CFLAGS+=	-DHAVE_OPENSSL
USE_OPENSSL=	yes
.include <${PORTSDIR}/Mk/bsd.openssl.mk>
PROFTPD_LIBS+=	-lssl -lcrypto -L${LOCALBASE}/lib
MODULES:=${MODULES}:mod_tls
.if defined(WITH_LDAP_TLS)
EXTRA_PATCHES=${FILESDIR}/extra_patch-ldap-tls-mod_ldap.c
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
.if defined(WITH_POSTGRESQL) || defined(WITH_MYSQL)
MODULES:=${MODULES}:mod_quotatab_sql
.endif
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

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

post-configure:
	${REINPLACE_CMD} -e 's:${EXAMPLESDIR}:${PREFIX}:' ${WRKSRC}/config.h
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

post-install:
	[ -f ${PREFIX}/etc/proftpd.conf ] || \
		${CP} ${EXAMPLESDIR}/etc/proftpd.conf ${PREFIX}/etc/proftpd.conf

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/proftpd
.for f in ${PORTDOCSdoc}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/proftpd
.endfor
.for f in ${PORTDOCScontrib}
	@${INSTALL_DATA} ${WRKSRC}/doc/contrib/${f} ${PREFIX}/share/doc/proftpd
.endfor
.endif

.if !defined(WITHOUT_PAM)
	@${CAT} ${PKGMESSAGE}
.endif

.if defined(WITH_CTRLS)
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpdctl ${PREFIX}/sbin/ftpdctl
	@${INSTALL_MAN} ${WRKSRC}/src/ftpdctl.8 ${PREFIX}/man/man8/ftpdctl.8
.endif

.include <bsd.port.post.mk>
