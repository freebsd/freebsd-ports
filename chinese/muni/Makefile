PORTNAME=	muni
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	http://www.whizkidtech.redprince.net/i18n/muni/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find Unicode values for Chinese characters
WWW=		http://www.whizkidtech.redprince.net/i18n/muni/

DEPRECATED=	Upstream disapeared and distfile is no more available
EXPIRATION_DATE=2025-03-31

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muni ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/m7773 ${STAGEDIR}${PREFIX}/bin
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/yung.gif ${STAGEDIR}${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/kang.gif ${STAGEDIR}${PREFIX}/share/doc/muni

.include <bsd.port.mk>
