# New ports collection makefile for:    jftpgw
# Date created:         Sun Jul 15 13:19:01 CEST 2001
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	jftpgw
PORTVERSION=	0.0.13a
CATEGORIES=	ftp
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	se@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-confpath=${PREFIX}/etc \
		--with-logpath=/var/log \
		--enable-crypt \
#		--enable-sftp

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jftpgw ${PREFIX}/sbin/
		${INSTALL_DATA} ${WRKSRC}/jftpgw.conf.sample ${PREFIX}/etc/
		@${SED} -e 's:@PREFIX@:${PREFIX}:g' \
			${FILESDIR}/jftpgw.sh.in > ${FILESDIR}/jftpgw.sh
		${INSTALL_SCRIPT} ${FILESDIR}/jftpgw.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
