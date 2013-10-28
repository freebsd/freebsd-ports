# Created by: Frank DENIS
# $FreeBSD$

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.36
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/ \
		SF/pureftpd/Pure-FTPd/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, easy to set up, fast, and secure FTP server

SUB_FILES=	pkg-message
SUB_LIST=	PAM_DIR=${PAM_DIR} PAM_TARGET=${PAM_TARGET}
USE_BZIP2=	yes
USE_PERL5=	run
USE_RC_SUBR=	pure-ftpd
USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-everything \
		--with-paranoidmsg \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var

MAN8=		pure-ftpd.8 pure-ftpwho.8 pure-mrtginfo.8 pure-statsdecode.8 \
		pure-uploadscript.8 pure-pw.8 pure-pwconvert.8 pure-quotacheck.8 \
		pure-authd.8

OPTIONS_DEFINE=	LDAP MYSQL PAM PGSQL TLS PRIVSEP PERUSERLIMITS THROTTLING \
		UPLOADSCRIPT UTF8 SENDFILE LARGEFILE VIRTUALCHROOT ANONRESUME \
		ANONRENAME ANONDELETE DOCS EXAMPLES
OPTIONS_DEFAULT=	PAM PRIVSEP SENDFILE VIRTUALCHROOT

LDAP_DESC=	Support for users in LDAP directories
MYSQL_DESC=	Support for users in MySQL database
PAM_DESC=	Support for PAM authentication
PGSQL_DESC=	Support for users in PostgreSQL database
TLS_DESC=	Support for TLS (experimental)
PRIVSEP_DESC=	Enable privilege separation
PERUSERLIMITS_DESC=	Per-user concurrency limits
THROTTLING_DESC=	Bandwidth throttling
UPLOADSCRIPT_DESC=	Support uploadscript daemon
UTF8_DESC=	Support for charset conversion
SENDFILE_DESC=	Support for the sendfile syscall
LARGEFILE_DESC=	Support downloading files larger than 2Gb
VIRTUALCHROOT_DESC=	Follow symlinks outside a chroot jail
ANONRESUME_DESC=	Allow anonymous user to resume file upload
ANONRENAME_DESC=	Allow anonymous user to rename file
ANONDELETE_DESC=	Allow anonymous user to delete file

NO_STAGE=	yes
.include <bsd.port.options.mk>

# language support requested?
.if ${PORT_OPTIONS:MLANG}
CONFIGURE_ARGS+=	--with-language="${WITH_LANG}"
.endif

# ldap support requested?
.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap
.endif

# mysql support requested?
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql
.endif

# postgresql support requested?
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		YES
CONFIGURE_ARGS+=	--with-pgsql
.endif

# privilege separation requested?
.if ${PORT_OPTIONS:MPRIVSEP}
CONFIGURE_ARGS+=	--with-privsep
.endif

# per-user concurrency limits requested?
.if ${PORT_OPTIONS:MPERUSERLIMITS}
CONFIGURE_ARGS+=	--with-peruserlimits
.endif

# throttling requested?
.if ${PORT_OPTIONS:MTHROTTLING}
CONFIGURE_ARGS+=	--with-throttling
.endif

# TLS
.if ${PORT_OPTIONS:MTLS}
CONFIGURE_ARGS+=	--with-tls
# different certificate file location?
CERTFILE?=      /etc/ssl/private/pure-ftpd.pem
CONFIGURE_ARGS+=	--with-certfile=${CERTFILE}
.endif

# if mysql or ldap are disabled, enable pam
.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
.endif

# support uploadscript?
.if ${PORT_OPTIONS:MUPLOADSCRIPT}
CONFIGURE_ARGS+=	--with-uploadscript
.endif

# RFC 2640 charset conversion requested?
.if ${PORT_OPTIONS:MUTF8}
USES+=			iconv
CONFIGURE_ARGS+=	--with-rfc2640
.endif

.if ${PORT_OPTIONS:MSENDFILE}
CONFIGURE_ARGS+=	--with-sendfile
.else
CONFIGURE_ARGS+=	--without-sendfile
.endif

.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if ${PORT_OPTIONS:MVIRTUALCHROOT}
CONFIGURE_ARGS+=	--with-virtualchroot
.else
CONFIGURE_ARGS+=	--without-virtualchroot
.endif

.if ${PORT_OPTIONS:MANONRESUME}
CFLAGS+=	-DANON_CAN_RESUME
.endif

.if ${PORT_OPTIONS:MANONRENAME}
CFLAGS+=	-DANON_CAN_RENAME
.endif

.if ${PORT_OPTIONS:MANONDELETE}
CFLAGS+=	-DANON_CAN_DELETE
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
	@${ECHO_MSG} "CERTFILE=/path        - Custom location of certificate file for TLS"
	@${ECHO_MSG} "WITH_LANG=lang        - Enable compilation of language support, lang is one of"
	@${ECHO_MSG} "  english, german, romanian, french, french-funny, polish, spanish,"
	@${ECHO_MSG} "  danish, dutch, italian, brazilian-portuguese, slovak, korean, swedish,"
	@${ECHO_MSG} "  norwegian, russian, traditional-chinese, simplified-chinese, czech,"
	@${ECHO_MSG} "  turkish, hungarian, catalan"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|@PERL@|${PERL}|; s|$${exec_prefix}|${PREFIX}|g' ${WRKSRC}/configuration-file/pure-config.pl.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/configuration-file/pure-config.pl ${PREFIX}/sbin/
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_SCRIPT} ${CONTRIB} ${EXAMPLESDIR}
	${MKDIR} ${PAM_DIR}
	${INSTALL_DATA} ${PAM_TEMPL} ${PAM_DIR}/${PAM_TARGET}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
