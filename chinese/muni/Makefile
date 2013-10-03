# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	muni
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	http://www.whizkidtech.redprince.net/i18n/muni/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find Unicode values for Chinese characters

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muni ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/m7773 ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/yung.gif ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/kang.gif ${STAGEDIR}${PREFIX}/share/doc/muni
.endif

.include <bsd.port.mk>
