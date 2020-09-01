# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pftpd
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ifm.liu.se/pub/unix/pftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded anonymous FTP daemon

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01


PLIST_FILES=	sbin/pftpd \
		man/man1/pftpd.1.gz \
		man/man1/rpad.1.gz

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} pftpd ${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} *.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
