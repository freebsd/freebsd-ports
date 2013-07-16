# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	pftpd
PORTVERSION=	1.0.3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ifm.liu.se/pub/unix/pftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded anonymous FTP daemon

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		pftpd.1 rpad.1
PLIST_FILES=	sbin/pftpd

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} pftpd ${PREFIX}/sbin)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} *.1 ${MANPREFIX}/man/man1)
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
