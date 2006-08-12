# New ports collection makefile for:    jftpgw
# Date created:         Sun Jul 15 13:19:01 CEST 2001
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	jftpgw
PORTVERSION=	0.13.5
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Highly configurable FTP proxy

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-logpath=/var/log \
		--enable-crypt \
		--enable-sftp
#USE_RC_SUBR=	yes
#USE_REINPLACE=	yes
MAN1=		jftpgw.1

USE_RC_SUBR=	jftpgw.sh

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jftpgw ${TARGETDIR}/sbin/
		${INSTALL_DATA} ${WRKSRC}/jftpgw.conf.sample ${TARGETDIR}/etc/
		${INSTALL_MAN} ${WRKSRC}/jftpgw.1 ${TARGETDIR}/man/man1/
#		${REINPLACE_CMD} -e 's:@PREFIX@:${TARGETDIR}:g' \
#			${FILESDIR}/jftpgw.sh.in > ${WRKDIR}/jftpgw.sh
#		${INSTALL_SCRIPT} ${WRKDIR}/jftpgw.sh ${TARGETDIR}/etc/rc.d
.if !defined(NOPORTDOCS)
		${MKDIR} ${TARGETDIR}/share/doc/jftpgw
		${INSTALL_DATA} ${WRKSRC}/doc/config.html ${TARGETDIR}/share/doc/jftpgw
.endif

.include <bsd.port.mk>
