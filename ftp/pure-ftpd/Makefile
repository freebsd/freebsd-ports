# New ports collection makefile for:	pure-ftpd
# Date created:				22 April 2001
# Whom:					Frank DENIS
#
# $FreeBSD$
#

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.20
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp2.fr.pureftpd.org/pub/mirrors/ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp3.fr.pureftpd.org/pure-ftpd/releases/ \
		ftp://ftp.dk.pureftpd.org/mirrors/pure-ftpd/releases/ \
		ftp://ftp.es.pureftpd.org/mirror/pureftpd/latest/releases/ \
		ftp://ftp.nl.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.cn.pureftpd.org/pub/pureftpd/pure-ftpd/releases/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pureftpd

MAINTAINER=	j@pureftpd.org
COMMENT=	A small, easy to set up, fast and very secure FTP server

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--with-everything \
			--with-paranoidmsg \
			--with-virtualchroot \
			--with-tls \
			--with-largefile \
			--sysconfdir=${PREFIX}/etc

MAN8=		pure-ftpd.8 pure-ftpwho.8 pure-mrtginfo.8 pure-statsdecode.8 \
		pure-uploadscript.8 pure-pw.8 pure-pwconvert.8 pure-quotacheck.8 \
		pure-authd.8

OPTIONS=	LDAP	"Support for users in LDAP directories" off \
		MYSQL	"Support for users in MySQL database" off \
		PGSQL	"Support for users in PostgreSQL database" off \
		PRIVSEP	"Enable privilege separation" off \
		PERUSERLIMITS	"Per-user concurrency limits" off

.include <bsd.port.pre.mk>

# language support requested?
.if defined(WITH_LANG)
CONFIGURE_ARGS+=	--with-language="${WITH_LANG}"
.endif

# ldap support requested?
.if defined(WITH_LDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap
.endif

# mysql support requested?
.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
.endif

# postgresql support requested?
.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-pgsql
.endif

# privilege separation requested?
.if defined(WITH_PRIVSEP)
CONFIGURE_ARGS+=	--with-privsep
.endif

# per-user concurrency limits requested?
.if defined(WITH_PERUSERLIMITS)
CONFIGURE_ARGS+=	--with-peruserlimits
.endif

# different certificate file location?
.if defined(WITH_CERTFILE)
CONFIGURE_ARGS+=	--with-certfile=${WITH_CERTFILE}
.endif

# if mysql or ldap are disabled, enable pam
.if !defined(WITH_LDAP) && !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pam
.endif

.if ${OSVERSION} > 500000
PAM_TEMPL?=	${FILESDIR}/pam.conf.5
.else
. if ${OSVERSION} > 400000
PAM_TEMPL?=	${FILESDIR}/pam.conf.4
. endif
.endif
.if defined(PAM_TEMPL)
PAM_DIR?=	${EXAMPLESDIR}/pam
PAM_TARGET?=	pure-ftpd
.endif

DOCS=		AUTHORS CONTACT COPYING HISTORY NEWS \
		README README.Configuration-File README.Contrib README.LDAP \
		README.Netfilter README.MySQL README.PGSQL README.Virtual-Users \
		README.Authentication-Modules THANKS pure-ftpd.png \
		pureftpd.schema README.TLS

CONTRIB=	xml_python_processors.txt pure-stat.pl pure-vpopauth.pl

pre-fetch:
	@${ECHO_MSG} "You can use the following additional options:"
	@${ECHO_MSG} "WITH_CERTFILE=/path   - Set different location of certificate file for TLS"
	@${ECHO_MSG} "WITH_LANG=lang        - Enable compilation of language support, lang is one of"
	@${ECHO_MSG} "  english, german, romanian, french, french-funny, polish, spanish,"
	@${ECHO_MSG} "  dutch, italian, brazilian-portuguese, danish, slovak, korean,"
	@${ECHO_MSG} "  norwegian, swedish, russian, traditional-chinese, simplified-chinese,"
	@${ECHO_MSG} "  hungarian, catalan and czech."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|$${exec_prefix}|${PREFIX}|g' ${WRKSRC}/configuration-file/pure-config.pl.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-config.pl ${PREFIX}/sbin/
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${CONTRIB} ${EXAMPLESDIR}
	${CHMOD} 755 ${PREFIX}/sbin/pure-config.pl
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%RC_SUBR%%|${RC_SUBR}|g" \
		< ${FILESDIR}/pure-ftpd.sh.sample > ${WRKDIR}/pure-ftpd.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pure-ftpd.sh ${PREFIX}/etc/rc.d
.if defined(PAM_TEMPL)
	${MKDIR} ${PAM_DIR}
	${INSTALL_DATA} ${PAM_TEMPL} ${PAM_DIR}/${PAM_TARGET}
	@${ECHO_MSG} "Now you need to examine ${PAM_DIR}/${PAM_TARGET}"
	@${ECHO_MSG} "and add the relevant PAM configuration lines to your /etc/pam.conf file."
.endif

.include <bsd.port.post.mk>
