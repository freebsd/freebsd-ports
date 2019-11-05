# Created by: Sugimoto Sadahiro <ixtl@utmc.or.jp>
# $FreeBSD$

PORTNAME=	mindfocus
PORTVERSION=	0.88
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.toyoshima-house.net/classic/mf/files/
DISTFILES=	mindfocus-0.88.tar.gz mindfocus-data1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lovely characters stay on top of active window

USES=		imake xorg
USE_XORG=	xpm
RESTRICTED=	'contains commercial character data'

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/*.mfc ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pixmaps
	${INSTALL_DATA} ${WRKDIR}/pixmaps/*.xpm ${STAGEDIR}${EXAMPLESDIR}/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.euc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
