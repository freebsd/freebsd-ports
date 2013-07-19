# Created by: Nick Leuta
# $FreeBSD$

PORTNAME=	bsdftpd-ssl
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://bsdftpd.org/files/bsdftpd-ssl/archive/1.1/src/ \
		http://www.sourcefiles.org/System/Daemons/FTP/
.if defined(CLIENT_ONLY)
PKGNAMESUFFIX=	-client
.endif

MAINTAINER=	skynick@mail.sc.ru
COMMENT=	Secure FTP server with the TLS/SSL support
.if defined(CLIENT_ONLY)
COMMENT=	FTP command-line client utility with the TLS/SSL support
.endif

USE_OPENSSL=	yes

MAKE_ENV+=	OBJFORMAT=elf

.include <bsd.port.pre.mk>

# Client only part
.if defined(CLIENT_ONLY)
DESCR=		${FILESDIR}/pkg-descr.client
PLIST=		${FILESDIR}/pkg-plist.client
.endif
# Client part
MAN1=	ftps.1
# Server part
.if !defined(CLIENT_ONLY)
MAN5=	ftpchroot.5 xferlog.5
MAN8=	ftpd.8
MLINKS=	ftpd.8 ftpd-ssl.8 ftpchroot.5 ftpchroot-ssl.5
.if ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES=	pkg-message
.endif
USE_RC_SUBR=	${PORTNAME}
.endif

MANCOMPRESSED=	yes

BINOWN=	root
BINGRP=	wheel
SHAREOWN=	${BINOWN}
SHAREGRP=	${BINGRP}
MANOWN=	${BINOWN}
MANGRP=	${BINGRP}
BINMODE=	555
SHAREMODE=	444
MANMODE=	${SHAREMODE}

MANDIR=	${PREFIX}/man/man
DOCDIR=	${DOCSDIR}${PKGNAMESUFFIX}

pre-build:
	(cd ${WRKSRC} && ./config.sh FreeBSD) || exit

do-build:
# Client part
	(cd ${WRKSRC}/port && ${SETENV} ${MAKE_ENV} make && cd ${WRKSRC}/ftp && ${SETENV} ${MAKE_ENV} make) || exit
# Server part
.if !defined(CLIENT_ONLY)
	(cd ${WRKSRC}/ftpd && ${SETENV} ${MAKE_ENV} make) || exit
.endif

do-install:
# Client part
	${INSTALL_PROGRAM} ${WRKSRC}/ftp/ftps ${PREFIX}/bin/ftps
	${INSTALL_MAN} ${WRKSRC}/ftp/ftps.1.gz ${MANDIR}1/ftps.1.gz
# Server part
.if !defined(CLIENT_ONLY)
	${INSTALL_PROGRAM} ${WRKSRC}/ftpd/ftpd ${PREFIX}/libexec/ftpd
	${INSTALL_MAN} ${WRKSRC}/ftpd/ftpchroot.5.gz ${MANDIR}5/ftpchroot.5.gz
	${INSTALL_MAN} ${WRKSRC}/ftpd/xferlog.5.gz ${MANDIR}5/xferlog.5.gz
	${INSTALL_MAN} ${WRKSRC}/ftpd/ftpd.8.gz ${MANDIR}8/ftpd.8.gz
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} -p ${WRKSRC}/COPYRIGHT ${DOCDIR}/COPYRIGHT
	${INSTALL_DATA} -p ${WRKSRC}/README ${DOCDIR}/README
	${INSTALL_DATA} -p ${WRKSRC}/INSTALL ${DOCDIR}/INSTALL
	${INSTALL_DATA} -p ${WRKSRC}/ChangeLog ${DOCDIR}/ChangeLog

	${MKDIR} ${DOCDIR}/docs
	${INSTALL_DATA} -p ${WRKSRC}/docs/README ${DOCDIR}/docs/README
	${INSTALL_DATA} -p ${WRKSRC}/docs/cert-basics.txt ${DOCDIR}/docs/cert-basics.txt
	${INSTALL_DATA} -p ${WRKSRC}/docs/cert-howto.txt ${DOCDIR}/docs/cert-howto.txt
	${INSTALL_DATA} -p ${WRKSRC}/docs/ciphers.txt ${DOCDIR}/docs/ciphers.txt
	${INSTALL_DATA} -p ${WRKSRC}/docs/licenses ${DOCDIR}/docs/licenses
	${INSTALL_DATA} -p ${WRKSRC}/docs/standards.txt ${DOCDIR}/docs/standards.txt
	${INSTALL_DATA} -p ${WRKSRC}/docs/verify.txt ${DOCDIR}/docs/verify.txt
	${INSTALL_DATA} -p ${WRKSRC}/docs/x509_auth.txt ${DOCDIR}/docs/x509_auth.txt

	${MKDIR} ${DOCDIR}/cert
	${INSTALL_SCRIPT} -p ${WRKSRC}/cert/cert-nopass.sh ${DOCDIR}/cert/cert-nopass.sh
	${INSTALL_SCRIPT} -p ${WRKSRC}/cert/cert-pass.sh ${DOCDIR}/cert/cert-pass.sh
	${INSTALL_SCRIPT} -p ${WRKSRC}/cert/cert-dummy.sh ${DOCDIR}/cert/cert-dummy.sh
	${INSTALL_SCRIPT} -p ${WRKSRC}/cert/xCA.sh ${DOCDIR}/cert/xCA.sh
.endif
.if !defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/rc.conf.d
	${INSTALL_DATA} -p ${FILESDIR}/README.examples ${EXAMPLESDIR}/README
	${INSTALL_DATA} -p ${FILESDIR}/ftpchroot ${EXAMPLESDIR}/ftpchroot
	${INSTALL_DATA} -p ${FILESDIR}/ftpusers ${EXAMPLESDIR}/ftpusers
	${INSTALL_DATA} -p ${FILESDIR}/rc_conf_d.bsdftpd_ssl ${EXAMPLESDIR}/rc.conf.d/bsdftpd_ssl
	@${ECHO_CMD} "*******************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "*******************************************************************************"
.endif
.endif

.include <bsd.port.post.mk>
