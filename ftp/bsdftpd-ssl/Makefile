# New ports collection makefile for:	bsdftpd-ssl
# Date created:				5 Apr 2003
# Whom:					Nick Leuta
#
# $FreeBSD$
#

PORTNAME=	bsdftpd-ssl
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	ftp
MASTER_SITES=	http://bsdftpd-ssl.sc.ru/files/bsdftpd-ssl/archive/1.0/src/
DISTNAME=	bsdftpd-ssl-${PORTVERSION}

MAINTAINER=	skynick@mail.sc.ru

# Client only part
.if defined(CLIENT_ONLY)
PKGNAMESUFFIX=	-client
COMMENT=	FTP command-line client utility with the TLS/SSL support
DESCR=		${FILESDIR}/pkg-descr.client
PLIST=		${FILESDIR}/pkg-plist.client
.endif
# Client part
MAN1=	ftps.1
# Server part
.if !defined(CLIENT_ONLY)
COMMENT=	Secure FTP server with the TLS/SSL support
MAN5=	ftpchroot.5 xferlog.5
MAN8=	ftpd.8
MLINKS=	ftpd.8 ftpd-ssl.8
PKGMESSAGE=	${WRKDIR}/pkg-message
SED_ARG=	's|%%PREFIX%%|${PREFIX}|g; s|%%DOCSDIR%%|${DOCSDIR}|g'
.endif

MANCOMPRESSED=	yes
USE_OPENSSL=	yes

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
	(cd ${WRKSRC}/port && make && cd ${WRKSRC}/ftp && make) || exit
# Server part
.if !defined(CLIENT_ONLY)
	(cd ${WRKSRC}/ftpd && make) || exit
	@${SED} ${SED_ARG} ${FILESDIR}/pkg-message.server > \
	${WRKDIR}/pkg-message
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
.if !defined(NOPORTDOCS)
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
	@${INSTALL_SCRIPT} ${FILESDIR}/bsdftpd-ssl.sh ${PREFIX}/etc/rc.d/bsdftpd-ssl.sh.sample
	@${ECHO_CMD} "*******************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "*******************************************************************************"
.endif

.include <bsd.port.mk>
