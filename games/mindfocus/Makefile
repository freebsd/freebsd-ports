# New ports collection makefile for:   mindfocus
# Date created:        3 December 1998
# Whom:                Sugimoto Sadahiro <ixtl@utmc.or.jp>
#
# $FreeBSD$
#

PORTNAME=	mindfocus
PORTVERSION=	0.88
CATEGORIES=	games
MASTER_SITES=	http://www.toyoshima-house.net/classic/mf/files/
DISTFILES=	mindfocus-0.88.tar.gz mindfocus-data1.tar.gz

MAINTAINER=	ixtl@utmc.or.jp
COMMENT=	Lovely characters stay on top of active window

USE_IMAKE=	yes
USE_XPM=	yes
RESTRICTED=	'contains commercial character data'

post-install:
.for i in mayu.mfc mio.mfc misaki2.mfc mizuka.mfc myu.mfc ryoko.mfc
	${INSTALL_DATA} ${WRKDIR}/$i ${PREFIX}/share/examples/mindfocus
.endfor
.for i in mayu1.xpm mayu2.xpm mayu3.xpm mayu4.xpm \
	mio1.xpm mio2.xpm mio3.xpm mio4.xpm \
	misaki2-1.xpm misaki2-2.xpm misaki2-3.xpm misaki2-4.xpm \
	mizuka1.xpm mizuka2.xpm mizuka3.xpm mizuka4.xpm \
	myu1.xpm myu2.xpm myu3.xpm myu4.xpm \
	ryoko1.xpm ryoko2.xpm ryoko3.xpm ryoko4.xpm
	${INSTALL_DATA} ${WRKDIR}/pixmaps/$i ${PREFIX}/share/examples/mindfocus/pixmaps
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/mindfocus
	${INSTALL_MAN} ${WRKSRC}/doc/HISTORY.euc ${PREFIX}/share/doc/ja/mindfocus
	${INSTALL_MAN} ${WRKSRC}/doc/MFC.euc ${PREFIX}/share/doc/ja/mindfocus
	${INSTALL_MAN} ${WRKSRC}/doc/README.euc ${PREFIX}/share/doc/ja/mindfocus
	${INSTALL_MAN} ${WRKSRC}/doc/SCRIPT.euc ${PREFIX}/share/doc/ja/mindfocus
	${INSTALL_MAN} ${WRKSRC}/doc/TODO.euc ${PREFIX}/share/doc/ja/mindfocus
.endif

.include <bsd.port.mk>
