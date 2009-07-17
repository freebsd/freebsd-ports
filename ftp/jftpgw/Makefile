# New ports collection makefile for:    jftpgw
# Date created:         Sun Jul 15 13:19:01 CEST 2001
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	jftpgw
PORTVERSION=	0.13.5
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly configurable FTP proxy

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-logpath=/var/log \
		--enable-crypt \
		--enable-sftp

MAN1=		jftpgw.1

USE_RC_SUBR=	${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jftpgw ${PREFIX}/sbin/
		${INSTALL_DATA} ${WRKSRC}/jftpgw.conf.sample ${PREFIX}/etc/
		${INSTALL_MAN} ${WRKSRC}/jftpgw.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/jftpgw
		${INSTALL_DATA} ${WRKSRC}/doc/config.html ${PREFIX}/share/doc/jftpgw
.endif

.include <bsd.port.mk>
