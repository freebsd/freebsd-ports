# New ports collection makefile for:    jftpgw
# Date created:         Sun Jul 15 13:19:01 CEST 2001
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	jftpgw
PORTVERSION=	0.13.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	se@FreeBSD.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-logpath=/var/log \
		--enable-crypt \
		--enable-sftp
MAN1=		jftpgw.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jftpgw ${PREFIX}/sbin/
		${INSTALL_DATA} ${WRKSRC}/jftpgw.conf.sample ${PREFIX}/etc/
		${INSTALL_MAN} ${WRKSRC}/jftpgw.1 ${PREFIX}/man/man1/
		@${SED} -e 's:@PREFIX@:${PREFIX}:g' \
			${FILESDIR}/jftpgw.sh.in > ${WRKDIR}/jftpgw.sh
		${INSTALL_SCRIPT} ${WRKDIR}/jftpgw.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
