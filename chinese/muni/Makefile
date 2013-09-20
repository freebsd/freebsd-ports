# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	muni
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	http://www.whizkidtech.redprince.net/i18n/muni/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find Unicode values for Chinese characters

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muni ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/m7773 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/yung.gif ${PREFIX}/share/doc/muni
	${INSTALL_DATA} ${WRKSRC}/kang.gif ${PREFIX}/share/doc/muni
.endif

.include <bsd.port.mk>
