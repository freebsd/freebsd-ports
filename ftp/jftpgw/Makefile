# Created by: se
# $FreeBSD$

PORTNAME=	jftpgw
PORTVERSION=	0.13.5
PORTREVISION=	5
CATEGORIES=	ftp
MASTER_SITES=	http://www.mcknight.de/jftpgw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly configurable FTP proxy

LICENSE=	GPLv2

USES=	tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-logpath=/var/log \
		--enable-crypt \
		--enable-sftp

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	${PORTNAME}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/jftpgw ${STAGEDIR}${PREFIX}/sbin/
		${INSTALL_DATA} ${WRKSRC}/jftpgw.conf.sample ${STAGEDIR}${PREFIX}/etc/
		${INSTALL_MAN} ${WRKSRC}/jftpgw.1 ${STAGEDIR}${PREFIX}/man/man1/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/jftpgw
		${INSTALL_DATA} ${WRKSRC}/doc/config.html ${STAGEDIR}${PREFIX}/share/doc/jftpgw

.include <bsd.port.mk>
