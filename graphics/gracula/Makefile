# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	gracula
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.whizkidtech.redprince.net/cgi/gcl/ \
		http://www.whizkidtech.redprince.net/gcl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic Counter Language compiler/interpreter

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gracula ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sec2000 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NNL  ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
