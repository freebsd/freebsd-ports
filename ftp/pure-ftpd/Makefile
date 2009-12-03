# New ports collection makefile for:	pure-ftpd
# Date created:				22 April 2001
# Whom:					Frank DENIS
#
# $FreeBSD$
#

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.27
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp2.fr.pureftpd.org/pub/mirrors/ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp3.fr.pureftpd.org/pure-ftpd/releases/ \
		ftp://ftp.dk.pureftpd.org/mirrors/pure-ftpd/releases/ \
		ftp://ftp.es.pureftpd.org/mirror/pureftpd/latest/releases/ \
		ftp://ftp.nl.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.cn.pureftpd.org/pub/pureftpd/pure-ftpd/releases/ \
		SF/pureftpd/Pure-FTPd/${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A small, easy to set up, fast and very secure FTP server

SUB_FILES=	pkg-message
SUB_LIST=	PAM_DIR=${PAM_DIR} PAM_TARGET=${PAM_TARGET}
USE_BZIP2=	yes
USE_PERL5_RUN=	yes
USE_RC_SUBR=	pure-ftpd.sh
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--with-everything \
		--with-paranoidmsg \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var

MAN8=		pure-ftpd.8 pure-ftpwho.8 pure-mrtginfo.8 pure-statsdecode.8 \
		pure-uploadscript.8 pure-pw.8 pure-pwconvert.8 pure-quotacheck.8 \
		pure-authd.8

OPTIONS=	LDAP		"Support for users in LDAP directories" off \
		MYSQL		"Support for users in MySQL database" off \
		PAM		"Support for PAM authentication" on \
		PGSQL		"Support for users in PostgreSQL database" off \
		TLS		"Support for TLS (experimental)" off \
		PRIVSEP		"Enable privilege separation" on \
		PERUSERLIMITS	"Per-user concurrency limits" off \
		THROTTLING	"Bandwidth throttling" off \
		BANNER		"Show ${PORTNAME} welcome upon session start" on \
		UPLOADSCRIPT	"Support uploadscript daemon" off \
		UTF8		"Support for charset conversion (expreimental)" off \
		SENDFILE	"Support for the sendfile syscall" on \
		LARGEFILE	"Support downloading files larger than 2Gb" off \
		VIRTUALCHROOT	"Follow symlinks outside a chroot jail" on

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
USE_PGSQL=		YES
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

# throttling requested?
.if defined(WITH_THROTTLING)
CONFIGURE_ARGS+=	--with-throttling
.endif

# TLS
.if defined(WITH_TLS)
CONFIGURE_ARGS+=	--with-tls
# different certificate file location?
. if defined(WITH_CERTFILE)
CONFIGURE_ARGS+=	--with-certfile=${WITH_CERTFILE}
. endif
.endif

# if mysql or ldap are disabled, enable pam
.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif

# for paranoia
.if defined(WITHOUT_BANNER)
CONFIGURE_ARGS+=	--without-banner
.endif

# support uploadscript?
.if defined (WITH_UPLOADSCRIPT)
CONFIGURE_ARGS+=	--with-uploadscript
.endif

# RFC 2640 charset conversion requested?
.if defined(WITH_UTF8)
USE_ICONV=	YES
CONFIGURE_ARGS+=	--with-rfc2640
.endif

.if defined(WITH_SENDFILE)
CONFIGURE_ARGS+=	--with-sendfile
.else
CONFIGURE_ARGS+=	--without-sendfile
.endif

.if defined(WITH_LARGEFILE)
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if defined(WITH_VIRTUALCHROOT)
CONFIGURE_ARGS+=	--with-virtualchroot
.else
CONFIGURE_ARGS+=	--without-virtualchroot
.endif

PAM_TEMPL?=	${FILESDIR}/pam.conf.5
PAM_DIR?=	${EXAMPLESDIR}/pam
PAM_TARGET?=	pure-ftpd

PORTDOCS=	AUTHORS CONTACT COPYING HISTORY NEWS \
		README README.Configuration-File README.Contrib README.LDAP \
		README.MySQL README.PGSQL README.Virtual-Users \
		README.Authentication-Modules THANKS pure-ftpd.png \
		pureftpd.schema README.TLS
PORTEXAMPLES=	*

CONTRIB=	xml_python_processors.txt pure-stat.pl pure-vpopauth.pl

pre-fetch:
	@${ECHO_MSG} "You can use the following additional options:"
	@${ECHO_MSG} "WITH_CERTFILE=/path   - Set different location of certificate file for TLS"
	@${ECHO_MSG} "WITH_LANG=lang        - Enable compilation of language support, lang is one of"
	@${ECHO_MSG} "  english, german, romanian, french, french-funny, polish, spanish,"
	@${ECHO_MSG} "  danish, dutch, italian, brazilian-portuguese, slovak, korean, swedish,"
	@${ECHO_MSG} "  norwegian, russian, traditional-chinese, simplified-chinese, czech,"
	@${ECHO_MSG} "  turkish, hungarian, catalan"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|$${exec_prefix}|${PREFIX}|g' \
		${WRKSRC}/configuration-file/pure-config.pl.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/configuration-file/pure-config.pl ${PREFIX}/sbin/
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${CONTRIB} ${EXAMPLESDIR}
	${MKDIR} ${PAM_DIR}
	${INSTALL_DATA} ${PAM_TEMPL} ${PAM_DIR}/${PAM_TARGET}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
