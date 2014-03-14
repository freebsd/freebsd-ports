# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wtf
PORTVERSION=	20140310
CATEGORIES=	games
MASTER_SITES=	SF/bsdwtf

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Translates common Internet acronyms

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/misc|${DATADIR}|g' ${WRKSRC}/wtf*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms.comp ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
