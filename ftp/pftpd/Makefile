# New ports collection makefile for:	vsftpd
# Date created:				17 Mar 2002
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pftpd
PORTVERSION=	0.42
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/pftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	Multithreaded anonymous FTP daemon

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

RESTRICTED=	License problem

MAN1=		pftpd.1 rpad.1
PLIST_FILES=	sbin/pftpd

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/plib/configure

post-install:
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.post.mk>
