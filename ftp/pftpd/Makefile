PORTNAME=	pftpd
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ifm.liu.se/pub/unix/pftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded anonymous FTP daemon
WWW=		https://www.lysator.liu.se/~pen/pftpd/

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	sbin/pftpd \
		share/man/man1/pftpd.1.gz \
		share/man/man1/rpad.1.gz

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} pftpd ${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/share/man/man1)
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
