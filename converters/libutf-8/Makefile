PORTNAME=	libutf-8
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.whizkidtech.redprince.net/i18n/ \
		ftp://ftp.whizkidtech.redprince.net/unix/

MAINTAINER=	dgjohns@gmail.com
COMMENT=	Unicode conversion routines between UCS-4 and UTF-8
WWW=		http://www.whizkidtech.redprince.net/i18n/

USE_LDCONFIG=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libutf-8.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libutf-8.so.1 ${STAGEDIR}${PREFIX}/lib/libutf-8.so
	${INSTALL_DATA} ${WRKSRC}/utf-8.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/*.3 ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>
