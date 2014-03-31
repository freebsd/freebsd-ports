# Created by: Frank DENIS
# $FreeBSD$

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.36
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://download.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/ \
		SF/pureftpd/Pure-FTPd/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, easy to set up, fast, and secure FTP server

LICENSE=	ISCL

OPTIONS_DEFINE=	ANONDELETE ANONRENAME ANONRESUME DOCS EXAMPLES LARGEFILE LDAP \
		MYSQL PAM PERUSERLIMITS PGSQL PRIVSEP SENDFILE THROTTLING TLS \
		UPLOADSCRIPT UTF8 VIRTUALCHROOT
OPTIONS_DEFAULT=PAM PRIVSEP SENDFILE VIRTUALCHROOT
ANONDELETE_DESC=	Allow anonymous user to delete files
ANONRENAME_DESC=	Allow anonymous user to rename files
ANONRESUME_DESC=	Allow anonymous user to resume file upload
LARGEFILE_DESC=		2GB+ file download
LDAP_DESC=		User accounts in LDAP directories
MYSQL_DESC=		User accounts in MySQL database
PAM_DESC=		PAM authentication
PGSQL_DESC=		User accounts in PostgreSQL database
PERUSERLIMITS_DESC=	Per-user concurrency limits
PRIVSEP_DESC=		Privilege separation (recommended)
SENDFILE_DESC=		Sendfile syscall
THROTTLING_DESC=	Bandwidth throttling
UPLOADSCRIPT_DESC=	Uploadscript daemon support
UTF8_DESC=		UTF-8 filenames
VIRTUALCHROOT_DESC=	Follow symlinks outside a chroot jail

CONFIGURE_ARGS=	--localstatedir=/var --sysconfdir=${PREFIX}/etc \
		--with-everything --with-ftpwho --with-language=${LANG} \
		--with-paranoidmsg
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PAM_DIR=${PAM_DIR} PAM_TARGET=${PAM_TARGET}
USE_BZIP2=	yes
USE_PERL5=	run
USE_RC_SUBR=	pure-ftpd
USES=		perl5 shebangfix

PORTDOCS=	AUTHORS CONTACT COPYING HISTORY NEWS README \
		README.Authentication-Modules README.Configuration-File \
		README.Contrib README.LDAP README.MySQL README.PGSQL \
		README.TLS README.Virtual-Users THANKS pure-ftpd.png \
		pureftpd.schema
PORTEXAMPLES=	*

SHEBANG_FILES=	contrib/pure-stat.pl contrib/pure-vpopauth.pl

CONTRIB=	pure-stat.pl pure-vpopauth.pl xml_python_processors.txt
LANG?=		english
PAM_DIR?=	${EXAMPLESDIR}/pam
PAM_TARGET?=	pure-ftpd
PAM_TEMPL?=	${FILESDIR}/pam.conf.5
TLS_CERTFILE?=	/etc/ssl/private/pure-ftpd.pem

ANONDELETE_CFLAGS=	-DANON_CAN_DELETE
ANONRENAME_CFLAGS=	-DANON_CAN_RENAME
ANONRESUME_CFLAGS=	-DANON_CAN_RESUME
LARGEFILE_CONFIGURE_ENABLE=	largefile
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		MYSQL=yes
PAM_CONFIGURE_WITH=	pam
PERUSERLIMITS_CONFIGURE_WITH=	peruserlimits
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USE=		PGSQL=yes
PRIVSEP_CONFIGURE_WITH=	privsep
SENDFILE_CONFIGURE_WITH=sendfile
THROTTLING_CONFIGURE_WITH=	throttling
TLS_CONFIGURE_ON=	--with-certfile=${TLS_CERTFILE}
TLS_CONFIGURE_WITH=	tls
UPLOADSCRIPT_CONFIGURE_WITH=	uploadscript
UTF8_CONFIGURE_WITH=	rfc2640
UTF8_USES=		iconv
VIRTUALCHROOT_CONFIGURE_WITH=	virtualchroot

pre-fetch:
	@${ECHO_MSG} "You can use the following additional options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "LANG=lang (default: english)"
	@${ECHO_MSG} "- Enable compilation of one language support"
	@${ECHO_MSG} "  available lang: brazilian-portuguese, catalan, czech, danish, dutch,"
	@${ECHO_MSG} "  english, french, french-funny, german, hungarian, italian, korean,"
	@${ECHO_MSG} "  norwegian, polish, romanian, russian, simplified-chinese, slovak,"
	@${ECHO_MSG} "  spanish, swedish, traditional-chinese, turkish"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "TLS_CERTFILE=/path/to/file (default: /etc/ssl/private/pure-ftpd.pem)"
	@${ECHO_MSG} "- Custom location of certificate file for TLS"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|@PERL@|${PERL}|; s|$${exec_prefix}|${PREFIX}|g' ${WRKSRC}/configuration-file/pure-config.pl.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/configuration-file/pure-ftpd.conf ${STAGEDIR}${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/configuration-file/pure-config.pl ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${FILESDIR}/pure-alwaysfail ${STAGEDIR}${PREFIX}/sbin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/contrib/ && ${INSTALL_SCRIPT} ${CONTRIB} ${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${PAM_DIR}/
	${INSTALL_DATA} ${PAM_TEMPL} ${STAGEDIR}${PAM_DIR}/${PAM_TARGET}

.include <bsd.port.mk>
