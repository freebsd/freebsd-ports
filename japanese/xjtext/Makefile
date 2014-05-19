# Created by: sada
# $FreeBSD$

PORTNAME=	xjtext
PORTVERSION=	1.3
PORTREVISION=	11
CATEGORIES=	japanese
MASTER_SITES=	http://plaza.harmonix.ne.jp/~onizuka/
DISTNAME=	XJTEXT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text viewer for Japanese vertical writings

USES=		bison
USE_GNOME=	imlib

SUB_FILES=	pkg-message

PORTDOCS=	README.txt
PORTEXAMPLES=	FSS README YAMA Ao.png Back2.png Brown.png Royal.png Royal2.png
PLIST_FILES=	bin/xjtext

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjtext ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
