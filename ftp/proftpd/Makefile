# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=	proftpd
PORTVERSION=	1.2.10.r3
PORTREVISION=	0
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.proftpd.net/distrib/source/ \
		ftp://ftp.stikman.com/pub/proftpd/ \
		ftp://ftp.empora.de/pub/mirrors/ftp.proftpd.org/ \
		ftp://ftp.fastorama.com/ \
		ftp://ftp.middle-earth.it/proftpd/ \
		ftp://ftp.dataguard.no/pub/proftpd/ \
		ftp://spirit.bentel.sk/mirrors/Proftpd/ \
		ftp://ftp.task.gda.pl/pub/proftpd/ \
		ftp://mirror1.dataphone.se/pub/ProFTPD/ \
		ftp://ftp.oss.eznetsols.org/proftpd/ \
		ftp://ftp.ccp14.ac.uk/ccp14/ftp-mirror/programming/proftpd/ \
		ftp://proftpd.networkedsystems.co.uk/ \
		ftp://www.linuxceptional.com/proftpd/ \
		ftp://ftp.ethereal.com/mirrors/ftp.proftpd.org/ \
		ftp://mirror.cybercomm.nl/
DISTNAME=	${PORTNAME}-1.2.10rc3

MAINTAINER?=	mharo@FreeBSD.org
COMMENT?=	Highly configurable ftp daemon

MAN1=	ftpcount.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpshut.8

PORTDOCSdoc=	Configuration.html faq.html
PORTDOCScontrib=mod_ifsession.html mod_radius.html mod_rewrite.html \
		mod_tls.html mod_wrap.html ftpasswd.html
PORTDOCS=	${PORTDOCSdoc} ${PORTDOCScontrib}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g'

USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
SED_SCRIPT+=	-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		-e 's|%%RC_DIR%%|${RC_DIR}|g' \
		-e 's|%%RC_SUFX%%|${RC_SUFX}|g'
PLIST_SUB+=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

CONFIGURE_ARGS=	--localstatedir=/var/run \
		--disable-sendfile

.if defined(WITH_SETPASSENT)
CONFIGURE_ARGS+=	--enable-force-setpassent
.endif

.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--disable-pam
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

#allow user to override
MODULES?=	mod_ratio:mod_readme:mod_wrap

INCLUDEDIRS=
LIBDIRS=

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
MODULES:=${MODULES}:mod_tls
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
MODULES:=${MODULES}:mod_ldap
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MODULES:=${MODULES}:mod_sql:mod_sql_mysql
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib/mysql
.endif

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
MODULES:=${MODULES}:mod_sql:mod_sql_postgres
INCLUDEDIRS:=${INCLUDEDIRS}:${PREFIX}/include
LIBDIRS:=${LIBDIRS}:${PREFIX}/lib
.endif

.if defined(WITH_OPENSSL)
CFLAGS+=	-DHAVE_OPENSSL
USE_OPENSSL=	yes
PROFTPD_LIBS+=	-lssl -lcrypto
.endif

.if defined(WITH_CTRLS)
CFLAGS+=	--enable-ctrls
MAN8+=		ftpdctl.8
.else
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

pre-configure:
	@${ECHO_MSG} "==> Configuring with ${MODULES}"

post-configure:
	@${MV} ${WRKSRC}/Make.rules ${WRKSRC}/Make.rules.pre_sed
	@${SED}	-e 's: -lnsl::' \
		< ${WRKSRC}/Make.rules.pre_sed > ${WRKSRC}/Make.rules

	@${MV} ${WRKSRC}/src/proftpd.8 ${WRKSRC}/src/proftpd.8.pre_sed
	@${SED}	-e 's:/usr/sbin/proftpd:${PREFIX}/libexec/proftpd:' \
		-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/src/proftpd.8.pre_sed > ${WRKSRC}/src/proftpd.8

	@${MV} ${WRKSRC}/utils/ftpshut.8 ${WRKSRC}/utils/ftpshut.8.pre_sed
	@${SED}	-e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/etc:/var/run:' \
		< ${WRKSRC}/utils/ftpshut.8.pre_sed > ${WRKSRC}/utils/ftpshut.8

	@${MV} ${WRKSRC}/utils/ftpcount.1 ${WRKSRC}/utils/ftpcount.1.pre_sed
	@${SED}	-e 's:/usr/bin:${PREFIX}/bin:' \
		< ${WRKSRC}/utils/ftpcount.1.pre_sed > ${WRKSRC}/utils/ftpcount.1

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/proftpd.sh > ${WRKSRC}/proftpd.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpcount ${PREFIX}/bin/ftpcount
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpwho ${PREFIX}/bin/ftpwho
	@${INSTALL_PROGRAM} ${WRKSRC}/ftptop ${PREFIX}/bin/ftptop
	@${INSTALL_PROGRAM} ${WRKSRC}/proftpd ${PREFIX}/libexec/proftpd
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpshut ${PREFIX}/sbin/ftpshut
	@${INSTALL_MAN} ${WRKSRC}/utils/ftpcount.1 ${PREFIX}/man/man1/ftpcount.1
	@${INSTALL_MAN} ${WRKSRC}/utils/ftpwho.1 ${PREFIX}/man/man1/ftpwho.1
	@${INSTALL_MAN} ${WRKSRC}/utils/ftptop.1 ${PREFIX}/man/man1/ftptop.1
	@${INSTALL_MAN} ${WRKSRC}/src/xferlog.5 ${PREFIX}/man/man5/xferlog.5
	@${INSTALL_MAN} ${WRKSRC}/utils/ftpshut.8 ${PREFIX}/man/man8/ftpshut.8
	@${INSTALL_MAN} ${WRKSRC}/src/proftpd.8 ${PREFIX}/man/man8/proftpd.8
	@${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf.default
	@if [ ! -f ${PREFIX}/etc/proftpd.conf ]; then \
		${INSTALL_DATA} \
		${WRKSRC}/sample-configurations/basic.conf ${PREFIX}/etc/proftpd.conf; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/proftpd.sh ${PREFIX}/etc/rc.d/proftpd${RC_SUFX}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/proftpd
.for f in ${PORTDOCSdoc}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/proftpd
.endfor
.for f in ${PORTDOCScontrib}
	@${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${PREFIX}/share/doc/proftpd
.endfor
.endif

.if !defined(WITHOUT_PAM)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
