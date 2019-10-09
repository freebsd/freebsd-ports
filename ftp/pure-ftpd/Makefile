# Created by: Frank DENIS
# $FreeBSD$

PORTNAME=	pure-ftpd
PORTVERSION=	1.0.49
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	https://github.com/jedisct1/pure-ftpd/releases/download/${PORTVERSION}/ \
		https://download.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, easy to set up, fast, and secure FTP server

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe perl5 tar:bzip2
USE_PERL5=	run

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-altlog --with-cookie --with-diraliases \
		--with-everything --with-extauth --with-ftpwho \
		--with-language=${LANGUAGE} --with-paranoidmsg --with-puredb \
		--with-quotas --with-ratios
GNU_CONFIGURE=	yes
USE_RC_SUBR=	pure-ftpd

SUB_FILES=	pkg-message

CPE_VENDOR=	pureftpd

LANGUAGE?=	english

OPTIONS_DEFINE=	ANONDELETE ANONRENAME ANONRESUME DOCS EXAMPLES LARGEFILE LDAP \
		MYSQL PAM PERUSERLIMITS PGSQL PRIVSEP SCRYPT SENDFILE \
		THROTTLING TLS UPLOADSCRIPT VIRTUALCHROOT
OPTIONS_DEFAULT=PAM PRIVSEP SENDFILE SCRYPT TLS VIRTUALCHROOT
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
SCRYPT_DESC=		Hash passwords in PureDB with scrypt
SENDFILE_DESC=		Sendfile syscall
THROTTLING_DESC=	Bandwidth throttling
UPLOADSCRIPT_DESC=	Uploadscript daemon support
VIRTUALCHROOT_DESC=	Follow symlinks outside a chroot jail

ANONDELETE_CPPFLAGS=	-DANON_CAN_DELETE
ANONRENAME_CPPFLAGS=	-DANON_CAN_RENAME
ANONRESUME_CPPFLAGS=	-DANON_CAN_RESUME
LARGEFILE_CONFIGURE_ENABLE=	largefile
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		OPENLDAP=yes
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USES=		mysql
PAM_CONFIGURE_WITH=	pam
PERUSERLIMITS_CONFIGURE_WITH=	peruserlimits
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USES=		pgsql
PRIVSEP_CONFIGURE_WITH=	privsep
SCRYPT_LIB_DEPENDS=	libsodium.so:security/libsodium
SENDFILE_CONFIGURE_WITH=sendfile
THROTTLING_CONFIGURE_WITH=	throttling
TLS_CONFIGURE_WITH=	tls
TLS_CPPFLAGS=		-I${OPENSSLINC}
TLS_LDFLAGS=		-L${OPENSSLLIB}
TLS_USES=		ssl
UPLOADSCRIPT_CONFIGURE_WITH=	uploadscript
VIRTUALCHROOT_CONFIGURE_WITH=	virtualchroot

pre-fetch:
	@${ECHO_MSG} "You can use the following additional options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "LANGUAGE=lang (default: english)"
	@${ECHO_MSG} "- Enable compilation of one language support"
	@${ECHO_MSG} "  available lang: albanian, brazilian-portuguese, catalan, czech, danish, dutch,"
	@${ECHO_MSG} "  english, french, german, hungarian, italian, korean, norwegian, polish,"
	@${ECHO_MSG} "  romanian, russian, simplified-chinese, slovak, spanish, swedish,"
	@${ECHO_MSG} "  traditional-chinese."
	@${ECHO_MSG} ""

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/pure-ftpd.conf ${STAGEDIR}${PREFIX}/etc/pure-ftpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-ldap.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-ldap.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-mysql.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-mysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/pureftpd-pgsql.conf ${STAGEDIR}${PREFIX}/etc/pureftpd-pgsql.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pure-alwaysfail ${STAGEDIR}${PREFIX}/sbin/

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pam.d/
	${INSTALL_DATA} ${FILESDIR}/pam.conf.5 ${STAGEDIR}${EXAMPLESDIR}/pam.d/pure-ftpd

.include <bsd.port.mk>
