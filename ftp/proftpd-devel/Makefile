# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
PORTVERSION=	1.2.6
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.proftpd.net/distrib/source/ \
		ftp://ftp.stikman.com/pub/proftpd/source/ \
		ftp://ftp.dataguard.no/pub/proftpd/distrib/source/ \
		ftp://ftp.club-internet.fr/pub/mirrors/ftp.proftpd.org/distrib/source/
DISTNAME=	${PORTNAME}-1.2.6

MAINTAINER=	mharo@FreeBSD.org

MAN1=	ftpcount.1 ftpwho.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	YES

CONFIGURE_ARGS=	--localstatedir=/var/run \
		--disable-sendfile

.if defined(WITH_SETPASSENT)
CONFIGURE_ARGS+=	--enable-force-setpassent
.endif

.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--disable-pam
.endif

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_wrap

INCLUDEDIRS=
LIBDIRS=

.if defined(WITH_LDAP)
MODULES:=${MODULES}:mod_ldap
BUILD_DEPENDS+=	${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib
.endif

.if defined(WITH_MYSQL)
MODULES:=${MODULES}:mod_sql:mod_sql_mysql
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib/mysql
.endif

.if defined(WITH_POSTGRES)
MODULES:=${MODULES}:mod_sql:mod_sql_postgres
LIB_DEPENDS+=	pq.2:\${PORTSDIR}/databases/postgresql7
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib
.endif

.if !empty(MODULES)
CONFIGURE_ARGS+= --with-modules=${MODULES}
.endif

.if !empty(INCLUDEDIRS)
CONFIGURE_ARGS+= --with-includes=${INCLUDEDIRS}
.endif

.if !empty(LIBDIRS)
CONFIGURE_ARGS+= --with-libraries=${LIBDIRS}
.endif

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

post-configure:
	@${MV} ${WRKSRC}/Make.rules ${WRKSRC}/Make.rules.pre_sed
	@${SED}	-e 's: -lnsl::' \
		< ${WRKSRC}/Make.rules.pre_sed > ${WRKSRC}/Make.rules

	@${MV} ${WRKSRC}/src/proftpd.8 ${WRKSRC}/src/proftpd.8.pre_sed
	@${SED}	-e 's:/etc:${PREFIX}/etc:' \
		-e 's:/usr/sbin/proftpd:${PREFIX}/libexec/proftpd:' \
		-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/src/proftpd.8.pre_sed > ${WRKSRC}/src/proftpd.8

	@${MV} ${WRKSRC}/src/ftpshut.8 ${WRKSRC}/src/ftpshut.8.pre_sed
	@${SED}	-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/etc:/var/run:' \
		< ${WRKSRC}/src/ftpshut.8.pre_sed > ${WRKSRC}/src/ftpshut.8

	@${MV} ${WRKSRC}/src/ftpcount.1 ${WRKSRC}/src/ftpcount.1.pre_sed
	@${SED}	-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/src/ftpcount.1.pre_sed > ${WRKSRC}/src/ftpcount.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpcount ${PREFIX}/bin/ftpcount
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpwho ${PREFIX}/bin/ftpwho
	@${INSTALL_PROGRAM} ${WRKSRC}/proftpd ${PREFIX}/libexec/proftpd
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpshut ${PREFIX}/sbin/ftpshut
	@${INSTALL_MAN} ${WRKSRC}/src/ftpcount.1 ${PREFIX}/man/man1/ftpcount.1
	@${INSTALL_MAN} ${WRKSRC}/src/ftpwho.1 ${PREFIX}/man/man1/ftpwho.1
	@${INSTALL_MAN} ${WRKSRC}/src/xferlog.5 ${PREFIX}/man/man5/xferlog.5
	@${INSTALL_MAN} ${WRKSRC}/src/ftpshut.8 ${PREFIX}/man/man8/ftpshut.8
	@${INSTALL_MAN} ${WRKSRC}/src/proftpd.8 ${PREFIX}/man/man8/proftpd.8
	@${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf.default
	@if [ ! -f ${PREFIX}/etc/proftpd.conf ]; then \
		${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf; \
	fi
	@${SED} -e 's,/usr/local,${PREFIX},g' ${FILESDIR}/proftpd.sh.sample > ${PREFIX}/etc/rc.d/proftpd.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/proftpd
	@${INSTALL_DATA} ${WRKSRC}/doc/Configuration.html ${PREFIX}/share/doc/proftpd
	@${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${PREFIX}/share/doc/proftpd
.endif

.if !defined(WITHOUT_PAM)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
