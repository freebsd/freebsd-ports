# New ports collection makefile for:	libutf-8
# Date created:				1 April 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	libutf
PORTVERSION=	8.1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.net/fports/ \
		ftp://ftp.whizkidtech.net/unix/ \
		http://www.whizkidtech.net/ISO-8859-2/
DISTNAME=	libutf-8-1.0

MAINTAINER=	adam@whizkidtech.net

INSTALLS_SHLIB=	yes

MAN3=		libutf-8.3 fgetu8.3 fputu8.3 sgetu8.3 sputu8.3

do-install:
	${INSTALL_DATA} ${WRKSRC}/libutf-8.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libutf-8.so.1 ${PREFIX}/lib/libutf-8.so
	${INSTALL_DATA} ${WRKSRC}/utf-8.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/libutf-8.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/fgetu8.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/fputu8.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/sgetu8.3 ${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/sputu8.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
