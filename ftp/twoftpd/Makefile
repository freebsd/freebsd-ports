# New ports collection makefile for:	twoftpd
# Date created:				14 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	twoftpd
PORTVERSION=	1.15
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/twoftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw

MAN1=		twoftpd-auth.1 twoftpd-xfer.1

BIN=		twoftpd-anon twoftpd-anon-conf twoftpd-auth twoftpd-conf twoftpd-xfer

do-install:
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${PREFIX}/man/man1
.endfor
.for FILE in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
