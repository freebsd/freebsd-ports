# New ports collection makefile for:	ftpproxy
# Date created:				15 May 2001
# Whom:					Philippe Le Berre <philippe@le-berre.com>
#
# $FreeBSD$
#

PORTNAME=	ftpproxy
PORTVERSION=	1.0.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.quietsche-entchen.de/download/
DISTNAME=	ftpproxy-${PORTVERSION}

MAINTAINER=	philippe@le-berre.com

MAN1=		ftp.proxy.1
MANCOMPRESSED=	no

pre-build:
	${PERL} -pi -e "s@gcc@${CC}@g; s@-O2 -Wall -ggdb@-Wall ${CFLAGS}@g; \
			s@/usr/local@${PREFIX}@g" ${WRKSRC}/Makefile

post-patch:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
