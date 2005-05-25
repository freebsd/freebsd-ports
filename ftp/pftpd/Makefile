# New ports collection makefile for:	vsftpd
# Date created:				17 Mar 2002
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pftpd
PORTVERSION=	1.0.1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/pftpd/ \
		ftp://ftp.ifm.liu.se/pub/unix/pftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded anonymous FTP daemon

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		pftpd.1 rpad.1
PLIST_FILES=	sbin/pftpd

post-extract:
.for f in ${MAN1}
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/doc/${f}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/plib/configure

post-install:
	@${CAT} ${WRKSRC}/ISSUES

.include <bsd.port.mk>
