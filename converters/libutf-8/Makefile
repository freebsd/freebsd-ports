# New ports collection makefile for:	libutf-8
# Date created:				1 April 1999
# Whom:					G. Adam Stanislav <adam@whizkidtech.net>
#
# $FreeBSD$
#

PORTNAME=	libutf-8
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/i18n/ \
		ftp://ftp.whizkidtech.redprince.net/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode conversion routines between UCS-4 and UTF-8

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
