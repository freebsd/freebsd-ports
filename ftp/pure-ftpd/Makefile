# New ports collection makefile for:	pure-ftpd
# Date created:				22 April 2001
# Whom:					Frank DENIS
#
# $FreeBSD$
#

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.13a
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

.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap2
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/databases/mysql323-client
.endif

.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-everything \
			--with-paranoidmsg \
			--with-virtualchroot \
			--sysconfdir=/etc
# language support requested?
.if defined(WITH_LANG)
CONFIGURE_ARGS+=	--with-language="${WITH_LANG}"
.endif

# ldap support requested ?
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-ldap
.endif

# mysql support requested ?
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
.endif

# mysql support requested ?
.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
.endif

# if mysql or ldap are disabled, enable pam
.if !defined(WITH_LDAP) && !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pam
.endif

MAN8=		pure-ftpd.8 pure-ftpwho.8 pure-mrtginfo.8 pure-statsdecode.8 \
		pure-uploadscript.8 pure-pw.8 pure-pwconvert.8 pure-quotacheck.8 \
		pure-authd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
PAM_TEMPL?=	${FILESDIR}/pam.conf.5
.else
. if ${OSVERSION} > 400000
PAM_TEMPL?=	${FILESDIR}/pam.conf.4
. endif
.endif
.if defined(PAM_TEMPL)
PAM_DIR?=	${PREFIX}/share/examples/${PORTNAME}/pam
PAM_TARGET?=	pure-ftpd
.endif

DOCS=		AUTHORS CONTACT COPYING HISTORY NEWS \
		README README.Configuration-File README.Contrib README.LDAP \
		README.Netfilter README.MySQL README.PGSQL README.Virtual-Users \
		README.Authentication-Modules THANKS pure-ftpd.png \
		pureftpd.schema

CONTRIB=	xml_python_processors.txt pure-vpopauth.pl

pre-fetch:
	@${ECHO_CMD} "You can use the following additional options:"
	@${ECHO_CMD} "WITH_LDAP=1           - Support for users in LDAP directories"
	@${ECHO_CMD} "WITH_MYSQL=1          - Support for users in MySQL databases"
	@${ECHO_CMD} "WITH_PGSQL=1          - Support for users in PostgreSQL databases"
	@${ECHO_CMD} "WITH_LANG=lang        - Enable compilation of language support, lang is one of"
	@${ECHO_CMD} "  english, german, romanian, french, french-funny, polish, spanish,"
	@${ECHO_CMD} "  dutch, italian, brazilian-portuguese, danish, slovak, korean,"
	@${ECHO_CMD} "  norwegian, swedish, russian, traditional-chinese, simplified-chinese"
	@${ECHO_CMD} "  and czech."
	@${ECHO_CMD} ""

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-config.pl ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/share/examples/pure-ftpd
	(cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${CONTRIB} ${PREFIX}/share/examples/pure-ftpd)
	${CHMOD} 755 ${PREFIX}/sbin/pure-config.pl
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pure-ftpd
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/pure-ftpd)
.endif
.if defined(PAM_TEMPL)
	${MKDIR} ${PAM_DIR}
	${INSTALL_DATA} ${PAM_TEMPL} ${PAM_DIR}/${PAM_TARGET}
	@${ECHO_CMD} "Now you need to examine ${PAM_DIR}/${PAM_TARGET}"
	@${ECHO_CMD} "and add the relevant PAM configuration lines to your /etc/pam.conf file."
.endif

.include <bsd.port.post.mk>
