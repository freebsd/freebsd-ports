# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
PORTVERSION=	1.2.2rc1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.stikman.com/pub/proftpd/source/ \
		ftp://ftp.dataguard.no/pub/proftpd/distrib/source/ \
		ftp://ftp.club-internet.fr/pub/mirrors/ftp.proftpd.org/distrib/source/

MAINTAINER=	mharo@FreeBSD.org

.if defined(WITH_LDAP)
MASTER_SITES+=	http://www.horde.net/~jwm/software/proftpd-ldap/
MOD_LDAP=	mod_ldap-2.7.4.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${MOD_LDAP}
.endif

MAN1=	ftpcount.1 ftpwho.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8

USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_BZIP2=	YES

CONFIGURE_ARGS=	--localstatedir=/var/run \
		--disable-sendfile

.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--disable-pam
.endif

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_quota:mod_wrap

.if defined(WITH_LDAP)
MODULES:=${MODULES}:mod_ldap
BUILD_DEPENDS+=	${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap
CONFIGURE_ENV+=	CFLAGS="-I/usr/local/include -g" LDFLAGS=-L/usr/local/lib
.endif

.if defined(WITH_MYSQL)
MODULES:=${MODULES}:mod_sql:mod_sql_mysql
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ENV+=	CFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib/mysql"
.endif

.if !empty(MODULES)
CONFIGURE_ARGS+= --with-modules=${MODULES}
.endif

.if defined(WITH_LDAP)
post-extract:
	${RM} -rf ${WRKSRC}/contrib/mod_ldap.c
	tar --to-stdout -xvz -f ${DISTDIR}/${MOD_LDAP} */mod_ldap.c > ${WRKSRC}/contrib/mod_ldap.c
.endif

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

post-configure:
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
	@${INSTALL_DATA} ${WRKSRC}/doc/FAQ-config.html ${PREFIX}/share/doc/proftpd
.endif

.if !defined(WITHOUT_PAM)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
