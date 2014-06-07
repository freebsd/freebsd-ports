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

USES=		imake
USE_XORG=	xpm
RESTRICTED=	'contains commercial character data'

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in mayu.mfc mio.mfc misaki2.mfc mizuka.mfc myu.mfc ryoko.mfc
	${INSTALL_DATA} ${WRKDIR}/$i ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pixmaps
.for i in mayu1.xpm mayu2.xpm mayu3.xpm mayu4.xpm \
	mio1.xpm mio2.xpm mio3.xpm mio4.xpm \
	misaki2-1.xpm misaki2-2.xpm misaki2-3.xpm misaki2-4.xpm \
	mizuka1.xpm mizuka2.xpm mizuka3.xpm mizuka4.xpm \
	myu1.xpm myu2.xpm myu3.xpm myu4.xpm \
	ryoko1.xpm ryoko2.xpm ryoko3.xpm ryoko4.xpm
	${INSTALL_DATA} ${WRKDIR}/pixmaps/$i ${STAGEDIR}${EXAMPLESDIR}/pixmaps
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/HISTORY.euc ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/MFC.euc ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/README.euc ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/SCRIPT.euc ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/TODO.euc ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
