# New ports collection makefile for:	twoftpd
# Date created:				14 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	twoftpd
PORTVERSION=	1.14
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/twoftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw

BIN=		twoftpd-anon twoftpd-anon-conf twoftpd-auth twoftpd-conf twoftpd-xfer

do-install:
.for FILE in ${BIN}
	@${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
