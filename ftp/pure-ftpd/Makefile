# New ports collection makefile for:	pure-ftpd
# Date created:				22 April 2001
# Whom:					Frank DENIS
#
# $FreeBSD$
#

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.8
CATEGORIES=	ftp ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pureftpd

MAINTAINER=	j@pureftpd.org

.if defined(WITH_DMALLOC)
LIB_DEPENDS+=	dmalloc.1:${PORTSDIR}/devel/dmalloc
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap2
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/databases/mysql323-client
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq:${PORTSDIR}/databases/postgresql7
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

# use of dmalloc requested?
.if defined(WITH_DMALLOC)
CONFIGURE_ARGS+=	--with-dmalloc
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
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
		README.Authentication-Modules THANKS poweredby.jpg

CONTRIB=	xml_python_processors.txt sfv-crc-check.pl

pre-fetch:
	@${ECHO} "You can use the following additional options:"
	@${ECHO} "WITH_DMALLOC=1        - enable use of the dmalloc library;"
	@${ECHO} "WITH_LDAP=1           - Support for users in LDAP \
		directories;"
	@${ECHO} "WITH_MYSQL=1          - Support for users in MySQL databases;"
	@${ECHO} "WITH_PGSQL=1          - Support for users in PostgreSQL databases;"	
	@${ECHO} "WITH_LANG=lang        - enable compilation of language \
		support, lang is one of"
	@${ECHO} "  english, german, romanian, french, french-funny, polish, spanish,"
	@${ECHO} "  dutch, italian, brazilian-portuguese, danish, slovak, korean or swedish."
	@${ECHO}

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
	@${ECHO} "Now you need to examine ${PAM_DIR}/${PAM_TARGET}"
	@${ECHO} "and add the relevant PAM configuration lines to your /etc/pam.conf file."
.endif

.include <bsd.port.post.mk>
